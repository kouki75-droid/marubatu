#pragma once

class Mode
{
public:
    // 1: タイトル  2: ゲーム中  3: セレクト  
    int game_mode = 1;
    int a = 0;
    int num;

    void riset();
   
    

private:
    int wait; // ← 追加
};