using System;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
namespace TestInput
{
    static class Program
    {
        static void Main(string[] args)
        {
            GraphicsDevice dev = new GraphicsDevice(new GraphicsAdapter(), 
			                                        new GraphicsProfile(), 
			                                        new PresentationParameters());
			while(true)
			{
				MouseState mstate = Mouse.GetState();
				KeyboardState state = Keyboard.GetState();
				
				Console.WriteLine(mstate.X);
				Console.WriteLine(mstate.Y);
				if(state.IsKeyDown(Keys.A))
					Console.WriteLine("a");
			}
        }
    }
}

