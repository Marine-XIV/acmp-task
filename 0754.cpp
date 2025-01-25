#include <iostream>
using namespace std;

int main() {
    int m1, m2, m3;
    cin >> m1 >> m2 >> m3;
    if (max(max(m1, m2), m3) <= 727 && min(min(m1, m2), m3) >= 94) {
        cout << max(max(m1, m2), m3);
    } else {
       cout << "Error";
    }
}
