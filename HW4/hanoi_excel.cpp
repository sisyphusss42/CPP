#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> Lines(2048,vector<int>(2048,0));
    Lines[0][0]=6;
    Lines[1][0]=4;
    Lines[1][1]=2;
    Lines[2][0]=3;
    Lines[2][2]=5;
    int n;
    cin>>n;
    int width=1;
    for (int i=2;i<=n;i++){
        for (int r=0;r<width;r++){
            for (int c=0;c<width;c++){
                Lines[width*3+3+r][c]=Lines[r][c]; //Left red copy
                Lines[width*3+3+r][width*3+3+c]=Lines[r][c]; //Right red copy

                Lines[width*2+2+r][c]=Lines[width*1+1+r][width*1+1+c]; //Left blue copy
                Lines[width*3+3+r][width*2+2+c]=Lines[width*1+1+r][width*1+1+c]; //Right blue copy

                Lines[width*3+3+r][width*1+1+c]=Lines[width*1+1+r][c]; //Left green copy
                Lines[width*2+2+r][width*2+2+c]=Lines[width*1+1+r][c]; //Right green copy

                //Add the 6 extra cells
                Lines[width*2+1][0]=4;
                Lines[width*2+1][width*2+1]=2;
                Lines[width*3+2][width*1]=2;
                Lines[width*3+2][width*2+2]=4;
                Lines[width*4+2][width*1]=1;
                Lines[width*4+2][width*3+2]=1;
            }
        }


        width=width*2+1;
    }
    for (int i=0;i<width*2+1;i++){
        for (int j=0;j<width*2+1;j++){
            if (Lines[i][j]!=0){
                cout<<Lines[i][j];
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;

    }
    return 0;
}