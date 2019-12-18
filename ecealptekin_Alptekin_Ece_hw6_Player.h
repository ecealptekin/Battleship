#ifndef ecealptekin_Alptekin_Ece_hw6_Player_h
#define ecealptekin_Alptekin_Ece_hw6_Player_h

#include<iostream>
#include<string>

using namespace std;

class Player
{
private:
	Board & theBoard;
	int playerid;

public:
	Player(Board & theBoard, const int & playerid);
	bool guess(int row, int column);
	bool wins();

};

#endif

Player::Player(Board & theBoard, const int & playerid)
	:theBoard(theBoard), playerid(playerid)
{}

bool Player::guess(int row, int column)
{
	return theBoard.makeAHit(row,column);
}

bool Player::wins()
{
	return theBoard.checkIfPlayerWon(playerid);
}

