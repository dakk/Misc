using System;

namespace OpenBoard
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        static void Main(string[] args)
        {
            using (Board b = new Board())
            {
                b.Run();
            }
        }
    }
}

