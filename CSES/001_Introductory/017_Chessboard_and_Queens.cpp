#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
    string s;
    vector<pair<int,int>> reserved;
    for (int i=0;i<=7;i++){
        cin>>s;
        for (int j=0;j<=7;j++){
            if (s[j]=='*'){
                reserved.push_back({i, j});
            }
        }
    }
    */

    vector<string> permu={"1"}, newPermu;
    for (int i=2;i<=8;i++){
        for (string ss: permu){
            for (int j=0;j<=ss.length();j++){
                newPermu.push_back(ss.substr(0,j)+to_string(i)+ss.substr(j));
            }
        }
        permu=newPermu;
        newPermu.clear();
    }

    for (string sss: permu){
        cout<<sss<<endl;
    }
    


    /*
    vector<int> A,B;
    for (int i=0;i<=7;i++){
        for (int j=0;j<=7;j++){

        }
    }
    */

    return 0;
}