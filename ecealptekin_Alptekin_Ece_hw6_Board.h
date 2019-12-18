#ifndef ecealptekin_Alptekin_Ece_hw6_Board_h
#define ecealptekin_Alptekin_Ece_hw6_Board_h

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Board
{
private:
	int theBoard[6][6];

public:
	Board();
	void displayBoard();
	bool putShip(int playerid, int shipid, int rowStart, int colStart, int rowEnd, int colEnd);
	bool checkShape(int shipid, int rowStart, int colStart, int rowEnd, int colEnd);
	bool checkCoordinates(int playerid, int shipid, int rowStart, int colStart, int rowEnd, int colEnd);
	bool checkCells(int shipid, int rowStart, int colStart, int rowEnd, int colEnd);
	bool makeAHit(int row, int column);
	bool checkIfPlayerWon(int playerid);
};

#endif

Board::Board()
{
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			theBoard[i][j] = 0;
		}
	}
}

void Board::displayBoard()
{
	cout << "Board:" << endl;
	cout << setw(9) << "P1" << setw(7) << "|" << setw(9) << "P2" << setw(8) << endl;
	for(int j=0; j<6; j++)
	{   
		for (int k=0; k<6; k++)
		{   
			cout << setw(4) << theBoard[j][k];
			if(k == 2)
			{
				cout << setw(4) << "|" << setw(4);
			}
		}
		cout << endl;
	}
	cout << "\n";
}

bool Board::checkShape(int shipid, int rowStart, int colStart, int rowEnd, int colEnd)
{
	if(shipid == 1) //1x2 or 2x1
	{
		if(rowStart == rowEnd || colStart == colEnd)
		{
			if(rowStart == rowEnd) //horizontal
			{
				if((colEnd - colStart != 1) && (colStart - colEnd != 1))
				{
					return false;
				}
			}

			else if(colStart == colEnd) //vertical
			{
				if((rowEnd - rowStart != 1) && (rowStart - rowEnd != 1))
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
	}
	else if(shipid == 2) //1x3 or 3x1
	{
		if(rowStart == rowEnd || colStart == colEnd)
		{
			if(rowStart == rowEnd) //horizontal
			{
				if((colEnd - colStart != 2) && (colStart - colEnd != 2))
				{
					return false;
				}
			}

			else if(colStart == colEnd) //vertical
			{
				if((rowEnd - rowStart != 2) && (rowStart - rowEnd != 2))
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Board::checkCoordinates(int playerid, int shipid, int rowStart, int colStart, int rowEnd, int colEnd)
{
	if(playerid == 1)
	{
		if(rowStart<0 || 5<rowStart || rowEnd<0 || 5<rowEnd || colStart<0 || 2<colStart || colEnd<0 || 2<colEnd)
		{
			return false;
		}
	}
	else if(playerid == 2)
	{
		if(rowStart<0 || 5<rowStart || rowEnd<0 || 5<rowEnd || colStart<3 || 5<colStart || colEnd<3 || 5<colEnd)
		{
			return false;
		}
	}
	return true;
}

bool Board::checkCells(int shipid, int rowStart, int colStart, int rowEnd, int colEnd)
{
	if(colStart == colEnd)
	{
		if(rowEnd > rowStart)
		{
			for(int i=rowStart; i<= rowEnd; i++)
			{
				if(theBoard[i][colStart] != 0)
				{
					return false;
				}
			}
		}

		else if(rowStart > rowEnd)
		{
			for(int i=rowEnd; i<= rowStart; i++)
			{
				if(theBoard[i][colStart] != 0)
				{
					return false;
				}
			}
		}
	}

	else if(rowStart == rowEnd)
	{

		if(colEnd > colStart)
		{
			for(int i=colStart; i<= colEnd; i++)
			{
				if(theBoard[rowStart][i] != 0)
				{
					return false;
				}
			}
		}

		else if(colStart > colEnd)
		{
			for(int i=colEnd; i<= colStart; i++)
			{
				if(theBoard[rowStart][i] != 0)
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool Board::putShip(int playerid, int shipid, int rowStart, int colStart, int rowEnd, int colEnd)
{ //this function checks three conditions for the coordinates.
  //if the coordinates are valid, it puts a ship.
	bool shape = checkShape(shipid, rowStart, colStart, rowEnd, colEnd);
	bool coord = checkCoordinates(playerid, shipid, rowStart, colStart, rowEnd, colEnd);
	bool cell = checkCells(shipid, rowStart, colStart, rowEnd, colEnd);

	if(shape == false || coord == false || cell == false)
	{
		return false;
	}

	else
	{
	if(colStart == colEnd){

		if(rowEnd > rowStart){

			for(int i=rowStart; i<= rowEnd; i++)
			{
				theBoard[i][colStart] = 1;
			}
		}

		else if(rowStart > rowEnd){

			for(int i=rowEnd; i<= rowStart; i++)
			{
				theBoard[i][colStart] = 1;
			}
		}
	}

	else if(rowStart == rowEnd){

		if(colEnd > colStart){

			for(int i=colStart; i<= colEnd; i++)
			{
				theBoard[rowStart][i] = 1;
			}
		}

		else if(colStart > colEnd){

			for(int i=colEnd; i<= colStart; i++)
			{
				theBoard[rowStart][i] = 1;
			}
		}
	}
	return true;
  }
}

bool Board::makeAHit(int row, int column)
{
	if((theBoard[row][column] == 0) || (theBoard[row][column] == -1))
	{
		return false;
	}

	else if(theBoard[row][column] == 1)
	{
		theBoard[row][column] = -1;
		return true;
	}
}

bool Board::checkIfPlayerWon(int playerid)
{ //this function checks the specified area of the player according to its id
	if(playerid == 1)
	{
		for(int i=0; i<6; i++)
		{
			for(int j=0; j<3; j++)
			{
				if(theBoard[i][j] == 1)
				{
					return false;
				}
			}
		}
	}
	else if(playerid == 2)
	{
       for(int i=0; i<6; i++)
		{
			for(int j=3; j<6; j++)
			{
				if(theBoard[i][j] == 1)
				{
					return false;
				}
			}
		}
	}
	return true;
}

