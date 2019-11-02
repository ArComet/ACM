// 【直线交点】
P isLL(L l1, L l2) {
	db s1 = det(l2.b - l2.a, l1.a - l2.a);
	db s2 = -det(l2.b - l2.a, l1.b - l2.a);
	return (l1.a * s2 + l1.b * s1) / (s1 + s2);
}
P isLL(L l, db a, db b, db c) { // ax + by + c = 0
	db u = a * l.a.x + b * l.a.y + c;
	db v = -(a * l.b.x + b * l.b.y + c);
	return (l.a * v + l.b * u) / (u + v);
}
P isLL(db a0, db b0, db c0, db a1, db b1, db c1) {
	db d = a0 * b1 - a1 * b0;
	return P(b0 * c1 - b1 * c0, a1 * c0 - a0 * c1) / d;
}
// 【线相交判定】
bool isSSr(const L &a, const L &b){
	db c1 = det(a.t - a.s, b.s - a.s), c2 = det(a.t - a.s, b.t - a.s);
	db c3 = det(b.t - b.s, a.s - b.s), c4 = det(b.t - b.s, a.t - b.s);
	return sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0;
}
bool isSS(L a,L b){
	db c1 = det(a.t - a.s, b.s - a.s), c2 = det(a.t - a.s, b.t - a.s);
	db c3 = det(b.t - b.s, a.s - b.s), c4 = det(b.t - b.s, a.t - b.s);
	return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0 &&
		sign(max(a.s.x, a.t.x) - min(b.s.x, b.t.x)) >= 0 &&
		sign(max(b.s.x, b.t.x) - min(a.s.x, a.t.x)) >= 0 &&
		sign(max(a.s.y, a.t.y) - min(b.s.y, b.t.y)) >= 0 &&
		sign(max(b.s.y, b.t.y) - min(a.s.y, a.t.y)) >= 0;
}
bool isLS(P a1, P a2, P b1, P b2) { // 判断直线线段是否相交（端点也算）
	db c1 = det(a2 - a1, b1 - a1), c2 = det(a2 - a1, b2 - a1);
	return sign(c1) * sign(c2) <= 0;
}
// 【点到线距离】
db disToL(L l, P p) {
  return fabs(det(l.a, p, l.b) / (l.b - l.a).len());
}
db disToS(L l, P p) {
  return sign(dot(l.a, p, l.b)) * sign(dot(l.b, p, l.a)) == 1 ? disToL(l, p) : min((p - l.a).len(), (p - l.b).len());
}
// 【线到线距离】
db disSS(L a, L b){
	if(isSS(a, b)) return 0;
	return min(min(disToSeg(b, a.s), disToSeg(b, a.t)), min(disToSeg(a, b.s), disToSeg(a, b.t)));
}