using System;

namespace Microsoft.Xna.Framework.Input
{
	public struct MouseState
	{
		public ButtonState LeftButton { get; set; }
		public ButtonState MiddleButton { get; set; }
		public ButtonState RightButton { get; set; }
		public int ScrollWheelValue { get; set; }
		public int X { get; set; }
		public int Y { get; set; }
		public ButtonState XButton1 { get; set; }
		public ButtonState XButton2 { get; set; }
		
		public MouseState ( int x, int y,
					        int scrollWheel,
					        ButtonState leftButton,
					        ButtonState middleButton,
					        ButtonState rightButton,
					        ButtonState xButton1,
					        ButtonState xButton2 ) : this()
		{
			this.X = x;
			this.Y = y;
			this.ScrollWheelValue = scrollWheel;
			this.LeftButton = leftButton;
			this.MiddleButton = middleButton;
			this.RightButton = rightButton;
			this.XButton1 = xButton1;
			this.XButton2 = xButton2;

		}
	}
}

