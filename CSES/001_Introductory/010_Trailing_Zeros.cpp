#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,a=0,b=0;
    cin>>n;
    for (int exp=1;pow(2,exp)<=n;exp++){
        a+=n/pow(2,exp);
    }
    for (int exp=1;pow(5,exp)<=n;exp++){
        b+=n/pow(5,exp);
    }
    cout<<min(a,b);
    return 0;
}