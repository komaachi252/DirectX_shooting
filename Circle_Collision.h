/**
* @file Circle_Collision.h
* @brief 円衝突ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/
#pragma once
#ifndef CIRCLE_COLLISION_H_
#define CIRCLE_COLLISION_H_
#include <d3dx9.h>

/**
* @class Circle_Collsion
* @brief 円衝突クラス
* @details オブジェクトの当たり判定用
*/
class Circle_Collsion
{
private:
	//!  中心座標
	D3DXVECTOR2 m_pos;
	//!  半径
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