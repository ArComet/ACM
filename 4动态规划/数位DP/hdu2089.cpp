#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;

int a[20];
ll dp[20][10];

ll dfs(int pos,int x,bool limit){
	if (pos==0) return 1;
	if (!limit)
		if (~dp[pos][x]) return dp[pos][x];
	int up=limit?a[pos]:9;
	ll ans=0;
	for (int i=0; i<=up; i++){
		if (x==6 && i==2) continue;
		if (i==4) continue;
		ans+=dfs(pos-1,i,limit && i==a[pos]);
	}
	if (!limit) dp[pos][x]=ans;
	return ans;
}

ll solve(int x){
	int pos=0;
	while (x){
		a[++pos]=x%10;
		x/=10;
	}
	return dfs(pos,0,1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    int a,b;
    while (cin>>a>>b){
    	if (a==0 && b==0) return 0;
    	cout<<solve(b)-solve(a-1)<<endl;
	}
    return 0;
}
