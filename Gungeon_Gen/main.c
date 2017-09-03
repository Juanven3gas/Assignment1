#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dungeon_rows 21
#define dungeon_columns 80
#define num_rooms 5

char dungeon[dungeon_rows][dungeon_columns];

void add_rooms(void)
{
    int i, j , k;

    srand(time(NULL));

    for(i = 0; i < num_rooms; i++)
    {
        int x_dim = (rand() % 6) + 3;
        int y_dim = (rand() % 6) + 2;

        //Check the perimeter
        for()
        {
            for()
            {

            }
        }

    }
}

void init_dungeon(void)
{
    int i, j;

    for(i = 0; i < dungeon_rows; i++)
    {
        for(j = 0; j < dungeon_columns; j++)
        {
            dungeon[i][j] = ' ';
            dungeon[0][j] = '-';
            dungeon[dungeon_rows - 1][j] = '-';
        }

        dungeon[i][0] = '|';
        dungeon[i][dungeon_columns - 1] = '|';
    }
}

void print_dungeon(void)
{
    int i, j;

    for(i = 0; i < dungeon_rows; i++)
    {
        for(j = 0; j < dungeon_columns; j++)
        {
            printf("%c", dungeon[i][j]);
        }

        printf("\n");
    }

}

int main()
{
    init_dungeon();
    print_dungeon();

    return 0;
}
