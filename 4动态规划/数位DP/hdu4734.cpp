#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;

int num[20];
ll dp[11][10000];

ll dfs(int pos,int sum,bool limit){
	if (pos==0) return 1;
	if (!limit)
		if (~dp[pos][sum]) return dp[pos][sum];
	int up=limit?num[pos]:9;
	ll ans=0;
	for (int i=0; i<=up; i++){
		if (sum-i*(1<<(pos-1))<0) continue;
		ans+=dfs(pos-1,sum-i*(1<<(pos-1)),limit && i==num[pos]);
	}
	if (!limit) dp[pos][sum]=ans;
	return ans;
}

ll solve(int a,int b){
	int sum=0,k=0;
	while (a){
		sum+=(a%10)*(1<<k);
		k++;
		a/=10;
	}
	int pos=0;
	while (b){
		num[++pos]=b%10;
		b/=10;
	}
	return dfs(pos,sum,1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
    	int a,b;
    	cin>>a>>b;
    	cout<<"Case #"<<i<<": "<<solve(a,b)<<endl;
	}
    return 0;
}
