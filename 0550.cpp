#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }

    string line;
    getline(inputFile, line);
    int n = stoi(line);

    string ans;
    if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0)) {
        ans = "12/09/";
    } else {
        ans = "13/09/";
    }

    
    outputFile << ans << setfill('0') << setw(4) << n << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}

