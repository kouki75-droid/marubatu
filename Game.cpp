#include "Game.h"
#include "DxLib.h"
#include <ctime>

/// <summary>
/// ゲームループ
/// </summary>
void Game::Game_loop()
{
    // ------------------------------
    //  ゲームループ
    // ------------------------------
    while (ProcessMessage() == 0)
    {
        // リフレッシュレートを設定するための処理.60分の1になるように設定
        clock_t check_fps = clock() + CLOCKS_PER_SEC / 60;

        // マウスカーソル表示設定  
        SetMouseDispFlag(FALSE);

        // 画面上の描画を初期化（画面を消去）  
        ClearDrawScreen();

        this->Titl();
        this->Input();  // 入力処理  
        this->Update(); // 更新処理  
        this->Draw();   // 描画処理  
        this->Sound();  // 音声再生処理  
        this->Result();

        // リフレッシュレートが一定になるまで待つ処理  
        while (clock() < check_fps) {}

        // 裏画面の描画を表に反映  
        ScreenFlip();

        // ESCキーでループから抜ける  
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }
    }
}

void Game::Titl()
{
    if (mode.game_mode == 1)
    {
        // 描画
        this->titl.Draw_titl();

        // 丸罰リセット
        this->gamenn.reset();

        // スペース押したらゲームに  
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            mode.a = 1;
        }
        else if (mode.a == 1)
        {
            mode.game_mode = 2;
            mode.a = 0;
        }
    }
}

/// <summary>
/// 入力処理
/// </summary>
void Game::Input()
{
    if (mode.game_mode == 2)
    {
        // キー情報の読み込み
        this->key.Read();
        this->gamenn.Input();
    }
}

/// <summary>
/// 更新処理
/// </summary>
void Game::Update()
{
    if (mode.game_mode == 2)
    {
        this->gamenn.Update();
        // 結果を外へもっていく  
        gamenn.Result_out(mode.num);
      
        // 値が入ったらリザルトへ  
        if (mode.num != 0)
        {
            //gamenn.cout(mode.num);
              // もらう  
            gamenn.mode_count++;
            if (gamenn.mode_count >= 100)
            {
                mode.game_mode = 3;
                result.result_in(mode.num);
            }
            else
            {
                mode.game_mode = 2;
            }
			
        }
    }
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Draw()
{
    if (mode.game_mode == 2)
    {
        ClearDrawScreen();
        this->gamenn.Draw();
        ScreenFlip();

		//DrawFormatString(0, 0, GetColor(255, 255, 255), "mode.num=%d", gamenn.mode_count);
    }
}

/// <summary>
/// 音声再生処理
/// </summary>
void Game::Sound()
{
    if (mode.game_mode == 2)
    {
    }
}

void Game::Result()
{
    if (mode.game_mode == 3)
    {
        result.Move_serect_box();
        result.Draw_serect();
        result.Draw_Titl();

        // Aキー押したらタイトルに  
        if (CheckHitKey(KEY_INPUT_A))
        {
            mode.a = 1;
        }
        else if (mode.a == 1)
        {
            mode.game_mode = 1;
            mode.a = 0;
        }

        // 番号を外へ  
        // result.srect_next();
    }
}