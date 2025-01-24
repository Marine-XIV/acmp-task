#include <iostream>
 
using namespace std;
int main()
{
char c ;
cin >>c;
 
if(c >= 'a' && c <= 'z'){
        int alnum = c - 'a';
    c = 'A' + alnum;
}
cout << c;
 
  return 0;
}
