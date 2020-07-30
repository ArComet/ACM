#include<iostream>
#include<ctime>
using namespace std;
typedef long long ll;
const int M = 1e9+7;

ll fmul(ll a,ll k,ll p){
	ll res=0;
	for (;k; a=(a+a)%p,k>>=1){
		if (k&1) res=(res+a)%p;
	}
	return res;
}

ll fpow(ll a,ll k,ll p){
	ll res=1;
	for (;k;a=fmul(a,a,p),k>>=1){
		if (k&1) res=fmul(res,a,p);
	}
	return res;
}

ll solve(ll x){
	if (x==2) return 1;
	if (x<2 || !(x&1)) return 0;
	srand((unsigned)time(NULL));
	for (int i=1; i<=10; i++){
		ll a=rand()%(x-1)+1;
		if (fpow(a,x-1,x)!=1) return 0;
	}
	return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    while (cin>>n){
		if (solve(n))
			cout<<"It is a prime number.\n";
		else
			cout<<"It is not a prime number.\n";
	}
    return 0;
}
