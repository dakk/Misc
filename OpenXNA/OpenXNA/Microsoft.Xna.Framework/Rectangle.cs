using System;
namespace Microsoft.Xna.Framework
{
	public struct Rectangle
	{
		public int X { set; get; }
		public int Y { set; get; }
		public int Width { set; get; }
		public int Height { set; get; }
		
		public Rectangle ( int x, int y, int width, int height ) : this()
		{
			this.X = x;
			this.Y = y;
			this.Width = width;
			this.Height = Height;
		}
	}
}

