/*
ŷ����ʽ Euler(n)=n/(1-1/p1)(1-1/p2)(��)
��[1,n-1]����n���ʵ����ĸ��� 
*/ 

// �󵥸�ŷ������ֵ 
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
//ɸ��������1..nŷ������ֵ 
