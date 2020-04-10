/**
* @file Urchin_Enemy.h
* @brief ウニヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef URCHIN_ENEMY_H_
#define URCHIN_ENEMY_H_
#include "Anim_Space_Ship.h"
#include "Enemy_Bullet_Generator.h"

/**
* @class Urchin_Enemy
* @brief ウニクラス
* @details
*/
class Urchin_Enemy : public Anim_Space_Ship
{
public:
	enum Mode 
	{
		STRAIGHT,
		TURN_UP,
		TURN_DOWN,
		BACK
	};
	static constexpr const char* FILE_NAME = "urchins.png";
	static constexpr const int TEX_WIDTH = 256;
	static constexpr const int TEX_HEIGHT = 256;
	static constexpr const int DRAW_WIDTH = 128;
	static constexpr const int DRAW_HEIGHT = 128;
	static constexpr const float MOVE_SPEED = 6.0f;
	static constexpr const int FRAME_DIVIDE = 4;
	static constexpr const int WIDTH_NUM = 2;
	static constexpr const int HEIGHT_NUM = 2;
private:
	static constexpr const float TURN_ANGLE = 120.0f;
	static constexpr const float TURN_DISTANCE = 128.0f;
	Mode m_mode;
	bool m_is_shot;
	int m_elapsed_frame;
	float m_old_y;
	std::unique_ptr<Enemy_Bullet_Generator> m_bullet;
public:
	Urchin_Enemy(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos, float move_speed, int width_num, int height_num, int frame_divide);
	~Urchin_Enemy(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
};


#endif
