/**
* @file Direct3d_Manager.h
* @brief 描画デバイスヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef DIRECT3D_H_
#define DIRECT3D_H_
#include <d3d9.h>

/**
* @class Direct3d_Manager
* @brief 描画デバイスクラス
*/
class Direct3d_Manager
{
private:
	LPDIRECT3DDEVICE9 m_device;
public:
	~Direct3d_Manager();
	bool Init(HWND hwnd);
	LPDIRECT3DDEVICE9 Get_Device(void);
};

#endif //! DIRECT3D_H_
