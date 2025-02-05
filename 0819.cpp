#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream inputFile("input.txt");
  ofstream outputFile("output.txt");

  long long a, b, c;
  inputFile >> a >> b >> c;

  long long surfaceArea = 2 * (a * b + a * c + b * c);
  long long volume = a * b * c;

  outputFile << surfaceArea << " " << volume << endl;

  inputFile.close();
  outputFile.close();

  return 0;
}

