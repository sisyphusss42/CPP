#include <iostream>
using namespace std;

int main(){
    for (int i=1; i<=7; i++){
        for (int j=1; j<=8-i;j++){
            cout<<" ";
        }
        for (int j=1; j<=i;j++){
            cout<<"/";
        }
        cout<<"|";
        for (int j=1; j<=i;j++){
            cout<<"\\";
        }
        cout<<endl;
    } 
    return 0;
}