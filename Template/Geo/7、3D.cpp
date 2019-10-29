// 【最小球覆盖】
P3 MinSphere(vector<P3> p) {
  int n = sz(p); assert(n);
  db t = 1; P3 ans(0, 0, 0);
  rep(i, 0, n) ans = ans + p[i]; ans = ans / n;
  while(t > eps) {
    int j = -1; db ret = -1;
    rep(i, 0, n) {
      db tmp = (p[i] - ans).len();
      if(ret < tmp) ret = tmp, j = i;
    }
    ans = ans + (p[j] - ans) * t;
    t *= 0.999;
  }
  return ans;
}
// 【三维向量变换】
struct Mat {
  db a[4][4];
  void set() { rep(i, 0, 4) rep(j, 0, 4) a[i][j] = 0; }
  void e() { rep(i, 0, 4) a[i][i] = 1; }
  Mat operator * (const Mat &c) {
    Mat r; r.set();
    rep(i, 0, 4) rep(j, 0, 4) rep(k, 0, 4) r.a[i][j] += a[i][k] * c.a[k][j];
    return r;
  }
};
Mat kpow(Mat a, int b) {
  Mat r; r.set(); r.e();
  while(b) {
    if(b & 1) r = r * a;
    a = a * a;
    b >>= 1;
  }
  return r;
}
Mat translate(db tx, db ty, db tz) { // 平移，以下矩阵均为左乘
  db p[4][4] = {
    1, 0, 0, tx, 
    0, 1, 0, ty,
    0, 0, 1, tz,
    0, 0, 0, 1};
  Mat r; rep(i, 0, 4) rep(j, 0, 4) r.a[i][j] = p[i][j]; return r;
}
Mat scale(db a, db b, db c) { // 缩放
  db p[4][4] = {
    a, 0, 0, 0,
    0, b, 0, 0,
    0, 0, c, 0,
    0, 0, 0, 1};
  Mat r; rep(i, 0, 4) rep(j, 0, 4) r.a[i][j] = p[i][j]; return r;
}
Mat rotate(P3 s, db a) { // 绕 s 为轴旋转 a 度，右手方向
  db l = s.len(), x = s.x / l, y = s.y / l, z = s.z / l, si = sin(a), co = cos(a);
  db p[4][4] = {
    co + (1 - co) * x * x, (1 - co) * x * y - si * z, (1 - co) * x * z + si * y, 0,
    (1 - co) * y * x + si * z, co + (1 - co) * y * y, (1 - co) * y * z - si * x, 0,
    (1 - co) * z * x - si * y, (1 - co) * z * y + si * x, co + (1 - co) * z * z, 0,
    0, 0, 0, 1};
  Mat r; rep(i, 0, 4) rep(j, 0, 4) r.a[i][j] = p[i][j]; return r;
}