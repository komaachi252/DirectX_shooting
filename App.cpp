/**
* @file main.cpp
* @brief 主処理
* @author 矢吹一俊
* @date 2020/03/18
*/

#include "App.h"
#include "Manager/Game_Manager.h"
#include "Manager/System_Timer_Manager.h"
#include "Design_Pattern/Singleton.h"

App::App(HINSTANCE instance)
{
	WNDCLASS wc = {};//0で初期化
	wc.lpfnWndProc = Wnd_Proc;//関数名
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = m_instance = instance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);

	RegisterClass(&wc);

	RECT window_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	AdjustWindowRect(&window_rect, WINDOW_STYLE, FALSE);

	int window_width = window_rect.right - window_rect.left;
	int window_height = window_rect.bottom - window_rect.top;
	int desktop_width = GetSystemMetrics(SM_CXSCREEN);//モニター幅
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);//モニター高さ
	int window_x = max((desktop_width - window_width) / 2, 0);//画面真ん中の座標を調べるX
	int window_y = max((desktop_height - window_height) / 2, 0);//Y
	m_hwnd = CreateWindow(
		CLASS_NAME,//クラス名
		WINDOW_CAPTION,//ウィンドウの名前
		WINDOW_STYLE,//ウィンドウの形 ウィンドウサイズ固定
		window_x,//座標左上X　テキストも含めて幅高さ
		window_y,//Y
		window_width,//幅
		window_height,//高さ
		NULL,
		NULL,
		instance,
		NULL
	);
}

int App::Run(int cmd_show)
{
	ShowWindow(m_hwnd, cmd_show);
	UpdateWindow(m_hwnd);

	MSG msg = {};
	Singleton<Game_Manager>::Create();
	Singleton<System_Timer_Manager>::Create();
	
	if(!Singleton<Game_Manager>::Get_Instance()->Init(m_hwnd, m_instance)){
		return -1;
	}
	while (WM_QUIT != msg.message) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {//ゲームの処理
			double time = Singleton<System_Timer_Manager>::Get_Instance()->Get_Time();
			if (time - Singleton<System_Timer_Manager>::Get_Instance()->m_static_frame_time < 1.0f / 60.0f) {
				Sleep(0);
			}else {
				Singleton<System_Timer_Manager>::Get_Instance()->Update(time);
				Singleton<Game_Manager>::Get_Instance()->Update();
				Singleton<Game_Manager>::Get_Instance()->Draw();
			}
		}
	}
	Singleton<System_Timer_Manager>::Destory();
	Singleton<Game_Manager>::Destory();

	return(int)msg.wParam;
}

LRESULT CALLBACK App::Wnd_Proc(HWND wnd, UINT msg, WPARAM w_param, LPARAM l_param)
{
	switch (msg) {
	case WM_KEYDOWN://キーの入力があった
		if (w_param == VK_ESCAPE) {//キーの名前を持っている Escapeキーで終了するようにする
			SendMessage(wnd, WM_CLOSE, 0, 0);
		}
		break;

	case WM_CLOSE://ウィンドウ閉じるときに出る
		if (MessageBox(wnd, "本当に終了してもよろしいですか？", "確認", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK) {
			DestroyWindow(wnd);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);//WM_QUITをGetMessageに出す
		return 0;
	};
	return DefWindowProc(wnd, msg, w_param, l_param);//他のメッセージを処理したい
}