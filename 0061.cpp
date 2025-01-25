#include <iostream>
#include <string>
using namespace std;
int main() {
    int a, b, s1 = 0, s2 = 0;
    for(int i = 0; i < 4; ++i){
        cin >> a >> b;
        s1+=a;
        s2+=b;
    }
    if(s1==s2)
        cout <<"DRAW";
    else
        if(s1 > s2)
            cout << 1;
    else
        cout << 2;
    return 0;
}
