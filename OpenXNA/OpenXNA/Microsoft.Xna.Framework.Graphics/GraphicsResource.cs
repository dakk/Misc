using System;

namespace Microsoft.Xna.Framework.Graphics
{
	public abstract class GraphicsResource : IDisposable
	{
		public GraphicsDevice GraphicsDevice { get; set; }
		
		public GraphicsResource ()
		{
		}
		
		/* Immediately releases the unmanaged resources used by this object */
		public void Dispose ()
		{
			
		}
		
	}
}

