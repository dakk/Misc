using Tao;
using Tao.Sdl;
using Microsoft.Xna.Framework;
using System;

namespace Microsoft.Xna.Framework.Graphics
{
	/* Handles the configuration and management of the graphics device */
	public class GraphicsDeviceManager : IGraphicsDeviceService, IDisposable, IGraphicsDeviceManager
	{
		public int PreferredBackBufferHeight			{ get; set; }
		public bool PreferMultiSampling					{ get; set; }
		public int PreferredBackBufferWidth				{ get; set; }
		
		
		public GraphicsDeviceManager (Game game)
		{
			Sdl.SDL_Init(Sdl.SDL_INIT_VIDEO);			
		}
		
		public void Dispose()
		{
			Sdl.SDL_Quit();
		}
	}
}

