using System;

namespace Microsoft.Xna.Framework
{
	public struct Point : IEquatable<Point>
	{
		public int X ;
		public int Y;
		
		public Point ( int x, int y ) : this()
		{
			X = x;
			Y = y;
		}
		
		public bool Equals( Point p)
		{
			if((X == p.X) && (Y == p.Y))
				return true;
			return false;	
		}
	}
}

