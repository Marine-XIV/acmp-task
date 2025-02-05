#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
 
    long long a, b;
    inputFile >> a >> b;
 
    long long remainder = a % b;
 
    if (remainder < 0) {
        remainder += abs(b);
    }
 
    outputFile << remainder << endl;
 
    inputFile.close();
    outputFile.close();
 
    return 0;
}
