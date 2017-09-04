#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dungeon_rows 21
#define dungeon_columns 80
#define num_rooms 5

char dungeon[dungeon_rows][dungeon_columns];
int rooms[5][4];

int check_rooms(int rows, int columns, int start_row, int start_column);
void init_rooms(void);
void add_rooms(void);
void add_corridors(void);
void init_dungeon(void);
void print_dungeon(void);

int main()
{
    init_dungeon();
    add_rooms();
    print_dungeon();

    return 0;
}

void add_rooms(void)
{
    int room_counter;
    int start_row, start_column;
    int rows, columns;
    int i, j;

    room_counter = 0;

    srand(time(NULL));

    while(room_counter < 5)
    {
        int success = 1;

        //random row from 3 - 9
        rows = (rand() % 7) + 3;

        //random col from 3 - 9
        columns = (rand() % 7) + 3;

        //random row from 1 - 12
        start_row = (rand() % 11) + 1;

        //random col from 1 - 71
        start_column = (rand() % 70) + 1;

        success = check_rooms(rows, columns, start_row, start_column);

        /*
         * Add room to the dungeon & then increment the room counter
         */
        if(success)
        {
            printf("room rows: %d, room columns: %d, start_row: %d, start_column: %d\n", rows, columns, start_row, start_column);

            for(i = start_row; i < (start_row + rows); i++)
            {
                for(j = start_column; j < (start_column + columns); j++)
                {
                    dungeon[i][j] = '.';
                }
            }

            rooms[room_counter][0] = rows;
            rooms[room_counter][1] = columns;
            rooms[room_counter][2] = start_row;
            rooms[room_counter][3] = start_column;

            room_counter++;
        }

    }
}

void init_rooms(void)
{
    int i, start_row, start_column, rows, columns;

    srand(time(NULL));

    for(i = 0; i < 5; i++)
    {
        //random row from 3 - 9
        rows = (rand() % 7) + 3;

        //random col from 3 - 9
        columns = (rand() % 7) + 3;

        //random row from 1 - 12
        start_row = (rand() % 11) + 1;

        //random col from 1 - 72
        start_column = (rand() % 71) + 1;

        rooms[i][0] = start_row;
        rooms[i][1] = start_column;
        rooms[i][2] = rows;
        rooms[i][3] = columns;
    }
}

int check_rooms(int rows, int columns, int start_row, int start_column)
{
    int i = 0;
    int j = 0;

    //checks to see if there is nothing above room
    for(i = (start_row - 3); i < start_row; i++)
    {
        for(j = start_column; j < (start_column + columns); j++)
        {
            if(dungeon[i][j] == '.')
            {
                return 0;
            }
        }
    }


    //checks to see if there is nothing below room

    for(i = (start_row + rows); i < (start_row + rows + 3); i++)
    {
        for(j = start_column; j < (start_column + columns); j ++)
        {
            if(dungeon[i][j] == '.')
            {
                return 0;
            }
        }
    }


    //checks to see if there is nothing to the right
    for(i = start_row; i < (start_row + rows); i++)
    {
        for(j = (start_column + columns); j < (start_column + columns + 3); j++)
        {
            if(dungeon[i][j] == '.')
            {
                return 0;
            }
        }
    }

    //checks to see if there is nothing to the left
    for(i = start_row; i < (start_row + rows); i++)
    {
        for(j = (start_column - columns); j < start_column; j++)
        {
            if(dungeon[i][j] == '.')
            {
                return 0;
            }
        }
    }


    return 1;
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
