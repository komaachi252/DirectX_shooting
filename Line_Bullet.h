/**
* @file Line_Bullet.h
* @brief ìGíeÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/

#pragma once
#ifndef LINE_BULLET_H_
#define LINE_BULLET_H_

#include "Enemy_Bullet.h"


class Line_Bullet : public Enemy_Bullet
{
public:

	enum Line_Mode {
		UP,
		DOWN
	};
private:
	Line_Mode m_mode;
public:
	Line_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos,
		float move_speed, After_Move after, Line_Mode mode);
	Line_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after, Line_Mode mode);
	~Line_Bullet(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Move(void);
};

#endif
