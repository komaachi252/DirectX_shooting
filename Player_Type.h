/**
* @file Player_Type.h
* @brief プレイヤータイプ描画ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef PLAYER_TYPE_H_
#define PLAYER_TYPE_H_
#include "Polygon2D.h"
#include "Item.h"

/**
* @class Player_Type
* @brief プレイヤータイプ描画クラス
* @details
*/
class Player_Type : public Polygon2D
{
public:
	static constexpr const char* FILE_NAME = "normal.png";
	static constexpr const int TEX_TYPE_WIDTH = 214;
	static constexpr const int TEX_TYPE_HEIGHT = 120;
	static constexpr const int DRAW_TYPE_WIDTH = 214;
	static constexpr const int DRAW_TYPE_HEIGHT = 30;
	static constexpr const float TYPE_POS_X = 50.0f;
	static constexpr const float TYPE_POS_Y = 600.0f;
private:
	Item::Item_Type m_type;
	int m_cut_y;
public:
	Player_Type(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos);
	~Player_Type(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
	void Set_Type(Item::Item_Type type);
};

#endif
