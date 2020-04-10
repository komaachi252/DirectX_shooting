/**
* @file System_Timer_Manager.h
* @brief システムタイマーヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#ifndef SYSTEM_TIMER_H_
#define SYSTEM_TIMER_H_
#include <Windows.h>

/**
* @class System_Timer_Manager
* @brief システムタイマークラス
*/
class System_Timer_Manager
{
private:
	bool m_is_timer_stopped; // ストップフラグ
	LONGLONG m_ticks_per_sec;  // １秒間の計測時間
	LONGLONG m_stop_time;         // ストップした時間
	LONGLONG m_last_elapsed_time;  // 最後に記録した更新時間
	LONGLONG m_base_time;         // 基本時間
public:
	static constexpr const float FPS_MEASUREMENT_TIME = 1.0f;
	int m_frame_count; // フレームカウンター
	int m_FPS_base_frame_count; // FPS計測の基となるフレームカウンター
	double m_FPS_base_time; // FPS計測の基となる時間
	double m_static_frame_time; // フレーム固定用計測時間
	float m_FPS; // FPS

	System_Timer_Manager(void);

	void Update(void);

	// システムタイマーのリセット
	void Reset(void);

	// システムタイマーのスタート
	void Start(void);

	// システムタイマーのストップ
	void Stop(void);

	// システムタイマーを0.1秒進める
	void Advance(void);

	// 計測時間の取得
	double Get_Time(void);

	// 現在の時間を取得
	double Get_Absolute_Time(void);

	// 経過時間の取得
	float Get_Elapsed_Time(void);

	// システムタイマーが止まっているか？
	bool Is_Stoped(void);

	// 現在のスレッドを1つのプロセッサ（現在のスレッド）に制限
	void Limit_Thread_Affinity_To_Current_Proc(void);
	LARGE_INTEGER Get_Adjusted_Current_Time(void);
};

#endif // SYSTEM_TIMER_H_
