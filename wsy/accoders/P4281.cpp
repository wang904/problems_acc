//luogu P4281
//state AC
#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,nxt;
}edges[1000100];
int cnt,head[1000100];
void add_edge(int u,int v){
	edges[++cnt].to = v;
	edges[cnt].nxt = head[u];
	head[u] = cnt;
}
int n,q,d[1000100],f[1000100][21];
void dfs(int s,int fa){
	for(int i = head[s];i!=0;i = edges[i].nxt){
		if(edges[i].to!=fa){
			int x = edges[i].to;
			d[x] = d[s]+1;
			f[x][0] = s;
			for(int j = 1;j<=20;j++)
				f[x][j] = f[f[x][j-1]][j-1];
			dfs(x,s); 
		}
	}
}
int lca(int u,int v){
	if(d[v]>d[u]) swap(u,v);
	for(int i = 20;i>=0;i--){
		if(d[u]>=d[v]+(1<<i)){
			u = f[u][i];
		}
	}
	if(u==v) return u;
	for(int i = 20;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];
}
int main(){
	scanf("%d %d",&n,&q);
	for(int i = 1;i<=n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	d[1] = 1,f[1][0] = 0;
	dfs(1,0);
	for(int i = 1;i<=q;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int lca1 = lca(a,b);
		int lca2 = lca(b,c);
		int lca3 = lca(a,c);
		int re = 0;
		if(lca1==lca2) re = lca3;
		else if(lca2==lca3) re = lca1;
		else if(lca1==lca3) re = lca2;
		//令x = min{lca(a,b),lca(a,c),lca(b,c)},y = man{lca(a,b),lca(a,c),lca(b,c)}
		//则(a->d + b->d + c->d) = d[a]+d[b]+d[c]-d[x]-2d[y])s
		int ans = d[a]+d[b]+d[c]-d[lca1]-d[lca2]-d[lca3];
		printf("%d %d\n",re,ans);
	}
	return 0;
}