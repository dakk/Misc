using System;

namespace Microsoft.Xna.Framework.Input
{
	public struct GamePadCapabilities
	{
		public GamePadType GamePadType { get; set; }
		public bool HasAButton { get; set; }
		public bool HasBackButton { get; set; }
		public bool HasBButton { get; set; }
		public bool HasBigButton { get; set; }
		public bool HasDPadDownButton { get; set; }
		public bool HasDPadLeftButton { get; set; }
		public bool HasDPadRightButton { get; set; }
		public bool HasDPadUpButton { get; set; }
		public bool HasLeftYThumbStick { get; set; }
		public bool HasRightShoulderButton { get; set; }
		public bool HasRightStickButton { get; set; }
		public bool HasRightTrigger { get; set; }
		public bool HasRightVibrationMotor { get; set; }
		public bool HasRightXThumbStick { get; set; }
		public bool HasRightYThumbStick { get; set; }
		public bool HasStartButton { get; set; }
		public bool HasVoiceSupport { get; set; }
		public bool HasXButton { get; set; }
		public bool HasYButton { get; set; }
		public bool IsConnected { get; set; }
		public bool HasLeftXThumbStick { get; set; }
		public bool HasLeftVibrationMotor { get; set; }
		public bool HasLeftTrigger { get; set; }
		public bool HasLeftStickButton { get; set; }
		public bool HasLeftShoulderButton { get; set; }
	}
}

