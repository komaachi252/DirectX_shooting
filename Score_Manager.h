/**
* @file Score_Manager.h
* @brief スコア管理ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef SCORE_MANAGER_H_
#define SCORE_MANAGER_H_
#include "Enemy_Generator.h"
/**
* @class Score_Manager
* @brief スコア管理クラス
*/
class Score_Manager
{
private:
	static constexpr const int URCHINS_SCORE = 50;
	static constexpr const int RAYS_SCORE = 100;
	static constexpr const int ANEMONES_SCORE = 100;
	static constexpr const int ACE_SCORE = 30000;
	static constexpr const int OCT_SCORE = 20000;
	static constexpr const int HEAD_SCORE = 5000;
	static constexpr const int NULL_SCORE = 200;
	static constexpr const float SCORE_X = 1200.0f;
	static constexpr const float SCORE_Y = 600.0f;
	static constexpr const int SCORE_DIGIT = 7;
	int m_score;
public:
	Score_Manager(void);
	~Score_Manager(void);
	void Draw(void);
	void Add(Enemy_Generator::Enemy_Type type);
	void Reset(void);
};

#endif //! SCORE_MANAGER_H_
