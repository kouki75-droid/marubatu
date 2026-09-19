#pragma once

#include <ctime>			// 標準C ライブラリ ヘッダー <time.h> をインクルードし、関連する名前を std 名前空間に追加します。
#include "DxLib.h"			// DxLib
#include "CheckKey.h"
#include "Gamegamenn.h"
#include "Titl.h"
#include "Result.h"
#include "Mode.h"


class Game
{
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

public:

    /// <summary>
    /// コンストラクター
    /// </summary>
    Game(){}

    ///
    /// タイトル
    /// 
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

    ///
   /// 結果
   /// 
    void Result();

};