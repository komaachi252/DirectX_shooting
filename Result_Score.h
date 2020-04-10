/**
* @file Result_Score.h
* @brief リザルトスコアヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef RESULT_SCORE_H_
#define RESULT_SCORE_H_
#include "Polygon2D.h"
#include "App.h"
#include <array>

/**
* @class Result_Score
* @brief リザルトスコアクラス
* @details
*/
class Result_Score : public Polygon2D
{
public:
	static constexpr const float POS_X = 720.0f;
	static constexpr const float POS_Y = App::SCREEN_HEIGHT * 0.3f;
	static constexpr const float RANK_X = 280.0f;
	static constexpr const float SCORE_DISTANCE_Y = 80.0f;
	static constexpr const float SCORE_DIS_Y = 80.0f;
	static constexpr const int NEW_WIDTH = 222;//222
	static constexpr const int NEW_HEIGHT = 30;
	static constexpr const int HI_WIDTH = 78;
	static constexpr const int HI_HEIGHT = 168;
	static constexpr const int P_WIDTH = 142;
	static constexpr const int P_HEIGHT = 30;
	static constexpr const int HIGH_HEIGHT = 42;
	static constexpr const int SCORE_MAX = 4;
	static constexpr const float P_X = App::SCREEN_WIDTH * 0.7f - 128.0f;
	static constexpr const float NEW_X = App::SCREEN_WIDTH * 0.8f;
	static constexpr const float NEW_Y = App::SCREEN_HEIGHT * 0.9f;
	static constexpr const char* NEW_RECORD_FILE_NAME = "newrecord.png";
	static constexpr const char* HIGHSCORE_FILE_NAME = "highscore.png";
	static constexpr const char* PLAYER_FILE_NAME = "playericon.png";

	struct Result_Data
	{
		D3DXVECTOR2 m_pos;
		int m_score;
		bool m_is_current;
	};
private:
	std::array<std::unique_ptr<Result_Data>, SCORE_MAX> m_data;
	int m_hiscore_tex_id;
	int m_player_icon_tex_id;
public:
	Result_Score(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos);
	~Result_Score(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
};

#endif