using System;
using Tao.Sdl;

namespace Microsoft.Xna.Framework.Graphics
{
	public class Texture2D : Texture
	{
		public IntPtr Data { get; set; }
		public int Id { get; set; }
		public int Width { get; set; }
		public int Height { get; set; }
	
		public Texture2D ()
		{
		}
		
		public void GetData<T> (T[] data )
		{
		}
	}
}

