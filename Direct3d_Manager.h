/**
* @file Direct3d_Manager.h
* @brief �`��f�o�C�X�w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef DIRECT3D_H_
#define DIRECT3D_H_
#include <d3d9.h>

/**
* @class Direct3d_Manager
* @brief �`��f�o�C�X�N���X
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
