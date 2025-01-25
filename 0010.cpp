#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long ipow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    long long a, b, c, d;
    inputFile >> a >> b >> c >> d;

    vector<int> roots;
    for (int x = -100; x <= 100; ++x) {
        if (a * ipow(x, 3) + b * ipow(x, 2) + c * x + d == 0) {
            roots.push_back(x);
        }
    }

    sort(roots.begin(), roots.end());
    roots.erase(unique(roots.begin(), roots.end()), roots.end()); 

    for (size_t i = 0; i < roots.size(); ++i) {
        outputFile << roots[i] << (i == roots.size() - 1 ? "" : " ");
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}

