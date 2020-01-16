#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Function prototypes
void print(int arr[9][9]);
bool solve(int arr[9][9]);
bool checkZ(int arr[9][9], int *row, int *col);
bool check(int arr[9][9], int num, int row, int col);


int main(void)
{
	int arr[9][9] ={{0, 0, 0, 0, 5, 9, 4, 8, 2},
					{0, 0, 2, 4, 7, 0, 3, 0, 9},
					{4, 0, 0, 0, 0, 0, 0, 7, 6},
					{1, 0, 0, 0, 4, 3, 0, 2, 0},
					{0, 0, 4, 9, 0, 7, 6, 0, 0},
					{0, 9, 0, 5, 2, 0, 0, 0, 1},
					{2, 1, 0, 0, 0, 0, 0, 0, 3},
					{5, 0, 6, 0, 9, 2, 7, 0, 0},
					{9, 3, 7, 1, 8, 0, 0, 0, 0}};
	if (solve(arr))
	{
		print(arr);
	}
	else
	{
		printf("Invalid Sudoku Input\n");
	}
	return 0;
}
/* What I need:
   something that finds and count the # of empty spaces "0"; if = 0, print array and end program
   recursive backtracking algorithm that goes through, fills number, checks number;
   print program

   -recursive solver
   -check to find slot of unassigned spot
   -check if number input is valid 
   -print function

   Backtracking:
   -finds unassigned spot
   -selects number(check if number fits)
   -return solve()(aka. continue)
   -if hit check = false --> go back to 2nd point

   Find Unassigned Spot:
   -iterate through array(row, col, and box), find element = "0"
   -return 
*/

//general Sudoku solver
bool solve(int arr[9][9])
{
	int row=0;
	int col=0;
	if (!checkZ(arr, &row, &col)) // base case
	{
		return true;
	}
	for (int i = 1; i <= 9; i++)
	{
		//printf("row, col, num: %d %d %d\n", row, col, i);
		//print(arr);
		if (check(arr, i, row, col))
		{
			//print(arr);
			arr[row][col] = i;
			if (solve(arr))
			{
				return true;
			}
			arr[row][col] = 0;
		}
	}

	return false;
}

//looks for an unassigned spot
bool checkZ(int arr[9][9], int *rowAd, int *colAd)
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (arr[row][col] == 0)
			{
				*rowAd = row;
				*colAd = col;
				return true;
			}
		}
	}
	return false;
}

//checks to see if there are duplicates in row and col
bool check(int arr[9][9], int num, int row, int col)
{
	//row and col checker
	for (int i = 0; i < 9; i++)
	{
		if (arr[row][i] == num)
		{
			return false;
		}
		if (arr[i][col] == num)
		{
			return false;
		}
	}
	//box checker
	for (int i = (row - row % 3); i < (row - row % 3)+3; i++)
	{
		for (int j = (col - col % 3); j < (col - col % 3)+3; j++)
		{
			if (arr[i][j] == num)
			{
				return false;
			}
		}
	}
	return true;
}

//print output
void print(int arr[9][9])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
			printf("%2d", arr[row][col]);
		printf("\n");
	}
	printf("------------------\n");
}
