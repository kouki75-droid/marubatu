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


	int panel_image[30];

	// カーソル位置（マップ配列上の座標）
	int cursorX = 0;
	int cursorY = 0;
	// キーの押しっぱなし判定用（前フレームの状態を保持）
	int oldKeyLeft = 0;
	int oldKeyRight = 0;
	int oldKeyUp = 0;
	int oldKeyDown = 0;
	int oldKeySpace = 0;
	enum marubatumode
	{
		maru,
		batu,
	};
	int mode = maru;

	public:
		Gamegamenn() {}
		
		void Input()
		{
			for (int i = 0; i < 30; i++) {
				panel_image[i] = LoadGraph("data/panel0.png");	//	通れる方の画像
			}
		}
		//更新処理
		void Update() 
		{
			// 現在のキー状態を取得
			int keyLeft = CheckHitKey(KEY_INPUT_LEFT);
			int keyRight = CheckHitKey(KEY_INPUT_RIGHT);
			int keyUp = CheckHitKey(KEY_INPUT_UP);
			int keyDown = CheckHitKey(KEY_INPUT_DOWN);
			

			// 押した瞬間だけ反応させる（押しっぱなしで連続移動しないように）
			if (keyLeft && !oldKeyLeft) {
				cursorX--;
			}
			if (keyRight && !oldKeyRight) {
				cursorX++;
			}
			if (keyUp && !oldKeyUp) {
				cursorY--;
			}
			if (keyDown && !oldKeyDown) {
				cursorY++;
			}
			
			oldKeyLeft = keyLeft;
			oldKeyRight = keyRight;
			oldKeyUp = keyUp;
			oldKeyDown = keyDown;

		}
		//描画処理
		void Draw() 
		{
			for (int h = 0; h < GAME_H; h++) {
				for (int w = 0; w < GAME_W; w++) {
					//	マップ配列から番号を取得
					int num = MapData[h][w];
					//	描画する座標（パネルサイズ分ずらしたところ）
					int x = w * PANEL_SIZE;
					int y = h * PANEL_SIZE;
					//	この番号の画像のパネル画像の描画
					DrawGraph(x+300, y+100, panel_image[num], TRUE);
				}
			}
			int selX = cursorX * PANEL_SIZE + 300;
			int selY = cursorY * PANEL_SIZE + 100;
			DrawBox(selX, selY, selX + PANEL_SIZE, selY + PANEL_SIZE, GetColor(255, 255, 0), FALSE);
			
			

			// スペースキーの押下状態を取得
			
			
			if (CheckHitKey(KEY_INPUT_SPACE)) {
				// スペースキーが押されたときの処理
				MapData[cursorY][cursorX] = (mode == maru) ? 1 : 0; // マップデータを更新
					
				DrawCircle(cursorX * PANEL_SIZE + 350, cursorY * PANEL_SIZE + 150, 40, GetColor(255, 0, 0), FALSE);
				


			}

		}
		//音声再生処理
		void Sound();
};