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

int main()
{
    setup();

//    board[5] = State::X;

    printBoard();

    return 0;
}

