#include <iostream>
#include <cmath>
using namespace std;
void changeValue(int &num){
    num = 10;
}

int main(){
    int a = 5;
    changeValue(a);
    cout<<a;
    return 0;
}