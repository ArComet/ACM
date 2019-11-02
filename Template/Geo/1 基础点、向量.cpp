struct P {
	int quad() const { return sign(y) > 0 || (sign(y) == 0 && sign(x) >= 0); }
	P rot90() { return P(-y, x); }
	P rot(db a) { return P(cos(a) * x - sin(a) * y, cos(a) * y + sin(a) * x); }
	P norm() { return *this / len(); }
};
db rad(P p1, P p2) { return atan2l(det(p1, p2), dot(p1, p2)); } // p1 与 p2 的夹角，有方向
bool cmp(const pii &a, const pii &b) { // 级角排序
	int o = a > pii(0, 0), t = b > pii(0, 0);
	if(o != t) return o < t;
	return det(a, b) > 0;
}
// 【点集中最近点对】
namespace NearestPoints { // sz(A) <= 1e5
	db solve(int l, int r, vector<P> &p) {
		if(l == r) return 1e100;
		int m = l + r >> 1;
		db Xm = p[m].x, lim = min(solve(l, m, p), solve(m + 1, r, p));
		inplace_merge(p.begin() + l, p.begin() + m + 1, p.begin() + r + 1, [&](P a, P b){return a.y < b.y;});
		vector<P> V;
		rep(i, l, r + 1) if(fabs(p[i].x - Xm) <= lim) V.pb(p[i]);
		rep(i, 0, sz(V)) rep(j, i + 1, sz(V)) {
			if(fabs(V[j].y - V[i].y) >= lim) break;
			T dis = (V[i] - V[j]).len();
			lim = min(lim, dis);
		}
		return lim;
	}
	db solve(vector<P> A) {
		sort(all(A), [&](P a, P b){return a.x < b.x;});
		return solve(0, sz(A) - 1, A);
	}
}
// 【最小圆覆盖】
C Mincir(P *p,int n){ 
	random_shuffle(p , p + n);
	P o = p[0];db r = 0;
	rep(i,1,n) {
		if(sgn(abs(o-p[i])-r) <= 0) continue;
		o = p[i] , r = 0;
		rep(j,0,i) {
			if(sgn(abs(o-p[j])-r) <= 0) continue;
			o = (p[i] + p[j]) / 2 , r = abs(o-p[j]);
			rep(k,0,j) {
				if(sgn(abs(o-p[k])-r) <= 0) continue;
				o = outC(p[i],p[j],p[k]) , r = abs(o-p[k]);
			}}}
	return C(o,r);
}
// 【费马点】
// sqrt((a ^ 2 + b ^ 2 + c ^ 2 + 4 * sqrt(3) * area) / 2)
// 如果有重点，大于 2 的直接用模拟退火法
P fermat(vector<P> p) {
  int n = sz(p); assert(n);
  if(n == 1) return p[0];
  if(n == 2) return (p[0] + p[1]) / 2;
  if(n == 3) {
    db a[3];
    rep(i, 0, 3) a[i] = (p[(i + 2) % 3] - p[(i + 1) % 3]).len();
    rep(i, 0, 3) {
      int j = (i + 1) % 3, k = (i + 2) % 3;
      if(sign(a[i] * a[i] - a[j] * a[j] - a[k] * a[k] - a[j] * a[k]) >= 0) return p[i];
    }
    if(det(p[0], p[1], p[2]) < 0) swap(p[1], p[2]);
    P q1 = (p[2] - p[0]).rot(pi / 3) + p[0]; 
    P q2 = (p[0] - p[1]).rot(pi / 3) + p[1];
    return isLL(L(q1, p[1]), L(q2, p[2]));
  }
  auto Rand = [&] () { return rand() % 10000 / 5000 * pi; };
  P ans(0, 0); rep(i, 0, n) ans = ans + p[i]; ans = ans / n;
  db len = 0; rep(i, 0, n) len += (ans - p[i]).len();
  db t = 10000; // modify
  while(t > eps) {
    db ang = Rand();
    P np(ans.x + t * sin(ang), ans.y + t * cos(ang));
    db k = 0; rep(i, 0, n) k += (np - p[i]).len();
    if(sign(len - k) > 0) ans = np, len = k;
    t *= 0.999;
  }
  return ans;
}