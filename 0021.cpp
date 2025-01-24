#include <iostream>
using namespace std;
int main(){
 
    int a, b, c, max, min;
    cin >> a>> b>> c;
    max = min = 0;
 
    if ( (a>=b) && (a>=c)) max = a;
    else if (b>c) max = b;
        else max = c;
 
 
 
 
    if ((a <= b) && (a <= c)) min =a;
        else if(b<c) min = b;
            else min = c;
 
            cout << max - min;
        return 0;
       }
