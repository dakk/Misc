using Tao.Sdl;
using System;

namespace Microsoft.Xna.Framework
{
	public abstract class GameWindow
	{
		public abstract bool AllowUserResizing { get; set; }
		
		public abstract string Title { get; set; }
		public abstract string ScreenDeviceName { get; }
		public abstract IntPtr Handle { get; }
		public abstract DisplayOrientation CurrentOrientation { get; }
		public abstract Rectangle ClientBounds { get; }
		
		public GameWindow ()
		{
		}
		
		public abstract void EndScreenDeviceChange ( string screenDeviceName,
         											 int clientWidth,
											         int clientHeight);
		
		public void EndScreenDeviceChange ( string screenDeviceName )
		{
		}
		
		public abstract void BeginScreenDeviceChange ( bool willBeFullScreen );
	}
	
	
	public class SdlGameWindow : GameWindow
	{
		private string m_Title;
		
		public override string Title
		{
        	get
        	{
        	    return m_Title;
        	}
        	set
        	{
        	    m_Title = value;
				Sdl.SDL_WM_SetCaption(Title, " ");
        	}
    	}	
		
		public override bool AllowUserResizing { get; set; }
		
		public override string ScreenDeviceName 
							{ get { return ScreenDeviceName; } }
		public override IntPtr Handle 
							{ get { return Handle; } }
		public override DisplayOrientation CurrentOrientation 
							{ get { return CurrentOrientation; } }
		public override Rectangle ClientBounds 
							{ get{ return ClientBounds; } }
		
		public SdlGameWindow ()
		{
			Title = "Untitled";
			Sdl.SDL_WM_SetCaption(Title, " ");
		}
		
		public override void EndScreenDeviceChange ( string screenDeviceName,
         											 int clientWidth,
											         int clientHeight)
		{
		}
		

		
		public override void BeginScreenDeviceChange ( bool willBeFullScreen )
		{
		}
		
	}

}

