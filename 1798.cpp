#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    int A, N;
    cin >> A >> N;
 
     
    if (A > 9 * N) {
        cout << -1 << endl;
        return 0;
    }
 
    string result;
     
     
    for (int i = 0; i < N; ++i) {
        
        int digit = min(9, A);
        result += to_string(digit);
        A -= digit; 
    }
 
     
    if (A > 0) {
        cout << -1 << endl;
        return 0;
    }
 
    cout << result << endl;
 
    return 0;
}
