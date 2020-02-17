#include <stdio.h>
#include <stdbool.h>
//Print board functions, ai turn
//make a binary function to define whose turn it is

void newBoard(char board[6][8])
{
    board[5][0] = '1';
    board[4][0] = '2';
    board[3][0] = '3';
    board[2][0] = '4';
    board[1][0] = '5';
    board[0][0] = '6';

    for (int i = 0; i < 6; i++) //rows
    {
        for (int j = 1; j < 8; j++) //columns
        {
            board[i][j] = '.';
        }
    }
}
void printBoard(char board[6][8], char head[8])
{
    printf("---------------- \n\n");

    for (int i = 0; i < 8; i++)
    {
        printf("%c ", head[i]);
    }
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void place(char placement, char board[6][8], char currPlayer) //can be A, B, C, D, E, F, G (value of 'placement' )
{
    if (placement == 'A') // j = 0 aka column 0
    {
        int furDown = 0; // acts to mark where the furthest open location in the column, starting from 0 (row 0)
        for (int i = 0; i <= 5; i++)
        {
            if (board[i][1] == '.')
            {
                furDown = i;
            }
        }
        board[furDown][1] = currPlayer;
    }
    if (placement == 'B')
    {
        int furDown = 0; // acts to mark where the furthest open location in the column, starting from 0 (row 0)
        for (int i = 0; i <= 5; i++)
        {
            if (board[i][2] == '.')
            {
                furDown = i;
            }
        }
        board[furDown][2] = currPlayer;
    }
    if (placement == 'C')
    {
        int furDown = 0; // acts to mark where the furthest open location in the column, starting from 0 (row 0)
        for (int i = 0; i <= 5; i++)
        {
            if (board[i][3] == '.')
            {
                furDown = i;
            }
        }
        board[furDown][3] = currPlayer;
    }
    if (placement == 'D')
    {
        int furDown = 0; // acts to mark where the furthest open location in the column, starting from 0 (row 0)
        for (int i = 0; i <= 5; i++)
        {
            if (board[i][4] == '.')
            {
                furDown = i;
            }
        }
        board[furDown][4] = currPlayer;
    }
    if (placement == 'E')
    {
        int furDown = 0; // acts to mark where the furthest open location in the column, starting from 0 (row 0)
        for (int i = 0; i <= 5; i++)
        {
            if (board[i][5] == '.')
            {
                furDown = i;
            }
        }
        board[furDown][5] = currPlayer;
    }
    if (placement == 'F')
    {
        int furDown = 0; // acts to mark where the furthest open location in the column, starting from 0 (row 0)
        for (int i = 0; i <= 5; i++)
        {
            if (board[i][6] == '.')
            {
                furDown = i;
            }
        }
        board[furDown][6] = currPlayer;
    }
    if (placement == 'G')
    {
        int furDown = 0; // acts to mark where the furthest open location in the column, starting from 0 (row 0)
        for (int i = 0; i <= 5; i++)
        {
            if (board[i][7] == '.')
            {
                furDown = i;
            }
        }
        board[furDown][7] = currPlayer;
    }
}

int resultCheck(char currPlayer, char board[6][8], char icon) //return can be 0(loss), 1(win), 2(draw), 3(game continues)
{
    //Upward diagonal check
    for (int i = 5; i > 2; i--) //rows
    {
        for (int j = 1; j < 5; j++) //columns
        {
            if (board[i][j] == currPlayer && board[i - 1][j + 1] == currPlayer && board[i - 2][j + 2] == currPlayer && board[i - 3][j + 3] == currPlayer)
            {
                if (currPlayer == icon)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    //Downward diagonal check
    for (int i = 0; i < 3; i++) //rows
    {
        for (int j = 1; j < 5; j++) //columns
        {
            if (board[i][j] == currPlayer && board[i + 1][j + 1] == currPlayer && board[i + 2][j + 2] == currPlayer && board[i + 3][j + 3] == currPlayer)
            {
                if (currPlayer == icon)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    //Horizontal check
    for (int i = 0; i < 6; i++) //rows
    {
        for (int j = 1; j < 5; j++) //columns
        {
            if (board[i][j] == currPlayer && board[i][j + 1] == currPlayer && board[i][j + 2] == currPlayer && board[i][j + 3] == currPlayer)
            {

                if (currPlayer == icon)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    //Vertical check
    for (int j = 1; j < 8; j++) //columns
    {
        for (int i = 5; i > 1; i--) //rows
        {
            if (board[i][j] == currPlayer && board[i - 1][j] == currPlayer && board[i - 2][j] == currPlayer && board[i - 3][j] == currPlayer)
            {
                if (currPlayer == icon)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    int count = 0;
    for (int i = 1; i < 8; i++) // checks for the draw
    {
        if (board[0][i] != '.')
        {
            count++;
        }
        if (count == 7)
        {
            return 2;
        }
    }
    return 3;
}
int is_col_full(char placement, char board[6][8], char head[8]) // 0 for true, 1 for false
{
    int column = 0;
    for (int i = 1; i < 8; i++)
    {
        if (head[i] == placement)
        {
            column = i;
        }
    }
    if (board[0][column] == '.')
    {
        return 1;
    }
    return 0;
}
int is_valid_col(char placement) //returns 0 if it does not exist
{
    if ((placement == 'A') || (placement == 'B') || (placement == 'C') || (placement == 'D') || (placement == 'E') || (placement == 'F') || (placement == 'G'))
    {
        return 1;
    }
    return 0;
}
int AI_move(char currPlayer, char board[6][8], char placement, char head[8], char icon) //returns the index of head
{
    for (int i = 0; i < 6; i++) //rows
    {
        for (int j = 1; j < 5; j++) //columns
        {
            if (board[i][j] == icon && board[i][j + 1] == icon && board[i][j + 2] == icon)
            {

                if (board[i][j + 3] == '.')
                {
                    return j + 3;
                }
                if (board[i][j - 1] == '.')
                {
                    return j - 1;
                }
            }
            if (board[i][j] == icon && board[i][j + 1] == icon && board[i][j + 3] == icon)
            {

                if (board[i][j + 2] == '.')
                {
                    return j + 2;
                }
            }
            if (board[i][j] == icon && board[i][j + 3] == icon && board[i][j + 2] == icon)
            {

                if (board[i][j + 1] == '.')
                {
                    return j + 1;
                }
            }
        }
    }
    for (int i = 1; i < 8; i++)
    {
        if (head[i] == placement)
        {
            while (is_col_full(placement, board, head) == 0)
            {
                i++;
            }
            return i;
        }
    }
}
int is_valid_icon(char icon)
{
    if ((icon == 'X') || (icon == 'O'))
    {
        return 1;
    }
    return 0;
}
int main(void)
{

    char head[8] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char board[6][8]; //[i] rows, [j] columns
    char icon = ' ';
    char currPlayer = ' '; //used to mark the current player
    char placement = ' ';  //used to choose which column the piece is dropped into
    char result = 3;       //the result of the game from the perspective of the player 0(loss), 1(win), 2(draw), 3(game continues)

    printf("\nWelcome to Connect 4!\n\n");
    newBoard(board);
    printBoard(board, head);
    printf("Choose player icon('X' or 'O' [Player X goes first]): ");
    scanf(" %c", &icon); //leave a space before the parenthesis!
    while (is_valid_icon(icon) == 0)
    {
        printf("Please only choose 'X' or 'O' [Player X goes first]: ");
        scanf(" %c", &icon);
    }
    currPlayer = icon;
    if (icon == 'X')
    {
        //  player goes first
        //  loops the game play, checking if there is a win after each placement,
        //  the placement function takes two parameters (char Player_Icon, char AI_Icon)
        //  if it is a win, the function breaks the loop the icon that wins and the game finishes
        //  ask if the player would like to play again and resets the board
        while (result == 3)
        {
            if (currPlayer == icon)
            {
                printf("Enter the column to drop your piece: ");
                // printf("A, B, C, D, E, F, G\n");
                scanf(" %c", &placement); //leave a space before the parenthesis!
                while (is_valid_col(placement) == 0)
                {
                    printf("Please only choose 'A','B','C','D','E','F', or 'G': ");
                    scanf(" %c", &placement);
                }
                while (is_col_full(placement, board, head) == 0)
                {
                    printf("This column is full, please choose a different one: ");
                    scanf(" %c", &placement);
                }
                place(placement, board, currPlayer);
                printBoard(board, head);
                result = resultCheck(currPlayer, board, icon);
                currPlayer = 'O'; //switches current player to computer(AI)
            }
            else
            {
                placement = head[AI_move(currPlayer, board, placement, head, icon)]; //AI does its move, random if first move or around the player move if not
                printf("Computer's Move: %c\n", placement);
                place(placement, board, currPlayer);
                printBoard(board, head);
                result = resultCheck(currPlayer, board, icon);
                currPlayer = 'X'; //switches current player to human player
            }
        }
    }
    else
    {
        //  computer goes first
        //  loops the game play, checking if there is a win after each placement,
        //  the placement function takes two parameters (char Player_Icon, char AI_Icon)
        //  if it is a win, the function breaks the loop the icon that wins and the game finishes
        //  ask if the player would like to play again and resets the board
        printf("Computer's Move: F\n");
        place('F', board, 'X');
        printBoard(board, head);
        while (result == 3)
        {
            if (currPlayer == icon)
            {
                printf("Enter the column to drop your piece: ");
                // printf("A, B, C, D, E, F, G\n");
                scanf(" %c", &placement); //leave a space before the parenthesis!
                while (is_valid_col(placement) == 0)
                {
                    printf("Please only choose 'A','B','C','D','E','F', or 'G': ");
                    scanf(" %c", &placement);
                }
                while (is_col_full(placement, board, head) == 0)
                {
                    printf("This column is full, please choose a different one: ");
                    scanf(" %c", &placement);
                }
                place(placement, board, currPlayer);
                printBoard(board, head);
                result = resultCheck(currPlayer, board, icon);
                currPlayer = 'X'; //switches current player to computer(AI)
            }
            else
            {
                placement = head[AI_move(currPlayer, board, placement, head, icon)]; //AI does its move, random if first move or around the player move if not
                printf("Computer's Move: %c\n", placement);
                place(placement, board, currPlayer);
                printBoard(board, head);
                result = resultCheck(currPlayer, board, icon);
                currPlayer = 'O'; //switches current player to human player
            }
        }
    }
    if (result == 1)
    {
        printf("You have won! \n");
    }
    else if (result == 0)
    {
        printf("Sorry, you have lost \n");
    }
    else if (result == 2)
    {
        printf("Nice try, it is a draw \n");
    }
    return 0;
}
