/**
* @file Ground_Generator.h
* @brief �n�ʐ����w�b�_
* @author ���r
* @date 2020/03/18
*/
#pragma once
#ifndef GROUND_GENERATOR_H_
#define GROUND_GENERATOR_H_

#include "Game_Object.h"
#include "App.h"
#include <d3dx9.h>
#include "ground.h"

/**
* @class Ground_Generator
* @brief �n�ʐ����N���X
* @details
*/
class Ground_Generator
{
public:
	static constexpr const char* FILE_NAME = "ground2.png";
	static constexpr const int TEX_WIDTH = 2048;
	static constexpr const int TEX_HEIGHT = 35;
	static constexpr const int DRAW_WIDTH = 1024;
	static constexpr const int DRAW_HEIGHT = 35;
	static constexpr const float START_X = 2816.0f;
	static constexpr const float START_Y = 702.5f;
public:
	Ground_Generator(void) {}
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects);
};

#endif