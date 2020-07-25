/*
algorithm: Íþ×ô·ò²©ÞÄ 
from: http://acm.hdu.edu.cn/showproblem.php?pid=2177
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dd(x) cout << #x << "=" << x << ","
#define de(x) cout << #x << "=" << x << endl

const double r=(sqrt(5.0)+1)/2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    while (cin>>a>>b){
    	if (a==0 && b==0) return 0;
    	int t=r*(b-a);
    	if (a!=t){
    		cout<<1<<endl;
    		if (a>t){
    			cout<<t<<' '<<b-a+t<<endl;
			}
			for (int i=0; i<=b; i++){
				int aa=r*i,bb=aa+i;
//				dd(aa),de(bb);
				if (aa==a && bb<b){
					cout<<aa<<' '<<bb<<endl;
				}
				else if (aa<a && bb==b){
					cout<<aa<<' '<<bb<<endl;
				}
				else if (aa<b && bb==a){
					cout<<aa<<' '<<bb<<endl;
				}
			}
		}
		else{
			cout<<0<<endl;
		}
	}
    return 0;
}

