#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compareStrings(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length(); 
    }
    return a < b;
}


int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    string n, m, k;
    inputFile >> n >> m >> k;

    vector<string> nums = {n, m, k};
    string maxVal = *max_element(nums.begin(), nums.end(), compareStrings);

    cout << maxVal << endl;
    outputFile << maxVal << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}

