#include <iostream>
using namespace std;

long long count = 0;

void dp(int n){
    if(n==0){
        count+=1;
        if (count==1e9+7) count=0;
    }
    else{
        for (int i=1;i<=6;i++){
            if (i>n){
                break;
            }
            dp(n-i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    cin>>num;
    dp(num);
    cout<<count<<endl;
    return 0;
}