using System;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;



namespace TestInput
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        private Texture2D background;
        private Texture2D gameover;
        


        public Game1()
        {
           Content.RootDirectory = "Content";			
        }

        /// <summary>
        ///  Allows the game to perform any initialization it needs to before starting to run.
        ///  This is where it can query for any required services and load any non-graphic
        ///  related content.  Calling base.Initialize will enumerate through any components
        ///  and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {


            base.Initialize();


        }

        /// <summary>
        ///  LoadContent will be called once per game and is the place to load
        ///  all of your content.
        /// </summary>
        protected override void LoadContent()
        {
           //Content.RootDirectory = "Content";	
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

            base.Draw(gameTime);
        }
    }



    static class Program
    {
        static void Main(string[] args)
        {
         	Game1 g = new Game1();
			g.Run();
        }
    }
}
