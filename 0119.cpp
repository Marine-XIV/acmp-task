#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple> 
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
    istringstream iss(line);
    int n;
    iss >> n;

    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; ++i) {
        getline(inputFile, line);
        istringstream iss(line);
        iss >> a[i] >> b[i] >> c[i];
    }
    
    cout << "a: ";
    for (int val : a) {
        cout << val << " ";
    }
    cout << endl;

    cout << "b: ";
    for (int val : b) {
        cout << val << " ";
    }
    cout << endl;

    cout << "c: ";
    for (int val : c) {
        cout << val << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (tie(a[j], b[j], c[j]) < tie(a[j - 1], b[j - 1], c[j - 1]))
            {
                swap(a[j], a[j - 1]);
                swap(b[j], b[j - 1]);
                swap(c[j], c[j - 1]);
            }
        }
    }
    
     cout << "Sorted a: ";
    for (int val : a) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Sorted b: ";
    for (int val : b) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Sorted c: ";
    for (int val : c) {
        cout << val << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        outputFile << a[i] << " " << b[i] << " " << c[i] << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

