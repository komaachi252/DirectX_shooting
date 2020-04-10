/**
* @file Circle_Collision.h
* @brief �~�Փ˃w�b�_
* @author ���r
* @date 2020/03/18
*/
#pragma once
#ifndef CIRCLE_COLLISION_H_
#define CIRCLE_COLLISION_H_
#include <d3dx9.h>

/**
* @class Circle_Collsion
* @brief �~�Փ˃N���X
* @details �I�u�W�F�N�g�̓����蔻��p
*/
class Circle_Collsion
{
private:
	//!  ���S���W
	D3DXVECTOR2 m_pos;
	//!  ���a
	float m_radius;
public:
	Circle_Collsion(const D3DXVECTOR2& pos, float radius);
	void Update(const D3DXVECTOR2& pos);
	bool Is_Collision(const Circle_Collsion& another);
	const D3DXVECTOR2& Get_Position(void) const;
	float Get_Radius(void) const;
	void Set_Radius(float radius);
};


#endif