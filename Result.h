#pragma once
#include <string>
#include "DxLib.h"		// DxLib

// 選択のマス幅
#define MASU_DISTANCE 16

class Result
{
	// タイトル何を表示するか
	// CPU
	// 勝ち
	bool cpu_win = false;
	int image_cpu_win;

	// 負け
	bool cpu_lose = false;
	int image_cpu_lose;

	// 引き分け
	bool cpu_drow = false;
	int image_cpu_drow;

	// オフライン
	// 勝ち
	bool maru_win = false;
	int image_maru_win;

	// 負け
	bool maru_lose = false;
	int image_maru_lose;

	// 引き分け
	bool maru_drow = false;
	int image_maru_drow;

	// もう一回プレイするか
	bool one_more = false;

	// メニューに戻るか
	bool return_menu = false;

	// 場面を見る
	bool look_scene = false;

	// 選択してる四角の画像
	float serect_x = 100;
	float serect_y = 300;

	// 
	bool end_serect = false;

	// 結果を受け取る
	int num_result = 0;

	// 結果描画
	float result_x = 400.0f;
	float result_y = 20.0f;

public:

	// コンストラクター
	Result() {}

	// リセット
	void reset()
	{
		cpu_win = false;

		// 負け
		cpu_lose = false;

		// 引き分け
		cpu_drow = false;

		// オフライン
		// 勝ち
		maru_win = false;

		// 負け
		maru_lose = false;

		// 引き分け
		maru_drow = false;

		// もう一回プレイするか
		one_more = false;

		// メニューに戻るか
		return_menu = false;

		// 場面を見る
		look_scene = false;

		// 選択してる四角の画像
		serect_x = 100;
		serect_y = 300;

		// 
		end_serect = false;

		// 結果を受け取る
		num_result = 0;

		// 結果描画
		result_x = 400.0f;
		result_y = 20.0f;
	}

	// 選択する四角を動かす
	void Move_serect_box()
	{
		// 上下と動かす
		move();
		// ボックスを範囲内に収める
		serect_box_in();
	}

	// ロードイメージ
	void Loadimage()
	{
		image_cpu_win = LoadGraph("data/cpu_win.png");
		image_cpu_lose = LoadGraph("data/cpu_lose.png");
		image_cpu_drow = LoadGraph("data/cpu_drow.png");

		image_maru_win = LoadGraph("data/maru_win.png");
		image_maru_lose = LoadGraph("data/maru_lose.png");
		image_maru_drow = LoadGraph("data/maru_drow.png");
		 
	}

	// 結果を受け取る
	// CPU対戦かオフライン対戦か受け取って
	// 勝ちか負けか引き分けか受け取る、（オフラインの場合〇目線で
	void result_in(int number)
	{
		// 勝ったか負けたか引き分けたか
		num_result = number;
	}

	// 結果によって画像を変える
	void result_image()
	{
		// オフラインの場合
		if (num_result == 0)
		{
			maru_win = false;
			maru_lose = false;
			maru_drow = false;
		}
		else if (num_result == 1)
		{
			maru_win = true;
		}
		else if (num_result == 2)
		{
			maru_lose = true;
		}
		else if (num_result == 3)
		{
			maru_drow = true;
		}
	}

	// 上を押したら上に動く
	// 下を押したら下に動く
	void move()
	{
		if (CheckHitKey(KEY_INPUT_UP))
		{
			if (end_serect == false)
			{
				serect_y -= MASU_DISTANCE* 2;
				end_serect = true;
			}
		}
		else if (CheckHitKey(KEY_INPUT_DOWN))
		{
			if (end_serect == false)
			{
				end_serect = true;
				serect_y += MASU_DISTANCE* 2;
			}
		}
		else
		{
			end_serect = false;
		}
	}

	// 1:リトライ　２：メニュー　３：場面を見る
	void srect_next(int &number)
	{
		// スペースを押したら
		if (CheckHitKey(KEY_INPUT_RETURN))
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
		DrawFormatString(0, 64, GetColor(255, 255, 255), "%d", number);
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
		DrawBox(serect_x, serect_y, serect_x + 200, serect_y + MASU_DISTANCE, GetColor(255, 255, 0),FALSE);

		DrawString(100, 300, "もう一回", GetColor(255, 255, 255));
		DrawString(100, 332, "メニューに戻る", GetColor(255, 255, 255));
		DrawString(100, 364, "場面を見る", GetColor(255, 255, 255));
	}

	// タイトルを描画
	void Draw_Titl()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", maru_win);
		DrawFormatString(0, 16, GetColor(255, 255, 255), "%d", maru_lose);
		DrawFormatString(0, 32, GetColor(255, 255, 255), "%d", maru_drow);
		DrawFormatString(0, 48, GetColor(255, 255, 255), "%d", num_result);

		// CPUの場合
		if (cpu_win == true)
		{
			DrawGraph(result_x, result_y, image_cpu_win, TRUE);
		}
		else if(cpu_lose == true)
		{
			DrawGraph(result_x, result_y, image_cpu_lose, TRUE);
		}
		else if (cpu_drow == true)
		{
			DrawGraph(result_x, result_y, image_cpu_drow, TRUE);
		}

		// オフラインの場合,〇の人基準
		if (maru_win == true)
		{
			DrawGraph(result_x, result_y, image_maru_win, TRUE);
		}
		else if (maru_lose == true)
		{
			DrawGraph(result_x, result_y, image_maru_lose, TRUE);
		}
		else if (maru_drow == true)
		{
			DrawGraph(result_x, result_y, image_maru_drow, TRUE);
		}

	}

};
