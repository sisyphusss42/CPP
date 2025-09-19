#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    for (int i=0;i<pow(2,s.length());i++){
        bitset<10> B(i);
        for (int j=0;j<s.length();j++){
            if (B[s.length()-1-j]){
                cout<<s[j];
            }
        }
        cout<<endl;
    }
    return 0;
}