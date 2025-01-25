#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    vector<long long> nums = {a1, a2, a3};
    
    bool found = false;
    
    sort(nums.begin(), nums.end()); 
  
    do {
      if (nums[0] + nums[1] == nums[2]){
        found = true;
        break;
      }
    } while (next_permutation(nums.begin(), nums.end()));

    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
