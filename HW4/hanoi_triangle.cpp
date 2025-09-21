#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SierpinskiTriangle {
private:
    vector<vector<int>> triangle;
    
    void generateTriangle(int level) {
        int rows = (1 << level); // 2^level rows
        triangle.assign(rows, vector<int>());
        
        // Generate Pascal's triangle modulo 2 (Sierpinski pattern)
        for (int i = 0; i < rows; i++) {
            triangle[i].assign(i + 1, 0);
            triangle[i][0] = 1; // First element is always 1
            if (i > 0) triangle[i][i] = 1; // Last element is always 1 (except for first row)
            
            for (int j = 1; j < i; j++) {
                // Pascal's triangle: C(i,j) = C(i-1,j-1) + C(i-1,j)
                // For Sierpinski, we only care about mod 2
                int left = (j-1 < triangle[i-1].size()) ? triangle[i-1][j-1] : 0;
                int right = (j < triangle[i-1].size()) ? triangle[i-1][j] : 0;
                triangle[i][j] = (left + right) % 2;
            }
        }
    }
    
public:
    void print(int level) {
        if (level < 1) {
            cout << "Level must be at least 1" << endl;
            return;
        }
        
        generateTriangle(level);
        int rows = triangle.size();
        int maxWidth = (rows - 1) * 4; // Each @ takes 4 positions (@ + 3 spaces), minus final 3 spaces
        
        for (int i = 0; i < rows; i++) {
            // Calculate leading spaces for centering
            int leadingSpaces = (maxWidth - (triangle[i].size() - 1) * 4) / 2;
            
            // Print leading spaces
            for (int s = 0; s < leadingSpaces; s++) {
                cout << " ";
            }
            
            // Print the row
            for (int j = 0; j < triangle[i].size(); j++) {
                if (triangle[i][j] == 1) {
                    cout << "@";
                } else {
                    cout << " ";
                }
                
                // Add 3 spaces between positions (except for the last element)
                if (j < triangle[i].size() - 1) {
                    cout << "   ";
                }
            }
            
            cout << endl;
            
            // Add blank line after each row (except the last one)
            if (i < rows - 1) {
                cout << endl;
            }
        }
    }
};

int main() {
    int input;
    cout << "Enter the level of Sierpinski triangle: ";
    cin >> input;
    cout << endl;
    
    SierpinskiTriangle sierpinski;
    sierpinski.print(input);
    cout << endl;
    
    return 0;
}