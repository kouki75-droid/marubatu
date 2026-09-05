#pragma once
#include <ctime>		// 標準C ライブラリ ヘッダー <time.h> をインクルードし、関連する名前を std 名前空間に追加します。
#include "DxLib.h"		// DxLib

/// <summary>
/// キーリーダークラス
/// </summary>
class Checkkey
{
	/// <summary>
	/// キーの状態配列
	/// </summary>
	char key_state_arr[256];

public:

	/// <summary>
	/// キー読み込み（一括）
	/// </summary>
	void Read()
	{
		GetHitKeyStateAll(this->key_state_arr);

	}

	bool Check_key(int arg_key_coode)
	{
		// 指定されたキーの状態をチェック
		if (this->key_state_arr[arg_key_coode] == 1)
		{
			// 押されていればtrueを返す
			return true;
		}
		// 押されていなければfalseを返す
		return false;

	}

};
