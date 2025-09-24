#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int nt, np;
    cin >> nt >> np;

    multiset<int> tickets;
    for (int i = 0; i < nt; i++) {
        int t; cin >> t;
        tickets.insert(t);
    }

    for (int i = 0; i < np; i++) {
        int p; cin >> p;
        auto it = tickets.upper_bound(p); // first ticket > p
        if (it == tickets.begin()) {
            cout << -1 << "\n"; // no ticket ≤ p
        } else {
            --it; // now points to largest ticket ≤ p
            cout << *it << "\n";
            tickets.erase(it); // O(log n)
        }
    }
    return 0;
}
