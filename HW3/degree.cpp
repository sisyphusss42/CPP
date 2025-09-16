#include <iostream>
#include <fstream>
#include <string>
# include <sstream>

using namespace std;
int main(){
    int v;
    int count = 0;
    cin>>v;
    ifstream file("com-amazon.ungraph.txt");
    string line;
    int lineNumber = 0;
    int a,b;
    while (getline(file,line)){
        lineNumber ++;
        if (lineNumber>=5){
            stringstream ss1(line);
            ss1>>a>>b;
            if (a==v || b==v){
                count ++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}