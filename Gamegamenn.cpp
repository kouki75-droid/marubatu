#include "Gamegamenn.h"
#include "DxLib.h"

void Gamegamenn::Input()
{
    // 画像は毎フレームロードするのではなく、1度だけロードする
    if (panel_image == -1)
    {
        panel_image = LoadGraph("data/panel0.png");
        panel_image_maru = LoadGraph("data/maru 1.png");
        panel_image_batu = LoadGraph("data/batu 1.png");
        panel_image_skill = LoadGraph("data/skill.png");

        panel_image_maruwin = LoadGraph("data/maruwin.png");
        panel_image_batuwin = LoadGraph("data/batuwin.png");
        panel_image_draw = LoadGraph("data/draw.png");

		panel_image_skill_on = LoadGraph("data/skill_on.png");
		panel_image_skill_off = LoadGraph("data/skill_of.png");
    }
}

void Gamegamenn::reset()
{
    for (int h = 0; h < GAME_H; h++) {
        for (int w = 0; w < GAME_W; w++) {
            MapData[h][w] = 0;
        }
    }

    cursorX = 0;
    cursorY = 0;
    oldKeyLeft = 0;
    oldKeyRight = 0;
    oldKeyUp = 0;
    oldKeyDown = 0;
    oldKeySpace = 0;
    oldKeyE = 0;

    winner_state = 0;
    WIN_COUNT = 4;

    mode = maru;

    mode_count = 0;

    // スキル使用フラグのリセット
    maru_skill_used = false;
    batu_skill_used = false;
}

void Gamegamenn::Update()
{
    // キー入力の取得
    int keyLeft = CheckHitKey(KEY_INPUT_LEFT);
    int keyRight = CheckHitKey(KEY_INPUT_RIGHT);
    int keyUp = CheckHitKey(KEY_INPUT_UP);
    int keyDown = CheckHitKey(KEY_INPUT_DOWN);
    int keySpace = CheckHitKey(KEY_INPUT_SPACE);
    int keyE = CheckHitKey(KEY_INPUT_E);

    // 左右上下のカーソル移動（トリガー判定）
    if (keyLeft && !oldKeyLeft) {
        cursorX--;
        if (cursorX < 0) cursorX = 0;
    }
    if (keyRight && !oldKeyRight) {
        cursorX++;
        if (cursorX > GAME_W - 1) cursorX = GAME_W - 1;
    }
    if (keyUp && !oldKeyUp) {
        cursorY--;
        if (cursorY < 0) cursorY = 0;
    }
    if (keyDown && !oldKeyDown) {
        cursorY++;
        if (cursorY > GAME_H - 1) cursorY = GAME_H - 1;
    }

    //  Eキー押下時のスキル処理 
    if (keyE && !oldKeyE) {
        // 現在のターンプレイヤーがスキル未使用かチェック
        bool can_use_skill = (mode == maru && !maru_skill_used) || (mode == batu && !batu_skill_used);

        // 空きマス(0) かつ スキルが使える状態の場合のみ発動
        if (MapData[cursorY][cursorX] == 0 && can_use_skill) {
            CheckSkill(cursorX, cursorY, mode);

            // 使用済みフラグを更新
            if (mode == maru) {
                maru_skill_used = true;
            }
            else if (mode == batu) {
                batu_skill_used = true;
            }
            // スキル使用後、ターンを相手に渡す
            mode = (mode == maru) ? batu : maru;
        }
    }
    // スペースキーが押された瞬間だけ反応
    if (keySpace && !oldKeySpace) {
        if (MapData[cursorY][cursorX] == 0) {
            MapData[cursorY][cursorX] = mode;

            // 置いた直後に勝利判定
            if (CheckWin(cursorX, cursorY, mode)) {
                winner_state = mode;
            }
            // 次はもう一方の記号にする(交互切り替え)
            mode = (mode == maru) ? batu : maru;
        }
    }

    oldKeyLeft = keyLeft;
    oldKeyRight = keyRight;
    oldKeyUp = keyUp;
    oldKeyDown = keyDown;
    oldKeySpace = keySpace;
	oldKeyE = keyE;
}

void Gamegamenn::CheckSkill(int x, int y, int who)
{
    // 指定された座標(x, y)のマスをスキル不可侵状態(skill = 3)にする
    MapData[y][x] = skill;
}

bool Gamegamenn::CheckWin(int x, int y, int who)
{
    // 4方向(横, 縦, 右下がり斜め, 右上がり斜め)を調べる
    int dx[4] = { 1, 0, 1, 1 };
    int dy[4] = { 0, 1, 1, -1 };

    for (int dir = 0; dir < 4; dir++) {
        int count = 1; // 置いたマス自身を1個と数える

        // 正方向に数える
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        while (nx >= 0 && nx < GAME_W && ny >= 0 && ny < GAME_H && MapData[ny][nx] == who) {
            count++;
            nx += dx[dir];
            ny += dy[dir];
        }

        // 逆方向に数える
        nx = x - dx[dir];
        ny = y - dy[dir];
        while (nx >= 0 && nx < GAME_W && ny >= 0 && ny < GAME_H && MapData[ny][nx] == who) {
            count++;
            nx -= dx[dir];
            ny -= dy[dir];
        }

        // 4つ揃ったかチェック
        if (count >= WIN_COUNT) {
            return true;
        }
    }

    // 全てのマスが埋まっているか（引き分けチェック）
    bool isFull = true;
    for (int h = 0; h < GAME_H; h++) {
        for (int w = 0; w < GAME_W; w++) {
            if (MapData[h][w] == 0) {
                isFull = false;
                break;
            }
        }
        if (!isFull) {
            break;
        }
    }
    if (isFull && winner_state == 0) {
        winner_state = 3; // 引き分け
    }

    return false;
}

void Gamegamenn::Result_out(int& num)
{
    num = winner_state;
}

void Gamegamenn::Draw()
{
    // パネル地の描画
    for (int h = 0; h < GAME_H; h++) {
        for (int w = 0; w < GAME_W; w++) {
            int x = w * PANEL_SIZE;
            int y = h * PANEL_SIZE;
            DrawGraph(x + 300, y + 100, panel_image, TRUE);
        }
    }

    // 4. スキル使用状態UIの描画
    Draw_SkillUI();

    // 選択中のマスを黄色で囲む
    int selX = cursorX * PANEL_SIZE + 300;
    int selY = cursorY * PANEL_SIZE + 100;
    DrawBox(selX, selY, selX + PANEL_SIZE, selY + PANEL_SIZE, GetColor(255, 255, 0), FALSE);

    // 3. 〇・×・スキルの描画
    for (int h = 0; h < GAME_H; h++) {
        for (int w = 0; w < GAME_W; w++) {
            int centerX = w * PANEL_SIZE + 300;
            int centerY = h * PANEL_SIZE + 100;

            if (MapData[h][w] == maru) {
                DrawGraph(centerX, centerY, panel_image_maru, TRUE);
            }
            else if (MapData[h][w] == batu) {
                DrawGraph(centerX, centerY, panel_image_batu, TRUE);
            }
            else if (MapData[h][w] == skill) {
                DrawGraph(centerX, centerY, panel_image_skill, TRUE);
            }
        }
    }
    
  

    // 勝敗結果の描画
    if (winner_state == 1) {
        DrawGraph(300, 100, panel_image_maruwin, TRUE);
    }
    else if (winner_state == 2) {
        DrawGraph(300, 100, panel_image_batuwin, TRUE);
    }
    else if (winner_state == 3) {
        DrawGraph(300, 100, panel_image_draw, TRUE);
    }
}

void Gamegamenn::Draw_SkillUI()
{
    // UI枠・テキストの描画（盤面の右側に配置）
    int uiX = 850;
    int uiY = 120;

    DrawString(uiX, uiY, "[ Eキー: スキル発動 ]", GetColor(255, 255, 255));

    // 〇のスキル状態表示
    if (!maru_skill_used) {
		DrawString(uiX, uiY + 20, "〇のスキル:", GetColor(255, 100, 100));
        DrawGraph(uiX, uiY + 40, panel_image_skill_on, TRUE); 
    }
    else {
        DrawString(uiX, uiY + 20, "〇のスキル:", GetColor(255, 100, 100));
        DrawGraph(uiX, uiY + 40, panel_image_skill_off, TRUE ); 
    }

    // ×のスキル状態表示
    if (!batu_skill_used) {
		DrawString(uiX, uiY + 200, "×のスキル:", GetColor(100, 100, 255));
        DrawGraph(uiX, uiY + 220, panel_image_skill_on, TRUE); 
    }
    else {
		DrawString(uiX, uiY + 200, "×のスキル:", GetColor(100, 100, 255));
        DrawGraph(uiX, uiY + 220, panel_image_skill_off, TRUE); 
    }

    // 現在のターン表示
    if (mode == maru) {
        DrawString(uiX,  10, "現在のターン: 〇", GetColor(255, 100, 100));
    }
    else if (mode == batu) {
        DrawString(uiX,  10, "現在のターン: ×", GetColor(100, 100, 255));
    }
}

void Gamegamenn::Sound()
{
}



