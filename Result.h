#pragma once
#include <string>
#include "DxLib.h"		// DxLib

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
	float serect_x = 0;
	float serect_y = 0;

public:

	// コンストラクター
	Result() {}

	// 選択する四角を動かす
	void Move_serect_box()
	{

	}

	// 選択肢を描画



};
