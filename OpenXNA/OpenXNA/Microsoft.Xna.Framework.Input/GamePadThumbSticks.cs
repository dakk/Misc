using System;

namespace Microsoft.Xna.Framework.Input
{
	public struct GamePadThumbSticks
	{
		public Vector2 Left { get; set; }
		public Vector2 Right { get; set; }
		
		public GamePadThumbSticks ( Vector2 leftThumbstick, Vector2 rightThumbstick ) : this()
		{
			Left = leftThumbstick;
			Right = rightThumbstick;			
		}
	}
}

