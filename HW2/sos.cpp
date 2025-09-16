# include <iostream>
# include <vector>
using namespace std;
int main (){
    int n;
    int sum = 0;
    cin>>n;
    for (int i=1; i<=n; i++){
        if (n%i==0 && i%4!=0){
            sum+=i;
        }
    }
    cout<<8*sum;
    return 0;
}