#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n,num=1;
    cin>>n;
    for (int i=1;i<=n;i++){
        num*=2;
        while (num>1e9+7){
            num-=1e9+7;
        }
    }
    cout<<num<<endl;
}