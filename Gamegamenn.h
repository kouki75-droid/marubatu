

#define GAME_W 5
#define GAME_H 5
#define PANEL_SIZE 100

class Gamegamenn
{
private:
    int MapData[GAME_H][GAME_W] =
    {
        { 0,0,0,0,0 },
        { 0,0,0,0,0 },
        { 0,0,0,0,0 },
        { 0,0,0,0,0 },
        { 0,0,0,0,0 },
    };

    // パネルの画像ハンドル
    int panel_image = -1;
    int panel_image_maru = -1;
    int panel_image_batu = -1;

    int panel_image_maruwin = -1;
    int panel_image_batuwin = -1;
    int panel_image_draw = -1;
    // スキルの画像ハンドル
    int panel_image_skill = -1;
	int panel_image_skill_on = -1;
	int panel_image_skill_off = -1;

    int _test = 0;

    // カーソルの位置
    int cursorX = 0;
    int cursorY = 0;
    int oldKeyLeft = 0;
    int oldKeyRight = 0;
    int oldKeyUp = 0;
    int oldKeyDown = 0;
    int oldKeySpace = 0;
	int oldKeyE = 0;
    
    // スキルの使用フラグ（各プレイヤー1回のみ）
    bool maru_skill_used = false; // trueなら使用済み
    bool batu_skill_used = false; // trueなら使用済み


    // 勝敗の状態を表す変数 (0=まだ勝負なし, 1=マルの勝ち, 2=バツの勝ち, 3=引き分け)
    int winner_state = 0;
    int WIN_COUNT = 4; // 何個揃ったら勝ちか

    // マルとバツの状態を表す列挙型
    enum marubatumode
    {
        maru = 1, // 0はマス未使用の意味で使うので1から
        batu = 2,
		skill = 3
    };
    int mode = maru;

    // カウント
  

public:
    int mode_count = 0;
    Gamegamenn() {}

    /// <summary>
    /// 画像素材の読み込み（初期化時に一度だけ呼ぶ）
    /// </summary>
    void Input();

    /// <summary>
    /// 状態のリセット
    /// </summary>
    void reset();

    /// <summary>
    /// フレーム毎の更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 勝敗判定処理
    /// </summary>
    bool CheckWin(int x, int y, int who);

	/// <summary>
	/// スキル判定処理
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="who"></param>
	void CheckSkill(int x, int y, int who);

    /// <summary>
    /// スキル使用状態UIの描画
    /// </summary>
    void Draw_SkillUI();

    /// <summary>
    /// 結果の出力
    /// </summary>
    void Result_out(int& num);

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

    /// <summary>
    /// サウンド処理
    /// </summary>
    void Sound();

};