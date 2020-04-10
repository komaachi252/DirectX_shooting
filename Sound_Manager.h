/**
* @file sound.h
* @brief サウンドヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef SOUND_H_
#define SOUND_H_
#include <Windows.h>
#include <XAudio2.h>

/**
* @class Sound_Manager
* @brief サウンドクラス
* @details 詳細なクラスの説明
*/
class Sound_Manager
{
public:
	/**
	* @enum Sound_Label
	* @brief サウンドラベル
	* @details 再生するサウンドを引数に設定する
	*/
	enum Sound_Label
	{
		SOUND_LABEL_BGM000 = 0,		// BGM0
		SOUND_LABEL_BGM_TITLE,
		SOUND_LABEL_BGM_GAME,
		SOUND_LABEL_BGM_BOSS,
		SOUND_LABEL_SE_RESULT,
		SOUND_LABEL_SE_NORMAL_SHOT,		// 弾発射音
		SOUND_LABEL_SE_PENETRATE_SHOT,
		SOUND_LABEL_SE_SIDE_SHOT,
		SOUND_LABEL_SE_METEOR_SHOT,
		SOUND_LABEL_SE_ENEMY_SHOT,
		SOUND_LABEL_SE_INDUCTION_SHOT,
		SOUND_LABEL_SE_EXPLOSION,	// 爆発音
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
		{ "Asset/BGM/parade.wav", -1 },		// BGM0  -1 無限ループ 0 一回saver_wing
		{ "Asset/BGM/title.wav", -1 },		// BGM0  -1 無限ループ 0 一回saver_wing
		{ "Asset/BGM/game.wav", -1 },		// BGM0  -1 無限ループ 0 一回saver_wing
		{ "Asset/BGM/boss.wav", -1 },		// BGM0  -1 無限ループ 0 一回saver_wing
		{ "Asset/BGM/result.wav", 0 },		// BGM0  -1 無限ループ 0 一回saver_wing
		{ "Asset/BGM/normal_bullet.wav", 0 },			// 弾発射音
		{ "Asset/BGM/penetrate_bullet.wav", 0 },			// 弾発射音
		{ "Asset/BGM/side_bullet.wav", 0 },			// 弾発射音
		{ "Asset/BGM/meteor_bullet.wav", 0 },			// 弾発射音
		{ "Asset/BGM/enemy_bullet.wav", 0 },			// 弾発射音
		{ "Asset/BGM/induction_bullet.wav", 0 },			// 弾発射音
		{ "Asset/BGM/explosion.wav", 0 },	// 爆発音
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

	IXAudio2 * xaudio2;								        //!< XAudio2オブジェクトへのインターフェイス
	IXAudio2MasteringVoice *mastering_voice;			    //!< マスターボイス
	IXAudio2SourceVoice *source_voice[SOUND_LABEL_MAX];	    //!< ソースボイス
	BYTE *data_audio[SOUND_LABEL_MAX];					    //!< オーディオデータ
	DWORD size_audio[SOUND_LABEL_MAX];					    //!< オーディオデータサイズ
};

#endif
