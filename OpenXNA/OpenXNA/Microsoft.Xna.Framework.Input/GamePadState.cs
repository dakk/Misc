using System;

namespace Microsoft.Xna.Framework.Input
{
	public struct GamePadState
	{
		public GamePadButtons Buttons { get; set; }
		public GamePadDPad DPad { get; set; }
		public bool IsConnected { get; set; }
		public int PacketNumber { get; set; }
		public GamePadThumbSticks ThumbSticks { get; set; }
		public GamePadTriggers Triggers { get; set; }
		
			
		/* Initializes a new instance of the GamePadState class with the specified 
		 * stick, trigger, and button values. */
		public GamePadState (   Vector2 leftThumbStick,
         						Vector2 rightThumbStick,
         						float leftTrigger,
         						float rightTrigger,
         						params Buttons[] buttons ) : this()
		{
			ThumbSticks = new GamePadThumbSticks(leftThumbStick, rightThumbStick);
			Triggers = new GamePadTriggers(leftTrigger, rightTrigger);
			
			Buttons = new GamePadButtons();
			for(int i = 0; i < buttons.Length; i++)
			{
				switch(buttons[i])
				{
				/* Buttons */
				case Microsoft.Xna.Framework.Input.Buttons.A:
					Buttons.A = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.B:
					Buttons.B = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.Back:
					Buttons.Back = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.BigButton:
					Buttons.BigButton = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.LeftShoulder:
					Buttons.LeftShoulder = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.LeftStick:
					Buttons.LeftStick = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.RightShoulder:
					Buttons.RightShoulder = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.RightStick:
					Buttons.RightStick = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.Start:
					Buttons.Start = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.X:
					Buttons.X = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.Y:
					Buttons.Y = ButtonState.Pressed;
					break;
				
				/* DPad */
				case Microsoft.Xna.Framework.Input.Buttons.DPadDown:
					DPad.Down = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.DPadLeft:
					DPad.Left = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.DPadRight:
					DPad.Right = ButtonState.Pressed;
					break;
				case Microsoft.Xna.Framework.Input.Buttons.DPadUp:
					DPad.Up = ButtonState.Pressed;
					break;
				
				}
			}
		}
		
		public GamePadState (	GamePadThumbSticks thumbSticks,
         						GamePadTriggers triggers,
						        GamePadButtons buttons,
						        GamePadDPad dPad ) : this()
		{
			ThumbSticks = thumbSticks;
			Triggers = triggers;
			Buttons = buttons;
			DPad = dPad;
		}
		
		
		private bool getButtonBool(ButtonState b)
		{
			if(b == ButtonState.Pressed)	
				return true;
			return false;
		}

		public bool IsButtonDown ( Buttons button )
		{
				switch(button)
				{
				/* Buttons */
				case Microsoft.Xna.Framework.Input.Buttons.A:
					return getButtonBool(Buttons.A);
				case Microsoft.Xna.Framework.Input.Buttons.B:
					return getButtonBool(Buttons.B);
				
				case Microsoft.Xna.Framework.Input.Buttons.Back:
					return getButtonBool(Buttons.Back);
				
				case Microsoft.Xna.Framework.Input.Buttons.BigButton:
					return getButtonBool(Buttons.BigButton);
				
				case Microsoft.Xna.Framework.Input.Buttons.LeftShoulder:
					return getButtonBool(Buttons.LeftShoulder);
				
				case Microsoft.Xna.Framework.Input.Buttons.LeftStick:
					return getButtonBool(Buttons.LeftStick);
				
				case Microsoft.Xna.Framework.Input.Buttons.RightShoulder:
					return getButtonBool(Buttons.RightShoulder);
				
				case Microsoft.Xna.Framework.Input.Buttons.RightStick:
					return getButtonBool(Buttons.RightStick);
				
				case Microsoft.Xna.Framework.Input.Buttons.Start:
					return getButtonBool(Buttons.Start);
				
				case Microsoft.Xna.Framework.Input.Buttons.X:
					return getButtonBool(Buttons.X);
				
				case Microsoft.Xna.Framework.Input.Buttons.Y:
					return getButtonBool(Buttons.Y);
				
				
				/* DPad */
				case Microsoft.Xna.Framework.Input.Buttons.DPadDown:
					return getButtonBool(DPad.Down);
				
				case Microsoft.Xna.Framework.Input.Buttons.DPadLeft:
					return getButtonBool(DPad.Left);
				
				case Microsoft.Xna.Framework.Input.Buttons.DPadRight:
					return getButtonBool(DPad.Right);
				
				case Microsoft.Xna.Framework.Input.Buttons.DPadUp:
					return getButtonBool(DPad.Up);
				
				
				default:
					return false;
				
				}
		}
		
		public bool IsButtonUp ( Buttons button )
		{
			return !IsButtonDown(button);
		}
	}
}

