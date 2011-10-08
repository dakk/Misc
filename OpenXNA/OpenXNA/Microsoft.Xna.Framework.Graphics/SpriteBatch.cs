using System;
using Tao.Sdl;
using Tao.OpenGl;

namespace Microsoft.Xna.Framework.Graphics
{
	public class SpriteBatch : GraphicsResource
	{
	
		public SpriteBatch ()
		{
		}

		public SpriteBatch (GraphicsDevice graphicsDevice)
		{
			GraphicsDevice = graphicsDevice;
		}
		
		/* Flushes the sprite batch and restores the device state to how it 
		 * was before Begin was called */
		public void End ()
		{
			Sdl.SDL_GL_SwapBuffers();
		}
		
		
		public void Draw ( Texture2D texture, 
		                   Rectangle destinationRectangle,
		                   Color color )
		{
			Rectangle d = destinationRectangle;
			
			Gl.glLoadIdentity();
			
 			Gl.glTranslatef(0.0f,0.0f,-7.0f);
			Gl.glBindTexture( Gl.GL_TEXTURE_2D, texture.Id );
			Gl.glBegin( Gl.GL_QUADS );			
			  Gl.glNormal3f( 0.0f, 0.0f, 1.0f );
			
			/*Gl.glTexCoord2f( 1.0f, 0.0f ); Gl.glVertex3f( 4 - d.X * 8 / 800, 4.0f,  0.0f );
		      Gl.glTexCoord2f( 0.0f, 0.0f ); Gl.glVertex3f(  4.0f, 4.0f,  0.0f );
		      Gl.glTexCoord2f( 0.0f, 1.0f ); Gl.glVertex3f(  4.0f, 4 - d.Y * 8 / 600,  0.0f );
		      Gl.glTexCoord2f( 1.0f, 1.0f ); Gl.glVertex3f( 4 - d.X * 8 / 800, 4 - d.Y * 8 / 600,  0.0f );
			*/
		      Gl.glTexCoord2f( 0.0f, 0.0f ); Gl.glVertex3f( -4.0f, 3.0f,  0.0f );
		      Gl.glTexCoord2f( 1.0f, 0.0f ); Gl.glVertex3f(  4.0f, 3.0f,  0.0f );
		      Gl.glTexCoord2f( 1.0f, 1.0f ); Gl.glVertex3f(  4.0f, -3.0f,  0.0f );
		      Gl.glTexCoord2f( 0.0f, 1.0f ); Gl.glVertex3f( -4.0f, -3.0f,  0.0f );
			Gl.glEnd();
		}
		
		
		public void Draw ( Texture2D texture, 
		                   Vector2 position,
		                   Color color )
		{
			Draw(texture, 
			     new Rectangle( (int) position.X, (int) position.Y, 
			                    texture.Width, texture.Height),
			     color);
		}
		
		
		public void Begin ()
		{
		}
		
	}
}

