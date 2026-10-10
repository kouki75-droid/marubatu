#include "Titl.h"
#include "DxLib.h"

void Titl::Input()
{
    
    if (op_image == -1)
    {
        op_image =LoadGraph("data/op.png");
    }
    move_serect();
    serect();
}
void Titl::serect()
{
    if (serect_number == 1)
    {
        serect_x = 570;
        serect_y = 210;
    }
    else if (serect_number == 2)
    {
        serect_x = 570;
        serect_y = 240;
    }
    else if (serect_number == 3)
    {
        serect_x = 570;
        serect_y = 320;
    }
    else if (serect_number == 4)
    {
        serect_x = 570;
        serect_y = 350;
    }
    else if (serect_number == 5)
    {
        serect_x = 530;
        serect_y = 390;
    }
}

void Titl::move_serect()
{

    if (CheckHitKey(KEY_INPUT_UP))
    {
        if (serect_move == true)
        {
            serect_number--;
            serect_move = false;
        }
    }
    else if (CheckHitKey(KEY_INPUT_DOWN))
    {
        if (serect_move == true)
        {
            serect_number++;
            serect_move = false;
        }
    }
    else
    {
        serect_move = true;
    }


    // ”š‚ª’´‚¦‚½‚ç’´‚¦‚È‚¢‚æ‚¤‚É‚·‚é
    if (serect_number > 5)
    {
        serect_number = 5;
    }
    if (serect_number < 1)
    {
        serect_number = 1;
    }
}

void Titl::Draw_titl()
{
	
    //DrawBox(op_x, op_y, title_x, title_y, GetColor(255, 255, 255), TRUE); // ”’‚¢lŠpŒ`‚ğ•`‰æ  
    DrawString(580, 100, "Z", GetColor(255, 0, 0));                      // •¶š—ñ‚ğ•`‰æ  
    DrawString(595, 100, "~", GetColor(0, 0, 255));                     // •¶š—ñ‚ğ•`‰æ  
    DrawString(610, 100, "ƒQ[ƒ€", GetColor(0, 0, 0));                   // •¶š—ñ‚ğ•`‰æ  
    DrawString(530, 180, "CPU‚Ì‹­‚³", GetColor(0, 0, 0));                // •¶š—ñ‚ğ•`‰æ  
    DrawString(550, 210, "< ƒm[ƒ}ƒ‹", GetColor(0, 0, 0));               // •¶š—ñ‚ğ•`‰æ  
    DrawString(550, 240, "< ƒn[ƒh", GetColor(0, 0, 0));                 // •¶š—ñ‚ğ•`‰æ  
    DrawString(530, 290, "CPU‘Îí", GetColor(0, 0, 0));                  // •¶š—ñ‚ğ•`‰æ  
    DrawString(550, 320, "< æs", GetColor(0, 0, 0));                   // •¶š—ñ‚ğ•`‰æ  
    DrawString(550, 350, "< ŒãU", GetColor(0, 0, 0));                   // •¶š—ñ‚ğ•`‰æ  
    DrawString(530, 390, "ƒIƒtƒ‰ƒCƒ“‘Îí", GetColor(0, 0, 0));           // •¶š—ñ‚ğ•`‰æ  

    DrawString(500, 480, "ƒXƒy[ƒX‰Ÿ‚µ‚ÄŠJnI", GetColor(0, 0, 0));           // •¶š—ñ‚ğ•`‰æ 
    DrawString(510, 510, "ƒIƒtƒ‰ƒCƒ“‘Îí‚Ì‚İÀ‘•", GetColor(0, 0, 0));           // •¶š—ñ‚ğ•`‰æ 

    DrawBox(serect_x, serect_y, serect_x + 120, serect_y + 20, GetColor(0, 150, 0), FALSE);
    DrawGraph(op_x, op_y, op_image, TRUE); // ‰æ‘œ‚ğ•`‰æ
}