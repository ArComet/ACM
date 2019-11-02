// 【两圆关系】
// 注意相等关系
// 4:相离 3:外切 2:相交 1:内切 0:内含
int relCC(C A, C B) { // 两圆关系
	db dis = (A.o - B.o).len();
	if(sign(dis - (A.r + B.r)) == 1) return 4;
	if(sign(dis - (A.r + B.r)) == 0) return 3;
	if(sign(dis - fabs(A.r - B.r)) == 1) return 2;
	if(sign(dis - fabs(A.r - B.r)) == 0) return 1;
	return 0;
}
// 【点圆切点】
bool tanCP(O c, P p0, P &p1, P &p2) {
	db x = (p0 - c.o).len2(), d = x - c.r * c.r;
	if(d < eps) return 0;
	P p = (p0 - c.o) * (c.r * c.r / x);
	P det = ((p0 - c.o) * (-c.r * sqrt(d) / x)).rot90();
	p1 = c.o + p + det;
	p2 = c.o + p - det;
	return 1;
}
// 【圆圆切点】
vector<P> tanCC(const C &c1, const C &c2) {
	vector<P> res;
	db dis = (c1.o - c2.o).len();
	if(sign(dis - (c1.r + c2.r)) == 0) {
		res.pb(c1.o + (c2.o - c1.o) * c1.r / (c1.r + c2.r));
	}
	if(sign(dis - fabs(c1.r - c2.r) == 0)) {
		res.pb(c1.o + (c2.o - c1.o) * c1.r / (c1.r - c2.r));
	}
	return res;
}
// 【直线和圆求交】
bool isCL(O a, L l, P &p1, P &p2) {
  db x = dot(l.a - a.o, l.b - l.a);
  db y = (l.b - l.a).len2();
  db d = x * x - y * ((l.a - a.o).len2() - a.r * a.r);
  if(sign(d) < 0) return 0;
  d = max(d, 0.);
  P p = l.a - ((l.b - l.a) * (x / y)), det = (l.b - l.a) * (sqrt(d) / y);
  p1 = p - det, p2 = p + det; // dir : l.a -> l.b
  return 1;
}
// 【圆与三角形交面积】
db areaCT(db r,P s,P t) { // 需要除 2
	P p1, p2;
	bool f = isCL(C(P(0, 0), r), L(s, t), p1, p2);
	if(!f) return r * r * rad(s, t);
	bool b1 = sign(s.len2() - r * r) == 1 , b2 = sign(t.len2() - r * r) == 1;
	if(b1 && b2) {
		if(sign(dot(s - p1, t - p1)) <= 0 && sign(dot(s - p2, t - p2) <= 0))
			return r * r * (rad(s, p1) + rad(p2, t)) + det(p1, p2);
		else return r * r * rad(s, t);
	} else if(b1) return r * r * rad(s, p1) + det(p1, t);
	else if(b2) return r * r * rad(p2, t) + det(s, p2);
	return det(s, t);
}
// 【圆与多边形交面积】
db areaCPoly(C c, vector<P> p) { 
	int n = sz(p);
	db ans = 0;
	rep(i, 0, n) {
		P u = p[i], v = p[(i + 1) % n];
		ans += areaCT(c.r, u - c.o, v - c.o);
	}
	return fabs(ans) / 2;
}
// 【圆交】
namespace CircleIntersection{ // ?
	struct E{
		P p;T ang;int delta;
		E(){} E(P p,T ang,int delta):p(p),ang(ang),delta(delta){}
		bool operator < (const E&b) const {return ang<b.ang;}
	};
	bool overlap(C a,C b) {return sgn(a.r-b.r-abs(a.o-b.o))>=0;}
	void solve(C *c,int n,T *ans) {
		memset(ans , 0 , sizeof(T) * (n + 1));
		rep(i,0,n) {
			int cnt=1;
			vector<E> evt;
			rep(j,0,i) if(c[i]==c[j]) cnt++;
			rep(j,0,n) if(j!=i&&!(c[i]==c[j])&&overlap(c[j],c[i])) cnt++;
			rep(j,0,n) if(j!=i){
				vector<P> pts=insCC(c[i],c[j]);
				if(sz(pts)) {
					T a[2];
					rep(j,0,2) a[j]=(pts[j]-c[i].o).arg();
					evt.pb(E(pts[0],a[0],1));
					evt.pb(E(pts[1],a[1],-1));
					cnt += a[0] > a[1];
				}
			}
			if(!sz(evt)) ans[cnt] += pi*c[i].r*c[i].r;
			else{
				sort(all(evt));
				evt.pb(evt.front());
				rep(j,0,sz(evt)-1) {
					cnt+=evt[j].delta;
					ans[cnt] += evt[j].p / evt[j+1].p / 2;
					db ang = evt[j + 1].ang - evt[j].ang;
					if(ang < 0) ang += pi * 2;
					ans[cnt] += ang * c[i].r * c[i].r / 2 - sin(ang) * c[i].r * c[i].r / 2;
				}}}}}