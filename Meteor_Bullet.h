/**
* @file Meteor_Bullet.h
* @brief Ë¶êŒÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/

#pragma once
#ifndef METEOR_BULLET_H_
#define METEOR_BULLET_H_

#include "Bullet.h"
#include "Effect_Generator.h"


class Meteor_Bullet : public Bullet
{
public:
	static constexpr const float ANGLE = 120 * D3DX_PI / 180;
	static constexpr const float EFFECT_DISTANCE_X = 10.0f;
	static constexpr const float EFFECT_DISTANCE_Y = 10.0f;
private:
	std::unique_ptr<Effect_Generator>m_effect;
public:
	Meteor_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos,
		float move_speed, After_Move after);
	Meteor_Bullet(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after);
	~Meteor_Bullet(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Move(void);
};

#endif
