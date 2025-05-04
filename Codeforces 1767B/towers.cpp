#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class TowerOptimizer {
private:
    vector<int> results; // Stores the results for each test case

public:
    void processTestCases(); // Function to process all test cases
    void maximizeFirstTower(int num, vector<int>& towercount); // Function to maximize the first tower
    void displayResults(); // Function to display the results
};

// Main function
int main() {
    TowerOptimizer optimizer;
    optimizer.processTestCases(); // Process all test cases
    optimizer.displayResults();   // Display the results
    return 0;
}

// Function to process all test cases
void TowerOptimizer::processTestCases() {
    int testcase;
    cout << "Enter number of test cases: ";
    cin >> testcase;

    while (testcase--) {
        int num;
        cout << "Enter number of towers: ";
        cin >> num;

        vector<int> towercount(num); // Vector to store the number of blocks in each tower
        cout << "Enter the number of blocks in each tower: ";
        for (int i = 0; i < num; i++) {
            cin >> towercount[i]; // Input the blocks for each tower
        }

        maximizeFirstTower(num, towercount); // Maximize the first tower
    }
}

// Function to maximize the first tower's blocks
void TowerOptimizer::maximizeFirstTower(int num, vector<int>& towercount) {
    // Sort all towers except the first in ascending order
    sort(towercount.begin() + 1, towercount.end());

    // Compare each tower with the first tower and maximize the first tower
    for (int i = 1; i < num; i++) {
        if (towercount[i] > towercount[0]) {
            int difference = towercount[i] - towercount[0];
            towercount[0] += (difference + 1) / 2; // Increment first tower by half of the difference
        }
    }

    results.push_back(towercount[0]); // Store the result for this test case
}

// Function to display the results
void TowerOptimizer::displayResults() {
    cout << "Maximized first tower blocks for each test case:" << endl;
    for (int result : results) {
        cout << result << endl;
    }
}

/*
Explanation:
1. The program processes multiple test cases.
2. For each test case, it takes the number of towers and the blocks in each tower.
3. It sorts all towers except the first in ascending order.
4. It compares each tower with the first tower and maximizes the first tower by adding half of the difference.
5. Finally, it displays the results for all test cases.

Time Complexity:
- Sorting: O(n log n), where n is the number of towers.
- Maximizing the first tower: O(n), where n is the number of towers.
Overall Time Complexity: O(n log n) per test case.
*/