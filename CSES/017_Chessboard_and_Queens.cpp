#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;

int main(){
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
    vector<int> A,B;
    for (int i=0;i<=7;i++){
        for (int j=0;j<=7;j++){

        }
    }

    return 0;
}