#include "Game.h"
#include "DxLib.h"

// 定数の宣言
#define WINDOW_W 1280 // 画面サイズ 横
#define WINDOW_H 720  // 画面サイズ 縦

// ------------------------------
// WinMain
// ------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    // =======================================  
    //  初期化処理（ DXライブラリ ）
    // =======================================  
    // ログの書き出しを無効化  
    SetOutApplicationLogValidFlag(FALSE);

    // ウィンドウモードの設定  
    ChangeWindowMode(TRUE);

    // ウィンドウサイズとカラービットの設定  
    SetGraphMode(WINDOW_W, WINDOW_H, 32);

    // ウィンドウのタイトル  
    SetMainWindowText("DxLib Template");

    // 背景色の設定  
    SetBackgroundColor(128, 128, 128);

    // ＤＸライブラリ初期化処理  
    if (DxLib_Init() == -1)
    {
        return -1; // エラーが起きたら直ちに終了  
    }

    // ウィンドウ描画モード設定  
    SetDrawScreen(DX_SCREEN_BACK); // 裏画面に描画する

    // ゲームクラスのインスタンスを作成  
    Game game_obj;

    // ゲームループを呼び出す  
    game_obj.Game_loop();

    // =======================================  
    //  終了処理  
    // =======================================  
    // ＤＸライブラリ使用の終了処理  
    DxLib_End();

    // ソフトの終了  
    return 0;
}