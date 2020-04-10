/**
* @file Boss_Bullet.h
* @brief É{ÉXíeÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/

#pragma once
#ifndef BOSS_BULLET_H_
#define BOSS_BULLET_H_

#include "Enemy_Bullet.h"


class Boss_Bullet : public Enemy_Bullet
{
private:
	static constexpr const int SET_ANGLE[] = { 140,150,180,160,180,170,150, };
	static constexpr const int SET_ANGLE_MAX = sizeof(SET_ANGLE) / sizeof(SET_ANGLE[0]);
	int m_angle;
public:
	static int m_generate_cnt;
public:
	Boss_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos,
		float move_speed, After_Move after);
	Boss_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after);
	~Boss_Bullet(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Move(void);
};
#endif
