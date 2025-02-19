#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    string s;
    cin >> s;
 
    int n = s.length();
    int j = -1;
 
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] < s[i + 1]) {
            j = i;
        }
    }
 
    
    if (j == -1) {
        return 0;
    }
 
    int l = j + 1;
 
     
    for (int i = j + 1; i < n; ++i) {
        if (s[i] > s[j]) {
            l = i;
        }
    }
 
    
    swap(s[j], s[l]);
 
    
    reverse(s.begin() + j + 1, s.end());
 
    cout << s << endl;
 
    return 0;
}
