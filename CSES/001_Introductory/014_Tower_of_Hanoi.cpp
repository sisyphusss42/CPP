#include <iostream>
#include <cmath>
using namespace std;
void Hanoi(int n, int a, int b){
    if (n==1){
        cout<<a<<" "<<b<<endl;
    }
    else{
        Hanoi(n-1,a,6-a-b);
        Hanoi(1,a,b);
        Hanoi(n-1,6-a-b,b);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    Hanoi(n,1,3);
    return 0;
}