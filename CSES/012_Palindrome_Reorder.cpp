#include<iostream>
#include<string>
using namespace std;
int main(){
    bool A[26] = {false};
    string str,ans;
    cin>>str;
    for (char c: str){
        if (A[c-65]){
            ans+=c;
        }
        A[c-65]=!A[c-65];
    }
    //Check if there's a single True in A, if yes, set it as s
    string s="";
    for (int i=0;i<=25;i++){
        if (A[i]){
            s+=char(i+65);
        }
    }
    if (s.length()>1){
        cout<<"NO SOLUTION";
    }
    else{
        cout<<ans<<s;
        for (int i=ans.length()-1;i>=0;i--){
            cout<<ans[i];
        }
    }
    
    return 0;
}