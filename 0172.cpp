#include <iostream>
#include <string>

using namespace std;

int main() {
  string n_str;
  int k;

  
  cin >> n_str >> k;

  
  long long remainder = 0;
  for (char c : n_str) {
    remainder = (remainder * 10 + (c - '0')) % k;
  }

 
  cout << remainder << endl;

  return 0;
}

