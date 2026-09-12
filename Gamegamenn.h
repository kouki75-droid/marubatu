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
	int panel_image[30];
	int panel_image_maru[30];
	int panel_image_batu[30];

	// カーソルの位置
	int cursorX = 0;
	int cursorY = 0;
	int oldKeyLeft = 0;
	int oldKeyRight = 0;
	int oldKeyUp = 0;
	int oldKeyDown = 0;
	int oldKeySpace = 0;

	// マルとバツの状態を表す列挙型
	enum marubatumode
	{
		maru = 1,	// 0はマス未使用の意味で使うので1から
		batu = 2,
	};
	int mode = maru;

public:
	Gamegamenn() {}

	void Input()
	{
		for (int i = 0; i < 30; i++) {
			panel_image[i] = LoadGraph("data/panel0.png");
			panel_image_maru[i] = LoadGraph("data/maru 1.png");
			panel_image_batu[i] = LoadGraph("data/batu 1.png");
		}
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
	


	//描画処理
	void Draw()
	{
		// パネル地の描画
		for (int h = 0; h < GAME_H; h++) {
			for (int w = 0; w < GAME_W; w++) {
				int num = MapData[h][w];
				int x = w * PANEL_SIZE;
				int y = h * PANEL_SIZE;
				DrawGraph(x + 300, y + 100, panel_image[0], TRUE); // パネル地の絵は常に0番
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
					DrawGraph(centerX, centerY, panel_image_maru[0], TRUE);
				}
				else if (MapData[h][w] == batu) {
					DrawGraph(centerX, centerY, panel_image_batu[0], TRUE);
				}
			}
		}
	}

	//サウンド処理
	void Sound();
};