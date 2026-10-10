#pragma once

class Titl
{
private:
    int op_x = 0;
    int op_y = 0;
    int title_x = 1280;
    int title_y = 720;

	int op_image = -1; 

    // はすい
    int serect_x = 530;
    int serect_y = 390;
    int serect_number = 5;
    bool serect_move = true;

public:
    /// <summary>
    /// 画像素材の読み込み（初期化時に一度だけ呼ぶ）
    /// </summary>
    void Input();
    // 選択を表示
    void serect();
    // 選択の移動
    void move_serect();

    // 描画  
    void Draw_titl();
};