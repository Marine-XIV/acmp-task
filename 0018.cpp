#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> multiply(const vector<int>& num, int multiplier) {
    vector<int> result;
    int carry = 0;
    for (int digit : num) {
        int product = digit * multiplier + carry;
        result.push_back(product % 10);
        carry = product / 10;
    }
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
    return result;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    inputFile >> n;

    
    vector<int> factorial = {1};

  
    for (int i = 2; i <= n; ++i) {
        factorial = multiply(factorial, i);
    }

    for (int i = factorial.size() - 1; i >= 0; --i) {
        outputFile << factorial[i];
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}

