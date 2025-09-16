# include <iostream>
# include <sstream>
# include <string>
using namespace std;
int main (){
    string line1, line2,tmp;
    getline(cin, line1);
    getline(cin, line2);
    
    int d1, r1, d2, r2;

    stringstream ss1(line1);
    ss1 >> tmp >> tmp >> d1 >> tmp >> r1;

    stringstream ss2(line2);
    ss2 >> tmp >> tmp >> d2 >> tmp >> r2;

    for (int i=1; i<=d1*d2; i++){
        if (i%d1==r1 && i%d2==r2){
            cout<<"x = "<<i;
            break;
        }
    }

    return 0;
}