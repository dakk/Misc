using System;

namespace Microsoft.Xna.Framework
{
	public enum CurveContinuity
	{
		Smooth,	//Interpolation can be used between this CurveKey and the next.
		Step	//Interpolation cannot be used between this CurveKey and the next. Specifying a position between the two points returns this point.
	}
}

