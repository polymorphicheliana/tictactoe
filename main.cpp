#include <cstdio>

enum State
{
    X, O, Empty
};

const unsigned int cellCount = 9;

State board[cellCount];

void setup()
{
    unsigned int counter = 0;

    while(counter < cellCount)
    {
        board[counter] = State::Empty;
        
        counter = counter + 1;
    }
}

char getCellStateCharacter(unsigned int position)
{
    if(board[position] == State::X)
    {
        return 'X';
    }
    else if(board[position] == State::O)
    {
        return 'O';
    }
    else
    {
        return '0' + position + 1;
    }
}

void printBoard()
{
    unsigned int counter = 0;

    while(counter < cellCount / 3)
    {
        unsigned int offset = counter * 3;

        printf("%c %c %c\n", getCellStateCharacter(6 - offset), getCellStateCharacter(7 - offset), getCellStateCharacter(8 - offset));

        counter = counter + 1;
    }
}

char readCharacter()
{
    const unsigned int maxSize = 128;
    char inputLine[maxSize];
    std::fgets(inputLine, maxSize, stdin);
    return inputLine[0];
}

unsigned int getMove(bool xturn)
{
    char move;
    char playerTurn;

    if(xturn)
    {
        playerTurn = 'X';    
    }
    else 
    {
        playerTurn = 'O';
    }
    printf("Choose your move (%c) : ", playerTurn);
    move = readCharacter();
//    printf("You entered : '%c'\n", move);
    while(true)
    {
        if(move < '1' || move > '9')
        {
            printf("Please choose a number from the board now... bitch... (%c) : ", playerTurn);
            move = readCharacter();
        }
        else if(board[move - '1'] != State::Empty)
        {
            printf("(%c) are you trying to be funny? right???, please choose an empty cell : ", playerTurn);
            move = readCharacter();
        }
        else
        {
            return move - '1';
        }
    }
}

void gameLoop()
{
    unsigned int counter = 0;
    bool xTurn;

    while(counter < cellCount)
    {
        
        if(counter % 2 == 0)
        {
            xTurn = true;
        }
        else
        {
            xTurn = false;
        }
        printBoard();
        unsigned int move = getMove(xTurn);
        if(xTurn)
        {
            board[move] = State::X;
        }
        else
        {
            board[move] = State::O;
        }
        counter = counter + 1;
    }
}
int main()
{
    setup();
    gameLoop();
//    board[5] = State::X;

    

    return 0;
}

