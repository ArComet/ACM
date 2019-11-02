// 【求凸包】
vector<P> convexHull(vector<P> ps) {
  int n = sz(ps); if(n <= 1) return ps;
  sort(all(ps)); vector<P> qs;
  for(int i = 0; i < n; qs.pb(ps[i++])) {
    while(sz(qs) > 1 && sign(det(qs[sz(qs) - 2], qs.back(), ps[i])) <= 0) qs.pop_back();
  }
  for(int i = n - 2, t = sz(qs); i >= 0; qs.pb(ps[i--])) {
    while(sz(qs) > t && sign(det(qs[sz(qs) - 2], qs.back(), ps[i])) <= 0) qs.pop_back();
  }
  qs.pop_back(); return qs;
}
// 【凸包最远点对】
db diameter(vector<P> A) {
	int n = sz(A);
	if(n <= 1) return 0;
	int l = 0, r = 0;
	rep(i, 1, n) (A[i] < A[l]) && (l = i), (A[r] < A[i]) && (r = i);
	db res = (A[l]-A[r]).len();
	int i = l, j = r;
	do (++(det(A[(i + 1) % n]- A[i], A[(j + 1) % n] - A[j]) >= 0 ? j : i)) %= n,
		res = max(res, (A[i] - A[j]).len());
	while(i != l || j != r);
	return res;
}
// 【动态凸包】
// O(nlogn)
// 插入点，询问点在不在凸包内部（包括边界）
namespace DCH {
	map<int, P> h1, h2;
	bool ao(P a, P b, P c) {
		// 包括边界：小等于
		return (b.y - a.y) * 1ll * (c.x - b.x) <= (c.y - b.y) * 1ll * (b.x - a.x);
	}
	bool in(map<int, P> &h, P p) {
		if(!sz(h)) return 0;
		if(p.x < h.begin()->se.x || p.x > h.rbegin()->se.x) return 0;
		auto l = h.lower_bound(p.x);
		if(p.x == l->se.x) return p.y <= l->se.y;
		auto r = l--;
		return ao(l->se, p, r->se);
	}
	void ins(map<int, P> &h, P p) {
		if(in(h, p)) return ;
		h[p.x] = p;
		auto pos = h.find(p.x);
		while(1) {
			auto l = pos; if(l == h.begin()) break; --l;
			auto ll = l; if(ll == h.begin()) break; --ll;
			if(ao(ll->se, l->se, p)) h.erase(l); else break;
		}
		while(1) {
			auto r = pos; r++; if(r == h.end()) break;
			auto rr = r; rr++; if(rr == h.end()) break;
			if(ao(p, r->se, rr->se)) h.erase(r); else break;
		}
	}
	void ins(int x, int y) { ins(h1, P(x, y)); ins(h2, P(x, -y)); }
	bool in(int x, int y) { return in(h1, P(x, y)) && in(h2, P(x, -y)); }
}
// 【凸包交】
namespace ConvecIntersection{ // ?
	const int N = 1005;
	struct Rec {
		P d[10];int dn;// d[dn] = d[0]
		P operator [] (const int&n) {return d[n];}
	}r[N];
	typedef pair<db,int> pdi;
	int n;pdi res[1000005];
	db getLoc(P a,P b,P p){
		if(sgn(b.x - a.x)) return (p.x - a.x) / (b.x - a.x);
		return (p.y - a.y) / (b.y - a.y);
	}
	db work() {
		db rt=0;
		rep(i,0,n) rep(j,0,r[i].dn){
			int sz=0;
			res[sz++] = pdi(0,0);res[sz++] = pdi(1,0);
			rep(t,0,n) {
				if(t == i) continue;
				rep(g,0,r[t].dn) {
					int du = sgn((r[i][j+1] - r[i][j]) / (r[t][g] - r[i][j]));
					int dv = sgn((r[i][j+1] - r[i][j]) / (r[t][g+1] - r[i][j]));
					if(!du && !dv) {
						if(sgn((r[i][j+1] - r[i][j]) * (r[t][g+1] - r[t][g])) < 0 || i < t){
							res[sz++] = pdi(getLoc(r[i][j] , r[i][j+1] , r[t][g]) , 1);
							res[sz++] = pdi(getLoc(r[i][j] , r[i][j+1] , r[t][g+1]) , -1);
						}} else {
							db s1 = (r[i][j] - r[t][g]) / (r[t][g+1] - r[t][g]);
							db s2 = (r[t][g+1] - r[t][g]) / (r[i][j+1] - r[t][g]);
							if(du >= 0 && dv < 0) res[sz++] = pdi(s1 / (s1 + s2) , 1);
							else if(du < 0 && dv >= 0) res[sz++] = pdi(s1 / (s1 + s2) , -1);
						}}}
			sort(res , res + sz);
			int cnt = 0; --sz;
			rep(t,0,sz) {
				cnt += res[t].se;
				if(cnt == 0 && sgn(res[t].fi - res[t+1].fi)) {
					db a = res[t].fi;
					if(a < 0) a = 0; if(a > 1) break;
					db b = res[t+1].fi;
					if(b < 0) continue; if(b > 1) b = 1;
					rt += ((r[i][j+1] - r[i][j]) * a + r[i][j]) / ((r[i][j+1]-r[i][j]) * b + r[i][j]);
				}}}
		return rt / 2;}}