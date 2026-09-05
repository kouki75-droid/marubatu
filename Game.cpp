#pragma once
#include"Game.h"

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
        // リフレッシュレートを設定するための処理.６０分の１になるように設定
        clock_t check_fps = clock() + CLOCKS_PER_SEC / 60;

        // マウスカーソル表示設定
        SetMouseDispFlag(FALSE);

        // 画面上の描画を初期化（画面を消去）
        ClearDrawScreen();

		this->Input();	// 入力処理
		this->Update();	// 更新処理
		this->Draw();	// 描画処理
		this->Sound();	// 音声再生処理

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

/// <summary>
    /// 入力処理
    /// </summary>
void Game::Input() 
{
    // キー情報の読み込み
    this->key.Read();
	this->gamenn.Input();
}

/// <summary>
/// 更新処理
/// </summary>
void Game::Update()
{
	this->gamenn.Update();
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Draw()
{
    ClearDrawScreen();
    this->gamenn.Draw();
    ScreenFlip();
	
}

/// <summary>
/// 音声再生処理
/// </summary>
void Game::Sound()
{

}
