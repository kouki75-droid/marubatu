#pragma once
#include <string>
#include "DxLib.h"		// DxLib

// 選択のマス幅
#define MASU_DISTANCE 32

class Result
{
	// タイトル何を表示するか
	// CPU
	// 勝ち
	bool cpu_win = false;

	// 負け
	bool cpu_lose = false;

	// 引き分け
	bool cpu_drow = false;

	// オフライン
	// 勝ち
	bool maru_win = false;

	// 負け
	bool maru_lose = false;

	// 引き分け
	bool maru_drow = false;

	// もう一回プレイするか
	bool one_more = false;

	// メニューに戻るか
	bool return_menu = false;

	// 場面を見る
	bool look_scene = false;

	// 選択してる四角の画像
	float serect_x = 100;
	float serect_y = 300;

public:

	// コンストラクター
	Result() {}

	// 選択する四角を動かす
	void Move_serect_box()
	{
		// 上下と動かす
		move_up();
		move_down();
		// ボックスを範囲内に収める
		serect_box_in();
	}

	// 結果を受け取る
	// CPU対戦かオフライン対戦か受け取って
	// 勝ちか負けか引き分けか受け取る、（オフラインの場合〇目線で
	void result_in(int &number)
	{

	}

	// 上を押したら上に動く
	void move_up()
	{
		if (CheckHitKey(KEY_INPUT_UP))
		{
			serect_y += MASU_DISTANCE;
		}
	}

	// 下を押したら下に動く
	void move_down()
	{
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			serect_y -= MASU_DISTANCE;
		}
	}

	// 1:リトライ　２：メニュー　３：場面を見る
	void srect_next(int number)
	{
		// スペースを押したら
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			// 選択してる選択肢をオンにする
			if (serect_y == 300)
			{
				number = 1;
			}
			else if (serect_y == 332)
			{
				number = 2;
			}
			else if (serect_y == 364)
			{
				number = 3;
			}
		}
	}

	// セレクトの箱を範囲外に行かせない
	void serect_box_in()
	{
		// 上に行き過ぎないように
		if (serect_y < 300)
		{
			serect_y = 300;
		}
		// 下に行き過ぎないように
		if (serect_y > 364)
		{
			serect_y = 364;
		}
	}

	// 選択肢を描画
	void Draw_serect()
	{
		// 
		DrawBox(serect_x, serect_y, MASU_DISTANCE, 50, GetColor(255, 255, 0),FALSE);

		DrawString(100, 300, "もう一回", GetColor(255, 255, 255));
		DrawString(100, 332, "メニューに戻る", GetColor(255, 255, 255));
		DrawString(100, 364, "場面を見る", GetColor(255, 255, 255));
	}

	// タイトルを描画
	void Draw_Titl()
	{
		// CPUの場合
		if (cpu_win == true)
		{

		}
		else if(cpu_lose == true)
		{
			
		}
		else if (cpu_drow == true)
		{

		}

		// オフラインの場合,〇の人基準
		if (maru_win == true)
		{

		}
		else if (maru_lose == true)
		{

		}
		else if (maru_drow == true)
		{

		}

	}

};
