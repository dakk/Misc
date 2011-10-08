using System;

namespace Microsoft.Xna.Framework
{
	public class GameServiceContainer : IServiceProvider
	{
		public GameServiceContainer ()
		{
		}
		
		public object GetService(System.Type type)
		{
			return this;
		}
	}
}

