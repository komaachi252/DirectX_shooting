/**
* @file sound.h
* @brief �T�E���h�w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef SOUND_H_
#define SOUND_H_
#include <Windows.h>
#include <XAudio2.h>

/**
* @class Sound_Manager
* @brief �T�E���h�N���X
* @details �ڍׂȃN���X�̐���
*/
class Sound_Manager
{
public:
	/**
	* @enum Sound_Label
	* @brief �T�E���h���x��
	* @details �Đ�����T�E���h�������ɐݒ肷��
	*/
	enum Sound_Label
	{
		SOUND_LABEL_BGM000 = 0,		// BGM0
		SOUND_LABEL_BGM_TITLE,
		SOUND_LABEL_BGM_GAME,
		SOUND_LABEL_BGM_BOSS,
		SOUND_LABEL_SE_RESULT,
		SOUND_LABEL_SE_NORMAL_SHOT,		// �e���ˉ�
		SOUND_LABEL_SE_PENETRATE_SHOT,
		SOUND_LABEL_SE_SIDE_SHOT,
		SOUND_LABEL_SE_METEOR_SHOT,
		SOUND_LABEL_SE_ENEMY_SHOT,
		SOUND_LABEL_SE_INDUCTION_SHOT,
		SOUND_LABEL_SE_EXPLOSION,	// ������
		SOUND_LABEL_SE_ITEM,
		SOUND_LABEL_SE_REFLECT,
		SOUND_LABEL_SE_DAMAGE,
		SOUND_LABEL_SE_DECISION,
		SOUND_LABEL_SE_CANNON,
		SOUND_LABEL_SE_SIREN,
		SOUND_LABEL_MAX,
	};
	struct Sound_Param
	{
		const char* file_name;
		int cnt_loop;
	};
	Sound_Param sound_param[SOUND_LABEL_MAX] =
	{
		{ "Asset/BGM/parade.wav", -1 },		// BGM0  -1 �������[�v 0 ���saver_wing
		{ "Asset/BGM/title.wav", -1 },		// BGM0  -1 �������[�v 0 ���saver_wing
		{ "Asset/BGM/game.wav", -1 },		// BGM0  -1 �������[�v 0 ���saver_wing
		{ "Asset/BGM/boss.wav", -1 },		// BGM0  -1 �������[�v 0 ���saver_wing
		{ "Asset/BGM/result.wav", 0 },		// BGM0  -1 �������[�v 0 ���saver_wing
		{ "Asset/BGM/normal_bullet.wav", 0 },			// �e���ˉ�
		{ "Asset/BGM/penetrate_bullet.wav", 0 },			// �e���ˉ�
		{ "Asset/BGM/side_bullet.wav", 0 },			// �e���ˉ�
		{ "Asset/BGM/meteor_bullet.wav", 0 },			// �e���ˉ�
		{ "Asset/BGM/enemy_bullet.wav", 0 },			// �e���ˉ�
		{ "Asset/BGM/induction_bullet.wav", 0 },			// �e���ˉ�
		{ "Asset/BGM/explosion.wav", 0 },	// ������
		{ "Asset/BGM/item.wav", 0 },
		{ "Asset/BGM/reflection.wav", 0 },
		{ "Asset/BGM/short_bomb.wav", 0 },
		{ "Asset/BGM/decision.wav", 0 },
		{ "Asset/BGM/cannon.wav", 0 },
		{ "Asset/BGM/siren.wav", 0 },

	};

	Sound_Manager(void) {}
	~Sound_Manager(void);

	HRESULT Init(HWND wnd);
	HRESULT Play(Sound_Label label);
	void Stop(Sound_Label label);
	void Stop(void);
	
private:
	HRESULT Check_Chunk(HANDLE file, DWORD format, DWORD *chunk_size, DWORD *chunk_data_position);
	HRESULT Read_Chunk_Data(HANDLE file, void *buffer, DWORD buffer_size, DWORD buffer_offset);

	IXAudio2 * xaudio2;								        //!< XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *mastering_voice;			    //!< �}�X�^�[�{�C�X
	IXAudio2SourceVoice *source_voice[SOUND_LABEL_MAX];	    //!< �\�[�X�{�C�X
	BYTE *data_audio[SOUND_LABEL_MAX];					    //!< �I�[�f�B�I�f�[�^
	DWORD size_audio[SOUND_LABEL_MAX];					    //!< �I�[�f�B�I�f�[�^�T�C�Y
};

#endif
