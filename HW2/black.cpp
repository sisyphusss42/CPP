# include <iostream>
# include <vector>
using namespace std;
int main (){
    int n,n_sorted,n_reversed,a,b,c,d,tmp;
    vector<int> L;
    cin>>n;
    while (n!=6174){
        L.push_back(n%10);
        L.push_back(n/10%10);
        L.push_back(n/100%10);
        L.push_back(n/1000);
        for (int i=0; i<=2; i++){
            for (int j=i+1; j<=3; j++){
                if (L[i]<L[j]){
                    tmp=L[i];
                    L[i]=L[j];
                    L[j]=tmp;
                }
            }
        }
        n_sorted = L[0]*1000+L[1]*100+L[2]*10+L[3];
        n_reversed = L[3]*1000+L[2]*100+L[1]*10+L[0];
        n = n_sorted - n_reversed;
        L.clear();
        if (L[3]!=0){
            cout<<n_sorted<<" - "<<n_reversed<<" = "<<n<<endl;
        }
        else{
            cout<<n_sorted<<" - "<<"0"<<n_reversed<<" = "<<n<<endl;
        }        
    }
    cout<<"7641 - 1467 = 6174";
    return 0;
}