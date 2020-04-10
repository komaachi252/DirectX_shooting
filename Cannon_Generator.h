/**
* @file Enemy_Bullet_Generator.h
* @brief “G’e¶¬ƒwƒbƒ_
* @author –îˆêr
* @date 2020/03/18
*/
#pragma once
#ifndef CANNON_GENERATOR_H_
#define CANNON_GENERATOR_H_
#include "Bullet_Generator.h"

/**
* @class Enemy_Bullet_Generator
* @brief “G’e¶¬ƒNƒ‰ƒX
* @details
*/
class Cannon_Generator : public Bullet_Generator
{
public:
	static constexpr const char* FILE_NAME = "cannon.png";
	static constexpr const int TEX_WIDTH = 256;
	static constexpr const int TEX_HEIGHT = 256;
	static constexpr const int DRAW_WIDTH = 153;
	static constexpr const int DRAW_HEIGHT = 153;
	static constexpr const float MOVE_SPEED = 7.0f;
public:
	Cannon_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif