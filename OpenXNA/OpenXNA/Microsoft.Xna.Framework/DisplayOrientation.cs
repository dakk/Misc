using System;

namespace Microsoft.Xna.Framework
{
	public enum DisplayOrientation
	{
		Default,			/* The default display orientation */
		LandscapeLeft,		/* The display is rotated counterclockwise 90 degrees into a 
								landscape orientation, where the width is greater than the height */
		LandscapeRight,		/* The display is rotated clockwise 90 degrees into a landscape orientation, 
								where the width is greater than the height */
		Portrait			/* The orientation is a portrait, where the height is greater than the width */
	}
}

