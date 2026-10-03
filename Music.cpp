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
	PlayMusic("music/Titlbgm.mp3", DX_PLAYTYPE_LOOP);
	SetVolumeMusic(music_volume);
}

// ゲームBGMを流す
void Music::game_bgm()
{
	PlayMusic("music/Gamebgm.mp3", DX_PLAYTYPE_LOOP);
	SetVolumeMusic(music_volume);
}


// BGMを止める
void Music::stop_music()
{
	StopMusic();
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
