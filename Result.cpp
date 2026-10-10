#include "Result.h"
#include "DxLib.h"

void Result::Loadimage()
{
    if (image_cpu_win == -1)
    {
        /*image_cpu_win = LoadGraph("data/cpu_win.png");
        image_cpu_lose = LoadGraph("data/cpu_lose.png");
        image_cpu_drow = LoadGraph("data/cpu_drow.png");

        image_maru_win = LoadGraph("data/maru_win.png");
        image_maru_lose = LoadGraph("data/maru_win.png");
        image_maru_drow = LoadGraph("data/maru_win.png");*/
        result_back = LoadGraph("data/result.png");
    }
}

void Result::Move_serect_box()
{
    move();
    serect_box_in();
}

void Result::result_in(int number)
{
    num_result = number;
    result_image(); // 値を受領した際にフラグも自動更新
}

void Result::result_image()
{
    // オフラインの場合の初期化と更新
    maru_win = false;
    maru_lose = false;
    maru_drow = false;

    if (num_result == 1)
    {
        maru_win = true;
    }
    else if (num_result == 2)
    {
        maru_lose = true;
    }
    else if (num_result == 3)
    {
        maru_drow = true;
    }
}

void Result::move()
{
    if (CheckHitKey(KEY_INPUT_UP))
    {
        if (!end_serect)
        {
            serect_y -= MASU_DISTANCE * 2;
            end_serect = true;
        }
    }
    else if (CheckHitKey(KEY_INPUT_DOWN))
    {
        if (!end_serect)
        {
            end_serect = true;
            serect_y += MASU_DISTANCE * 2;
        }
    }
    else
    {
        end_serect = false;
    }
}

void Result::srect_next(int& number)
{
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        if (serect_y == 300)
        {
            number = 1;
        }
        else if (serect_y == 332)
        {
            number = 2;
        }
        else if (serect_y == 364)
        {
            number = 3;
        }
    }
}

void Result::serect_box_in()
{
    if (serect_y < 300)
    {
        serect_y = 300;
    }
    if (serect_y > 364)
    {
        serect_y = 364;
    }
}

void Result::Draw_serect()
{ 
	
    DrawBox((int)serect_x, (int)serect_y, (int)serect_x + 200, (int)serect_y + MASU_DISTANCE, GetColor(255, 255, 0), FALSE);

    DrawString(100, 300, "もう一回", GetColor(255, 255, 255));
    DrawString(100, 332, "メニューに戻る", GetColor(255, 255, 255));
    DrawString(100, 364, "場面を見る", GetColor(255, 255, 255));

    DrawString(100, 396, "Aで選択", GetColor(255, 255, 255));

    DrawGraph(0, 0, result_back, TRUE);
}

void Result::Draw_Titl()
{
    
    // CPUの場合
    if (cpu_win)
    {
        DrawGraph((int)result_x, (int)result_y, image_cpu_win, TRUE);
    }
    else if (cpu_lose)
    {
        DrawGraph((int)result_x, (int)result_y, image_cpu_lose, TRUE);
    }
    else if (cpu_drow)
    {
        DrawGraph((int)result_x, (int)result_y, image_cpu_drow, TRUE);
    }

    // オフラインの場合
    if (maru_win)
    {
        DrawGraph((int)result_x, (int)result_y, image_maru_win, TRUE);
    }
    else if (maru_lose)
    {
        DrawGraph((int)result_x, (int)result_y, image_maru_lose, TRUE);
    }
    else if (maru_drow)
    {
        DrawGraph((int)result_x, (int)result_y, image_maru_drow, TRUE);
    }
}