void sift_prime(bool notprime[],int N){
	int i,j;
	vector<int> prime; 
	memset(notprime,false,sizeof(bool)*N);
	notprime[0] = notprime[1] = 1;
	for (i = 2; i < N; ++i){
		if (!notprime[i]){
			prime.push_back(i);
		}
		for (j = 0; i * prime[j] <= N && j < prime.size(); ++j){
			notprime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break; //speed up linear time
		}
	}
}

