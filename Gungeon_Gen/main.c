#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dungeon_rows 21
#define dungeon_columns 80
#define num_rooms 5

char dungeon[dungeon_rows][dungeon_columns];
char rooms[5][4];

void add_rooms(void);
void init_rooms(void);
void init_dungeon(void);
void print_dungeon(void);

int main()
{
    init_dungeon();
    //add_rooms();
    print_dungeon();

    return 0;
}

void add_rooms(void)
{
    int i, j;
    int start_row, start_column;
    int rows, columns;

    srand(time(NULL));

    rows = (rand() % 7) + 3;
    columns = (rand() % 7) + 2;
    start_row = (rand() % 24) + 1;
    start_column = (rand() % 81) + 1;

    printf("room rows: %d, room columns: %d, start_row: %d, start_column: %d\n", rows, columns, start_row, start_column);

    for(i = start_row; i < (start_row + rows); i++)
    {
        for(j = start_column; j < (start_column + columns); j++)
        {
            dungeon[i][j] = '.';
        }
    }
}

void init_rooms(void)
{
    srand(time(NULL));


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
