#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits> // Для INT_MIN и INT_MAX

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    vector<int> a(n);
    int summ = 0;
    
    for (int i = 0; i < n; ++i) {
        inputFile >> a[i];
        if (a[i] > 0) {
            summ += a[i];
        }
    }

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int minIndex = -1;
    int maxIndex = -1;

    for (int i = 0; i < n; ++i) {
      if (a[i] < minVal) {
        minVal = a[i];
        minIndex = i;
      }
      if (a[i] > maxVal) {
        maxVal = a[i];
        maxIndex = i;
      }
    }

    long long pr = 1; 
    int start = min(minIndex, maxIndex);
    int end = max(minIndex, maxIndex);


    for(int i = start + 1; i < end; i++){
        pr *= a[i];
    }

    cout << summ << " " << pr << endl;
    outputFile << summ << " " << pr << endl;


    inputFile.close();
    outputFile.close();

    return 0;
}

