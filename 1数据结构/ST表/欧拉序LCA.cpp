/*********************************
Contest: POJ - 1330
Title: Nearest Common Ancestors 
Algorithm: LCA -> 欧拉序+ST表深度最小值 
*********************************/ 
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
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
const int N = 10010<<1;
const int M = 1e9+7;

int a[20][N],lft[N],dep[N],lg[N],L;
int rmin(int x,int y){
	return dep[x]<dep[y]?x:y;
}
void add(int x){
	a[0][L++]=x;
}
void dfs(int c,int fa,const vi g[]){
	lft[c]=L;add(c);
	for (int i=0; i<sz(g[c]); i++){
		int t=g[c][i];
		if (t!=fa) dep[t]=dep[c]+1,dfs(t,c,g),add(c);
	} 
		
}
void build(const vi g[],int rt){
//	memset(a,0,sizeof(a));
//	memset(lft,0,sizeof(lft));
//	memset(dep,0,sizeof(dep));
	L=0;
	dfs(rt,0,g);
	dep[0]=-1;
	rep(i,2,L) lg[i]=lg[i>>1]+1;
	rep(i,1,20){
		int lim=L+1-(1<<i);
		rep(j,0,lim) a[i][j]=rmin(a[i-1][j],a[i-1][j+(1<<i>>1)]);
	}
}
int lca(int x,int y){
	x=lft[x],y=lft[y];
	if (x>y) swap(x,y);
	int i=lg[y-x+1];
	return rmin(a[i][x],a[i][y+1-(1<<i)]);
}
vi g[N];
bool vis[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--){
    	
    	int n;
    	cin>>n;
    	rep(i,0,n-1){
    		int u,v;
    		cin>>u>>v;
    		g[u].pb(v);
    		vis[v]=1;
		}
		int rt=1;
		rep(i,1,n+1) if (vis[i]==0) rt=i;
		build(g,rt);
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<endl;
		rep(i,0,n){
			g[i].clear();
			vis[i]=0;	
		}
	}
    return 0;
}
