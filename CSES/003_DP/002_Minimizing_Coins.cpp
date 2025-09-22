#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,sum,tmp,min;
    cin>>n>>sum;
    vector<int> coin;
    vector<int> dp(sum+1,-1);
    for(int i=1;i<=n;i++){
        cin>>tmp;
        coin.push_back(tmp);
    }
    dp[0]=0;
    for(int i=1;i<=sum;i++){
        min=1e8;
        for (int c: coin){
            if(i-c>=0 && dp[i-c]!=-1 && dp[i-c]+1<min){
                min=dp[i-c]+1;
            }
        }
        if(min==1e8){
            min=-1;
        }
        dp[i]=min;
    }
    cout<<dp[sum]<<endl;
    return 0;
}