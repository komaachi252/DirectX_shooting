/**
* @file Trident_Bullet_Generator.h
* @brief 3ï˚å¸íeê∂ê¨ÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/
#pragma once
#ifndef TRIDENT_BULLET_GENERATOR_H_
#define RIDENT_BULLET_GENERATOR_H_
#include "Bullet_Generator.h"

/**
* @class Trident_Bullet_Generator
* @brief íeê∂ê¨ÉNÉâÉX
* @details
*/
class Trident_Bullet_Generator : public Bullet_Generator
{
public:
	static constexpr const char* FILE_NAME = "bullet1.png";
	static constexpr const int TEX_WIDTH = 64;
	static constexpr const int TEX_HEIGHT = 64;
	static constexpr const int DRAW_WIDTH = 25;
	static constexpr const int DRAW_HEIGHT = 25;
	static constexpr const float SIDE_ANGLE = 120.0f;
	static constexpr const int SIDE_LIFE_FRAME = 10;
	static constexpr const float MOVE_SPEED = 15.0f;
public:
	Trident_Bullet_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif