#include<iostream>
using namespace std;
int main(){
    int n,a,b;
    long long count=0;
    cin>>n;
    cin>>a; //first num
    for (int i=0;i<n-1;i++){
        cin>>b;
        if (b<a){
            count+=a-b;
            b=a;
        }
        a=b;
    }
    cout<<count;
    return 0;
}