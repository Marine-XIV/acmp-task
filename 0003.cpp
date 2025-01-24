#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin >>a;
  if (a>=15)
 
{
      a/=10;
      b=a+1;
      a*=b;
      cout << a <<"25";
  }
    else{
         
        a*=a;
        cout << a;
    }
}
