/**
* @file Xinput_Manager.h
* @brief 入力デバイスヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef XINPUT_H_
#define XINPUT_H_
#include <d3d9.h>
#include <XInput.h>
#include <map>

/**
* @class Xinput_Manager
* @brief テクスチャ管理クラス
*/
//#define XINPUT_GAMEPAD_L2 (0x0001)
//#define XINPUT_GAMEPAD_R2 (0x0008)

class Xinput_Manager
{
public:
	static constexpr const WORD XINPUT_GAMEPAD_L2 = 0x0001;
	static constexpr const WORD XINPUT_GAMEPAD_R2 = 0x0008;
private:
	static constexpr const DWORD XINPUT_MAX_CONTROLLERS = 4;
	enum INPUT_STATE {
		NONE,
		PUSH,
		ENTER,
		EXIT
	};
	struct Vibration {
		XINPUT_VIBRATION vib;
		int frame;
		bool is_used;
	};
	static constexpr const WORD KEY_INFO[] = {
		XINPUT_GAMEPAD_A,
		XINPUT_GAMEPAD_B,
		XINPUT_GAMEPAD_X,
		XINPUT_GAMEPAD_Y,
		XINPUT_GAMEPAD_START,
		XINPUT_GAMEPAD_BACK,
		XINPUT_GAMEPAD_LEFT_THUMB,
		XINPUT_GAMEPAD_RIGHT_THUMB,
		XINPUT_GAMEPAD_LEFT_SHOULDER,
		XINPUT_GAMEPAD_RIGHT_SHOULDER,
		XINPUT_GAMEPAD_L2,
		XINPUT_GAMEPAD_R2
	};
	static constexpr const int KEY_MAX = sizeof(KEY_INFO) / sizeof(KEY_INFO[0]);

	std::map<int, WORD> m_map_key;
	std::map<WORD, INPUT_STATE> m_key_state;
	XINPUT_STATE m_state;
	Vibration m_vibration;
public:
	bool Init(HWND hWnd);	//初期化関数
	void Update(void);	//更新処理
	bool Is_Press(int key);
	bool Is_Trigger(int key);
	bool Is_Exit(int key);
	float Is_Axis_LX(void);
	float Is_Axis_RX(void);
	float Is_Axis_LY(void);
	float Is_Axis_RY(void);
	void Vibration(int frame, WORD left_speed, WORD right_speed);
};

#endif
