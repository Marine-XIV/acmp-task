#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long w, h, r;
    cin >> w >> h >> r;

    if (2 * r <= w && 2 * r <= h) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
