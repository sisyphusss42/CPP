#include<iostream>
using namespace std;
int main(){
    int t,a,b;
    cin>>t;
    for (int test=1;test<=t;test++){
        cin>>a>>b;
        if (a<b){
            swap(a,b);
        }
        if ((a-b)>b){
            cout<<"NO"<<endl;
        }
        else if((b-(a-b))%3!=0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}