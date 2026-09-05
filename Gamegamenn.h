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
	

	public:
		Gamegamenn() {}
		
		void Input()
		{
			for(int i = 0; i < 30; i++){
				panel_image[i] = LoadGraph("data/panel0.png");	//	通れる方の画像
			}
		}
		void Update() 
		{

		}
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
			 
			     

		}
		void Sound();
};