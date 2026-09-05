#pragma once
#include <string>
#include "DxLib.h"		// DxLib
#include "Background.h"

/// <summary>
/// スプライトクラス
/// </summary>
class Sprite: public Background
{
protected:

	/// <summary>
	/// 横表示位置
	/// </summary>
	int pos_x = 0;

	/// <summary>
	/// 縦表示位置
	/// </summary>
	int pos_y = 0;

public:

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Sprite(){}

	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="arg_file_path">初期画像ファイルパス</param>
	Sprite(std::string arg_file_path)
	{
		// 画像ファイルの読み込み
		this->Load_image(arg_file_path);
	}

	/// <summary>
	/// 表示位置の指定
	/// </summary>
	/// <param name="arg_x">横位置</param>
	/// <param name="arg_y">縦位置</param>
	void Set_pos(int arg_x, int arg_y)
	{
		// 横座標の登録
		this->pos_x = arg_x;
		// 縦座標の登録
		this->pos_y = arg_y;
	}

	/// <summary>
	/// 移動
	/// </summary>
	/// <param name="arg_diff_x">横位置の差分</param>
	/// <param name="arg_diff_y">縦位置の差分</param>
	void Move(int arg_diff_x, int arg_diff_y)
	{
		// 横位置の差分を反映
		this->pos_x += arg_diff_x;
		// 縦位置の差分を反映
		this->pos_y += arg_diff_y;
	}

	/// <summary>
	/// 画像を描画
	/// 　透過あり
	/// </summary>
	void Draw() override
	{
		// 画像描画
		DrawGraph(this->pos_x, this->pos_y, this->image_hnd, true);	
	}

};
