#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,a;
    cin>>n;
    for (int i=1;i<=pow(2,n);i++){
        for (int j=1;j<=n;j++){
            if ((i%(int)(pow(2,j)))<=(pow(2,j-1))){
                a=0;
            }
            else{
                a=1;
            }
            if (((i/(int)(pow(2,j)))%2)==1){
                a=1-a;
            }
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
}