using Tao.Sdl;
using Tao.OpenGl;
using Microsoft.Xna.Framework.Graphics;
using System;

namespace Microsoft.Xna.Framework
{
	/* Performs primitive-based rendering, creates resources, handles system-level 
	 * variables, adjusts gamma ramp levels, and creates shaders */
	public class GraphicsDevice : IDisposable
	{
		public IntPtr Screen { get; set; }
		
		public GraphicsDevice (	GraphicsAdapter adapter,
         						GraphicsProfile graphicsProfile,
         						PresentationParameters presentationParameters)
		{
			Screen = Sdl.SDL_SetVideoMode(800, 600, 32, 
			                              Sdl.SDL_SWSURFACE |
			                              Sdl.SDL_OPENGL | 
			                              Sdl.SDL_GL_DOUBLEBUFFER | 
			                              Sdl.SDL_ANYFORMAT);
			Sdl.SDL_GL_SetAttribute ( Sdl.SDL_GL_DOUBLEBUFFER, 1 );
			
			
			Gl.glEnable( Gl.GL_TEXTURE );
			Gl.glEnable( Gl.GL_TEXTURE_2D );
			 
		    Gl.glShadeModel( Gl.GL_SMOOTH );
		    Gl.glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
		    Gl.glClearDepth( 1.0f );
		    Gl.glEnable( Gl.GL_DEPTH_TEST );
		    Gl.glDepthFunc( Gl.GL_LEQUAL );
		    Gl.glHint( Gl.GL_PERSPECTIVE_CORRECTION_HINT, Gl.GL_NICEST );
			
			Resize(800, 600);
		}
		
		
		public void Resize ( int x, int y )
		{		
		    Gl.glViewport( 0, 0, x, y);
		    Gl.glMatrixMode( Gl.GL_PROJECTION );
		    Gl.glLoadIdentity( );
		    Glu.gluPerspective( 45.0f, ((float) x / (float) y), 0.1f, 100.0f );
		    Gl.glMatrixMode( Gl.GL_MODELVIEW );
		    Gl.glLoadIdentity( );			
		}
		
		public void Dispose ()
		{
			
		}
		
		public void Clear(Color c)
		{
			Gl.glClearColor( c.R, c.G, c.B, c.A );
			Gl.glClear(Gl.GL_COLOR_BUFFER_BIT | Gl.GL_DEPTH_BUFFER_BIT);
		}
	}
}

