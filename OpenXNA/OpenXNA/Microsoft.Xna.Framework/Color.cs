using System;
using Microsoft.Xna.Framework.Graphics.PackedVector;

namespace Microsoft.Xna.Framework
{
	public struct Color : IPackedVector<uint>, IPackedVector, IEquatable<Color>
	{
		public static Color Black = new Color(0, 0, 0);
		public static Color White = new Color(255, 255, 255);
		public static Color Red = new Color(255, 0, 0);
		
		public byte R { get; set; }
		public byte G { get; set; }
		public byte B { get; set; }
		public byte A { get; set; }
		
		public Color(Int32 r, Int32 g, Int32 b, Int32 a) : this()
		{
			R = (byte) r;
			G = (byte) g;
			B = (byte) b;
			A = (byte) a;
		}
		
		public Color(Int32 r, Int32 g, Int32 b) : this(r, g, b, 255)
		{
		}
		


		public bool Equals(Color c)
		{
			if((c.A == A) && (c.G == G) && (c.B == B) && (c.R == R))
				return true;
			return false;
		}
	}
}

