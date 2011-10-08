using System;

namespace Microsoft.Xna.Framework.Input
{
	public struct GamePadButtons
	{
		public ButtonState A { get; set; }
		public ButtonState B { get; set; }
		public ButtonState Back { get; set; }
		public ButtonState BigButton { get; set; }
		public ButtonState LeftShoulder { get; set; }
		public ButtonState LeftStick { get; set; }
		public ButtonState RightShoulder { get; set; }
		public ButtonState RightStick { get; set; }
		public ButtonState Start { get; set; }
		public ButtonState X { get; set; }
		public ButtonState Y { get; set; }
		
		/* Initializes a new instance of the GamePadButtons class, setting the 
		 * specified buttons to pressed in. */
		public GamePadButtons ( Buttons buttons ) : this()
		{
			switch(buttons)
			{
			case Buttons.A:
				A = ButtonState.Pressed;
				break;
			case Buttons.B:
				B = ButtonState.Pressed;
				break;
			case Buttons.Back:
				Back = ButtonState.Pressed;
				break;
			case Buttons.BigButton:
				BigButton = ButtonState.Pressed;
				break;
			case Buttons.LeftShoulder:
				LeftShoulder = ButtonState.Pressed;
				break;
			case Buttons.LeftStick:
				LeftStick = ButtonState.Pressed;
				break;
			case Buttons.RightShoulder:
				RightShoulder = ButtonState.Pressed;
				break;
			case Buttons.RightStick:
				RightStick = ButtonState.Pressed;
				break;
			case Buttons.Start:
				Start = ButtonState.Pressed;
				break;
			case Buttons.Y:
				Y = ButtonState.Pressed;
				break;
			case Buttons.X:
				X = ButtonState.Pressed;
				break;
			}
		}
	}
}

