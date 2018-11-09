/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;
//position of 0
int row0, col0;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
void swap(int i, int j);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
        DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
     }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)

    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(50000);
        }


        // sleep thread for animation's sake
        usleep(50000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(20000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // TODO
    int n = 1;
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            board[i][j] = (d*d) - n;
            n++;
        }
    }

    //checks the condition if there are even number of rows
    if(d % 2 == 0)
    {
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }

    row0 = d - 1;
    col0 = d - 1;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
   for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            printf("%2d  ", board[i][j]);
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // TODO

    //The row number and column number of the tile
    int row = 0;
    int col = 0;


    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if(tile == board[i][j])
            {
                row = i;
                col = j;
            }
        }
    }


    if(row  == row0 && col + 1 == col0)
    {
        swap(row, col);
        row0 = row;
        col0 = col;

        return true;
    }
    else if(row  == row0 && col - 1 == col0)
    {
        swap(row, col);
        row0 = row;
        col0 = col;

        return true;
    }
    else if(row + 1 == row0 && col == col0)
    {
        swap(row, col);
        row0 = row;
        col0 = col;

        return true;
    }
    else if(row - 1 == row0 && col == col0)
    {
        swap(row, col);
        row0 = row;
        col0 = col;

        return true;
    }

    else
    {
        return false;
    }


}

/**Swaps the positions of i and j on the board
 * Return type void
 */

void swap(int i, int j)
{
    int x = board[i][j];
    board[i][j] = board[row0][col0];
    board[row0][col0] = x;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
 bool won(void)
{
    // TODO
    int counter = 0;
    int previous = 0;

    if(board[d - 1][d - 1] == 0)
    {
        for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++)
            {
                if(i == d - 1 && j == d - 1) //The last tile
                {
                    break;
                }
                else if(board[i][j] > previous) //Checks if numbers are in ascending order
                {
                    counter++;
                    previous = board[i][j];
                }
                else
                {
                    break;
                }
            }
        }
    }

    if(counter == (d*d) - 1)
    {
        return true;
    }
    else
    {
        return false;
    }


}
