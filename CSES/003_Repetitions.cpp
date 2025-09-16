#include<iostream>
#include<string>
using namespace std;
int main(){
    string A;
    cin>>A;
    int n=1, max=1;
    for (int i=1; i<A.size();i++){
        if (A[i]==A[i-1]){
            n++;
            if (n>max){
            max=n;
            }
        }
        else{
            n=1;
        }
    }
    cout<<max;
    return 0;
}