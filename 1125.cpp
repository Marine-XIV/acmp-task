#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
 
using namespace std;
 
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
 
    int n;
    inputFile >> n;
 
    vector<long long> squares;
    for (long long i = 1; ; ++i) {  
        long long square = i * i;
        if (square > n) {
            break;
        }
        squares.push_back(square);
    }
 
    
    for (size_t i = 0; i < squares.size(); ++i) {
        outputFile << squares[i];
        if (i < squares.size() - 1) {
            outputFile << " ";
        }
    }
    outputFile << endl;
 
    inputFile.close();
    outputFile.close();
 
    return 0;
}
