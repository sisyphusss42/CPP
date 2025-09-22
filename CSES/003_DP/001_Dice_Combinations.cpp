#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num;
    cin>>num;
    vector<long long int> dp(1e6,0);
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    dp[5]=16;
    dp[6]=32;
    for (int i=7;i<=num;i++){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%(1000000007);
    }
    cout<<dp[num];
    return 0;
}