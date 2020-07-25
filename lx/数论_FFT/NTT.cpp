/* 
https://ac.nowcoder.com/acm/contest/6110/A
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define dd(x) cout << #x << "=" << x << ","
#define de(x) cout << #x << "=" << x << endl

const int M = 1 << 20;
ll a[M], b[M];

const int mod=998244353;

ll fpow(ll a, ll b){
	ll c = 1;
	for (; b; b >>= 1,a = a * a % mod) if (b & 1) c = c * a %mod;
	return c;
}

const int sqr2=116195171,inv2=fpow(sqr2,mod-2);


struct NTT{
	static const int G = 3, P = 998244353; //P = C*2^k + 1
	ll N, na, nb, w[2][M], rev[M];
	ll kpow(ll a, ll b){
		ll c = 1;
		for (; b; b >>= 1,a = a * a % P) if (b & 1) c = c * a %P;
		return c;
	}
	void FFT(ll *a, int f){
		rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (ll i = 1; i < N; i <<= 1)
			for (ll j = 0, t = N / (i << 1); j < N; j += i << 1)
				for (ll k = 0, l = 0, x, y; k < i; k++, l += t)
					x = w[f][l] * a[j+k+i] % P, y = a[j+k], a[j+k] = (y+x) % P, a[j+k+i] = (y-x+P) % P;
		if (f) for (ll i = 0, x = kpow(N, P-2); i < N; i++) a[i] = a[i] * x % P;
	}
	void work(){
		ll d = __builtin_ctz(N);
		w[0][0] = w[1][0] = 1;
		for (ll i = 1, x = kpow(G, (P-1) / N), y = kpow(x, P-2); i < N; i++) {
			rev[i] = (rev[i>>1] >> 1) | ((i&1) << (d-1));
			w[0][i] = x * w[0][i-1] % P, w[1][i] = y * w[1][i-1] % P;
		}
	}
	void doit(ll *a, ll *b, ll na, ll nb){ // [0, na)
		for (N = 1; N < na + nb - 1; N <<= 1);
		rep(i, na, N) a[i] = 0;
		rep(i, nb, N) b[i] = 0;
		work(), FFT(a,0), FFT(b,0);
		rep(i, 0, N) a[i] = a[i] * b[i] % P;
		FFT(a, 1);
//		cout<<N<<endl;
//		rep(i, 0, N){
//			cout << a[i] << endl;
//		}
		ll res=0;
		for (ll i=0; i<N; i++){
			res=(res+a[i]*kpow(sqr2,i*i)%P)%P;
		}
		cout<<res<<endl;
	}
} ntt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll len=0; 
    for (int i=0; i<n; i++){
		ll x;
		cin>>x;
		a[x]+=fpow(inv2,x*x);
		b[x]+=fpow(inv2,x*x);
		len=max(len,x);
	}
	ntt.doit(a,b,len+1,len+1);
    return 0;
}
