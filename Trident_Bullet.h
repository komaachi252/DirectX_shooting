/**
* @file Trident_Bullet.h
* @brief ‚R•ûŒü’eƒwƒbƒ_
* @author –îˆêr
* @date 2020/03/18
*/

#pragma once
#ifndef TRIDENT_BULLET_H_
#define TRIDENT_BULLET_H_

#include "Bullet.h"


class Trident_Bullet : public Bullet
{
private:
	float m_angle;
	int m_elapsed_frame;
	int m_frame;
public:
	Trident_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos,
		float move_speed, After_Move after, float angle, int frame);
	Trident_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after, float angle, int frame);
	~Trident_Bullet(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
};

#endif