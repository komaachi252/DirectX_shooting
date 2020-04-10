/**
* @file Texture_Manager.h
* @brief �e�N�X�`���w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <d3d9.h>
#include <string>

/**
* @class Texture_Manager
* @brief �e�N�X�`���Ǘ��N���X
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
		//!  ���ݎg���Ă��鐔
		int cnt;
	};
	Texture_Data m_textures[TEXTURE_DATA_MAX];
public:
	Texture_Manager(void);
	int Set_File(const std::string& file_name, int width, int height);//�ǂݍ��ރe�N�X�`���̗\��@(�t�@�C����, �e�N�X�`����,�@����)�߂�l �\��ԍ�(id) -1���Ԃ�����󂫂��Ȃ���
	int Load(void);                       //�t�@�C���̓ǂݍ��� �߂�l�@�ǂݍ��߂Ȃ�������
	LPDIRECT3DTEXTURE9 Get(int id);//�e�N�X�`���C���^�t�F�[�X���擾����֐��@(�\��ԍ�) �s���ԍ���NULL���Ԃ�
	void Destroy(int tex_id);   //�e�N�X�`����������@��������@(���������id���������z��̐擪�A�h���X, ���̃A�h���X���牽���H)    int id; (&id,1)�ł������@
	void Destroy(void);                   //�e�N�X�`����������@�S�����
	int Get_Width(int id);                 //�e�N�X�`���̕����擾
	int Get_Height(int id);                //�e�N�X�`���̍������擾
};


#endif