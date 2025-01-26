#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return 1;
    }
    if (!outputFile.is_open()){
        cerr << "Error opening output file" << endl;
        return 1;
    }

    long long r1, r2, r3;
    inputFile >> r1 >> r2 >> r3;

    if (r2 + r3 <= r1) {
        outputFile << "YES" << endl;
    } else {
        outputFile << "NO" << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
