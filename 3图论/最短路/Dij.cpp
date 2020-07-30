/*********************************
Contest: POJ - 1797
Title: Heavy Transportation
Algorithm: ×î¶ÌÂ·Ä£°å 
*********************************/ 
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define dd(x) cout << #x << "=" << x << ","
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b-1);i>=a;--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define lowbit(x) x&(-x)
#define inf 0x3f3f3f3f
const int N = 50010;
const int M = 1e9+7;

vector<pii> g[1100];
int d[1100],vis[1100];

int dij(int n,int st,int ed){
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	priority_queue<pii> pq;
	d[st]=inf;
	pq.push(mp(d[st],st));
	while (!pq.empty()){
		int u=pq.top().se;
//		dd(u),de(d[u]);
		pq.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=0; i<sz(g[u]); i++){
			int &v=g[u][i].fi,&w=g[u][i].se;
//			dd(v),de(w);
			if (min(d[u],w)>=d[v]){
				d[v]=min(d[u],w);
				pq.push(mp(d[v],v));
			}
		}
	}
	return d[ed];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int q=1; q<=t; q++){
    	int n,m;
    	cin>>n>>m;
    	for (int i=1; i<=m; i++){
    		int u,v,w;
    		cin>>u>>v>>w;
    		g[u].pb(mp(v,w));
    		g[v].pb(mp(u,w));
		}
		cout<<"Scenario #"<<q<<":\n";
		cout<<dij(n,1,n)<<endl;
		cout<<endl;
		for (int i=1; i<=n; i++) g[i].clear();
	}
    return 0;
}
