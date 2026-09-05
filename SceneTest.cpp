#include "SceneTest.h"
#include "DxLib.h"


void SceneTest::Init()
{
	// 背景画像の読込
	this->bg0.Load_image("bg.png");

	// スプライト画像の読込
	this->sp0.Load_image("tama_g.png");
	// スプライトの初期位置設定
	this->sp0.Set_pos(1280 / 2 - 24, 720 / 2 -24);
}

/// <summary>
/// 入力処理
/// </summary>
void SceneTest::Input()
{
	// キー状態読込（一括）
	this->key_state.Read();
}

/// <summary>
/// 更新処理
/// </summary>
void SceneTest::Update()
{
	// スプライトを動かす
	if(this->key_state.CheckKey(KEY_INPUT_LEFT))
	{
		this->sp0.Move(-1, 0);
	}
	if(this->key_state.CheckKey(KEY_INPUT_RIGHT))
	{
		this->sp0.Move(1, 0);
	}
	if(this->key_state.CheckKey(KEY_INPUT_UP))
	{
		this->sp0.Move(0, -1);
	}
	if(this->key_state.CheckKey(KEY_INPUT_DOWN))
	{
		this->sp0.Move(0, 1);
	}

	// ESCキーで終了
	if (this->key_state.CheckKey(KEY_INPUT_ESCAPE))
	{
		this->game_ptr->ChageScene(2);
	}

}

/// <summary>
/// 描画処理
/// </summary>
void SceneTest::Draw()
{
	// 背景0を描画
	this->bg0.Draw();

	// スプライトの描画
	this->sp0.Draw();
}

/// <summary>
/// 音声再生処理
/// </summary>
void SceneTest::Sound_play()
{


}
