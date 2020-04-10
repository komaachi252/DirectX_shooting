/**
* @file Squid_Enemy.h
* @brief ウニヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef SQUID_ENEMY_H_
#define SQUID_ENEMY_H_
#include "Anim_Space_Ship.h"
#include "Line_Bullet_Generator.h"

/**
* @class Squid_Enemy
* @brief イカクラス
* @details
*/
class Squid_Enemy : public Anim_Space_Ship
{
public:
	static constexpr const char* FILE_NAME = "squids.png";
	static constexpr const int TEX_WIDTH = 256;
	static constexpr const int TEX_HEIGHT = 256;
	static constexpr const int DRAW_WIDTH = 128;
	static constexpr const int DRAW_HEIGHT = 128;
	static constexpr const float MOVE_SPEED = 7.0f;
	static constexpr const float PLAYER_SHOT_DISTANCE = 32.0f;
	static constexpr const int FRAME_DIVIDE = 4;
	static constexpr const int WIDTH_NUM = 2;
	static constexpr const int HEIGHT_NUM = 2;
private:
	static constexpr const float CURVE_AMPLITUDE = 8.0f;
	//!  振幅の制御値
	static constexpr const float CURVE_RESISTER = 0.1f;
	int m_elapsed_frame;
	bool m_is_shot;
	std::unique_ptr<Line_Bullet_Generator> m_bullet;
public:
	Squid_Enemy(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos, float move_speed, int width_num, int height_num, int frame_divide);
	~Squid_Enemy(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Move(void);
	void Shot(std::list<std::shared_ptr<Game_Object>>& objects);
};


#endif
