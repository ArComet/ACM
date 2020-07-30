/*********************************
Contest: HDU - 1846
Title: Brave Game
Algorithm: Ä£°å-µÝÍÆÇóSG 
*********************************/ 
#include<bits/stdc++.h>
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
const int N = 20000;
const int M = 1e9+7;

int sg[1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
    	memset(sg,0,sizeof(sg));
    	int n,m;
    	cin>>n>>m;
    	for (int i=1; i<=n; i++){
    		int f[1010];
    		memset(f,0,sizeof(f));
    		for (int j=1; i-j>=0 && j<=m; j++){
    			f[sg[i-j]]=1;
			}
			int j;
			for (j=0;f[j]; j++);
			sg[i]=j;
//			de(sg[i]);
		}
		if (sg[n]!=0) cout<<"first\n";
		else cout<<"second\n";
	}
    return 0;
}
