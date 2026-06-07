#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include <utility>
#include "snake_map.h"
#include "macros.h"
#include "input.h"
#include "snake.h"

using namespace std;

Snake snake;
SnakeMap snake_map(&snake);


void initialize()
{
    input_init();
    input_enter_off();
}

bool is_game_end()
{
    bool result = false;
    pair<int, int> snake_head = snake.snake_head;
    if (snake_head.first < 0 || snake_head.first >= MAP_HEIGHT || snake_head.second < 0 || snake_head.second >= MAP_WIDTH)
    {
        result = true;
    }
    if (snake.is_dead)
    {
        result = true;
    }
    return result;
}

void game_over()
{
    cout << "GAME IS OVER" << endl;
}

void start_game()
{
    while (true)
    {
        snake.update_movement();
        if (is_game_end())
        {
            game_over();
            break;
        }

        snake.handlePreview();//new

        if(snake.food_eaten && snake.bHelpMeWin)//new
        {
            snake_map.redrawPreview(); 
        } 
        else
        {
            snake_map.redraw();
        }

        usleep(PAUSE_LENGTH);

        snake.validate_direction();
    }
}

int main(int argc, char* argv[])
{
    //DOTO: run ./snake HelpMeWin
    if(argc == 2)
    {
        if (!strcmp(argv[1],"HelpMeWin"))
        {
            printf("MODE ON\n");
            snake.bHelpMeWin = true;
        }
    }

    initialize();
    start_game();

    return 0;
}
