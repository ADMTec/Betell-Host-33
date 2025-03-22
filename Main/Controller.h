#pragma once
// ----------------------------------------------------------------------------------------------
class Controller
{
public:
	bool	Load();
	// ----
	static	LRESULT WINAPI Mouse(int Code, WPARAM wParam, LPARAM lParam);
	static	LRESULT WINAPI Keyboard(int Code, WPARAM wParam, LPARAM lParam);
	static	LRESULT WINAPI Keyboard2(int Code, WPARAM wParam, LPARAM lParam);
	static	LRESULT WINAPI Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam);
	// ----
	HINSTANCE	Instance;
	BOOL VKF9_State;
	WPARAM	wMouse;
	WPARAM wKeyBord;
private:
	HHOOK		MouseHook;
	HHOOK		KeyboardHook;
	HHOOK		KeyboardHook2;
	// ----
}; extern Controller gController;
// ----------------------------------------------------------------------------------------------

extern char Notice_1[1024];
extern char Notice_2[1024];
extern char Notice_3[1024];
extern char Notice_4[1024];
extern char Notice_5[1024];
extern char Notice_6[1024];
extern char Notice_7[1024];
extern BOOL isNotice;