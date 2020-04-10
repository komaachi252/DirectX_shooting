/**
* @file Ace_Boss_Enemy.h
* @brief エースボスヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef ACE_BOSS_ENEMY_H_
#define ACE_BOSS_ENEMY_H_
#include "Space_Ship.h"
#include "App.h"
#include "Enemy_Bullet_Generator.h"
#include "Explosion_Generator.h"

/**
* @class Ace_Boss_Enemy
* @brief エースボスクラス
* @details
*/
class Ace_Boss_Enemy : public Space_Ship
{
public:
	enum Mode {
		NONE,
		DEPARTURE,
		TRANSLATE,
		TURN_UP,
		TURN_DOWN,
		RAYS_GENERATE,
		ATTACK,
		BREAK,
	};
	static constexpr const char* FILE_NAME = "ace.png";
	static constexpr const int TEX_WIDTH = 256;
	static constexpr const int TEX_HEIGHT = 128;
	static constexpr const int DRAW_WIDTH = 192;
	static constexpr const int DRAW_HEIGHT = 96;
	static constexpr const float ACE_SCALE = 0.75f;
	static constexpr const float MOVE_SPEED = 8.0f;
	static constexpr const float DOWN_SPEED = 2.0f;
	static constexpr const int DOWN_ANGLE = 120;
	static constexpr const int BOMB_FRAME = 30;
	static constexpr const float START_POS_X = App::SCREEN_WIDTH * 0.25f;
	static constexpr const float START_POS_Y = -DRAW_HEIGHT;
	static constexpr const float END_POS_X = 900.0f;
	static constexpr const float END_POS_Y = App::SCREEN_HEIGHT * 0.5f;
	static constexpr const float ENEMY_DISTANCE = 150.0f;
	static constexpr const int CREATE_FRAME = 30;
	static constexpr const int TRANS_FRAME = 150;
	static constexpr const float MUZZLE_DISTANCE = -80.0f;
	static constexpr const float DISTANCE_ENGINE_X = -82.0f;
	static constexpr const float DISTANCE_ENGINE_Y = 5.0f;
	static constexpr const int RAYS_GENERATE_MAX = 8;
	static constexpr const int TRANS_MAX = 5;
	static constexpr const Mode MODE_TABLE[TRANS_MAX] = { RAYS_GENERATE, ATTACK, RAYS_GENERATE, ATTACK, RAYS_GENERATE };
	static constexpr const float GENERATE_POS_Y[RAYS_GENERATE_MAX] = { 150.0f, 360.0f, 580.0f, 460.0f, 140.0f, 360.0f, 440.0f, 150.0f };
	static constexpr const int BOSS_HP = 60;
private:
	int m_hp;
	int m_angle;
	float m_enemy_y;
	int m_elapsed_frame;
	Mode m_mode;
	int m_trans_item;
	int m_generate_cnt;
	bool m_is_generate;
	std::unique_ptr<Enemy_Bullet_Generator> m_bullet;
	std::unique_ptr<Explosion_Generator> m_explosion;
public:
	Ace_Boss_Enemy(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos, float move_speed);
	~Ace_Boss_Enemy(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Departure(void);
	void Translate(void);
	void Rays_Generate(std::list<std::shared_ptr<Game_Object>>& objects);
	void Turn_Up(void);
	void Turn_Down(void);
	void Attack(std::list<std::shared_ptr<Game_Object>>& objects);
	void Break(std::list<std::shared_ptr<Game_Object>>& objects);
	void Turn_Check(std::list<std::shared_ptr<Game_Object>>& objects);
};



#endif
