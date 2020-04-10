/**
* @file Oct_Boss_Enemy.h
* @brief タコボスヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef OCT_BOSS_ENEMY_H_
#define OCT_BOSS_ENEMY_H_
#include "Space_Ship.h"
#include "App.h"
#include "Enemy_Bullet.h"
#include "Cannon_Generator.h"
/**
* @class Oct_Boss_Enemy
* @brief タコボスクラス
* @details
*/
class Oct_Boss_Enemy : public Space_Ship
{
public:
	static constexpr const char* FILE_NAME = "oct.png";
	static constexpr const int TEX_WIDTH = 512;
	static constexpr const int TEX_HEIGHT = 512;
	static constexpr const int DRAW_WIDTH = 512;
	static constexpr const int DRAW_HEIGHT = 512;
	static constexpr const float MOVE_SPEED = 5.0f;
	static constexpr const float START_POS_X = App::SCREEN_WIDTH * 0.5f;
	static constexpr const float START_POS_Y = -DRAW_HEIGHT;
	static constexpr const float BOSS_RADIUS = 230.0f;
	static constexpr const float BOSS_COLLISION_X = 80.0f;
	static constexpr const float BOSS_TO_HEAD_POS_X = 80.0f;
	static constexpr const float BOSS_TO_HEAD_POS_Y = -230.0f;
	static constexpr const float BOSS_END_POS_X = App::SCREEN_WIDTH * 0.7f;
	static constexpr const float BOSS_END_POS_Y = App::SCREEN_HEIGHT * 0.5f;
	static constexpr const float BOSS_UP_LIMIT = 100.0f;
	static constexpr const float BOSS_DOWN_LIMIT = App::SCREEN_HEIGHT + 28.0f;
	static constexpr const int BOSS_WAIT_FRAME = 200;
	static constexpr const int BOSS_BULLET_WAIT_FRAME = 30;
	static constexpr const float CANNON_MUZZLE_DISTANCE_X = -190.0f;
	static constexpr const float CANNON_MUZZLE_DISTANCE_Y = 0.0f;
	static constexpr const float MUZZLE_WIDTH = 120.0f;
	static constexpr const float MUZZLE_HEIGHT = 120.0f;
	static constexpr const float MUZZLE_POS_X = -150.0f;
	static constexpr const float MUZZLE_POS_Y = 0.0f;
	static constexpr const int BOMB_FRAME = 20;
	static constexpr const float DOWN_SPEED = 1.8f;
	static constexpr const float EXPLOSION_DISTANCE_X1 = -50.0f;
	static constexpr const float EXPLOSION_DISTANCE_X2 = 120.0f;
	static constexpr const float EXPLOSION_DISTANCE_X3 = 70.0f;
	static constexpr const float EXPLOSION_DISTANCE_X4 = 200.0f;
	static constexpr const float EXPLOSION_DISTANCE_X5 = -50.0f;
	static constexpr const float EXPLOSION_DISTANCE_Y1 = 10.0f;
	static constexpr const float EXPLOSION_DISTANCE_Y2 = -40.0f;
	static constexpr const float EXPLOSION_DISTANCE_Y3 = 200.0f;
	static constexpr const float EXPLOSION_DISTANCE_Y4 = 100.0f;
	static constexpr const float EXPLOSION_DISTANCE_Y5 = -200.0f;
	static constexpr const int BOSS_HP = 60;
private:
	enum Mode {
		DEPARTURE,
		WAIT,
		MOVE_UP,
		MOVE_DOWN,
		BREAK
	};
	Mode m_mode;
	int m_hp;
	int m_elapsed_frame;
	int m_angle;
	std::unique_ptr<Cannon_Generator> m_bullet;

	void Departure(void);
	void Wait(std::list<std::shared_ptr<Game_Object>>& objects);
	void Move_Up(std::list<std::shared_ptr<Game_Object>>& objects);
	void Move_Down(std::list<std::shared_ptr<Game_Object>>& objects);
	void Break(std::list<std::shared_ptr<Game_Object>>& objects);
	void Shot(std::list<std::shared_ptr<Game_Object>>& objects);
	void Explosion(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
public:
	Oct_Boss_Enemy(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos, float move_speed);
	~Oct_Boss_Enemy(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Sub_HP(Item::Item_Type type);
};



#endif
