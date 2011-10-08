using System;
using Tao.Sdl;
using Microsoft.Xna.Framework;

namespace Microsoft.Xna.Framework.Input
{
	public static class Keyboard
	{	
		public static KeyboardState GetState ( PlayerIndex playerIndex )
		{
			return new KeyboardState(new Keys());
		}
		
		public static KeyboardState GetState ()
		{
			int n;
			KeyboardState state = new KeyboardState(new Keys()); 
			
			Sdl.SDL_PumpEvents();
			byte[] keys = Sdl.SDL_GetKeyState(out n);
			
		
			for (int key = 0; key < n; key++)
			{
				if (keys[key] != 0)
					state.KeyList[key] = KeyState.Down;
				else
					state.KeyList[key] = KeyState.Up;
			}
			
			return state;
		}
	}
}

