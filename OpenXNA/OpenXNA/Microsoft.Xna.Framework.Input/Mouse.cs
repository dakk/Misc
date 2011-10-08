using System;
using Tao.Sdl;

namespace Microsoft.Xna.Framework.Input
{
	public static class Mouse
	{
		public static IntPtr WindowHandle { get; set; }
		
		public static void SetPosition ( int x, int y)
		{
		}
		
		public static MouseState GetState ()
		{
			int x;
			int y;
			uint mouse;
			
			Sdl.SDL_PumpEvents();
			mouse = Sdl.SDL_GetMouseState(out x, out y);
			
			return new MouseState(x, y, 0, (ButtonState) (mouse & Sdl.SDL_BUTTON(1)), 
			                      (ButtonState) (mouse & Sdl.SDL_BUTTON(2)),
			                      (ButtonState) (mouse & Sdl.SDL_BUTTON(3)),
			                      (ButtonState) (mouse & Sdl.SDL_BUTTON(4)),
			                      (ButtonState) (mouse & Sdl.SDL_BUTTON(5)));
		}
	}
}

