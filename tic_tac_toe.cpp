#include<bits/stdc++.h>
using namespace std;

struct Move
{
    int row, col;
};
char maxplayer = 'x', minplayer = 'o';

bool movesLeft(char board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='_')
                return true;
    return false;
}
int calculateBestScore(char b[3][3])
{
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
        {
            if (b[row][0]==maxplayer)
                return +10;
            else if (b[row][0]==minplayer)
                return -10;
        }
    }
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
        {
            if (b[0][col]==maxplayer)
                return +10;

            else if (b[0][col]==minplayer)
                return -10;
        }
    }

    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==maxplayer)
            return +10;
        else if (b[0][0]==minplayer)
            return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==maxplayer)
            return +10;
        else if (b[0][2]==minplayer)
            return -10;
    }

    return 0;
}
int minimax(char board[3][3], bool isMax)
{
    int score = calculateBestScore(board);
    if (score == 10)
        return score;
    if (score == -10)
        return score;
    if (movesLeft(board)==false)
        return 0;
    if (isMax)
    {
        int best = -1000;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]=='_')
                {
                    board[i][j] = maxplayer;
                    best = max( best,minimax(board, !isMax) );
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }

    else
    {
        int best = 1000;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]=='_')
                {
                    board[i][j] = minplayer;
                    best = min(best,minimax(board,  !isMax));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}
Move findBestMove(char board[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board[i][j]=='_')
            {
                board[i][j] = maxplayer;
                int moveVal = minimax(board,  false);
                board[i][j] = '_';
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    if(bestVal==10)
        printf("Winner is max\n");
    else if(bestVal==-10)
        printf("Winner is min\n");
    else if(bestVal==0)
        printf("draw\n");

    return bestMove;
}
int main()
{
    char player;
    char board[3][3];
    for(int i =0;i<3;i++)
        {
            for(int j=0; j<3;j++)
            {
                cin>> board[i][j];
            }
        }
        /*
         { 'x', '_', '_' },
        { '_', 'o', 'x' },
        { 'o', '_', '_' } */

        printf("Player = ");
        cin>> player;

    Move bestMove = findBestMove(board);

        for(int i =0;i<3;i++)
        {
            for(int j=0; j<3;j++)
            {
                    if(i==bestMove.row && j==bestMove.col)
                    {
                        if(player='min')
                            board[i][j]='x';
                        else if(player='max')
                            board[i][j]='o';
                    }

                }

        }
        for(int i =0;i<3;i++)
            {
                for(int j=0; j<3;j++)
                    {
                    printf("%c ",board[i][j]);

                    }
                    printf("\n");

            }
    return 0;
}
