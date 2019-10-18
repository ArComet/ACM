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
#define rk(x) upper_bound(all(V) , x) - V.begin()
#define lowbit(x) x&(-x)
//EPS 
const double EPS=1e-6;
//点和圆的类
struct point{
	double x,y;
	point(){};
	point(double x,double y):x(x),y(y){};
}; 
struct circle{
	point o;
	double r;
	circle(){};
	circle(point o,double r):o(o),r(r){};
};
//两点距离 
double dis(point p1,point p2){
	double dx=p1.x-p2.x;
	double dy=p1.y-p2.y;
	return sqrt(dx*dx+dy*dy);
}
//点圆关系：0-圆外，1-圆内 
bool point_in(circle c,point p){
	double d2=dis(p,c.o)*dis(p,c.o);
	double r2=c.r*c.r;
	return d2<r2||fabs(r2-d2)<EPS;
}
//两圆关系：1-相离，2-外切，3-相交，4-内切，5-内含 
int check(circle c1,circle c2){
	point p1=c1.o,p2=c2.o;
	double r1=c1.r,r2=c2.r;
	double d=dis(p1,p2);
	if (fabs(p1.x-p2.x)<EPS && fabs(p1.y-p2.y)<EPS && fabs(r1-r2)<EPS)
		return 0;
	if (fabs(d-r1-r2)<EPS) return 2;
	if (fabs(d-fabs(r1-r2))<EPS) return 4;
	if (d>r1+r2) return 1;
	if (d<fabs(r1-r2)) return 5;
	if (fabs(r1-r2)<d && d<r1+r2) return 3;
	return -1;
}
//两圆交点（已判两圆关系） 
void c2point(circle c1,circle c2,point &rp1,point &rp2){
	point p1=c1.o,p2=c2.o;
	double r1=c1.r,r2=c2.r;
	double a=p2.x-p1.x,b=p2.y-p1.y;
	double r=(a*a+b*b+r1*r1-r2*r2)/2;
	if (a==0 && b!=0){
		rp1.y=rp2.y=r/b;
		rp1.x=sqrt(r1*r1-rp1.y*rp1.y);
		rp2.x=-rp1.x;
	}
	else if (a!=0 && b==0){
		
		rp1.x=rp2.x=r/a;
		rp1.y=sqrt(r1*r1-rp1.x*rp1.x);
		rp2.y=-rp1.y;
	}
	else if (a!=0 && b!=0){
		double delta=b*b*r*r-(a*a+b*b)*(r*r-r1*r1*a*a);
		rp1.y=(b*r+sqrt(delta))/(a*a+b*b);
		rp2.y=(b*r-sqrt(delta))/(a*a+b*b);
		rp1.x=(r-b*rp1.y)/a;
		rp2.x=(r-b*rp2.y)/a;
	}
	rp1.x+=p1.x;rp1.y+=p1.y;
	rp2.x+=p1.x;rp2.y+=p1.y;
}
 
vector<circle> cc;
vector<point> pp;
 
int main(){
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
	int t,n;
	cin>>t;
	for (int q=1; q<=t; q++){
		double R;
		cin>>n>>R;
		circle c1(point(0.0,0.0),R);
		for (int i=1; i<=n; i++){
			double x,y,r;
			cin>>x>>y>>r;
			circle c2(point(x,y),r);
//			de(check(c1,c2));
			cc.pb(c2);
			if (check(c1,c2)==3){
				point p1,p2;
				c2point(c1,c2,p1,p2);
				pp.pb(p1);
				pp.pb(p2);
//				dd(p1.x),dd(p1.y),dd(p2.x),de(p2.y);
			}
		}
		double ans=0;
		for (int i=0; i<sz(pp); i++){
			bool f=1;
			for (int j=0; j<sz(cc); j++)
				if (point_in(cc[j],point(-pp[i].x,-pp[i].y))) f=0;
			if (f) ans=2*R;
			for (int j=i+1; j<sz(pp); j++)
				ans=max(ans,dis(pp[i],pp[j]));
		}
		printf("Case #%d: %.10lf\n",q,ans);
		cc.clear();
		pp.clear();
	} 
	return 0;
}
