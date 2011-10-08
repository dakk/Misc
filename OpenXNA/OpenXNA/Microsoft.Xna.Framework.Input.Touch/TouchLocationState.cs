using System;

namespace Microsoft.Xna.Framework.Input.Touch
{
	public enum TouchLocationState
	{
		Invalid, //	This touch location position is invalid. Typically, you will encounter this state when a new touch location attempts to get the previous state of itself.
		Moved,	 //	This touch location position was updated or pressed at the same position.
		Pressed, //	This touch location position is new.
		Released //	This touch location position was released.
	}
}

