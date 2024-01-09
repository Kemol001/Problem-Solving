// Ahmed, Mohamed and Omar are planning to have a meeting at some place. Their apartments are located at different
// points in a rectangular grid of size M*N. They want to meet in minimum time.
// The grid contains some impassable points (denoted by a '#'). None of them wants to step over these points. 
// They can only step over passable points (denoted by a '.'). They can also meet at some point outside the grid. 
// You can assume that the points outside the grid are all passable. They cannot party on an impassable point and
// their apartments exist only on passable points. They can move either to a North, South, East or West passable
// point from the current passable point and it takes 1 unit time to do so. Also they can wait at a passable point
// if they want to.
// Find the minimum time of meeting.
// Note: Assume that they will always meet at some point.
// Input
// First line gives T, the number of test cases.
// Each test case has two space separated integers M and N, the dimensions of the grid.
// Next M lines contain N characters per line (no spaces). 
// Characters can be either “#” (impassable) or “.” (passable) or “1” (Ahmed’s apartment) or “2” (Mohamed’s 
// apartment) or “3” (Omar’s apartment).
// Each test case will have exactly 1 “1”, exactly 1 “2” and exactly 1 “3”.
// 1<=T<=10
// 1<=M<=200
// 1<=N<=200
// Output
// Output T lines, each containing the required answer.

#include <iostream>
#include <queue>

using namespace std;

int timeNeeded[202][202][3];
bool visited[202][202][3];
char grid[202][202];
int characterHomes[3][2];
int gridRows, gridColumns;

void clear_grids()
{
    for (int i = 0; i < 202; i++)
    {
        for (int j = 0; j < 202; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                timeNeeded[i][j][k] = 0;
                visited[i][j][k] = false;
            }
            grid[i][j] = ' ';
        }
    }
}

void bfs(int character_index, int character_i_position, int character_j_position)
{
    queue<int> queue;
    int starting_point_flattened_position = character_i_position * gridColumns + character_j_position;
    queue.push(starting_point_flattened_position);
    visited[character_i_position][character_j_position][character_index] = true;
    while (!queue.empty())
    {
        int flattened_position = queue.front();
        queue.pop();
        int x = flattened_position / gridColumns;
        int y = flattened_position - (x * gridColumns);
        // check above you
        if (x > 0 && !visited[x - 1][y][character_index] && grid[x - 1][y] != '#')
        {
            timeNeeded[x - 1][y][character_index] = timeNeeded[x][y][character_index] + 1;
            visited[x - 1][y][character_index] = true;
            queue.push((x - 1) * gridColumns + y);
        }
        if (y > 0 && !visited[x][y - 1][character_index] && grid[x][y - 1] != '#')
        {
            timeNeeded[x][y - 1][character_index] = timeNeeded[x][y][character_index] + 1;
            visited[x][y - 1][character_index] = true;
            queue.push(x * gridColumns + y - 1);
        }
        if (x < (gridRows - 1) && !visited[x + 1][y][character_index] && grid[x + 1][y] != '#')
        {
            timeNeeded[x + 1][y][character_index] = timeNeeded[x][y][character_index] + 1;
            queue.push((x + 1) * gridColumns + y);
            visited[x + 1][y][character_index] = true;
        }
        if (y < (gridColumns - 1) && !visited[x][y + 1][character_index] && grid[x][y + 1] != '#')
        {
            timeNeeded[x][y + 1][character_index] = timeNeeded[x][y][character_index] + 1;
            queue.push((x * gridColumns + y + 1));
            visited[x][y + 1][character_index] = true;
        }
    }
}

int main()
{
    int number_of_test_cases;
    cin >> number_of_test_cases;
    while (number_of_test_cases--)
    {
        clear_grids();
        char grid_character;
        cin >> gridRows >> gridColumns;
        // if meeting was outside of grid
        gridRows += 2;
        gridColumns += 2;

        // set the the two rows of the extra layer
        for (int j = 0; j < gridColumns; j++)
            grid[gridRows - 1][j] = grid[0][j] = '.';

        for (int i = 1; i < gridRows - 1; i++)
        {
            grid[i][0] = grid[i][gridColumns - 1] = '.';
            for (int j = 1; j < gridColumns - 1; j++)
            {
                cin >> grid_character;
                grid[i][j] = grid_character;
                if (grid_character == '1')
                {
                    characterHomes[0][0] = i;
                    characterHomes[0][1] = j;
                }
                if (grid_character == '2')
                {
                    characterHomes[1][0] = i;
                    characterHomes[1][1] = j;
                }
                if (grid_character == '3')
                {
                    characterHomes[2][0] = i;
                    characterHomes[2][1] = j;
                }
            }
        }

        bfs(0, characterHomes[0][0], characterHomes[0][1]);
        bfs(1, characterHomes[1][0], characterHomes[1][1]);
        bfs(2, characterHomes[2][0], characterHomes[2][1]);

        int optimal_meeting_time_needed = 1e8;
        for (int i = 0; i < gridRows; ++i)
        {
            for (int j = 0; j < gridColumns; ++j)
            {
                if (!(visited[i][j][0] && visited[i][j][1] && visited[i][j][2]))
                    continue;
                int time_needed_to_meet_in_this_point = max(max(timeNeeded[i][j][0], timeNeeded[i][j][1]), timeNeeded[i][j][2]);
                optimal_meeting_time_needed = min(time_needed_to_meet_in_this_point, optimal_meeting_time_needed);
            }
        }
        cout << optimal_meeting_time_needed << "\n";
    }
    return 0;
}