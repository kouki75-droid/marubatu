#pragma once

#include "CheckKey.h"
#include "Gamegamenn.h"
#include "Titl.h"
#include "Result.h"
#include "Mode.h"
#include"Music.h"

class Game
{
private:
    // キーインスタンス
    CheckKey key;

    // 丸罰ゲーム  
    Gamegamenn gamenn;

    // タイトル  
    Titl titl;

    // 結果  
    Result result;

    // ゲームモード  
    Mode mode;

    // 音楽
    Music music;

public:
    /// <summary>  
    /// コンストラクター  
    /// </summary>  
    Game() {}

    /// <summary>
    /// タイトル処理
    /// </summary>
    void Titl();

    /// <summary>  
    /// ゲームループ  
    /// </summary>  
    void Game_loop();

    /// <summary>  
    /// 入力処理  
    /// </summary>  
    void Input();

    /// <summary>  
    /// 更新処理  
    /// </summary>  
    void Update();

    /// <summary>  
    /// 描画処理  
    /// </summary>  
    void Draw();

    /// <summary>  
    /// 音声再生処理  
    /// </summary>  
    void Sound();

    /// <summary>
    /// 結果処理
    /// </summary>
    void Result();
};