#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;
 
const int INF = numeric_limits<int>::max(); 
 
int main() {
    int n;
    cin >> n;
 
 
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }
 
 
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] < INF && graph[k][j] < INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
 
    
    vector<vector<int>> result(n, vector<int>(n, 0));
 
  
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                result[i][j] = 1;
            } else if (graph[i][j] < INF) {
                result[i][j] = 1; 
            } else {
                result[i][j] = 0; 
            }
        }
    }
 
    
    for (int k = 0; k < n; ++k) {
        if (graph[k][k] < 0) { 
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (graph[i][k] < INF && graph[k][j] < INF) {
                        result[i][j] = 2;
                    }
                }
            }
        }
    }
 
     
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
 
    return 0;
}
