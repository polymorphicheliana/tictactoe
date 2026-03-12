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
    char playerTurn = xturn? 'X' : 'O';

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

bool winCondition(bool playerTurnX)
{
    const unsigned int winningCombosCount = 8;
    const unsigned int winningCombos[winningCombosCount] = {7, 56, 73, 84, 146, 273, 292, 448};
    unsigned int counter = 0;
    unsigned int currentCombo = 0;
    
    State playerState = playerTurnX? State::X : State::O;

    while(counter < cellCount)
    {
        if(board[counter] == playerState)
        {
            currentCombo = currentCombo + (1 << counter);
        }

        counter = counter + 1;
    }

    counter = 0;

    while(counter < winningCombosCount)
    {
        if(winningCombos[counter] == (currentCombo & winningCombos[counter]))
        {
            return true;
        }
        
        counter = counter + 1;
    }

    return false;
}

void gameLoop()
{
    unsigned int counter = 0;
    bool xTurn;

    while(counter < cellCount)
    {
        xTurn = counter % 2 == 0;

        printBoard();
        unsigned int move = getMove(xTurn);

        board[move] = xTurn? State::X : State::O;

        if(winCondition(xTurn))
        {
            printBoard();
            printf("The Winner is %c\n", xTurn? 'X' : 'O');

            return;
        }
    
        counter = counter + 1;
    }

    printBoard();
    printf("The game came (aah) to a draw\n");
}



int main()
{
    setup();
    gameLoop();
    return 0;
}

