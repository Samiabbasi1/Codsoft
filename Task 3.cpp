#include<iostream>
#include<cstdlib>
using namespace std;

char board[3][3];
char player = 'X';
//function for initializing the board for the tic-tac-toe game
void initializeBoard()
{
    for(int i=0;i<3;i++)
	{
        for(int j=0;j<3;j++)
		{
			//initialize all the points with " " to make it look simple
            board[i][j] = ' ';
        }
    }
}
//function for displaying the tic-tac-toe board
void displayBoard()
{
    cout<<"-------------"<<endl;
    for(int i=0;i<3;i++)
	{
        cout<<"| "<<board[i][0]<<" | "<<board[i][1]<<" | "<<board[i][2]<<" |"<<endl;
        cout<<"-------------"<<endl;
    }
}
//function to make a move for players and checking it's validity
bool makeMove(int row, int col)
{
    if (row<0 || row>=3 || col<0 || col>=3 || board[row][col]!=' ')
	{
        return false;
    }
    board[row][col]=player;
    return true;
}
//function to check if a player won
bool checkWin()
{
    for (int i=0;i<3;i++)
	{
		//for checking in x and y axis (vertically and horizontally)
        if (board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;
        if (board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;
    }
    // for checking both diagonals
    if (board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;
    if (board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;
    return false;
}
//function to check if the game is a draw or not
bool checkDraw()
{
    for(int i=0;i<3;i++)
	{
        for(int j=0;j<3;j++)
		{
            if(board[i][j]==' ')
			{
                return false;
            }
        }
    }
    return true;
}

int main()
{
	//calling function to initialize the board
    initializeBoard();
    //looping until anyone wins or the game draws
    while(1)
	{
		//calling the function to display the board
        displayBoard();
        int x,y;
        cout<<"Player : "<<player<<" enter your co-ordinates (x,y)";
        cin>>x>>y;
        if(makeMove(x,y))
		{
			//checking if any player won if anyone wins the the program ends after displaying results
            if (checkWin())
			{
                displayBoard();
                cout<<"Player : "<<player<<" wins "<<endl;
                break;
            }
            //if the game is draw the result is displayed
			else if (checkDraw())
			{
                displayBoard();
                cout<<" Draw "<<endl;
                break;
            }
            //this line helps to choose the player alternatively until the game ends
            player=(player=='X')?'O':'X';
        }
		else
		{
			//incase you enter invalid co-ordinates
            cout << "Please enter valid co-ordinates" << endl;
        }
    }
}

