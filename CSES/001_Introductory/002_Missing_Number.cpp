#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,num;
    cin>>n;
    vector<int> A(n+1,0);
    
    for (int i=0; i<n-1; i++){
        cin>>num;
        A[num] = 1;
    }
    
    for (int i=1; i<=n; i++){
        if (!A[i]){
            cout<<i;
            break;
        }
    }
    return 0;
}