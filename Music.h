#pragma once
#include <ctime>		// 標準C ライブラリ ヘッダー <time.h> をインクルードし、関連する名前を std 名前空間に追加します。
#include "DxLib.h"		// DxLib

class Music
{
	// BGMの音量
	int music_volume = 255;

	// BGM

	// SE
	int skil;
	int marubatu;
	int serect;

	// 一回しか呼び出さないようにする
	bool one_music = false;
	

public:

	// 音楽を入れる
	void music_in();

	// BGMを流す
	void titl_bgm();

	// BGMを流す
	void game_bgm();


	// SEを流す
	void skil_se();

	// SEを流す
	void marubatu_se();


	// SEを流す
	void serect_se();



	// BGMを止める
	void stop_music();
};

