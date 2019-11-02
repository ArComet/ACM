// 【平面图欧拉定理】 V + F - E = 2
// 【简单多边形求面积交】
db polyInter(vector<P> &p, vector<P> &q) {
	int n = sz(p), m = sz(q);
	if(n < 3 || m < 3) return 0;
	//	if(area(p) < 0) reverse(all(p));
	//	if(area(q) < 0) reverse(all(q));
	db ans = 0;
	rep(i, 1, n - 1) {
		P p1 = p[i], p2 = p[i + 1];
		bool f1 = 0;
		if(det(p[0], p1, p2) < 0) swap(p1, p2), f1 = 1;
		rep(j, 1, m - 1) {
			P q1 = q[j], q2 = q[j + 1];
			bool f2 = 0;
			if(det(q[0], q1, q2) < 0) swap(q1, q2), f2 = 1;
			vector<P> ps({p[0], p1, p2});
			convexCut(ps, L(q[0], q1));
			convexCut(ps, L(q1, q2));
			convexCut(ps, L(q2, q[0]));
			db res = f1 == f2 ? area(ps) : -area(ps);
			ans += res;
		}
	}
	return fabs(ans);
}