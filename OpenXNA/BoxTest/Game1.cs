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
namespace BoxTest
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
		Vector3[] cube;

        public Game1()
        {
            this.Window.Title = "BoxTest";
            graphics = new GraphicsDeviceManager(this);


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
           
			
			cube = new Vector3[6];

			//TopLeft
			cube[0] = new Vector3(-1f, 1f, 0.0f);
			//BottomLeft
			cube[1] = new Vector3(-1f, -1f, 0.0f);
			//TopRight
			cube[2] = new Vector3(1f, 1f, 0.0f);
			//BottomLeft
			cube[3] = new Vector3(-1f, -1f, 0.0f);
			//BottomRight
			cube[4] = new Vector3(1f, -1f, 0.0f);
			//TopRight
			cube[5] = new Vector3(1f, 1f, 0.0f);
			
            base.Initialize();
        }

        /// <summary>
        ///  LoadContent will be called once per game and is the place to load
        ///  all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
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
            //spriteBatch.Draw(background, new Vector2(sepX, sepY), Color.White);

    
            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
