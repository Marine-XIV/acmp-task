#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
 
    string a_str, b_str;
    inputFile >> a_str >> b_str;
 
    bool negative = false;
 
     
    if (a_str.length() < b_str.length() || (a_str.length() == b_str.length() && a_str < b_str)) {
        swap(a_str, b_str);
        negative = true; 
    }
 
    
    while (b_str.length() < a_str.length()) {
        b_str = "0" + b_str;
    }
 
    
    string result_str = "";
    int borrow = 0;
    for (int i = a_str.length() - 1; i >= 0; --i) {
        int a_digit = a_str[i] - '0';
        int b_digit = b_str[i] - '0';
 
        int diff = a_digit - b_digit - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
 
        result_str = to_string(diff) + result_str;
    }
 
   
    size_t first_digit_pos = result_str.find_first_not_of('0');
    if (first_digit_pos == string::npos) {
        result_str = "0"; 
    } else {
        result_str = result_str.substr(first_digit_pos);
    }
 
 
    if (negative && result_str != "0") {
        result_str = "-" + result_str;
    }
 
    outputFile << result_str << endl;
 
    inputFile.close();
    outputFile.close();
 
    return 0;
}
