#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HanoiTriangle {
private:
    vector<vector<int>> vertices;
    vector<vector<int>> edges;
    
    void generateVertices(int level) {
        int rows = (1 << level);
        vertices.assign(rows, vector<int>());
        
        for (int i = 0; i < rows; i++) {
            vertices[i].assign(i + 1, 0);
            vertices[i][0] = 1;
            if (i > 0) vertices[i][i] = 1;
            
            for (int j = 1; j < i; j++) {
                int left = (j-1 < vertices[i-1].size()) ? vertices[i-1][j-1] : 0;
                int right = (j < vertices[i-1].size()) ? vertices[i-1][j] : 0;
                vertices[i][j] = (left + right) % 2;
            }
        }
    }
    
    void generateEdges(int n) {
        edges.assign(4100, vector<int>(4100, 0));
        edges[0][0] = 6;
        edges[1][0] = 4;
        edges[1][1] = 2;
        edges[2][0] = 3;
        edges[2][2] = 5;
        
        int width = 1;
        for (int i = 2; i <= n; i++) {
            for (int r = 0; r < width; r++) {
                for (int c = 0; c < width; c++) {
                    edges[width*3+3+r][c] = edges[r][c];
                    edges[width*3+3+r][width*3+3+c] = edges[r][c];
                    edges[width*2+2+r][c] = edges[width*1+1+r][width*1+1+c];
                    edges[width*3+3+r][width*2+2+c] = edges[width*1+1+r][width*1+1+c];
                    edges[width*3+3+r][width*1+1+c] = edges[width*1+1+r][c];
                    edges[width*2+2+r][width*2+2+c] = edges[width*1+1+r][c];
                    
                    edges[width*2+1][0] = 4;
                    edges[width*2+1][width*2+1] = 2;
                    edges[width*3+2][width*1] = 2;
                    edges[width*3+2][width*2+2] = 4;
                    edges[width*4+2][width*1] = 1;
                    edges[width*4+2][width*3+2] = 1;
                }
            }
            width = width * 2 + 1;
        }
    }
    
public:
    void print(int level) {
        if (level < 0) {
            cout << "Level must be at least 1" << endl;
            return;
        }
        else if (level == 0){
            cout << "@";
            return;
        }
        
        generateVertices(level);
        generateEdges(level);
        
        int vertexRows = vertices.size();
        int triangleRows = (1 << level) - 1; // Number of triangle rows
        
        // Create output grid
        int totalRows = vertexRows * 2 - 1; // Vertices + edge rows
        int maxCols = (vertexRows - 1) * 4 + 1;
        vector<vector<char>> output(totalRows, vector<char>(maxCols, ' '));
        
        // Place vertices
        for (int i = 0; i < vertexRows; i++) {
            int leadingSpaces = (maxCols - 1 - (vertices[i].size() - 1) * 4) / 2;
            for (int j = 0; j < vertices[i].size(); j++) {
                if (vertices[i][j] == 1) {
                    int col = leadingSpaces + j * 4;
                    output[i * 2][col] = '@';
                }
            }
        }
        
        // Place edges based on triangle coordinates
        for (int triRow = 0; triRow < triangleRows; triRow++) {
            for (int triCol = 0; triCol <= triRow; triCol++) {
                if (triRow < edges.size() && triCol < edges[triRow].size()) {
                    int edgeValue = edges[triRow][triCol];
                    
                    // Calculate position of this triangle's center
                    int baseRow = triRow * 2 + 1; // Edge row between vertex rows
                    int leadingSpaces = (maxCols - 1 - triRow * 4) / 2;
                    int baseCol = leadingSpaces + triCol * 4;
                    
                    // Place edges based on binary flags
                    if (edgeValue & 4) { // / edge
                        if (baseRow < totalRows && baseCol - 1 >= 0)
                            output[baseRow][baseCol - 1] = '/';
                    }
                    if (edgeValue & 2) { // \ edge  
                        if (baseRow < totalRows && baseCol + 1 < maxCols)
                            output[baseRow][baseCol + 1] = '\\';
                    }
                    if (edgeValue & 1) { // --- edge
                        if (baseRow + 1 < totalRows) {
                            for (int k = -1; k <= 1; k++) {
                                if (baseCol + k >= 0 && baseCol + k < maxCols)
                                    output[baseRow + 1][baseCol + k] = '-';
                            }
                        }
                    }
                }
            }
        }
        
        // Print output with consistent line lengths
        for (int i = 0; i < totalRows; i++) {
            string line = "";
            for (int j = 0; j < maxCols; j++) {
                line += output[i][j];
            }
            cout << line;
            if (i < totalRows - 1) cout << endl;
        }
    }
};

int main() {
    int input;
    cin >> input;
    
    HanoiTriangle hanoi;
    hanoi.print(input);
    
    return 0;
}