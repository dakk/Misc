using System;

namespace Microsoft.Xna.Framework.Input.Touch
{
	public enum GestureType
	{
		None,		// Represents no gestures.
		Tap,		// The user briefly touched a single point on the screen.
		DoubleTap,  // The user tapped the screen twice in quick succession. This always is preceded by a Tap gesture. If the time between taps is too great to be considered a DoubleTap, two Tap gestures will be generated instead.
		Hold,		// The user touched a single point on the screen for approximately one second. This is a single event, and not continuously generated while the user is holding the touchpoint.
		HorizontalDrag,	// The user touched the screen, and then performed a horizontal (left to right or right to left) gesture.
		VerticalDrag,	// The user touched the screen, and then performed a vertical (top to bottom or bottom to top) gesture.
		FreeDrag,		// The user touched the screen, and then performed a free-form drag gesture.
		Pinch,			// The user touched two points on the screen, and then converged or diverged them. Pinch behaves like a two-finger drag. When this gesture is enabled, it takes precedence over drag gestures while two fingers are down.
		Flick,			// The user performed a touch combined with a quick swipe of the screen. Flicks are positionless. The velocity of the flick can be retrieved by reading the Delta member of GestureSample.
		DragComplete,	// A drag gesture (VerticalDrag, HorizontalDrag, or FreeDrag) was completed. This signals only completion. No position or delta data is valid for this sample.
		PinchComplete	// A pinch operation was completed. This signals only completion. No position or delta data is valid for this sample.
	}
}

