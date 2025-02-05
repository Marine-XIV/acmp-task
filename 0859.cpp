#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
vector<int> multiplyBigNumbers(const vector<int>& num1, const vector<int>& num2) {
    vector<int> result(num1.size() + num2.size(), 0);  
    for (size_t i = 0; i < num1.size(); ++i) {
        for (size_t j = 0; j < num2.size(); ++j) {
            result[i + j] += num1[i] * num2[j];
            result[i + j + 1] += result[i + j] / 10;
            result[i + j] %= 10;
        }
    }
 
     
    int carry = 0;
    for (size_t i = 0; i < result.size(); ++i) {
        int sum = result[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
 
     
    if (carry > 0) {
        result.push_back(carry);
    }
 
   
    size_t first_digit_pos = result.size() - 1;
    while (first_digit_pos > 0 && result[first_digit_pos] == 0) {
        first_digit_pos--;
    }
    result.erase(result.begin() + first_digit_pos + 1, result.end());
 
    return result;
}
 
 
pair<vector<int>, int> divide(const vector<int>& num, int divisor) {
    vector<int> quotient(num.size()); 
    int remainder = 0;
 
    for (int i = num.size() - 1; i >= 0; --i) { 
        int current = remainder * 10 + num[i];
        quotient[i] = current / divisor;
        remainder = current % divisor;
    }
 
     
    size_t first_digit_pos = quotient.size() - 1;
    while (first_digit_pos > 0 && quotient[first_digit_pos] == 0) {
        first_digit_pos--;
    }
    quotient.erase(quotient.begin() + first_digit_pos + 1, quotient.end());
 
    return {quotient, remainder};
}
 
 
vector<int> stringToVector(const string& s) {
    vector<int> result;
    for (int i = s.length() - 1; i >= 0; --i) {
        result.push_back(s[i] - '0');
    }
    return result;
}
 
 
string vectorToString(const vector<int>& v) {
    string result = "";
    for (int i = v.size() - 1; i >= 0; --i) {
        result += to_string(v[i]);
    }
    return result;
}
 
 
vector<int> addOne(vector<int> num) {
    int carry = 1;
    for (int i = 0; i < num.size(); ++i) {
        int sum = num[i] + carry;
        num[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) {
        num.push_back(carry);
    }
    return num;
}
 
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
 
    string n_str;
    inputFile >> n_str;
 
    vector<int> n = stringToVector(n_str);
    vector<int> n_plus_1 = addOne(n);
 
     
    vector<int> product = multiplyBigNumbers(n, n_plus_1);
 
     
    pair<vector<int>, int> division_result = divide(product, 2);
 
    string result = vectorToString(division_result.first);
 
    outputFile << result << endl;
 
    inputFile.close();
    outputFile.close();
 
    return 0;
}
