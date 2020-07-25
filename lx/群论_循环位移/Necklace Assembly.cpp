/*
http://codeforces.com/contest/1367/problem/E
*/

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

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int cnt[30];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
    	memset(cnt,0,sizeof(cnt));
    	int n,k;
    	cin>>n>>k;
    	string s;
    	cin>>s;
    	for (int i=0; i<sz(s); i++)
    		cnt[s[i]-'a']++;
    	for (int i=n; i; i--){
    		int t=gcd(i,k);//循环子群个数 
    		int e=i/t;//循环子群大小 
    		int num=0;
    		for (int j=0; j<26; j++){
    			if (cnt[j]>=e){
    				num+=cnt[j]/e;
				}
			}
			if (num>=t){
				cout<<i<<endl;
				break;
			}
		}
	}
    return 0;
}

