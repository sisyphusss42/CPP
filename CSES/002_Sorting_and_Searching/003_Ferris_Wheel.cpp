#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, maxW, tmp, end=0;
    cin>>n>>maxW;
    int gondola=n;
    vector<int> children;
    for (int i=0; i<n;i++){
        cin>>tmp;
        children.push_back(tmp);
    }
    sort(children.begin(),children.end());

    for (int i=children.size()-1;i>=end;i--){
        if (i!=end && children[i]+children[end]<=maxW){
            end++;
            gondola--;
        }
    }
    cout<<gondola<<endl;
    return 0;
};