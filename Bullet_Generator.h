/**
* @file Bullet_Generator.h
* @brief íeê∂ê¨ÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/
#pragma once
#ifndef BULLET_GENERATOR_H_
#define BULLET_GENERATOR_H_
#include <memory>
#include <list>
#include <d3dx9.h>
#include "Game_Object.h"
/**
* @class Bullet_Generator
* @brief íeê∂ê¨ÉNÉâÉX
* @details
*/
class Bullet_Generator
{
public:
	static constexpr const char* FILE_NAME = "bullet1.png";
	static constexpr const int TEX_WIDTH = 64;
	static constexpr const int TEX_HEIGHT = 64;
	static constexpr const int DRAW_WIDTH = 25;
	static constexpr const int DRAW_HEIGHT = 25;
	static constexpr const float MOVE_SPEED = 15.0f;
public:
	Bullet_Generator(void);
	virtual void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif
