#include <iostream>

using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}


long long combinations(int n, int k){
    if (k < 0 || k > n){
        return 0;
    }
    return factorial(n) / (factorial(k) * factorial(n - k));
}


int main() {
    int n, k;
    cin >> n >> k;

    if (k > n) {
        cout << 0 << endl;
    } else {
        long long ways = combinations(n, k);
        long long perms = 1;
        for(int i = 0; i < k; ++i)
          perms *= (n - i);
        
        cout << ways * perms << endl;
    }

    return 0;
}
