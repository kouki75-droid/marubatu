#include "Music.h"

void Music::music_in()
{
	skil = LoadSoundMem("music/Skil_Usage.mp3");
	marubatu = LoadSoundMem("music/marubatuse.mp3");
	serect = LoadSoundMem("music/serect.mp3");
}

// タイトルBGMを流す
void Music::titl_bgm()
{
	if (one_music == false)
	{
		PlayMusic("music/Titlbgm.mp3", DX_PLAYTYPE_LOOP);
		SetVolumeMusic(music_volume);
		one_music = true;
	}
	
}

// ゲームBGMを流す
void Music::game_bgm()
{
	if (one_music == false)
	{
		PlayMusic("music/Gamebgm.mp3", DX_PLAYTYPE_LOOP);
		SetVolumeMusic(music_volume);
		one_music = true;
	}
}


// BGMを止める
void Music::stop_music()
{
	StopMusic();
	one_music = false;
}

// SEを流す
// スキル
void Music::skil_se()
{
	PlaySoundMem(skil, DX_PLAYTYPE_BACK);
	ChangeVolumeSoundMem(music_volume, skil);
}

// 〇×設置
void Music::marubatu_se()
{
	PlaySoundMem(marubatu, DX_PLAYTYPE_BACK);
	ChangeVolumeSoundMem(music_volume, marubatu);
}

// 選ぶとき
void Music::serect_se()
{
	PlaySoundMem(serect, DX_PLAYTYPE_BACK);
	ChangeVolumeSoundMem(music_volume, serect);
}
