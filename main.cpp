//Falling Stars: a game where you avoid falling stars.
//Date finished: April 22, 2019
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
using namespace std;

//global varables for this file

char controls;     //input for controls

int width = 20;    //width of map
int height = 10;   //height of map
int counter_w = 0; //for while loops for width
int counter_h = 0; //for while loops for height
int x = 10;        //x coordinate of the player
int y = 9;         //y coordinate of the player
char tile;         //space on the map

//variables for title anmation
int title_timer;             //a timer for the title animation
int x_s0 = 0;               //"s" is equal to star
int x_s1 = width / 4;       // = 25
int x_s2 = width / 2;       // = 50
int x_s3 = (width / 4) * 3; // = 75
int x_s4 = width;

int y_s0 = 0;
int y_s1 = 0;
int y_s2 = 0;
int y_s3 = 0;
int y_s4 = 0;

char any_char; //allows advancment from the title screen.

//variables for falling stars (enemies)
int x_f0 = rand() % 20;
int x_f1 = rand() % 20; 
int x_f2 = rand() % 20;
int x_f3 = rand() % 20;
int x_f4 = rand() % 20;
int x_f5 = rand() % 20;
int x_f6 = rand() % 20;

int y_f0 = 0;
int y_f1 = 0;
int y_f2 = 0;
int y_f3 = 0;
int y_f4 = 0;
int y_f5 = 0;
int y_f6 = 0;


class Enemy //class for the generation of trees
{
    public:
        void enemy_seeder()//this is the if statements to get the falling stars to work properly
        {
            if(counter_w == x_f0 and counter_h == y_f0)
            {
                tile = '*';
                cout << "\033[31m" << tile << "\033[0m"; //prints red
            }
    
            if(counter_w == x_f1 and counter_h == y_f1)
            {
                tile = '*';
                cout << "\033[32m" << tile << "\033[0m"; //prints green
            }
    
            if(counter_w == x_f2 and counter_h == y_f2)
            {
                tile = '*';
                cout << "\033[33m" << tile << "\033[0m"; //prints yellow
            }
    
            if(counter_w == x_f3 and counter_h == y_f3)
            {
                tile = '*';
                cout << "\033[35m" << tile << "\033[0m"; //prints magenta
            }
    
            if(counter_w == x_f4 and counter_h == y_f4)
            {
                tile = '*';
                cout << "\033[37m" << tile << "\033[0m"; //prints white
            }
    
            if(counter_w == x_f5 and counter_h == y_f5)
            {
                tile = '*';
                cout << "\033[35m" << tile << "\033[0m"; //prints black
            }
    
            if(counter_w == x_f6 and counter_h == y_f6)
            {
                tile = '*';
                cout << "\033[31m" << tile << "\033[0m"; //prints red
            }   
    
            //resets enemies
            //since all are moving at the same pace, the game only needs to detect only one hitting the bottom
            if(y_f6 == height)
            {
                //resets y coordinate of falling stars
                y_f0 = 0;
                y_f1 = 0;
                y_f2 = 0;
                y_f3 = 0;
                y_f4 = 0;
                y_f5 = 0;
                y_f6 = 0;
        
                //resets x coordinate of falling stars and gives them a new random position
                x_f0 = rand() % 20;
                x_f1 = rand() % 20; 
                x_f2 = rand() % 20;
                x_f3 = rand() % 20;
                x_f4 = rand() % 20;
                x_f5 = rand() % 20;
                x_f6 = rand() % 20;
            }
        }
        void enemy_logic()//controls enemy's actions. Basically if the player inputs a valid control they will move.
        {
            if(controls == 'a' or controls == 'd' or controls == 'w')
            {
                y_f0 = y_f0 + 1;
                y_f1 = y_f1 + 1;
                y_f2 = y_f2 + 1;
                y_f3 = y_f3 + 1;
                y_f4 = y_f4 + 1;
                y_f5 = y_f5 + 1;
                y_f6 = y_f6 + 1;
            }
        }
};

void title_animation()//animation of the title
{
    while(title_timer <= 10)
    {
        //map generator
        while(counter_h <= height)
        {
            while(counter_w <= width)
            {
                //prints out the falling stars in the title animation
                if(//begin if statement
                    (counter_w == x_s0 and counter_h == y_s0) or
                    (counter_w == x_s1 and counter_h == y_s1) or
                    (counter_w == x_s2 and counter_h == y_s2) or
                    (counter_w == x_s3 and counter_h == y_s3) or
                    (counter_w == x_s4 and counter_h == y_s4)
                  )
                {
                    tile = '*';
                    cout << "\033[33m" << tile << "\033[0m"; //prints yellow stars
                }//end if statement
                
                else
                {
                    tile = ' ';
                    cout << tile;
                }
                
                counter_w = counter_w + 1;
                
            }
            counter_w = 0;

            cout << endl;
            counter_h = counter_h + 1;
        }
        
        counter_h = 0;
        cout << "\033[2J"; //clears screen
        usleep(500000);
        title_timer = title_timer + 1;
        
        //increases y coordinate for falling stars
         y_s0 = y_s0 + 1;
         y_s1 = y_s1 + 1;
         y_s2 = y_s2 + 1;
         y_s3 = y_s3 + 1;
         y_s4 = y_s4 + 1;
    }
        
}

void title()           //prints the title
{
    cout << "\033[0m"; //change to normal color to be safe
    
    //the word falling
    cout << "\033[33m" << "     *********     *        *     *    *****    *     *     *******" << endl;
    cout << "\033[33m" << "     *            * *       *     *      *      **    *     *      " << endl;
    cout << "\033[33m" << "     *           *   *      *     *      *      * *   *     *      " << endl;
    cout << "\033[33m" << "     *****      *******     *     *      *      *  *  *     *  ****" << endl;
    cout << "\033[33m" << "     *         *       *    *     *      *      *   * *     *     *" << endl;
    cout << "\033[33m" << "     *        *         *   *     *      *      *    **     *     *" << endl;
    cout << "\033[33m" << "     *       *           *  *     *    *****    *     *     *******" << endl;
    cout << "\033[37m" << "     ********  ***********      *        *******    ********       " << endl;
    cout << "\033[37m" << "     *              *          * *       *      *   *              " << endl;
    cout << "\033[37m" << "     *              *         *   *      *      *   *              " << endl;
    cout << "\033[37m" << "     ********       *        *******     *******    ********       " << endl;
    cout << "\033[37m" << "            *       *       *       *    *     *           *       " << endl;
    cout << "\033[37m" << "            *       *      *         *   *      *          *       " << endl;
    cout << "\033[37m" << "     ********       *     *           *  *       *  ********       " << endl;
    
    cout << endl;
    cout << "Press any character to continue: ";
    cin  >> any_char;
}

int main()
{
    Enemy enemy_main; //allowing class to enter
    
    bool game_over = false; // variable for controling if game is over
    
   title_animation();
   title();
    
    cout << "\033[2J"; // clears screen
    
    //instructions
    cout << "Rules:" << endl;
    cout << "The objective of the game is to avoid being hit by a falling star (*)." << endl;
    cout << "If you get hit by a falling star, please show some chivalry and manually end the game." << endl;
    cout << "When you have decided which direction you want to move in using either the a or d keys, press enter to advance. Pressing w with send you forward" << endl;
    cout << "To exit the game, press e and hit enter." << endl;
    cout << endl;
    cout << "Press any character to continue: ";
    cin  >> any_char;
    
    cout << "\033[2J"; // clears screen
    
    //while statement that keeps the game running
    while(game_over == false)
    {
        //map generator
        while(counter_h <= height)
        {
            while(counter_w <= width)
            {
                
                //keeps player within boundary.
                if(x > width)
                {
                    x = 0;
                }
                if(x < 0)
                {
                    x = width;
                }
                
                else                                      //determines whether the map prints a blank space the player sprite
                {
                    
                    enemy_main.enemy_seeder();            //this is the if statements to get the falling stars to work properly

                    if(counter_w == x and counter_h == y) //finds location of player and prints *
                    {
                        tile = '*';
                        cout << "\033[34m" << tile << "\033[0m";
                    }
                
                    else//if nothing else print out blank spaces
                    {
                        tile = ' ';
                        cout << tile;
                    }
                }
                counter_w = counter_w + 1;  //adds one to width counter
                
            }
            
            counter_w = 0;                  //resets width counter

            cout << endl;
            counter_h = counter_h + 1;      //adds one to height counter

        }
        
        //controls
        cin >> controls;
        switch(controls)
        {
            case 'a':
            x = x - 1;
            break;
                
            case 'd':
            x = x + 1 ;
            break;
                
            case 'w':
            x = x;
            break;
                
            case 'e':
            game_over = true;
            break;
        }
        enemy_main.enemy_logic(); //allows enemies to move down toward the player

        counter_h = 0;
        cout << "\033[2J"; // clears screen
        
    }
    cout << "\033[31m" << "GAME OVER" << "\033[0m" << endl; //Prints game over in red letters
}
