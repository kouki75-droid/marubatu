#pragma once
#include <string>
#include "DxLib.h"		// DxLib

class Titl
{
	int op_x = 0;
	int op_y = 0;
	int title_x = 1280;
	int title_y = 720;

public:

	// •`‰æ
	void Draw_titl()
	{
		DrawBox(op_x, op_y, title_x, title_y, GetColor(255, 255, 255), TRUE);	// ”’‚¢lŠpŒ`‚ğ•`‰æ
		DrawString(580, 100, "Z", GetColor(255, 0, 0));	// •¶š—ñ‚ğ•`‰æ
		DrawString(595, 100, "~", GetColor(0, 0, 255));	// •¶š—ñ‚ğ•`‰æ
		DrawString(610, 100, "ƒQ[ƒ€", GetColor(0, 0, 0));	// •¶š—ñ‚ğ•`‰æ
		DrawString(530, 180, "CPU‚Ì‹­‚³", GetColor(0, 0, 0));	// •¶š—ñ‚ğ•`‰æ
		DrawString(550, 210, "< ƒm[ƒ}ƒ‹", GetColor(0, 0, 0));	// •¶š—ñ‚ğ•`‰æ
		DrawString(550, 240, "< ƒn[ƒh", GetColor(0, 0, 0));	// •¶š—ñ‚ğ•`‰æ
		DrawString(530, 290, "CPU‘Îí", GetColor(0, 0, 0));	// •¶š—ñ‚ğ•`‰æ
		DrawString(550, 320, "< æs", GetColor(0, 0, 0));	// •¶š—ñ‚ğ•`‰æ
		DrawString(550, 350, "< ŒãU", GetColor(0, 0, 0));	// •¶š—ñ‚ğ•`‰æ
		DrawString(530, 390, "ƒIƒtƒ‰ƒCƒ“‘Îí", GetColor(0, 0, 0));	// •¶š—ñ‚ğ•`‰æ
	}

};