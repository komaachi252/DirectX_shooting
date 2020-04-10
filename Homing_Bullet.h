/**
* @file Homing_Bullet.h
* @brief í«îˆíeÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/

#pragma once
#ifndef HOMING_BULLET_H_
#define HOMING_BULLET_H_

#include "Enemy_Bullet.h"


class Homing_Bullet : public Enemy_Bullet
{
public:

private:
	static constexpr const int BULLET_FRAME_MAX = 2;
	static constexpr const int BULLET_FRAME_DIVIDE = 12;
	static constexpr const float HOMING_INTERVAL = 128.0f;
	enum Mode {
		GET_ANGLE,
		STRAIGHT
	};
	Mode m_mode;
	int m_angle;
	int m_frame;
public:
	Homing_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos,
		float move_speed, After_Move after);
	Homing_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after);
	~Homing_Bullet(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
	void Move(std::list<std::shared_ptr<Game_Object>>& objects);
};

#endif
