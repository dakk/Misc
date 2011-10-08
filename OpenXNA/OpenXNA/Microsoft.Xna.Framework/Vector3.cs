using System;

namespace Microsoft.Xna.Framework
{
	public struct Vector3 : IEquatable<Vector3>
	{
		public float X;
		public float Y;
		public float Z;
		
		public Vector3 (float value)
		{
			X = Y = Z = value;
		}
		
		public Vector3 (float x, float y, float z)
		{
			X = x;
			Y = y;
			Z = z;
		}
				
		
		public bool Equals (Vector3 v)
		{
			if((v.X != X) || (v.Y != Y) || (v.Z != Z))
				return false;
			return true;
		}
		
		
		/* Adds two vectors */
		public static void Add (	ref Vector3 v1,
         							ref Vector3 v2,
							        out Vector3 result)
		{
			result.X = v1.X + v2.X;
			result.Y = v1.Y + v2.Y;
			result.Z = v1.Z + v2.Z;
		}
		
		/* Adds two vectors */
		public static Vector3 Add (Vector3 v1, Vector3 v2)
		{
			return new Vector3(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
		}
		
		/* Calculates the length of the vector */
		public float Length ()
		{
			return 0.0f;
			//return (float) Math.Sqrt(Math.Pow((double) X, 2.0) + Math.Pow((double) Y, 2.0));
		}

	}
}

