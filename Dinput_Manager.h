/**
* @file Dinput_Manager.h
* @brief キーボード入力ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#ifndef DINPUT_H_
#define DINPUT_H_
#include <Windows.h>
// dinput.hをインクルードする前にこれを入れないと警告が出るので注意
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>

/**
* @class Dinput_Manager
* @brief 入力管理クラス
*/
class Dinput_Manager
{
private:
	static constexpr const int NUM_KEY_MAX = 256;
	LPDIRECTINPUT8			m_input;					// DirectInputオブジェクトへのポインタ
	LPDIRECTINPUTDEVICE8	m_dev_keyboard;				// 入力デバイス(キーボード)へのポインタ
	BYTE					m_key_state[NUM_KEY_MAX];			// キーボードの入力情報ワーク
	BYTE					m_key_state_trigger[NUM_KEY_MAX];	// キーボードのトリガー情報ワーク
	BYTE					m_key_state_release[NUM_KEY_MAX];	// キーボードのリリース情報ワーク
public:
	bool Init(HWND hwnd, HINSTANCE instance);
	bool Create_Input(HINSTANCE instance);
	~Dinput_Manager(void);
	void Update(void);
	bool Is_Press(int key);
	bool Is_Trigger(int key);
	bool Is_Release(int key);

};

/*------------------------------------------------------------------------------
   関数のプロトタイプ宣言
------------------------------------------------------------------------------*/

// キーボード入力モジュールの初期化
//
// 戻り値：初期化出来なかった場合false
//
// 引数：hinstance ... インスタンスハンドル（WinMainの引数などで取得）
//       hWnd      ... ウィンドウハンドル
//
bool Keyboard_Initialize(HINSTANCE hInstance, HWND hWnd);

// キーボードモジュールの終了処理
void Keyboard_Finalize(void);

// キーボードモジュールの更新
// ※キーボード全体のキー状態の取得
//
void Keyboard_Update(void);

// キーボードのキー状態の取得
//
// Keyboard_Update()で取得したキーの状態を確認する関数群
//
// 戻り値：指定のキーが
//     Press   ... 押されている
//     Trigger ... 押した瞬間
//     Release ... 離した瞬間
// であった場合trueを返す
//
// 引数：nKey ... キー指定（DIK_～というキー列挙）
//
bool Keyboard_IsPress(int nKey);
bool Keyboard_IsTrigger(int nKey);//押した瞬間
bool Keyboard_IsRelease(int nKey);//離した瞬間

#endif