#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return 1;
    }
    if(!outputFile.is_open()){
      cerr << "Error opening output file" << endl;
      return 1;
    }

    int n;
    inputFile >> n;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        double x, y, x1, y1, x2, y2, x3, y3, x4, y4;
        inputFile >> x >> y >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        
        double rectArea = triangleArea(x1, y1, x2, y2, x3, y3) + triangleArea(x1, y1, x3, y3, x4, y4);

        double sumAreas = triangleArea(x, y, x1, y1, x2, y2) +
                          triangleArea(x, y, x2, y2, x3, y3) +
                          triangleArea(x, y, x3, y3, x4, y4) +
                          triangleArea(x, y, x4, y4, x1, y1);

       
        if (abs(rectArea - sumAreas) < 1e-9) {
            count++;
        }
    }

    outputFile << count << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
