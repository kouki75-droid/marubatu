#pragma once

#define MASU_DISTANCE 16

class Result
{
private:
    // CPU結果状態・画像
    bool cpu_win = false;
    int image_cpu_win = -1;

    bool cpu_lose = false;
    int image_cpu_lose = -1;

    bool cpu_drow = false;
    int image_cpu_drow = -1;

    // オフライン結果状態・画像
    bool maru_win = false;
    int image_maru_win = -1;

    bool maru_lose = false;
    int image_maru_lose = -1;

    bool maru_drow = false;
    int image_maru_drow = -1;

    bool one_more = false;
    bool return_menu = false;
    bool look_scene = false;

    // 選択枠の位置
    float serect_x = 100.0f;
    float serect_y = 300.0f;

    bool end_serect = false;

    // 結果を受け取る
    int num_result = 0;

    // 結果描画位置
    float result_x = 400.0f;
    float result_y = 20.0f;

public:
    Result() {}

    /// <summary>
    /// 画像読み込み
    /// </summary>
    void Loadimage();

    /// <summary>
    /// 選択枠移動処理
    /// </summary>
    void Move_serect_box();

    /// <summary>
    /// 結果数値の受取
    /// </summary>
    void result_in(int number);

    /// <summary>
    /// 結果に応じた描画フラグ切り替え
    /// </summary>
    void result_image();

    /// <summary>
    /// 上下移動処理
    /// </summary>
    void move();

    /// <summary>
    /// 選択決定処理
    /// </summary>
    void srect_next(int& number);

    /// <summary>
    /// 選択枠の移動制限
    /// </summary>
    void serect_box_in();

    /// <summary>
    /// 選択肢描画
    /// </summary>
    void Draw_serect();

    /// <summary>
    /// タイトル/勝敗結果描画
    /// </summary>
    void Draw_Titl();
};