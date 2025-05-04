#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function prototype
vector<int> calculateScores(const vector<vector<string>>& words);

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<string>> words(3, vector<string>(n));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> words[i][j];
            }
        }
        
        vector<int> scores = calculateScores(words);
        cout << scores[0] << " " << scores[1] << " " << scores[2] << '\n';
    }
    
    return 0;
}

// Function definition
vector<int> calculateScores(const vector<vector<string>>& words) {
    unordered_map<string, int> wordCount;
    vector<int> scores(3, 0);
    
    // Count occurrences of each word
    for (int i = 0; i < 3; i++) {
        for (const string& word : words[i]) {
            wordCount[word]++;
        }
    }
    
    // Calculate scores
    for (int i = 0; i < 3; i++) {
        for (const string& word : words[i]) {
            if (wordCount.at(word) == 1) {
                scores[i] += 3;
            } else if (wordCount.at(word) == 2) {
                scores[i] += 1;
            }
        }
    }
    
    return scores;
}