using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using System;

namespace Microsoft.Xna.Framework
{
	public class Game : IDisposable
	{
		public TimeSpan InactiveSleepTime				{ get; set; }
		public TimeSpan TargetElapsedTime				{ get; set; }
		public GameComponentCollection Components		{ get; set; } //not set
		public GameWindow Window 						{ get; set; } //not set
		public GameServiceContainer Services			{ get; set; } //not set
		public LaunchParameters LaunchParameters		{ get; set; } //not set
		public bool IsMouseVisible						{ get; set; }
		public bool IsFixedTimeStep						{ get; set; }
		public bool IsActive							{ get; set; } //not set
		public GraphicsDevice GraphicsDevice { get; set; }
		public ContentManager Content { get; set; }
		
		public Game ()
		{
			Content = new ContentManager();
			GraphicsDevice = new GraphicsDevice(new GraphicsAdapter(), 
			                                    new GraphicsProfile(), 
			                                    new PresentationParameters());
			Window = new SdlGameWindow();
			
			IsMouseVisible = false;
			IsFixedTimeStep = true;
			IsActive = true;
			
			InactiveSleepTime = new TimeSpan(0);
			TargetElapsedTime = new TimeSpan(0);
		}
		
		/* Immediately releases the unmanaged resources used by this object */
		public void Dispose ()
		{
			
		}
		
		
		/* Exits the game */
		public void Exit ()
		{
		}
		
		
		/* Resets the elapsed time counter */
		public void ResetElapsedTime ()
		{
		}
		
		/* Initialize the game, begin running the game loop, and start processing events for the game */
		public void Run ()
		{
			GameTime gt = new GameTime();
			LoadContent();
			Initialize();
			
			while(true)
			{
				Update(gt);
				Draw(gt);
			}
		}
		
		/* Run the game through what would happen in a single tick of the game clock; 
		 * this method is designed for debugging only */
		public void RunOneFrame ()
		{
		}
		
		/* Prevents calls to Draw until the next Update */
		public void SuppressDraw ()
		{
		}
		
		/* Updates the game's clock and calls Update and Draw */
		public void Tick ()
		{
		}
		
		protected virtual void Initialize()
		{
		}
		
		protected virtual void LoadContent ()
		{
		}
		
		protected virtual void UnloadContent ()
		{
		}
		
		protected virtual void Update(GameTime gameTime)
		{
		}
		
		protected virtual void Draw(GameTime gameTime)
		{
		}
	}
}

