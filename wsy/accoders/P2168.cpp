//luogu:P2168
//state: AC
#include<bits/stdc++.h>
using namespace std;
struct node{
    long long w,h;
    node(){w = 0,h = 0;}
    node(long long w,long long h):w(w),h(h){}
    friend bool operator<(node a,node b){
        if(a.w==b.w) return a.h>b.h;
        else return a.w>b.w;
    }
};
long long ans;
priority_queue<node> q;
long long n,k;
int main(){
    scanf("%lld %lld",&n,&k);
    for(int i = 1;i<=n;i++){
        long long w;
        scanf("%lld",&w);
        q.push(node(w,1));
    }
    while((q.size()-1)%(k-1)!=0) q.push(node(0,1));
    while(q.size()>=k){
        long long h = -0x7f7f7f7f;
        long long w = 0;
        for(int i = 1;i<=k;i++){
            node t = q.top();
            q.pop();
            h = max(h,t.h);
            w += t.w;
        }
        ans += w;
        q.push(node(w,h+1));
    }
    printf("%lld\n%lld",ans,q.top().h-1);
    return 0;
}