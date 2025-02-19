#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
  string a, b;
  cin >> a >> b;
 
  int bulls = 0;
  int cows = 0;
 
  for (int i = 0; i < 4; ++i) {
    if (a[i] == b[i]) {
      bulls++;
    } else {
      for (int j = 0; j < 4; ++j) {
        if (a[i] == b[j] && i != j) {
          cows++;
          break; 
        }
      }
    }
  }
 
  cout << bulls << " " << cows << endl;
 
  return 0;
}
