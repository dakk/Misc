using System;

namespace Microsoft.Xna.Framework.Input
{
	public struct GamePadDPad
	{
		public ButtonState Up { get; set; }
		public ButtonState Down { get; set; }
		public ButtonState Left { get; set; }
		public ButtonState Right { get; set; }
		
		public GamePadDPad ( ButtonState upValue,
         					 ButtonState downValue,
					         ButtonState leftValue,
					         ButtonState rightValue ) : this()
		{
			Up = upValue;
			Down = downValue;
			Left = leftValue;
			Right = rightValue;
		}
	}
}

