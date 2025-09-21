#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class HilbertCurve {
private:
    int level;
    int size;
    vector<vector<bool>> horizontal; // horizontal line segments
    vector<vector<bool>> vertical;   // vertical line segments
    vector<pair<int, int>> path;     // store the path points
    
    // Convert Hilbert curve index to (x, y) coordinates
    pair<int, int> hilbertToXY(int n, int d) {
        int x = 0, y = 0;
        for (int s = 1; s < n; s *= 2) {
            int rx = 1 & (d / 2);
            int ry = 1 & (d ^ rx);
            if (ry == 0) {
                if (rx == 1) {
                    x = s - 1 - x;
                    y = s - 1 - y;
                }
                swap(x, y);
            }
            x += s * rx;
            y += s * ry;
            d /= 4;
        }
        return {x, y};
    }
    
public:
    HilbertCurve(int n) : level(n) {
        size = (1 << n); // 2^n
        int total_points = size * size;
        
        // Initialize grids
        horizontal.assign(size, vector<bool>(size - 1, false));
        vertical.assign(size - 1, vector<bool>(size, false));
        
        // Generate path points using Hilbert curve algorithm
        for (int i = 0; i < total_points; i++) {
            auto point = hilbertToXY(size, i);
            path.push_back(point);
        }
        
        // Connect consecutive points with line segments
        for (int i = 0; i < path.size() - 1; i++) {
            int x1 = path[i].first, y1 = path[i].second;
            int x2 = path[i + 1].first, y2 = path[i + 1].second;
            
            if (x1 == x2) { // vertical line
                int min_y = min(y1, y2);
                vertical[min_y][x1] = true;
            } else if (y1 == y2) { // horizontal line
                int min_x = min(x1, x2);
                horizontal[y1][min_x] = true;
            }
        }
    }
    
    void print() {
        // Print the grid
        for (int row = 0; row < size; row++) {
            // Print horizontal connections and vertices
            for (int col = 0; col < size; col++) {
                cout << "+";
                if (col < size - 1) {
                    if (horizontal[row][col]) {
                        cout << "--";
                    } else {
                        cout << "  ";
                    }
                }
            }
            cout << endl;
            
            // Print vertical connections (if not last row)
            if (row < size - 1) {
                for (int col = 0; col < size; col++) {
                    if (vertical[row][col]) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                    if (col < size - 1) {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
        }
    }
};

int main() {
    int n;
    //cout << "Enter level: ";
    cin >> n;
    
    if (n < 1) {
        cout << "Level must be at least 1" << endl;
        return 1;
    }
    
    HilbertCurve curve(n);
    curve.print();
    
    return 0;
}