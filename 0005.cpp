#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
 
using namespace std;
 
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
 
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }
 
    int n;
    string line;
    getline(inputFile, line);
    stringstream ss(line);
    ss >> n;
 
    vector<int> a, b;
    getline(inputFile, line);
    stringstream ss2(line);
    int num;
    for (int i = 0; i < n; ++i) {
        ss2 >> num;
        if (num % 2 == 0) {
            b.push_back(num);
        } else {
            a.push_back(num);
        }
    }
 
    for(int x: a) {cout << x << " ";}
    cout << endl;
    for(int x: b) {cout << x << " ";}
    cout << endl;
 
    string ans = (a.size() <= b.size()) ? "YES" : "NO";
    cout << ans << endl;
 
    for(int x: a){ outputFile << x << " ";}
    outputFile << "\n";
    for(int x: b){ outputFile << x << " ";}
    outputFile << "\n";
    outputFile << ans << "\n";
 
    inputFile.close();
    outputFile.close();
 
    return 0;
}
