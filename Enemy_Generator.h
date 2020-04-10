/**
* @file Enemy_Generator.h
* @brief 敵生成ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/
#pragma once
#ifndef ENEMY_GENERATOR_H_
#define ENEMY_GENERATOR_H_
#include <memory>
#include <list>
#include <d3dx9.h>
#include "Game_Object.h"
#include "Data_Manager.h"
#include "Ground_Generator.h"

/**
* @class Enemy_Generator
* @brief 敵生成クラス
* @details
*/
class Enemy_Generator : public Game_Object
{
public:
	enum Enemy_Type
	{
		ANEMONES,
		RAYS,
		URCHINS,
		SQUIDS,
		OCT,
		OCT_HEAD,
		ACE,
		TYPE_MAX
	};

	struct Enemy_Generate
	{
		float frame;
		float y;
		Enemy_Type type;
	};

	static constexpr const Enemy_Generate ENEMY_GENERATE[] = {
	{100,128.0f,URCHINS},
	{240,640.0f,URCHINS},
	{380,256.0f,URCHINS},
	{520,512.0f,URCHINS},
	{640,128.0f,RAYS},
	{700,640.0f,RAYS},
	{760,384.0f,RAYS},
	{780,256.0f,RAYS},
	{890,128.0f,URCHINS},
	{890,540.0f,URCHINS},
	{960,350.0f,RAYS},
	{1000,350.0f,RAYS},
	{1200,512.0f,URCHINS},
	{1320,256.0f,URCHINS},
	{1420,128.0f,URCHINS},
	{1520,512.0f,URCHINS},
	{1620,640.0f,URCHINS},
	{1800,128.0f,RAYS},
	{1801,256.0f,RAYS},
	{1820,512.0f,RAYS},
	{1821,384.0f,RAYS},
	{1840,640.0f,RAYS},
	{1841,512.0f,RAYS},
	{1860,384.0f,RAYS},
	{1861,640.0f,RAYS},
	{1880,128.0f,RAYS},
	{1900,256.0f,RAYS},
	{1980,0.0f,ANEMONES},
	{2020,128.0f,URCHINS},
	{2100,384.0f,URCHINS},
	{2130,384.0f,ANEMONES},
	{2160,128.0f,URCHINS},
	{2200,384.0f,URCHINS},
	{2220,384.0f,ANEMONES},
	{2230,128.0f,RAYS},
	{2231,256.0f,RAYS},
	{2300,512.0f,URCHINS},
	{2330,384.0f,RAYS},
	{2380,384.0f,ANEMONES},
	{2400,384.0f,ANEMONES},
	{2401,128.0f,RAYS},
	{2406,256.0f,RAYS},
	{2410,384.0f,RAYS},
	{2414,512.0f,RAYS},
	{2422,128.0f,RAYS},
	{2426,384.0f,RAYS},
	{2500,512.0f,ANEMONES},
	{2550,512.0f,ANEMONES},
	{2600,128.0f,URCHINS},
	{2640,384.0f,URCHINS},
	{2680,256.0f,RAYS},
	{2740,512.0f,ANEMONES},
	{2780,256.0f,URCHINS},
	{2800,512.0f,URCHINS},
	};
	static constexpr const Enemy_Generate ENEMY_GENERATE2[] = {
	{ 100,128.0f,URCHINS },
	{ 200,480.0f,SQUIDS },
	{ 300,512.0f,URCHINS },
	{ 420,180.0f,SQUIDS },
	{ 560,128.0f,ANEMONES },
	{ 600,640.0f,RAYS },
	{ 730,384.0f,SQUIDS },
	{ 780,256.0f,RAYS },
	{ 890,128.0f,ANEMONES },
	{ 910,384.0f,URCHINS },
	{ 960,480.0f,SQUIDS },
	{ 1000,128.0f,RAYS },
	{ 1200,512.0f,ANEMONES },
	{ 1320,256.0f,URCHINS },
	{ 1420,128.0f,URCHINS },
	{ 1520,512.0f,ANEMONES },
	{ 1620,512.0f,URCHINS },
	{ 1800,256.0f,SQUIDS },
	{ 1801,256.0f,RAYS },
	{ 1820,512.0f,ANEMONES },
	{ 1821,384.0f,SQUIDS },
	{ 1840,640.0f,RAYS },
	{ 1841,512.0f,URCHINS },
	{ 1860,640.0f,ANEMONES },
	{ 1861,384.0f,RAYS },
	{ 1880,128.0f,RAYS },
	{ 1900,256.0f,SQUIDS },
	{ 1980,0.0f,SQUIDS },
	{ 2020,384.0f,SQUIDS },
	{ 2100,384.0f,RAYS },
	{ 2130,384.0f,RAYS },
	{ 2160,128.0f,URCHINS },
	{ 2200,384.0f,RAYS },
	{ 2220,384.0f,URCHINS },
	{ 2230,128.0f,RAYS },
	{ 2231,256.0f,SQUIDS },
	{ 2300,512.0f,URCHINS },
	{ 2330,384.0f,RAYS },
	{ 2380,384.0f,URCHINS },
	{ 2400,384.0f,SQUIDS },
	{ 2401,128.0f,RAYS },
	{ 2406,256.0f,SQUIDS },
	{ 2410,384.0f,RAYS },
	{ 2414,480.0f,SQUIDS },
	{ 2422,128.0f,URCHINS },
	{ 2426,384.0f,RAYS },
	{ 2500,512.0f,RAYS },
	{ 2550,512.0f,SQUIDS },
	{ 2600,128.0f,URCHINS },
	{ 2640,384.0f,URCHINS },
	{ 2680,256.0f,RAYS },
	{ 2740,512.0f,SQUIDS },
	{ 2780,256.0f,URCHINS },
	{ 2800,512.0f,ANEMONES },
	};
	static constexpr const int CREATE_GROUND_FRAME[] = { 1800 };
	static constexpr const int CREATE_GROUND_FRAME2[] = { 10,2000 };
	static constexpr const int ENENMY_GENERATE_MAX = sizeof(ENEMY_GENERATE) / sizeof(ENEMY_GENERATE[0]);   // エネミー最大生成数
	static constexpr const int GROUND_MAX = sizeof(CREATE_GROUND_FRAME) / sizeof(CREATE_GROUND_FRAME[0]);   // 地面最大生成数
	static constexpr const float ANEMONE_POS_Y = 660.0f;
	static constexpr const int BOSS_POP_FRAME = 3200;

private:
	int m_generate_arrow;
	int m_frame_cnt;
	int m_boss_frame;
	int m_ground_cnt;
	Data_Manager::Stage_Number m_stage_num;
	Data_Manager::Stage_State m_state;
	bool m_is_boss;
	std::unique_ptr<Ground_Generator> m_ground;
public:
	Enemy_Generator(Object_Tag tag, int draw_priority);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, Enemy_Type type, const D3DXVECTOR2& pos);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects) override;
	void Draw(void)override {}
};

#endif