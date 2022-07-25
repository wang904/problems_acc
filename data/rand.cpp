#include<bits/stdc++.h>
using namespace std;
const int n = 100000;
int main(){
    srand(time(0));
    freopen("1.in","w",stdout);
    cout<<n<<" ";
    cout<<(rand()%500+1)*(rand()%200+1)<<endl;
    for(int i = 1;i<=n;i++){
        printf("%d",rand()%2000+1);
        if(i!=n) printf(" ");
    }
    return 0;
}