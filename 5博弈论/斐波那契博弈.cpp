#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
const ll M = 1LL<<31;

vector<ll> f;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    f.pb(0);
    f.pb(1);
    while (1){ 
    	ll t=f[sz(f)-1]+f[sz(f)-2];
    	if (t>=M) break;
    	f.pb(t);
	}
	ll x;
	while (cin>>x){
		if (x==0) return 0;
		if (*lower_bound(all(f),x)==x){
			cout<<"Second win\n";
		}	
		else{
			cout<<"First win\n";
		}	
	} 
    return 0;
}

