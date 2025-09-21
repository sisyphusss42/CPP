#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class SierpinskiTriangle {
private:
    vector<vector<int>> triangle;
    vector<vector<string>> labels;
    set<string> removedNodes;
    
    string generateLabel(int row, int col, int level) {
        if (level == 0) return "";
        
        // We'll build the label recursively
        vector<int> positions;
        
        int currentRow = row;
        int currentCol = col;
        
        // Determine position at each subdivision level
        for (int lev = 1; lev <= level; lev++) {
            int blockSize = 1 << (level - lev);
            
            int pos;
            if (blockSize == 0) {
                pos = 1;
            } else {
                int regionRow = currentRow / blockSize;
                int regionCol = currentCol / blockSize;
                
                if (regionRow == 0) {
                    pos = 1; // Top
                } else if (regionCol < regionRow) {
                    pos = 2; // Left  
                } else {
                    pos = 3; // Right
                }
                
                currentRow = currentRow % blockSize;
                currentCol = currentCol % blockSize;
            }
            
            positions.push_back(pos);
        }
        
        // Build the label using the subdivision rules
        string label = "";
        
        for (int i = 0; i < level; i++) {
            int digit;
            
            if (i == 0) {
                // First digit is the main region
                digit = positions[0];
            } else {
                // Apply the labeling rule
                int prevDigit = label[i-1] - '0';
                int currentPos = positions[i];
                bool isEvenLevel = ((i + 1) % 2 == 0);
                
                // Same corner gets same digit
                if (currentPos == prevDigit) {
                    digit = prevDigit;
                } else {
                    // Apply directional rule based on previous triangle type
                    if (prevDigit == 1) { // T triangle
                        if (isEvenLevel) { // Clockwise: TT(1) → TR(2) → TL(3)
                            digit = (currentPos == 3) ? 2 : 3; // TR=2, TL=3
                        } else { // Counterclockwise: TT(1) → TL(3) → TR(2)
                            digit = (currentPos == 2) ? 3 : 2; // TL=3, TR=2
                        }
                    } else if (prevDigit == 2) { // L triangle
                        if (isEvenLevel) { // Clockwise: LL(2) → LT(3) → LR(1)
                            digit = (currentPos == 1) ? 3 : 1; // LT=3, LR=1
                        } else { // Counterclockwise: LL(2) → LR(1) → LT(3)
                            digit = (currentPos == 3) ? 1 : 3; // LR=1, LT=3
                        }
                    } else { // R triangle (prevDigit == 3)
                        if (isEvenLevel) { // Clockwise: RR(3) → RL(1) → RT(2)
                            digit = (currentPos == 2) ? 1 : 2; // RL=1, RT=2
                        } else { // Counterclockwise: RR(3) → RT(2) → RL(1)
                            digit = (currentPos == 1) ? 2 : 1; // RT=2, RL=1
                        }
                    }
                }
            }
            
            label += to_string(digit);
        }
        
        // Reverse the label since we built it left-to-right but need right-to-left
        reverse(label.begin(), label.end());
        return label;
    }
    
    void generateTriangle(int level) {
        // Calculate correct number of rows
        int rows;
        if (level == 1) {
            rows = 3; // Special case for level 1
        } else {
            rows = 1 << level; // 2^level for higher levels
        }
        
        triangle.assign(rows, vector<int>());
        labels.assign(rows, vector<string>());
        
        // Generate Pascal's triangle modulo 2 (Sierpinski pattern)
        for (int i = 0; i < rows; i++) {
            triangle[i].assign(i + 1, 0);
            labels[i].assign(i + 1, "");
            
            triangle[i][0] = 1; // First element is always 1
            triangle[i][i] = 1; // Last element is always 1
            
            for (int j = 1; j < i; j++) {
                // Pascal's triangle: C(i,j) = C(i-1,j-1) + C(i-1,j)
                // For Sierpinski, we only care about mod 2
                int left = (j-1 < triangle[i-1].size()) ? triangle[i-1][j-1] : 0;
                int right = (j < triangle[i-1].size()) ? triangle[i-1][j] : 0;
                triangle[i][j] = (left + right) % 2;
            }
            
            // Generate labels for nodes that have @ symbols
            for (int j = 0; j < triangle[i].size(); j++) {
                if (triangle[i][j] == 1) {
                    labels[i][j] = generateLabel(i, j, level);
                }
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
                if (triangle[i][j] == 1 && removedNodes.find(labels[i][j]) == removedNodes.end()) {
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
    
    void removeNode(const string& nodeLabel) {
        removedNodes.insert(nodeLabel);
    }
    
    void clearRemovedNodes() {
        removedNodes.clear();
    }
};

int main() {
    SierpinskiTriangle sierpinski;
    
    while (true) {
        int level;
        cout << "Enter the level of Sierpinski triangle (0 to exit): ";
        cin >> level;
        
        if (level == 0) break;
        
        sierpinski.clearRemovedNodes();
        cout << "\nOriginal triangle:" << endl;
        sierpinski.print(level);
        
        string nodeToRemove;
        cout << "\nEnter node label to remove (or press Enter to skip): ";
        cin.ignore(); // Clear the newline from previous input
        getline(cin, nodeToRemove);
        
        if (!nodeToRemove.empty()) {
            // Validate input
            bool valid = true;
            if (nodeToRemove.length() != level) {
                valid = false;
            } else {
                for (char c : nodeToRemove) {
                    if (c != '1' && c != '2' && c != '3') {
                        valid = false;
                        break;
                    }
                }
            }
            
            if (valid) {
                sierpinski.removeNode(nodeToRemove);
                cout << "\nTriangle with node " << nodeToRemove << " removed:" << endl;
                sierpinski.print(level);
            } else {
                cout << "Invalid input! Node label must be " << level << " digits long and contain only 1, 2, or 3." << endl;
            }
        }
        
        cout << "\n" << string(50, '-') << "\n" << endl;
    }
    
    return 0;
}