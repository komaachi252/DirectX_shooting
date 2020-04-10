/**
* @file Game_Manager.h
* @brief �Q�[���Ǘ��w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef FADE_H_
#define FADE_H_
#include <d3d9.h>
#include <d3dx9.h>
#include "singleton.h"


/**
* @class
* @brief �ȒP�ȃN���X�̐���
* @details �ڍׂȃN���X�̐���
*/
class Fade_Manager
{
private:
	struct Fade_Vertex {
		D3DXVECTOR4 position;
		D3DCOLOR color;
	};
	bool m_is_fade_out;
	bool m_is_fade;
	int m_fade_frame;
	int m_fade_frame_count;
	int m_fade_start_frame;
	D3DCOLOR m_fade_color;
public:
	Fade_Manager(void);
	void Update(void);
	void Draw(void);
	void Start(int frame, D3DCOLOR color, bool fade_out);
	bool Is_Fade(void);
};

#endif
