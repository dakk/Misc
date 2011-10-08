using System;
using Tao;
using Tao.Sdl;

namespace Microsoft.Xna.Framework.Input
{
	public struct KeyboardState
	{
		public KeyState[] KeyList;
		
		
		public KeyState this [Keys key] { get{ return KeyList[(int) key]; } }
	
		public KeyboardState (params Keys[] keys)
		{
			KeyList = new KeyState[(int) Sdl.SDLK_LAST];
		}

		
		public bool IsKeyUp (Keys key)
		{
			if(KeyList[(int) key] == KeyState.Up)
				return true;
			return false;
		}
		
		public bool IsKeyDown (Keys key)
		{
			if(KeyList[(int) key] == KeyState.Down)
				return true;
			return false;		
		}
		
		public Keys[] GetPressedKeys()
		{
			return new Keys[1];
			//for(KeyState k = KeyList[0]; k < KeyList.GetValue(KeyList.GetLength); k++);
			//return KeyList;
		}
		
	}
}

