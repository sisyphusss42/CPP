#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main(){
    string s="ABCDE";
    cout<<s.find('D')<<endl;
    cout<<(s.find('X')==string::npos);
    return 0;
}