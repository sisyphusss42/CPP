#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
set<string> elements = {
    "h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p","s","cl","ar","k","ca","sc","ti","v","cr","mn","fe",
    "co","ni","cu","zn","ga","ge","as","se","br","kr","rb","sr","y","zr","nb","mo","tc","ru","rh","pd","ag","cd","in",
    "sn","sb","te","i","xe","cs","ba","la","ce","pr","nd","pm","sm","eu","gd","tb","dy","ho","er","tm","yb","lu","hf",
    "ta","w","re","os","ir","pt","au","hg","tl","pb","bi","po","at","rn","fr","ra","ac","th","pa","u","np","pu","am",
    "cm","bk","cf","es","fm","md","no","lr","rf","db","sg","bh","hs","mt","ds","rg","cn","nh","fl","mc","lv","ts","og"
};

string word;
vector<string> solution;
bool found = false;

void dfs(int i){
    if (found){
        return;
    }
    if (i==word.length()){
        found = true;
        for (string c: solution){
            cout<<"["<<c<<"]";
        }
        return;
    }

    if (i+1<=word.length()){
        string one = word.substr(i,1);
        if (elements.count(one)){
            solution.push_back(one);
            dfs(i+1);
            solution.pop_back();
        }
    }
    if (i+2<=word.length()){
        string two = word.substr(i,2);
        if (elements.count(two)){
            solution.push_back(two);
            dfs(i+2);
            solution.pop_back();
        }
    }

}

int main(){
    cin>>word;
    dfs(0);
    return 0;
}