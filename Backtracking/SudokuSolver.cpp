#include <bits/stdc++.h> 

bool isSafe(int row,int col,vector<vector<int>> &board,int val){
    for(int i=0;i<board.size();i++){

        //a row should have unique values
        if(board[row][i]==val){
            return false;
        }

        //a column should have unique values
        if(board[i][col]==val){
            return false;
        }

        //a 3x3 grid should have unique values
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board){
    int n=board.size();

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){//checking for empty cell
                for(int val=0;val<=9;val++){//checking for all possible values from 1 to 9

                    //checking if the value is safe to put in the cell or not 
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;

                        //recursive call to solve the next cell in the board 
                        bool aageSolutionPossible= solve(board);
                        if(aageSolutionPossible){
                            return true;
                        }
                        else{
                        //backtracking step if no solution is possible for the current value
                        board[row][col]=0;
                        }
                    }
                }
                //if isSafe function is not true for any value
                return false;
            }
        }
    }
    //if all cells are filled with valid values then return true 
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}