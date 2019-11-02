// 【心】
P outC(P A, P B, P C) { // 外心
	P b = B - A, c = C - A;
	db dB = b.len2(), dC = c.len2(), d = 2 * det(b, c);
	return A - P(b.y * dC - c.y * dB, c.x * dB - b.x * dC) / d;
}
P baryC(P p[], int n) { // 重心
	P fz(0, 0); db fm = 0;
	rep(i, 1, n - 1) {
		db t = det(p[0], p[i], p[i + 1]);
		fm += t;
		fz = fz + (p[0] + p[i] + p[i + 1]) * t / 3;
	}
	return fz / fm;
}