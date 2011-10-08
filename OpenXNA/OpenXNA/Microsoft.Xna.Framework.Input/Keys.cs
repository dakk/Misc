using System;
using Tao.Sdl;

namespace Microsoft.Xna.Framework.Input
{
	public enum Keys
	{
		A = Sdl.SDLK_a, //	A key
		Add, //	Add key
		Apps, //	Applications key
		Attn, //	Attn key
		B = Sdl.SDLK_b, //	B key
		Back = Sdl.SDLK_BACKSPACE, //	BACKSPACE key
		BrowserBack, //	Windows 2000/XP: Browser Back key
		BrowserFavorites, //	Windows 2000/XP: Browser Favorites key
		BrowserForward, //	Windows 2000/XP: Browser Forward key
		BrowserHome, //	Windows 2000/XP: Browser Start and Home key
		BrowserRefresh, //	Windows 2000/XP: Browser Refresh key
		BrowserSearch, //	Windows 2000/XP: Browser Search key
		BrowserStop, //	Windows 2000/XP: Browser Stop key
		C = Sdl.SDLK_c, //	C key
		CapsLock = Sdl.SDLK_CAPSLOCK, //	CAPS LOCK key
		ChatPadGreen, //	Green ChatPad key
		ChatPadOrange, //	Orange ChatPad key
		Crsel, //	CrSel key
		D = Sdl.SDLK_d, //	D key
		D0, //	Used for miscellaneous characters; it can vary by keyboard.
		D1, //	Used for miscellaneous characters; it can vary by keyboard.
		D2, //	Used for miscellaneous characters; it can vary by keyboard.
		D3, //	Used for miscellaneous characters; it can vary by keyboard.
		D4, //	Used for miscellaneous characters; it can vary by keyboard.
		D5, //	Used for miscellaneous characters; it can vary by keyboard.
		D6, //	Used for miscellaneous characters; it can vary by keyboard.
		D7, //	Used for miscellaneous characters; it can vary by keyboard.
		D8, //	Used for miscellaneous characters; it can vary by keyboard.
		D9, //	Used for miscellaneous characters; it can vary by keyboard.
		Decimal, //	Decimal key
		Delete = Sdl.SDLK_DELETE, //	DEL key
		Divide = Sdl.SDLK_KP_DIVIDE, //	Divide key
		Down = Sdl.SDLK_DOWN, //	DOWN ARROW key
		E = Sdl.SDLK_e, //	E key
		End = Sdl.SDLK_END, //	END key
		Enter = Sdl.SDLK_KP_ENTER, //	ENTER key
		EraseEof, //	Erase EOF key
		Escape = Sdl.SDLK_ESCAPE, //	ESC key
		Execute, //	EXECUTE key
		Exsel, //	ExSel key
		F = Sdl.SDLK_f, //	F key
		F1 = Sdl.SDLK_F1, //	F1 key
		F10 = Sdl.SDLK_F10, //	F10 key
		F11 = Sdl.SDLK_F11, //	F11 key
		F12 = Sdl.SDLK_F12, //	F12 key
		F13 = Sdl.SDLK_F13, //	F13 key
		F14 = Sdl.SDLK_F14, //	F14 key
		F15 = Sdl.SDLK_F15, //	F15 key
		F16, //	F16 key
		F17, //	F17 key
		F18, //	F18 key
		F19, //	F19 key
		F2 = Sdl.SDLK_F2, //	F2 key
		F20, //	F20 key
		F21, //	F21 key
		F22, //	F22 key
		F23, //	F23 key
		F24, //	F24 key
		F3 = Sdl.SDLK_F3, //	F3 key
		F4 = Sdl.SDLK_F4, //	F4 key
		F5 = Sdl.SDLK_F5, //	F5 key
		F6 = Sdl.SDLK_F6, //	F6 key
		F7 = Sdl.SDLK_F7, //	F7 key
		F8 = Sdl.SDLK_F8, //	F8 key
		F9 = Sdl.SDLK_F9, //F9 key
		G = Sdl.SDLK_g, //G key
		H = Sdl.SDLK_h, //H key
		Help = Sdl.SDLK_HELP, //	HELP key
		Home = Sdl.SDLK_HOME, //	HOME key
		I = Sdl.SDLK_i, //	I key
		ImeConvert, //	IME Convert key
		ImeNoConvert, //	IME NoConvert key
		Insert = Sdl.SDLK_INSERT, //	INS key
		J = Sdl.SDLK_j, //	J key
		K = Sdl.SDLK_k, //	K key
		Kana, //	Kana key on Japanese keyboards
		Kanji, //	Kanji key on Japanese keyboards
		L = Sdl.SDLK_l, //	L key
		LaunchApplication1, //	Windows 2000/XP: Start Application 1 key
		LaunchApplication2, //	Windows 2000/XP: Start Application 2 key
		LaunchMail, //	Windows 2000/XP: Start Mail key
		Left = Sdl.SDLK_LEFT, //	LEFT ARROW key
		LeftAlt = Sdl.SDLK_LALT, //	Left ALT key
		LeftControl = Sdl.SDLK_LCTRL, //	Left CONTROL key
		LeftShift = Sdl.SDLK_LSHIFT, //	Left SHIFT key
		LeftWindows, //	Left Windows key
		M = Sdl.SDLK_m, //	M key
		MediaNextTrack, //	Windows 2000/XP: Next Track key
		MediaPlayPause, //	Windows 2000/XP: Play/Pause Media key
		MediaPreviousTrack, //	Windows 2000/XP: Previous Track key
		MediaStop, //	Windows 2000/XP: Stop Media key
		Multiply, //	Multiply key
		N = Sdl.SDLK_n, //	N key
		None, //	Reserved
		NumLock = Sdl.SDLK_NUMLOCK, //	NUM LOCK key
		NumPad0 = Sdl.SDLK_0, //	Numeric keypad 0 key
		NumPad1 = Sdl.SDLK_1, //	Numeric keypad 1 key
		NumPad2 = Sdl.SDLK_2, //	Numeric keypad 2 key
		NumPad3 = Sdl.SDLK_3, //	Numeric keypad 3 key
		NumPad4 = Sdl.SDLK_4, //	Numeric keypad 4 key
		NumPad5 = Sdl.SDLK_5, //	Numeric keypad 5 key
		NumPad6 = Sdl.SDLK_6, //Numeric keypad 6 key
		NumPad7 = Sdl.SDLK_7, //	Numeric keypad 7 key
		NumPad8 = Sdl.SDLK_8, //	Numeric keypad 8 key
		NumPad9 = Sdl.SDLK_9, //	Numeric keypad 9 key
		O = Sdl.SDLK_o, //	O key
		Oem8, //	Used for miscellaneous characters; it can vary by keyboard.
		OemAuto, //	OEM Auto key
		OemBackslash, //	Windows 2000/XP: The OEM angle bracket or backslash key on the RT 102 key keyboard
		OemClear, //	CLEAR key
		OemCloseBrackets, //	Windows 2000/XP: The OEM close bracket key on a US standard keyboard
		OemComma, //	Windows 2000/XP: For any country/region, the ',' key
		OemCopy, //	OEM Copy key
		OemEnlW, //	OEM Enlarge Window key
		OemMinus, //	Windows 2000/XP: For any country/region, the '-' key
		OemOpenBrackets, //	Windows 2000/XP: The OEM open bracket key on a US standard keyboard
		OemPeriod, //	Windows 2000/XP: For any country/region, the '.' key
		OemPipe, //	Windows 2000/XP: The OEM pipe key on a US standard keyboard
		OemPlus, //	Windows 2000/XP: For any country/region, the '+' key
		OemQuestion, //	Windows 2000/XP: The OEM question mark key on a US standard keyboard
		OemQuotes, //	Windows 2000/XP: The OEM singled/double quote key on a US standard keyboard
		OemSemicolon, //	Windows 2000/XP: The OEM Semicolon key on a US standard keyboard
		OemTilde, //	Windows 2000/XP: The OEM tilde key on a US standard keyboard
		P = Sdl.SDLK_p, //	P key
		Pa1, //	PA1 key
		PageDown = Sdl.SDLK_PAGEDOWN, //	PAGE DOWN key
		PageUp = Sdl.SDLK_PAGEUP, //	PAGE UP key
		Pause = Sdl.SDLK_PAUSE, //	PAUSE key
		Play, //	Play key
		Print = Sdl.SDLK_PRINT, //	PRINT key
		PrintScreen = Sdl.SDLK_PRINT, //	PRINT SCREEN key
		ProcessKey, //	Windows 95/98/Me, Windows NT 4.0, Windows 2000/XP: IME PROCESS key
		Q = Sdl.SDLK_q, //	Q key
		R = Sdl.SDLK_r, //	R key
		Right = Sdl.SDLK_RIGHT, //	RIGHT ARROW key
		RightAlt = Sdl.SDLK_RALT, //	Right ALT key
		RightControl = Sdl.SDLK_RCTRL, //	Right CONTROL key
		RightShift = Sdl.SDLK_RSHIFT, //	Right SHIFT key
		RightWindows, //	Right Windows key
		S = Sdl.SDLK_s, //	S key
		Scroll = Sdl.SDLK_SCROLLOCK, //	SCROLL LOCK key
		Select, //	SELECT key
		SelectMedia, //	Windows 2000/XP: Select Media key
		Separator, //	Separator key
		Sleep, //	Computer Sleep key
		Space = Sdl.SDLK_SPACE, //	SPACEBAR
		Subtract, //	Subtract key
		T = Sdl.SDLK_t, //	T key
		Tab = Sdl.SDLK_TAB, //	TAB key
		U = Sdl.SDLK_u, //	U key
		Up = Sdl.SDLK_UP, //	UP ARROW key
		V = Sdl.SDLK_v, //	V key
		VolumeDown, //	Windows 2000/XP: Volume Down key
		VolumeMute, //	Windows 2000/XP: Volume Mute key
		VolumeUp, //	Windows 2000/XP: Volume Up key
		W = Sdl.SDLK_w, //	W key
		X = Sdl.SDLK_x, //	X key
		Y = Sdl.SDLK_y, //	Y key
		Z = Sdl.SDLK_z, //	Z key
		Zoom,
		_End
	}
}

