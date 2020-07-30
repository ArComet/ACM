/*********************************
Contest: HDU - 5443
Title: The Water Problem
Algorithm: ST±íÄ£°å 
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

struct ST{
	int a[20][10010],lg[10010];//[0,n)
	void init(int *v,int n){
		rep(i,2,n+1) lg[i] = lg[i>>1]+1;
		rep(i,0,n) a[0][i] = v[i];
		rep(i,1,lg[n]+1)
			rep(j,0,n-(1<<i)+1){
				a[i][j]=max(a[i-1][j],a[i-1][j+(1<<(i-1))]);
			}
	}
	int qry(int l,int r){
		int i=lg[r-l+1];
		return max(a[i][l],a[i][r+1-(1<<i)]);
	}
}st;

int a[10010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--){
    	int n;
    	cin>>n;
    	for (int i=0; i<n; i++) cin>>a[i];
    	st.init(a,n);
    	int q;
    	cin>>q;
    	for (int i=1; i<=q; i++){
    		int l,r;
    		cin>>l>>r;
    		cout<<st.qry(l-1,r-1)<<endl;
		}
	}
    return 0;
}
