#pragma once

class Titl
{
private:
    int op_x = 0;
    int op_y = 0;
    int title_x = 1280;
    int title_y = 720;

    // ‚Í‚·‚¢
    int serect_x = 530;
    int serect_y = 390;
    int serect_number = 5;
    bool serect_move = true;

public:

    // ‘I‘ð‚ð•\Ž¦
    void serect();
    // ‘I‘ð‚ÌˆÚ“®
    void move_serect();

    // •`‰æ  
    void Draw_titl();
};