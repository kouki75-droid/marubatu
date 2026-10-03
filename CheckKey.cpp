#include "CheckKey.h"
#include "DxLib.h"

void CheckKey::Read()
{
    GetHitKeyStateAll(this->key_state_arr);
}

bool CheckKey::Check_key(int arg_key_code)
{
    // 指定されたキーの状態をチェック  
    if (this->key_state_arr[arg_key_code] == 1)
    {
        // 押されていればtrueを返す  
        return true;
    }
    // 押されていなければfalseを返す  
    return false;
}