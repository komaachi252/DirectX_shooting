/**
* @file Collision_Manager.h
* @brief 当たり判定管理ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/
#pragma once
#ifndef COLLISION_MANAGER_H_
#define COLLISION_MANAGER_H_
#include "Game_Object.h"

/**
* @class Collision_Manager
* @brief 当たり判定管理クラス
* @details
*/
class Collision_Manager
{
public:
public:
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
};

#endif