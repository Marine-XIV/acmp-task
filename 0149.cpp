#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

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

    int n;
    inputFile >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> numbers[i];
    }

    reverse(numbers.begin(), numbers.end());

    for (int i = 0; i < n; ++i) {
        outputFile << numbers[i] << (i == n - 1 ? "" : " ");
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
