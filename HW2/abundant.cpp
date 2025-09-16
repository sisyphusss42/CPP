# include <iostream>
# include <vector>
using namespace std;
int main(){
    int n,sum;
    vector<int> nums;
    cin>>n;
    for (int i=2; i<=n; i++){
        sum = 0;
        for (int j=1; j<i;j++){
            if (i%j==0){
                sum+=j;
            }
        }
        if(sum>i){
            nums.push_back(i);
        }
    }
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size()-1) {
            cout << ", ";
        }
    }
    return 0;
}