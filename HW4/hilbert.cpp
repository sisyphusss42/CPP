#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<char>> grid;
int n;

void draw_hilbert(int level, int x, int y, int dx, int dy, int dx2, int dy2) {
    if (level == 0) {
        int x1 = x, y1 = y;
        int x2 = x + dx, y2 = y + dy;
        int x3 = x + dx + dx2, y3 = y + dy + dy2;
        
        // Draw corners
        grid[y1][x1] = '+';
        grid[y2][x2] = '+';
        grid[y3][x3] = '+';
        
        // Draw horizontal segments
        if (dx != 0) {
            int start = min(x1, x2);
            int end = max(x1, x2);
            for (int i = start + 1; i < end; i++) {
                grid[y1][i] = (grid[y1][i] == '|' || grid[y1][i] == '+') ? '+' : '-';
            }
        }
        
        // Draw vertical segments
        if (dy != 0) {
            int start = min(y1, y2);
            int end = max(y1, y2);
            for (int j = start + 1; j < end; j++) {
                grid[j][x1] = (grid[j][x1] == '-' || grid[j][x1] == '+') ? '+' : '|';
            }
        }
        
        // Draw the second segment
        if (dx2 != 0) {
            int start = min(x2, x3);
            int end = max(x2, x3);
            for (int i = start + 1; i < end; i++) {
                grid[y2][i] = (grid[y2][i] == '|' || grid[y2][i] == '+') ? '+' : '-';
            }
        }
        
        if (dy2 != 0) {
            int start = min(y2, y3);
            int end = max(y2, y3);
            for (int j = start + 1; j < end; j++) {
                grid[j][x2] = (grid[j][x2] == '-' || grid[j][x2] == '+') ? '+' : '|';
            }
        }
    } else {
        draw_hilbert(level - 1, x, y, dx2, dy2, dx, dy);
        draw_hilbert(level - 1, x + dx, y + dy, dx, dy, dx2, dy2);
        draw_hilbert(level - 1, x + dx + dx2, y + dy + dy2, dx, dy, dx2, dy2);
        draw_hilbert(level - 1, x + dx + dx2 - dx2, y + dy + dy2 - dy2, -dx2, -dy2, -dx, -dy);
    }
}

int main() {
    int level;
    cin >> level;
    
    if (level < 1) return 0;
    
    n = pow(2, level);
    int grid_size = 2 * n - 1;
    grid.resize(grid_size, vector<char>(grid_size, ' '));
    
    draw_hilbert(level - 1, 0, 0, grid_size - 1, 0, 0, grid_size - 1);
    
    // Output the grid
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    return 0;
}