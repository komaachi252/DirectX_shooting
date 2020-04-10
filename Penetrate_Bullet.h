/**
* @file Penetrate_Bullet.h
* @brief ä—í íeÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/

#pragma once
#ifndef PENETRATE_BULLET_H_
#define PENETRATE_BULLET_H_

#include "Bullet.h"


class Penetrate_Bullet : public Bullet
{

public:
	Penetrate_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos,
		float move_speed, After_Move after);
	Penetrate_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after);
	~Penetrate_Bullet(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Move(void);
};

#endif