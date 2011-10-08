using System;

namespace Microsoft.Xna.Framework
{
	public struct Vector2 : IEquatable<Vector2>
	{
		public float X;
		public float Y;
		
		public Vector2 (float value)
		{
			X = Y = value;
		}
		
		public Vector2 (float x, float y)
		{
			X = x;
			Y = y;
		}
				
		
		/* Determines whether the specified Object is equal to the Vector2 */
		public bool Equals (Vector2 v)
		{
			if((v.X != X) || (v.Y != Y))
				return false;
			return true;
		}
		
		
		/* Adds two vectors */
		public static void Add (	ref Vector2 v1,
         							ref Vector2 v2,
							        out Vector2 result)
		{
			result.X = v1.X + v2.X;
			result.Y = v1.Y + v2.Y;
		}
		
		/* Adds two vectors */
		public static Vector2 Add (Vector2 v1, Vector2 v2)
		{
			return new Vector2(v1.X + v2.X, v1.Y + v2.Y);
		}
		
		/* Calculates the length of the vector */
		public float Length ()
		{
			return (float) Math.Sqrt(Math.Pow((double) X, 2.0) + Math.Pow((double) Y, 2.0));
		}

	}
	
	
}

