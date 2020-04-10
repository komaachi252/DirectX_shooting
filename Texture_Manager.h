/**
* @file Texture_Manager.h
* @brief テクスチャヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <d3d9.h>
#include <string>

/**
* @class Texture_Manager
* @brief テクスチャ管理クラス
*/
class Texture_Manager
{
private:
	static constexpr const int TEXTURE_DATA_MAX = 64;
	static constexpr const char* TEXTURE_FILE_PATH = "Asset/Texture/";
	struct Texture_Data
	{
		std::string file_name;
		int width;
		int height;
		LPDIRECT3DTEXTURE9 texture;
		//!  現在使われている数
		int cnt;
	};
	Texture_Data m_textures[TEXTURE_DATA_MAX];
public:
	Texture_Manager(void);
	int Set_File(const std::string& file_name, int width, int height);//読み込むテクスチャの予約　(ファイル名, テクスチャ幅,　高さ)戻り値 予約番号(id) -1が返ったら空きがないよ
	int Load(void);                       //ファイルの読み込み 戻り値　読み込めなかった数
	LPDIRECT3DTEXTURE9 Get(int id);//テクスチャインタフェースを取得する関数　(予約番号) 不正番号でNULLが返る
	void Destroy(int tex_id);   //テクスチャ解放処理　部分解放　(解放したいidが入った配列の先頭アドレス, このアドレスから何個分？)    int id; (&id,1)でおっけ　
	void Destroy(void);                   //テクスチャ解放処理　全部解放
	int Get_Width(int id);                 //テクスチャの幅を取得
	int Get_Height(int id);                //テクスチャの高さを取得
};


#endif