/**
* @file Explosion_Generator.h
* @brief 爆発生成ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/
#pragma once
#ifndef EXPLOSION_GENERATOR_H_
#define EXPLOSION_GENERATOR_H_

#include "Game_Object.h"
#include <d3dx9.h>

/**
* @class Explosion_Generator
* @brief 爆発生成クラス
* @details
*/
class Explosion_Generator
{
public:
	static constexpr const char* FILE_NAME = "bomb.png";
	static constexpr const int TEX_WIDTH = 512;
	static constexpr const int TEX_HEIGHT = 512;
	static constexpr const int DRAW_WIDTH = 128;
	static constexpr const int DRAW_HEIGHT = 128;
	static constexpr const int FRAME_DIVIDE = 4;
	static constexpr const int WIDTH_NUM = 4;
	static constexpr const int HEIGHT_NUM = 4;
public:
	Explosion_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif
