/**
* @file Sprite_Manager.h
* @brief スプライトヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef SPRITE_MANAGER_H_
#define SPRITE_MANAGER_H_
#include <d3d9.h>
#include <d3dx9.h>

/**
* @class Sprite_Manager
* @brief スプライトクラス
* @details 詳細なクラスの説明
*/
class Sprite_Manager
{
public:
	static constexpr const D3DCOLOR DEFAULT_COLOR = D3DCOLOR_RGBA(255, 255, 255, 255);
	static constexpr const char* FILE_NAME = "number.png";
	static constexpr const int NUM_WIDTH = 32;
	static constexpr const int NUM_HEIGHT = 32;
	static constexpr const int TEX_NUM_WIDTH = 320;
	static constexpr const int TEX_NUM_HEIGHT = 32;
	int m_tex_id;
private:
	struct Vertex_2d {
		D3DXVECTOR4 position;
		D3DCOLOR color;
		D3DXVECTOR2 uv;
	};
	D3DCOLOR m_color;
public:
	Sprite_Manager(void);
	~Sprite_Manager(void);
	void Draw(int texture_id, float dx, float dy);
	void Draw(int texture_id, float dx, float dy, float w, float h);
	void Draw_Scroll(int texture_id, float dx, float dy, float w, float h, float u, float v);
	void Draw_Alpha(int texture_id, float dx, float dy, float w, float h, int alpha);
	void Draw(int texture_id, float dx, float dy, int cut_x, int cut_y, int cut_w, int cut_h);
	void Draw(int texture_id, float dx, float dy, int cut_x, int cut_y, int cut_w, int cut_h, float angle, float cx, float cy, float scale);
	void Draw_Scale(int texture_id, float dx, float dy, int cut_x, int cut_y, int cut_w, int cut_h, float cx, float cy, float scale);
	void Draw_Mirror(int texture_id, float dx, float dy, float w, float h);
	void Draw(int texture_id, float dx, float dy, int cut_x, int cut_y, int cut_w, int cut_h, int w, int h);
	void Set_Color(D3DCOLOR color);
	void Number_Draw(int num, float x, float y);
	void Score_Draw(int score, float x, float y, int digit);
};

#endif //SPRITE_MANAGER_H_