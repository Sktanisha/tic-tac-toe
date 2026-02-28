Here, we have to give a board configuration of the tic-tac-toe game and mention which player to give the next move. 
Using minimax alpha-beta pruning, we have to generate a game tree, and from the game tree, we have to decide which player (min or max) 
is going to win the game. In addition, we have to show the position of the board configuration after the player's move.  
First, we have to check which position has empty space (‘_’) and generate a game tree by finding the best move for min player 
(by giving less to max, here if min gets the best move, we have returned -10) and max player (by gaining more from min, here if 
max gets the best move we have returned 10). If the best move is 0, that’s indicated as a draw between max and min. 

Findings:
•	The minimax algorithm is complete and optimal if the tree is finite.
•	In alpha-beta pruning, it eliminates some of the branches compared to the minimax algorithm. 

Limitations:  
•	The Minimax algorithm becomes very slow when the game tree or branching factor has increased, such as in Chess, Go, etc. 
•	Alpha-beta pruning does not solve all the problems associated with the original minimax algorithm.
•	In the worst board configuration, Alpha-beta pruning can’t prune any branch, so it generates the game tree like the minimax algorithm. 

