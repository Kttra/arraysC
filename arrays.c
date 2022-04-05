/*  A program that shows how to create 1-D, 2-D, and 3-D arrays in C.

    This program also shows how to pass the arrays through functions,
    how to print out the arrays, and how to delete them after you
    are done.

    Note that this program will not show how to print 3-D arrays or
    how to pass them to a function as looking at the 1-D and 2-D
    examples should give a good idea of how to do so.

    Additionally, this code can also be used in C++. You would
    just need to replace both includes with "#include <iostream>".
*/

#include <stdio.h>
#include <stdlib.h>

int* getArray(int size);
void change(int* primes);
void print1D(int* array, int size);
void deleteArray(int** primes);
char** makeBoard(int rows, int cols);
void changeBoard(char** board);
void print2D(char** board, int row, int col);
void deleteBoard(char** board, int numRows);

int main(){
    //-------------1-D Array--------------
    //Make a 1-D Array of Size 4
    int* primes = getArray(4);

    //int primes[] = {1,2,3,7}; //declare a static array like this
    primes[0] = 1;
    primes[1] = 2;
    primes[2] = 3;
    primes[3] = 7;

    //Print the starting array
    printf("The starting array: ");
	print1D(primes, 4);

    //Pass by pointer
	change(primes);

	//Print the array after the change
	printf("The array after passing it through a function: ");
	print1D(primes, 4);

    //Delete the Array
    deleteArray(&primes);

    //-------------2-D Array--------------
    //Make a 4 by 5 board
    char** board = makeBoard(4, 5);

    //Prints the board out
    printf("\nThe 2D Board:\n");
    print2D(board, 4, 5);

    //Change one element on the board
    changeBoard(board);
    printf("\nThe 2D Board after passing through a function:\n");
    print2D(board, 4, 5);

    //Delete the 2-D Array
    deleteBoard(board, 4);

    //-------------3-D Array--------------
    //Initializing the dimensions
    int D1 = 2;
    int D2 = 3;
    int D3 = 4;

    //Creating space for the 3-D Array
    int*** array = (int***)malloc(D1*sizeof(int**));
    for(int i = 0; i < D1; i++){
    	array[i] = (int**)malloc(D2*sizeof(int*));
    	for(int j = 0; j < D2; j++){
    		array[i][j] = (int*)malloc(D3*sizeof(int));
    	}
    }

    //Freeing 3-D Array
    for (int i = 0; i < D1; i++)
    {
        for (int j = 0; j < D2; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);

    return 0;
}

//Make a 1-D Array
int* getArray(int size){
    int* array = (int*)malloc((size)*sizeof(int)); //Declare
    array = (int*)realloc(array,(size)*sizeof(int)); //Resize

	return array;
}

//Change the 1st element in the 1-D array
void change(int* primes){
	primes[0] = 7;
}

//1-D Array (Freeing)
void deleteArray(int** primes){
	free(*primes);
}

//Print 1-D Array
void print1D(int* array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

//Make a 2-D Array
char** makeBoard(int rows, int cols){
	char** board = (char**)malloc(rows*sizeof(char*));
	for(int i = 0; i < rows; i++){
		board[i] = (char*)malloc(cols*sizeof(char));
		for(int j = 0; j < cols; j++){
			board[i][j] = '#';
		}
	}
	return board;
}

//Change one element on the board
void changeBoard(char** board){
    board[1][2] = 'h';
}

//Cleaning up the 2-D Array
void deleteBoard(char **board, int rows){
    for (int i = 0; i < rows; ++i) {
        free(board[i]);
    }
    free(board);
}

//Print the 2-D Array
void print2D(char** board, int row, int col){

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
