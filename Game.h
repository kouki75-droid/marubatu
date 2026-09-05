#pragma once

#include <ctime>			// 標準C ライブラリ ヘッダー <time.h> をインクルードし、関連する名前を std 名前空間に追加します。
#include "DxLib.h"			// DxLib
#include "CheckKey.h"
#include "Gamegamenn.h"

class Game
{
    CheckKey key;
    Gamegamenn gamenn;
public:

    /// <summary>
    /// コンストラクター
    /// </summary>
    Game(){}

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

};