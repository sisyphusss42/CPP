#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n,a,minSum=10e8;
    long long sum;
    cin>>n;
    vector<int> A(n);
    for (int i=0;i<n;i++){
        cin>>a;
        A[i]=a;
    }
    for (int i=0; i<pow(2,n); i++){
        bitset<20> binary(i);
        sum=0;
        for (int j=0;j<n;j++){
            if(binary[j]){
                sum+=A[j];
            }
            else{
                sum-=A[j];
            }
        }
        if (abs(sum)<abs(minSum)){
            minSum=abs(sum);
        }
    }
    cout<<minSum;
    
    return 0;
}