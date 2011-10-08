using System;

namespace Microsoft.Xna.Framework.Graphics
{
	public class Effect : GraphicsResource
	{
		//public EffectTechnique CurrentTechnique { get; set; }
		//public EffectParameterCollection Parameters { get; }
		//public EffectTechniqueCollection Techniques { get; }
					
		public Effect (GraphicsDevice graphicsDevice, byte[] effectCode)
		{
		}
		
		protected Effect (Effect cloneSource)
		{
		}
		
		public Effect()
		{
		}
		
		//protected override void Dispose ( bool )
		
		public virtual Effect Clone ()
		{
			return default(Effect);
		}
		
		protected internal virtual void OnApply ()
		{
		}
	}
}

