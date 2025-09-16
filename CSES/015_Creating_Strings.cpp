#include<iostream>
#include<string>
#include <set>
using namespace std;

int main(){
    string s;
    cin>>s;
    set<string> A = {string(1,s[0])};
    set<string> newA;
    for (int i=1; i<s.length(); i++){
        for (string a: A){
            for (int j=0;j<=a.length();j++){
                newA.insert(a.substr(0,j)+s[i]+a.substr(j));
            }
        }
        A=newA;
        newA.clear();
    }
    cout<<A.size()<<endl;
    for (string a: A){
        cout<<a<<endl;
    }
    return 0;
}