#include<iostream>
using namespace std;
int main(){
    long long t,y,x;
    cin>>t;
    for (int i=1; i<=t; i++){
        cin>>y>>x;
        if (y>=x){
            if ((y-1)%2==1){
                cout<<y*y-x+1<<endl;
            }
            else{
                cout<<(y-1)*(y-1)+x<<endl;
            }
        }
        else{
            if ((x-1)%2==1){
                cout<<(x-1)*(x-1)+y<<endl;
            }
            else{
                cout<<x*x-y+1<<endl;
            }
        }
    }
    return 0;
}