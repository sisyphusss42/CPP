#include<iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    for (int n=1;n<=k;n++){
        int sub=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i+2>0 && i+2<=n){
                    if (j+1>0 && j+1<=n){
                        sub++;
                    }
                    if (j-1>0 && j-1<=n){
                        sub++;
                    }
                }
                if (i-2>0 && i-2<=n){
                    if (j+1>0 && j+1<=n){
                        sub++;
                    }
                    if (j-1>0 && j-1<=n){
                        sub++;
                    }
                }
                if (j+2>0 && j+2<=n){
                    if (i+1>0 && i+1<=n){
                        sub++;
                    }
                    if (i-1>0 && i-1<=n){
                        sub++;
                    }
                }
                if (j-2>0 && j-2<=n){
                    if (i+1>0 && i+1<=n){
                        sub++;
                    }
                    if (i-1>0 && i-1<=n){
                        sub++;
                    }
                }
            }
        }
        cout<<n*n*(n*n-1)/2-sub/2<<endl;
    }
    return 0;
}