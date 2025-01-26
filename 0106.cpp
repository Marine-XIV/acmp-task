#include <iostream>
using namespace std;
 
int main() {
    int n; 
    cin >> n;
    int kk = 0;
    for (int i = 0; i < n; ++i) {
        int tk; 
        cin >> tk;
        kk +=tk;
    }
    cout << min(n - kk, kk);
}
