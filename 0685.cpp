#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return 1;
    }
    if(!outputFile.is_open()){
        cerr << "Error opening output file" << endl;
        return 1;
    }

    vector<int> prices(3);
    vector<int> capacities(3);

    for (int i = 0; i < 3; ++i) {
        inputFile >> prices[i];
    }
    for (int i = 0; i < 3; ++i){
        inputFile >> capacities[i];
    }
    
    sort(prices.begin(), prices.end(), greater<int>());
    sort(capacities.begin(), capacities.end(), greater<int>()); 

    long long total_value = 0;
    for (int i = 0; i < 3; ++i) {
        total_value += (long long)prices[i] * capacities[i];
    }

    outputFile << total_value << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}

