#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> generateSequence(int n) {
    // Base case: 1-tuple
    if (n == 1) {
        return {"2", "1", "3"};
    }
    
    // Get the (n-1)-tuple sequence
    vector<string> prevSequence = generateSequence(n - 1);
    vector<string> result;
    
    // First copy: append '2' to each element
    for (const string& element : prevSequence) {
        result.push_back(element + "2");
    }
    
    // Second copy: append '1' to each element, then invert the order
    vector<string> secondCopy;
    for (const string& element : prevSequence) {
        secondCopy.push_back(element + "1");
    }
    // Invert (reverse) the second copy
    reverse(secondCopy.begin(), secondCopy.end());
    
    // Add inverted second copy to result
    for (const string& element : secondCopy) {
        result.push_back(element);
    }
    
    // Third copy: append '3' to each element
    for (const string& element : prevSequence) {
        result.push_back(element + "3");
    }
    
    return result;
}

void printSequence(int n) {
    vector<string> sequence = generateSequence(n);
    
    cout << n << "-tuple sequence (" << sequence.size() << " elements):\n";
    for (size_t i = 0; i < sequence.size(); ++i) {
        cout << sequence[i];
        if (i < sequence.size() - 1) {
            cout << ", ";
        }
        // Add line breaks for readability with larger sequences
        if ((i + 1) % 10 == 0 && i < sequence.size() - 1) {
            cout << "\n";
        }
    }
    cout << "\n\n";
}

int main() {
    // Generate and print sequences for n = 1, 2, 3, and 4
    for (int n = 1; n <= 4; ++n) {
        printSequence(n);
    }
    
    // Example: Generate just the 5-tuple sequence
    cout << "5-tuple sequence has " << generateSequence(5).size() << " elements.\n";
    
    return 0;
}