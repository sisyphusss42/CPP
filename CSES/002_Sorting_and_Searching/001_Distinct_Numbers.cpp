#include <iostream>
#include <set>
using namespace std;
int main(){
    int n,tmp;
    cin>>n;
    set<int> A;
    for (int i=1;i<=n;i++){
        cin>>tmp;
        A.insert(tmp);
    }
    cout<<A.size();
    return 0;
}