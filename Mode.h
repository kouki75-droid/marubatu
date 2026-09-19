#pragma once
#include <string>
#include "DxLib.h"		// DxLib

class Mode
{
public:

	// １：タイトル　２：ゲーム中　３：セレクト
	int game_mode = 1;

	int a = 0;

	int num = 0;

	int turn_gema = 0;

	void riset()
	{
		num = 0;
	}

};
