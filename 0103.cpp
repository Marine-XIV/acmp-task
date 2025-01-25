#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void readLong(vector<int>& num) {
    string s;
    cin >> s;
    num.resize(s.size() + 1); 
    num[0] = s.size();
    for (size_t i = 0; i < s.size(); ++i) {
        num[s.size() - i] = s[i] - '0'; 
    }
}
 
 
void writeLong(const vector<int>& num) {
    for (int i = num[0]; i >= 1; --i) {
        cout << num[i];
    }
    cout << std::endl;
}
 
int main() {
    const int maxSize = 102;
    vector<int> a(maxSize), b(maxSize);
     
    readLong(a);
    readLong(b);
 
    int m = max(a[0], b[0]);
    int c = 0;
 
    for (int i = 1; i <= m; ++i) {
        c = c + a[i] + b[i];
        a[i] = c % 10;
        c = c / 10;
    }
 
    if (c > 0) {
        m = m + 1;
        a[m] = c;
    }
    a[0] = m;
 
    writeLong(a);
 
    return 0;
}
