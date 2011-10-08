using System;

namespace Microsoft.Xna.Framework
{
	public class GameTime
	{
		public TimeSpan ElapsedGameTime		{ get; set; }
		public bool IsRunningSlowly			{ get; set; }
		public TimeSpan TotalGameTime		{ get; set; }
		
		public GameTime ()
		{
		}
	}
}

