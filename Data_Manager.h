/**
* @file Data_Manager.h
* @brief データ管理ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_

#include <memory>
#include <array>

/**
* @class Data_Manager
* @brief データ管理クラス
*/
class Data_Manager
{
public:
	enum Stage_Number 
	{
		STAGE_1,
		STAGE_2,
		STAGE_3
	};
	enum Stage_State 
	{
		TO_STAGE_1,
		TO_STAGE_2,
		TO_STAGE_MAX
	};
	struct Score_Data
	{
		int score;
		bool current_player;
	};

	static constexpr const int DATA_MAX = 6;
	static constexpr const int STAGE_DATA_MAX = 4;
private:
	std::array<std::unique_ptr<Score_Data>, DATA_MAX> m_data;
	std::array<std::unique_ptr<Score_Data>, STAGE_DATA_MAX> m_stage_data1;
	std::array<std::unique_ptr<Score_Data>, STAGE_DATA_MAX> m_stage_data2;
	Stage_Number m_stage_num;
	Stage_State m_state;
	Stage_State m_next;
public:
	Data_Manager(void);
	~Data_Manager(void);
	void Set_Stage_Number(Stage_Number num);
	Stage_Number Get_Stage_Number(void);
	void Set_Score(int score);
	int Get_Score(int i);
	int Get_Current_Player(void);
	void Set_Stage_State(Stage_State state);
	Stage_State Get_Stage_State(void);
	void Set_Stage_Next(Stage_State next);
	Stage_State Get_Stage_Next(void);
};

#endif //! DATA_MANAGER_H_
