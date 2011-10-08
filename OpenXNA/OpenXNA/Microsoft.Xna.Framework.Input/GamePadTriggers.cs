using System;

namespace Microsoft.Xna.Framework.Input
{
	public struct GamePadTriggers
	{
		public float Left { get; set; }
		public float Right { get; set; }
		
		public GamePadTriggers ( float leftTrigger, float rightTrigger ) : this()
		{
			Left = leftTrigger;
			Right = rightTrigger;
		}
	}
}

