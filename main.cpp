#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

enum Direction{STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;
bool gameOver;
const int height = 20;
const int width = 20;
int headX, headY, fruitX, fruitY, score;
int tailx[100], taily[100];
int tail_len;

void setup();
void draw();
void input();
void logic();

int main()
{
    char start;
    cout << "\t-------------------------------" << endl;
    cout << "\t\t Simple Snake Game" << endl;
    cout << "\t-------------------------------" << endl;
    cout << "\tPress 's' to start: ";
    cin >> start;
    if(start == 's')
        {
        setup();
        while(!gameOver)
        {
            draw();
            input();
            logic();
            // Sleep for 100 milliseconds
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            
        }
        // Display the final score
        cout << "\t-------------------------------" << endl;
        cout << "\t\t Game Over!" << endl;
        cout << "\t\t Congratulations! Your Score: " << score << endl;
        cout << "\t-------------------------------" << endl;
    }

    return 0;
}
void setup()
{
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}


void draw()
{
    // Get the console handle
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the cursor position to the top-left corner
    SetConsoleCursorPosition(console, {0, 0});

    // Upper Border
    cout << "\t\t";
    for (int i = 0; i < width; i++)
    {
        cout << "# ";
    }
    cout << endl;

    // Snake, fruit, space, and side borders
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // left border
            if (j == 0)
            {
                cout << "\t\t#";
            }

            // extra border in the middle
            if (j == (2 * width) / 3 && (5 < i && i < 15))
            {
                cout << "   #";
            }

            // snake head
            if (i == headY && j == headX)
            {
                cout << "O";
            }
            // fruit
            else if (i == fruitY && j == fruitX)
            {
                cout << "*";
            }
            // space, snake tail
            else
            {
                bool print = false;
                // tail
                for (int k = 0; k < tail_len; k++)
                {
                    if (tailx[k] == j && taily[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                // space
                if (!print)
                {
                    cout << " ";
                }
            }

            // right border
            if (j == width - 1)
            {
                cout << "\t\t    #";
            }
        }

        cout << endl;
    }
    void input()
{
    if (_kbhit())
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        default:
            break;
        }
}


    // Lower Border
    cout << "\t\t";
    for (int i = 0; i < width; i++)
    {
        cout << "# ";
    }
    cout << endl;
    cout << "\t\t\tScore: " << score << endl;
}
