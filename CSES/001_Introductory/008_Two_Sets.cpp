#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if (n%4==3){
        cout<<"YES"<<endl;
        cout<<(n-3)/2+2<<endl;
        for (int i=0;4*i<n;i++){
            cout<<4*i+1<<" "<<4*i+2<<" ";
        }
        cout<<endl;
        cout<<n-((n-3)/2+2)<<endl;
        for (int i=0;4*i<n;i++){
            if (i!=0){
                cout<<4*i<<" "<<4*i+3<<" ";
            }
            else{
                cout<<4*i+3<<" ";
            }
        }
    }
    else if(n%4==0){
        cout<<"YES"<<endl;
        cout<<n/2<<endl;
        for (int i=0;4*i+1<n;i++){
            cout<<4*i+1<<" "<<4*i+4<<" ";
        }
        cout<<endl;
        cout<<n/2<<endl;
        for (int i=0;4*i<n;i++){
            cout<<4*i+2<<" "<<4*i+3<<" ";
        }
    }
    else{
        cout<<"NO";
    }
    return 0;
}