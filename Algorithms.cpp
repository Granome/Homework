#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


void print_board(const std::vector<std::vector<char>>& gameField)
{
    std::cout << "============" << std::endl;
    std::cout << "  1 2 3" << std::endl;
    int i = 1;
    for (auto row : gameField)
    {
        std::cout << i << " ";
        for (auto cell : row)
        {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
        i++;
    }
    std::cout << "============" << std::endl;
}

void read_input(std::vector<std::vector<char>>& gameField, char currentPlayer)
{
    int row = 10;
    int column = 10;
    std::cout << "Enter coordinates of your next move (row, column): ";
    std::cin >> row >> column;
    if (row < 1 || row > 3 || column < 1 || column > 3) //check for invalid input
    {
        std::cout << "Enter coordinates from 1 to 3" << std::endl;
        read_input(gameField, currentPlayer);
        return;
    }
    else if (gameField[row-1][column-1] != ' ') // check if this cell already has something
    {
        std::cout << "There is something in this cell already" << std::endl;
        read_input(gameField, currentPlayer);
        return;
    }
    else
    {
        gameField[row-1][column-1] = currentPlayer;
    }
}


bool checkWin(const std::vector<std::vector<char>> &gameField, char player) {
    for (int i = 0; i < 3; i++) {
        if ((gameField[i][0] == player && gameField[i][1] == player && gameField[i][2] == player) ||
            (gameField[0][i] == player && gameField[1][i] == player && gameField[2][i] == player)) // horisontal and vertical checks
        {
            return true;
        }
    }
    if((gameField[0][0] == player && gameField[1][1] == player && gameField[2][2] == player) ||
        (gameField[0][2] == player && gameField[1][1] == player && gameField[2][0] == player)) // diagonal check
    {
        return true;
    }
    return false;
}


void ticTacToe()
{
    char currentPlayer = 'X';
    bool isGameOver = false;
    int moves = 0; // move counter to detect draw
    std::vector<std::vector<char>> gameField(3, std::vector<char>(3, ' '));
    print_board(gameField);


    while(!isGameOver)
    {
        moves++;


        read_input(gameField, currentPlayer);
        print_board(gameField);

        if (checkWin(gameField, currentPlayer))
        {
            std::cout << currentPlayer << " won!!!" << std::endl;
            isGameOver = true;
        }
        else if (moves == 9)
        {
            std::cout << "Draw on the board!!!" << std::endl;
            isGameOver = true;
        }


        if (currentPlayer == 'O')
        {
            currentPlayer = 'X';
        }
        else if (currentPlayer == 'X')
        {
            currentPlayer = 'O';
        }
    }
    std::cout << std::endl << std::endl;
}




struct Child
{
    std::string name;
    int x;
    int y;
};


double distance_2d(int x1, int y1, int x2, int y2)
{
    return std::sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


bool compareCoordinates(const Child& a, const Child& b) //I create point on y=-x line, coordinates of which have to be equal to abs value of biggest coordinate of children, and then calculate distance betweent everything. It seems to work
{
    int north_west_point = std::max(std::max(std::abs(a.x), std::abs(a.y)), std::max(std::abs(b.x), std::abs(b.y)));

    return distance_2d(-north_west_point, north_west_point, a.x, a.y) < distance_2d(-north_west_point, north_west_point, b.x, b.y); //even im not sure whats going on at that point, but it works!

}

int childrenSorting()
{
    std::vector<Child> children;

    for (int i = 0; i < 4; i++)
    {
        Child child;

        std::cout << "Enter child's name, x-position, y-position: ";
        std::cin >> child.name >> child.x >> child.y;
        children.emplace_back(child);
    }



    std::sort(children.begin(), children.end(), compareCoordinates);


    for (const Child& child : children)
    {
        std::cout << child.name << std::endl;
    }
    std::cout << std::endl << std::endl;
    return 0;
}


void menu()
{
    while (true)
    {
        int exercise_number;
        std::cout << "Choose an exercise:  \n  1 - Tic Tac Toe\n  2 - Santa helper\n0 - EXIT:     ";
        std::cin >> exercise_number;

        switch(exercise_number)
        {
        case 1:
            ticTacToe();

            break;
        case 2:
            childrenSorting();

            break;
        case 0:
            return;

            break;
        default:
            std::cout << "Enter 1 or 2" << std::endl;

            break;
        }
    }

}


int main()
{
    menu();
}
