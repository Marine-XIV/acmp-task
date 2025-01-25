#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>

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

    int n, s, f;
    inputFile >> n >> s >> f;
    
    vector<vector<int>> a(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
             inputFile >> a[i][j];
             if(a[i][j] == -1)
                 a[i][j] = numeric_limits<int>::max();
        }
    }

    
     for (int i = 0; i < n; ++i) {
        cout << "[";
        for(int j = 0; j < n; ++j) {
            cout << a[i][j];
            if(j < n -1)
                cout << ", ";
        }
           cout << "]" << endl;
    }

    vector<int> distances(n, numeric_limits<int>::max());
    vector<bool> visited(n, false);

    distances[s - 1] = 0;

    for (int t = 0; t < n; ++t) {
        int minDist = numeric_limits<int>::max();
        int k = -1;

        for (int i = 0; i < n; ++i) {
            if (distances[i] < minDist && !visited[i]) {
                minDist = distances[i];
                k = i;
            }
        }
         if (k == -1 || minDist == numeric_limits<int>::max()) {
            break;
        }
          cout << "k = " << k << endl;
        visited[k] = true;

        for (int j = 0; j < n; ++j) {
            if (a[k][j] != numeric_limits<int>::max() && 
                distances[k] != numeric_limits<int>::max() &&
                a[k][j] + distances[k] < distances[j]) {
                distances[j] = a[k][j] + distances[k];
            }
        }
    }

    cout << "Distances: [";
    for (int i = 0; i < n; ++i) {
        cout << distances[i];
         if(i < n - 1)
            cout << ", ";
    }
        cout << "]" << endl;
    if (distances[f - 1] == numeric_limits<int>::max()) {
        distances[f - 1] = -1;
    }

    outputFile << distances[f - 1] << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
