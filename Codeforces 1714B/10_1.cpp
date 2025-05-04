#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function prototype
int calculateMinimumMoves(const vector<int>& a);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << calculateMinimumMoves(a) << '\n';
    }
    
    return 0;
}

// Function definition
int calculateMinimumMoves(const vector<int>& a) {
    unordered_set<int> seen;
    int result = 0;
    
    // Start from the end and move left to find the rightmost duplicate
    for (int i = a.size() - 1; i >= 0; i--) {
        if (seen.count(a[i])) {
            result = i + 1;
            break;
        }
        seen.insert(a[i]);
    }
    
    return result;
}