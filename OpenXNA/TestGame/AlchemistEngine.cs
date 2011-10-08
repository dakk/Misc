#region License
/*
 * 
 * 
 */
#endregion License
using System;

namespace XAlchemist
{
	public class AlchemistEngine
	{
        private int[,] m_Grid;
        private int[] m_Block;
        private int[] m_NextBlock;
		private int m_BlockPosition;
		private int m_BlockRotation;
		private int m_Score;
		private bool m_Over;
		private bool m_CanMove;
		private int m_Limit;
        private Random random;
		
		

		/// <summary>
		///  Create the engine
		/// </summary>
		public AlchemistEngine()
		{
			m_Grid = new int [8,8];

            m_Block = new int[2];
            m_NextBlock = new int[2];
			random = new Random();
			m_Limit = 2;
		}
		
		

		
		/// <summary>
		///  Create new game
		/// </summary>
		public void newGame()
		{
			m_Over = false;
			m_Score = 0;
			m_CanMove = true;
			m_Limit = 4;
			m_BlockPosition = 3;
            m_BlockRotation = 0;

            for (int x = 0; x < m_Grid.GetLength(0); x++)
                for (int y = 0; y < m_Grid.GetLength(1); y++)
                    m_Grid[x, y] = 0;

            m_NextBlock[0] = random.Next(1, m_Limit);
            m_NextBlock[1] = random.Next(1, m_Limit);
			generateBlock();
		}
		
		
		/// <summary>
		///  Return true if the game is over
		/// </summary>
		public bool ifOver()
		{
			return m_Over;
		}
		
		
		/// <summary>
		///  Return the block
		/// </summary>
		public int [] getBlock()
		{
			return m_Block;
		}


        /// <summary>
        ///  Return the next block
        /// </summary>
        public int[] getNextBlock()
        {
            return m_NextBlock;
        }
		
		
		/// <summary>
		///  Return the grid
		/// </summary>
		public int [,] getGrid()
		{
			return m_Grid;
		}
		
		
		/// <summary>
		///  Return block position
		/// </summary>
		public int getBlockPosition()
		{
			return m_BlockPosition;
		}
		
		/// <summary>
		/// </summary>
		public int getX()
		{
            return m_Grid.GetLength(0);
		}
		
		/// <summary>
		/// </summary>
		public int getY()
		{
            return m_Grid.GetLength(1);
		}

        /// <summary>
        ///  Return block rotation
        /// </summary>
        public int getBlockRotation()
        {
            return m_BlockRotation;
        }


        /// <summary>
        ///  Return score
        /// </summary>
        public int getScore()
        {
            return m_Score;
        }
		

		
		
		/// <summary>
		///  Generate new block
		/// </summary>
		private void generateBlock()
		{
            m_Block[0] = m_NextBlock[0];
            m_Block[1] = m_NextBlock[1];
			m_NextBlock[0] = random.Next(1, m_Limit);
            m_NextBlock[1] = random.Next(1, m_Limit);
		}
		
		
		
		/// <summary>
		///  Put the block in the grid
		/// </summary>
		public void Down()
		{
			if(!m_CanMove)
				return;


            switch (m_BlockRotation)
            {
                case 0:
                    m_Grid[m_BlockPosition, 0] = m_Block[0];
                    m_Grid[m_BlockPosition + 1, 0] = m_Block[1];

                    break;
                case 1:
                    m_Grid[m_BlockPosition, 1] = m_Block[1];
                    m_Grid[m_BlockPosition, 0] = m_Block[0];

                    break;
                case 2:
                    m_Grid[m_BlockPosition, 0] = m_Block[1];
                    m_Grid[m_BlockPosition + 1, 0] = m_Block[0];

                    break;
                case 3:
                    m_Grid[m_BlockPosition, 0] = m_Block[1];
                    m_Grid[m_BlockPosition, 1] = m_Block[0];

                    break;
            }

            m_CanMove = false;
			
			generateBlock();
		}


        /// <summary>
        ///  Rotate the block to the right
        /// </summary>
        public void Rotate()
        {
            if (m_BlockPosition == m_Grid.GetLength(0) - 1)
                return;

            if (m_BlockRotation < 3)
                m_BlockRotation++;
            else
                m_BlockRotation = 0;
        }
		

		/// <summary>
		///  Move the block to the right
		/// </summary>
		public void Right()
        {
            if (m_BlockPosition < m_Grid.GetLength(0) - 2)
                m_BlockPosition++;
            if ((m_BlockPosition < m_Grid.GetLength(0) - 1) && (m_BlockRotation != 0) && (m_BlockRotation != 2))
                m_BlockPosition++;		
		}
		
		
		
		/// <summary>
		///  Move the block to the left
		/// </summary>
		public void Left()
		{
			if(m_BlockPosition > 0)
				m_BlockPosition--;
		}
		
		
		
		/// <summary>
		///  Explode all blocks near (x, y) with value
		/// </summary>
		public void Explode(int x, int y, int value)
		{
			if(x < 7)
				if(m_Grid[x+1,y] == value)
				{
					m_Grid[x+1,y] = 0;
					Explode(x+1, y, value);
				}

			if(x > 0)
				if(m_Grid[x-1,y] == value)
				{
					m_Grid[x-1,y] = 0;
					Explode(x-1, y, value);
				}

			if(y < 7)		
				if(m_Grid[x,y+1] == value)
				{
					m_Grid[x,y+1] = 0;
					Explode(x, y+1, value);
				}

			if(y > 0)
				if(m_Grid[x,y-1] == value)
				{
					m_Grid[x,y-1] = 0;
					Explode(x, y-1, value);
				}
		}
		
		/// <summary>
		///  Update the grid
		/// </summary>
		public bool Update()
		{
			bool explosion = false;

            m_CanMove = true;
			
			// Shift down all blocks if it's possible
			for(int x = 7; x >= 0; x--)
			{
				for(int y = 7; y >= 1; y--)
				{
					if((m_Grid[x,y-1] != 0) && (m_Grid[x,y] == 0))
					{
						m_Grid[x,y] = m_Grid[x,y-1];
						m_Grid[x,y-1] = 0;
                        m_CanMove = false;
					}
				}
			}
			
			
			// Explode all combinations
            if (m_CanMove)
            {
                for (int x = 6; x >= 1; x--)
                {
                    for (int y = 6; y >= 1; y--)
                    {
                        if ((m_Grid[x, y] != 0) && (m_Grid[x, y] < 13))
                        {
                            int t = m_Grid[x, y];

                            if (((m_Grid[x, y + 1] == t) && (m_Grid[x, y - 1] == t)) ||
                                ((m_Grid[x + 1, y] == t) && (m_Grid[x - 1, y] == t)) ||
                                 ((m_Grid[x + 1, y] == t) && (m_Grid[x, y + 1] == t)) ||
                                 ((m_Grid[x - 1, y] == t) && (m_Grid[x, y - 1] == t)) ||
                                 ((m_Grid[x - 1, y] == t) && (m_Grid[x, y + 1] == t)) ||
                                 ((m_Grid[x + 1, y] == t) && (m_Grid[x, y - 1] == t)))
                             {
                                  if (t < 12)
                                      m_Grid[x, y]++;
                                  else
                                      m_Grid[x, y] = 0;

                                  Explode(x, y, t);
                                  explosion = true;
                                  m_Score += (t * 10) + t * t;

                                  if (t > m_Limit)
                                      m_Limit++;

                                  m_CanMove = false;
                              }
                        }
                    }
                }

                if(m_CanMove)
                for (int x = 1; x < 6; x++)
                {
                    if ((m_Grid[x, 7] == 0) || (m_Grid[x, 7] >= 13)) continue;

                    int t = m_Grid[x, 7];

                    if ((m_Grid[x - 1, 7] == t) && (m_Grid[x + 1, 7] == t))
                    {
                        if (t < 12)
                            m_Grid[x, 7]++;
                        else
                            m_Grid[x, 7] = 0;

                        Explode(x, 7, t);
                        explosion = true;
                        m_Score += (t * 10) + t * t;

                        if (t > m_Limit)
                            m_Limit++;

                        m_CanMove = false;
                    }
                }

                if(m_CanMove)
                for (int y = 1; y < 6; y++)
                {
                    for (int x = 0; x < 7; x += 7)
                    {
                        if ((m_Grid[x, y] == 0) || (m_Grid[x, y] >= 13)) continue;

                        int t = m_Grid[x, y];

                        if ((m_Grid[x, y - 1] == t) && (m_Grid[x, y + 1] == t))
                        {
                            if (t < 12)
                                m_Grid[x, 7]++;
                            else
                                m_Grid[x, 7] = 0;

                            Explode(x, 7, t);
                            explosion = true;
                            m_Score += (t * 10) + t * t;

                            if (t > m_Limit)
                                m_Limit++;

                            m_CanMove = false;
                        }
                    }
                }
            }

            if (m_CanMove)
            {
                for (int x = 0; x < m_Grid.GetLength(0); x++)
                    if (m_Grid[x, 0] != 0)
                        m_Over = true;
            }
            return explosion;

				
	/*		for x in xrange(len(self.grid)-1,0,-1):
				for y in xrange(0, len(self.grid[0])):
					s = 0
					for a in xrange(len(self.grid)): s += self.grid[a][y]

					if self.grid[x][y] == 0 and s > 0:
						for a in xrange(x, 0, -1):
							if self.grid[a-1][y] != 0: 
								self.grid[a][y] = self.grid[a-1][y]
								self.grid[a-1][y] = 0
								md = True
			self.mov = md

			# Controlliamo se possiamo far esplodere qualcosa :P
			if not self.mov:
				for x in xrange(-1,len(self.grid)-1):		
					for y in xrange(-1,len(self.grid[0])-1):
						# La pressa
						if self.grid[x][y] == 15 and x == len(self.grid)-2:
								self.grid[len(self.grid)-2][y] = 0
								self.grid[len(self.grid)-1][y] = 0

						elif self.grid[x][y] == 15:
							if x < len(self.grid)-1:
								self.grid[x][y] = 0
								self.grid[x+1][y] = 15

						# Bomba 1
						elif self.grid[x][y] == 14:
							self.grid[x][y] = 0
							if y-1 != -1:			self.grid[x][y-1] = 0
							if y+1 < len(self.grid[0]):	self.grid[x][y+1] = 0
							if x+1 < len(self.grid): 	self.grid[x+1][y] = 0
							if x-1 != -1:		 	self.grid[x-1][y] = 0

						# Bomba 2
						elif self.grid[x][y] == 16:
							self.grid[x][y] = 0
							if y-1 != -1:			self.grid[x][y-1] = 0
							if y+1 < len(self.grid[0]):	self.grid[x][y+1] = 0
							if x+1 < len(self.grid): 	self.grid[x+1][y] = 0
							if x-1 != -1:		 	self.grid[x-1][y] = 0
							if y-1 != -1 and x-1 != -1:					self.grid[x-1][y-1] = 0
							if y+1 < len(self.grid[0]) and x+1 < len(self.grid):		self.grid[x+1][y+1] = 0
							if x+1 < len(self.grid) and y-1 != -1: 				self.grid[x+1][y-1] = 0
							if x-1 != -1 and y+1 < len(self.grid[0]):		 	self.grid[x-1][y+1] = 0
							if y-2 != -2:			self.grid[x][y-2] = 0
							if y+2 < len(self.grid[0]):	self.grid[x][y+2] = 0
							if x+2 < len(self.grid): 	self.grid[x+2][y] = 0
							if x-2 != -2:		 	self.grid[x-2][y] = 0


						# Normale
						elif self.grid[x][y] != 0 and self.grid[x][y] < 13:
							t = self.grid[x][y]
							if (self.grid[x][y+1] == t and self.grid[x][y-1] == t) or (self.grid[x+1][y] == t and self.grid[x-1][y] == t) or (self.grid[x+1][y] == t and self.grid[x][y+1] == t) or (self.grid[x-1][y] == t and self.grid[x][y-1] == t)  or (self.grid[x-1][y] == t and self.grid[x][y+1] == t) or (self.grid[x+1][y] == t and self.grid[x][y-1] == t): 
									
									#upgrade our center piece
									if t < 12: self.grid[x][y] += 1
									else: self.grid[x][y] = 0
									#explode the touching pieces
									self.explode(x,y,t)
									self.points += (t*10)+t*t

							if t-1 > self.lim and t-1 < 13: self.lim += 1

			if self.points % 2 != 0: self.points += 1





			# Se ci son cubetti nelle prime due righe, game over
			if not self.mov: 
				if sum(self.grid[0]) > 0: self.fail += 1
				elif sum(self.grid[1]) > 0: self.fail += 1
				else: self.fail = 0 
			if self.fail > 2: self.over = True		
			*/
		}
		
	}
}
