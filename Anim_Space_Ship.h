/**
* @file Anim_Space_Ship.h
* @brief �A�j���t���F���D�w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef ANIM_SPACE_SHIP_H_
#define ANIM_SPACE_SHIP_H_
#include <d3dx9.h>
#include "Space_Ship.h"

/**
* @class Anim_Space_Ship
* @brief �A�j���t���F���D�N���X
* @details �~�̓����蔻���ێ����Ă���
*/
class Anim_Space_Ship : public Space_Ship
{
protected:
	int m_frame;
	int m_width_num;
	int m_height_num;
	int m_frame_divide;
public:
	Anim_Space_Ship(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos, float move_speed, int width_num, int height_num, int frame_divide);
	Anim_Space_Ship(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos,
		float move_speed, int width_num, int height_num, int frame_divide);
	virtual ~Anim_Space_Ship(void);
	virtual void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
};

#endif
