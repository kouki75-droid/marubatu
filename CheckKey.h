#pragma once

/// <summary>
/// キーリーダークラス
/// </summary>
class CheckKey
{
private:
    /// <summary>
    /// キーの状態配列
    /// </summary>
    char key_state_arr[256];

public:
    /// <summary>  
    /// キー読み込み（一括）  
    /// </summary>  
    void Read();

    /// <summary>
    /// 指定されたキーが押されているか確認
    /// </summary>
    bool Check_key(int arg_key_code);
};