#include <iostream>
#include <fstream>
#include <string>
 
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
 
    int month;
    inputFile >> month;
    string season;
 
    if (month < 1 || month > 12) {
        season = "Error";
    } else if (month == 1 || month == 2 || month == 12) {
        season = "Winter";
    } else if (month == 3 || month == 4 || month == 5) {
        season = "Spring";
    } else if (month == 6 || month == 7 || month == 8) {
        season = "Summer";
    } else {
        season = "Autumn";
    }
 
    outputFile << season << endl;
 
    inputFile.close();
    outputFile.close();
 
    return 0;
}
