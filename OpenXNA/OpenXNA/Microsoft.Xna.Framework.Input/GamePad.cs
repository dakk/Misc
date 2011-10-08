using System;

namespace Microsoft.Xna.Framework.Input
{
	public class GamePad
	{
		public static GamePadCapabilities GetCapabilities ( PlayerIndex playerIndex )
		{
			return new GamePadCapabilities();
		}
			
		public static bool SetVibration ( PlayerIndex playerIndex,
       									  float leftMotor,
       									  float rightMotor )
		{
			return true;
		}
			
		public static GamePadState GetState ( PlayerIndex playerIndex )
		{
			return new GamePadState();
		}
			
		public static GamePadState GetState ( PlayerIndex playerIndex,
       										  GamePadDeadZone deadZoneMode )
		{
			return new GamePadState();	
		}
	}
}

