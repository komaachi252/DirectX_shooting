/**
* @file Homing_Bullet_Generator.h
* @brief ’Ç”ö’e¶¬ƒwƒbƒ_
* @author –îˆêr
* @date 2020/03/18
*/
#pragma once
#ifndef HOMING_BULLET_GENERATOR_H_
#define HOMING_BULLET_GENERATOR_H_
#include "Bullet_Generator.h"

/**
* @class Homing_Bullet_Generator
* @brief ’Ç”ö’e¶¬ƒNƒ‰ƒX
* @details
*/
class Homing_Bullet_Generator : public Bullet_Generator
{
public:
	static constexpr const char* FILE_NAME = "bullet4.png";
	static constexpr const int TEX_WIDTH = 64;
	static constexpr const int TEX_HEIGHT = 32;
	static constexpr const int DRAW_WIDTH = 32;
	static constexpr const int DRAW_HEIGHT = 32;
	static constexpr const float MOVE_SPEED = 6.0f;

public:
	Homing_Bullet_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif
