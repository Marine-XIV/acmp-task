#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

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
    int x = stoi(line);

    string n = "";
    while (x > 0) {
        string y = to_string(x % 2);
        n = y + n;
        x = x / 2;
    }
    
    cout << n << endl;
    
     vector<char> n_list(n.begin(), n.end());
    cout << "[";
    for (size_t i = 0; i < n_list.size(); ++i) {
        cout << n_list[i];
        if (i < n_list.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    

    int k = 0;
    for (char bit : n_list) {
        if (bit == '1') {
            k = k + 1;
        }
    }

    cout << k << endl;
    outputFile << k << endl;
    
    inputFile.close();
    outputFile.close();

    return 0;
}

