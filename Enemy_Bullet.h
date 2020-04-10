/**
* @file Enemy_Bullet.h
* @brief “G’eƒwƒbƒ_
* @author –îˆêr
* @date 2020/03/18
*/

#pragma once
#ifndef ENEMY_BULLET_H_
#define ENEMY_BULLET_H_

#include "Bullet.h"


class Enemy_Bullet : public Bullet
{
public:

protected:
	bool m_is_turn_over;

public:
	Enemy_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos,
		float move_speed, After_Move after);
	Enemy_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after);
	~Enemy_Bullet(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
};

#endif
