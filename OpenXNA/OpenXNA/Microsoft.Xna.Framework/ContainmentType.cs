using System;

namespace Microsoft.Xna.Framework
{
	public enum ContainmentType
	{
		Contains,	// Indicates that one bounding volume completely contains the other.
		Disjoint,	//Indicates there is no overlap between the bounding volumes.
		Intersects	//Indicates that the bounding volumes partially overlap.
	}
}

