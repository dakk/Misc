using System;
using Tao.OpenGl;
using Tao.DevIl;

using Microsoft.Xna.Framework.Graphics;

namespace Microsoft.Xna.Framework.Content
{
	public class ContentManager : IDisposable
	{
		public String RootDirectory { get; set; }
		public IServiceProvider ServiceProvider { get; set; }
		
		
		public ContentManager ( )
		{
		}
		
		public ContentManager ( IServiceProvider serviceProvider )
		{
			ServiceProvider = serviceProvider;
		}
		
		public ContentManager ( IServiceProvider serviceProvider, string rootDirectory )
		{
			RootDirectory = rootDirectory;	
			ServiceProvider = serviceProvider;
		}
		
		public void Dispose()
		{
		}
		
		
		public virtual T Load<T> ( string assetName )
		{
			string path = RootDirectory + "/" + assetName;
			
			Console.Write("ContentManager::Load '"+path+"' ");
			
			/* Load a texture as an opengl texture */
			if( typeof(T) == typeof(Texture2D) )
			{
				int id;
				
				Console.Write("(Texture2D)... ");
				
				Il.ilInit();
				Il.ilGenImages(1, out id);
				Il.ilBindImage(id);
				if( ( Il.ilLoadImage(path) ) && 
				    (Il.ilConvertImage(Il.IL_RGB, Il.IL_UNSIGNED_BYTE) ))
				{
					uint image;
				
    				//Il.ilConvertImage(Il.IL_RGB, Il.IL_UNSIGNED_BYTE);
					
					Gl.glGenTextures(1, out image);
    				Gl.glBindTexture(Gl.GL_TEXTURE_2D, image);
					Gl.glTexParameteri( Gl.GL_TEXTURE_2D, 
					                   	Gl.GL_TEXTURE_MAG_FILTER, 
					                   	Gl.GL_LINEAR );
					Gl.glTexParameteri( Gl.GL_TEXTURE_2D, 
					                   	Gl.GL_TEXTURE_MIN_FILTER, 
					                   	Gl.GL_LINEAR );


					Gl.glTexImage2D(Gl.GL_TEXTURE_2D, 0, 
					                Il.ilGetInteger(Il.IL_IMAGE_BPP), 
					                Il.ilGetInteger(Il.IL_IMAGE_WIDTH),
      								Il.ilGetInteger(Il.IL_IMAGE_HEIGHT), 0, 
					                Il.ilGetInteger(Il.IL_IMAGE_FORMAT), 
					                Gl.GL_UNSIGNED_BYTE,
					                Il.ilGetData());
					
					Texture2D tx = new Texture2D();
					tx.Id = (int) image;
					
					Il.ilDeleteImages(1, ref id);
					
					Console.Write("Done\n");
					
					object ob = tx;
					return (T) ob;
				}
				else 
				{
					Il.ilDeleteImages(1, ref id);
					Console.Write("Error\n");
				}
			}
			else 
			{
				Console.Write("(Unknown type)... Error\n");
			}
			
			return default(T);
		}
		
		
		/* Dispose all data */
		public virtual void Unload ()
		{
			
		}
		
		protected T ReadAsset<T> ( string assetName, 
		                           Action<IDisposable> recordDisposableObject )
		{
			return default(T);
		}

		/*
		protected virtual Stream OpenStream ( string assetName )
		{
		}
		*/
	}

}

