/*
欧拉公式Euler(n)=n/(1-1/p1)(1-1/p2)(…)
求[1,n-1]中与n互质的数的个数 
*/ 

//求单个欧拉函数值 
int euler(int n){
	int ans = 1,i;
	for (i = 2; i * i <= n; i++){
		if (n % i == 0){
			n /= i;
			ans *= i - 1;
			while (n % i == 0){
				n /= i;
				ans *= i;
			}
		}
	}
	if (n > 1) ans *= n - 1;
	return ans;
}
//筛素数法求1..n欧拉函数值 
