#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream fin("123.txt");
    ofstream fout("456.txt");
    int a,b,c;
    fin>>a>>b>>c;
    cout<<c<<endl;
    cout<<a<<endl<<b<<endl;
    fout<<a+b<<endl<<a+b<<endl;
    cout<<sin(30);
    return 0;
}