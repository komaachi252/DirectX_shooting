/**
* @file Math_Manager.h
* @brief 計算用ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef MATH_MANAGER_H_
#define MATH_MANAGER_H_

/**
* @class Math_Manager
* @brief 計算用クラス
*/
class Math_Manager
{
private:
	float m_sin[360];
	float m_cos[360];
public:
	Math_Manager(void);
	int Get_Angle(float from_x, float from_y, float to_x, float to_y);
	float Get_Sin(int angle);
	float Get_Cos(int angle);
};

#endif //! MATH_MANAGER_H_
