#pragma once
#include <string>
#include "DxLib.h"		// DxLib

#define GAME_W 5
#define GAME_H 5
#define PANEL_SIZE	100


class Gamegamenn
{
	int MapData[GAME_H][GAME_W] =
	{
		{ 0,0,0,0,0, },
		{ 0,0,0,0,0, },
		{ 0,0,0,0,0, },
		{ 0,0,0,0,0, },
		{ 0,0,0,0,0, },
	};

	// パネルの画像ハンドル
	int panel_image;
	int panel_image_maru;
	int panel_image_batu;

	int panel_image_maruwin = 0;
	int panel_image_batuwin = 0;
	int panel_image_draw = 0;

	int _test = 0;

	// カーソルの位置
	int cursorX = 0;
	int cursorY = 0;
	int oldKeyLeft = 0;
	int oldKeyRight = 0;
	int oldKeyUp = 0;
	int oldKeyDown = 0;
	int oldKeySpace = 0;


	//// 勝敗の状態を表す変数
	int winner_state = 0;		// 0=まだ勝負なし, 1=マルの勝ち, 2=バツの勝ち 3=引き分け
	int WIN_COUNT = 4;	// 何個揃ったら勝ちか

	// マルとバツの状態を表す列挙型
	enum marubatumode
	{
		maru = 1,	// 0はマス未使用の意味で使うので1から
		batu = 2,
	};
	int mode = maru;

public:
	Gamegamenn() {}

	// 入力処理
	void Input()
	{

		/*_test = LoadGraph("data/panel0.png");*/

		// パネルの画像を読み込む
		panel_image = LoadGraph("data/panel0.png");
		panel_image_maru= LoadGraph("data/maru 1.png");
		panel_image_batu = LoadGraph("data/batu 1.png");
		

		// 勝敗の画像を読み込む
		panel_image_maruwin = LoadGraph("data/maruwin.png");
		panel_image_batuwin = LoadGraph("data/batuwin.png");
		panel_image_draw = LoadGraph("data/draw.png");
	}

	//更新処理
	void Update()
	{
		

		// キー入力の取得
		int keyLeft = CheckHitKey(KEY_INPUT_LEFT);
		int keyRight = CheckHitKey(KEY_INPUT_RIGHT);
		int keyUp = CheckHitKey(KEY_INPUT_UP);
		int keyDown = CheckHitKey(KEY_INPUT_DOWN);
		int keySpace = CheckHitKey(KEY_INPUT_SPACE);

		// キーが押された瞬間だけ反応するようにする
		// 左右上下のカーソル移動
		if (keyLeft && !oldKeyLeft) {
			cursorX--;
			if (cursorX < 0) {
				cursorX = 0;
			}
		}
		if (keyRight && !oldKeyRight) {
			cursorX++;
			if (cursorX > GAME_W - 1) {
				cursorX = GAME_W - 1;
			}
		}
		if (keyUp && !oldKeyUp) {
			cursorY--;
			if (cursorY < 0) {
				cursorY = 0;
			}
		}
		if (keyDown && !oldKeyDown) {
			cursorY++;
			if (cursorY > GAME_H - 1) {
				cursorY = GAME_H - 1;
			}
		}

		// スペースキーが「押された瞬間」だけ反応
		if (keySpace && !oldKeySpace) {
			// まだ何も置かれていないマスだけ置けるようにする
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
	}
	
	// (x, y)に置いた記号(who)を基準に4つ揃ったかチェック
	bool CheckWin(int x, int y, int who)
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
		// 引き分け判定
		if (MapData[0][0] != 0 && MapData[0][1] != 0 && MapData[0][2] != 0 && MapData[0][3] != 0 && MapData[0][4] != 0 &&
			MapData[1][0] != 0 && MapData[1][1] != 0 && MapData[1][2] != 0 && MapData[1][3] != 0 && MapData[1][4] != 0 &&
			MapData[2][0] != 0 && MapData[2][1] != 0 && MapData[2][2] != 0 && MapData[2][3] != 0 && MapData[2][4] != 0 &&
			MapData[3][0] != 0 && MapData[3][1] != 0 && MapData[3][2] != 0 && MapData[3][3] != 0 && MapData[3][4] != 0 &&
			MapData[4][0] != 0 && MapData[4][1] != 0 && MapData[4][2] != 0 && MapData[4][3] != 0 && MapData[4][4] != 0)
		{
			winner_state = 3; // 引き分け
		}
		return false;

	
	}


	
	//描画処理
	void Draw()
	{



		// パネル地の描画
		for (int h = 0; h < GAME_H; h++) {
			for (int w = 0; w < GAME_W; w++) {
				int num = MapData[h][w];
				int x = w * PANEL_SIZE;
				int y = h * PANEL_SIZE;
				DrawGraph(x + 300, y + 100, panel_image, TRUE); // パネル地の絵は常に0番
			}
		}

		// 選択中のマスを黄色で囲む
		int selX = cursorX * PANEL_SIZE + 300;
		int selY = cursorY * PANEL_SIZE + 100;
		DrawBox(selX, selY, selX + PANEL_SIZE, selY + PANEL_SIZE, GetColor(255, 255, 0), FALSE);


		// マルとバツを描画
		for (int h = 0; h < GAME_H; h++) {
			for (int w = 0; w < GAME_W; w++) {
				int centerX = w * PANEL_SIZE + 300;
				int centerY = h * PANEL_SIZE + 100;

				// マルとバツを描画
				if (MapData[h][w] == maru) {
					DrawGraph(centerX, centerY, panel_image_maru, TRUE);
				}
				else if (MapData[h][w] == batu) {
					DrawGraph(centerX, centerY, panel_image_batu, TRUE);
				}
			}
		}

		if (winner_state == 0)
		{
			// 勝敗が決まっていない場合は何もしない
		}
		else if (winner_state == 1)
		{
			//DrawString(300, 50, "マルの勝ち", GetColor(255, 0, 0));
			DrawGraph(300, 100, panel_image_maruwin, TRUE);
		}
		else if (winner_state == 2)
		{
			//DrawString(300, 50, "バツの勝ち", GetColor(0, 0, 255));
			DrawGraph(300, 100, panel_image_batuwin, TRUE);
		}
		else if (winner_state == 3) {
			//DrawString(300, 50, "引き分け", GetColor(0, 255, 0));
			DrawGraph(300, 100, panel_image_draw, TRUE);
		}
	}

	//サウンド処理
	void Sound();

};