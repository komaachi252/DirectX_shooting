/**
* @file Collision_Manager.h
* @brief �����蔻��Ǘ��w�b�_
* @author ���r
* @date 2020/03/18
*/
#pragma once
#ifndef COLLISION_MANAGER_H_
#define COLLISION_MANAGER_H_
#include "Game_Object.h"

/**
* @class Collision_Manager
* @brief �����蔻��Ǘ��N���X
* @details
*/
class Collision_Manager
{
public:
public:
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
};

#endif