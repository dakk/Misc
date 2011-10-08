using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Input;

/*using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Input.Touch;
using Microsoft.Xna.Framework.Media;
*/
namespace XAlchemist
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        private AlchemistEngine engine;
        private Texture2D[] blocks = new Texture2D[15];
        private Texture2D background;
        private Texture2D gameover;
        
		private bool[] keyLock = new bool[4];
        private DateTime startTime;
        /*private SpriteFont font;
        private SpriteFont font2;
        */
		private int sepX;
        private int sepY;
        private TimeSpan endTime;
        private enum GameState { PRESENTATION, MAIN, PLAY, OVER, EXIT };
        private GameState gameState;

        public Game1()
        {
            //this.Window.Title = "XAlchemist";
            graphics = new GraphicsDeviceManager(this);
            engine = new AlchemistEngine();

            Content.RootDirectory = "Content";

            for (int x = 0; x < 4; x++) keyLock[x] = false;
            gameState = GameState.MAIN;

            graphics.PreferredBackBufferHeight = 434;
            graphics.PreferredBackBufferWidth = 446;
			
        }

        /// <summary>
        ///  Allows the game to perform any initialization it needs to before starting to run.
        ///  This is where it can query for any required services and load any non-graphic
        ///  related content.  Calling base.Initialize will enumerate through any components
        ///  and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            engine.newGame();
            startTime = DateTime.Now;

            base.Initialize();


            sepX = graphics.PreferredBackBufferWidth / 2 - 446 / 2;
            sepY = graphics.PreferredBackBufferHeight / 2 - 434 / 2;
        }

        /// <summary>
        ///  LoadContent will be called once per game and is the place to load
        ///  all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);


            for (int i = 0; i < 15; i++)
            {
                string name = "p" + (i + 1);
                blocks[i] = Content.Load<Texture2D>(name);
            }


            background = Content.Load<Texture2D>("background");
            gameover = Content.Load<Texture2D>("gameover");

        }


        /// <summary>
        ///  UnloadContent will be called once per game and is the place to unload
        ///  all content.
        /// </summary>
        protected override void UnloadContent()
        {
        }

        /// <summary>
        ///  Allows the game to run logic such as updating the world,
        ///  checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {

            // Update base game
            base.Update(gameTime);

        }

        /// <summary>
        ///  This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Red);

            spriteBatch.Begin();


            // Draw the background 
            spriteBatch.Draw(background, new Vector2(sepX, sepY), Color.White);

    
            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
