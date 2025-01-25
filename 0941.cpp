#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long toDecimal(const string& ternary) {
  long long decimal = 0;
  long long power = 0;
  for (int i = ternary.size() - 1; i >= 0; --i) {
    decimal += (ternary[i] - '0') * pow(3, power);
    power++;
  }
  return decimal;
}

int main() {
  string n_ternary, m_ternary;
  cin >> n_ternary >> m_ternary;

  long long n_decimal = toDecimal(n_ternary);
  long long m_decimal = toDecimal(m_ternary);

  cout << n_decimal + m_decimal << endl;

  return 0;
}
