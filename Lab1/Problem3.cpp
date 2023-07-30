#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long a, b;
 cin>> a >> b;
 int x=a;
 int y=b;
 while (a*b != 0){ 
        if (a > b){
            a %= b; 
        }else{
            b %= a;
        }
    }
    long long c=a+b;
    cout<<"GCD: "<<c<<endl;
  cout<<"LCM: "<<(x*y)/c;   
}
