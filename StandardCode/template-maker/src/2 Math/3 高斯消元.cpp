int guass(int n){
	int ans=1,t,tmp;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			while (mat[j][i]){
				t=mat[i][i]/mat[j][i];
				for (int k=0; k<n; k++){
					tmp=mat[i][k];
					tmp-=t*mat[j][k];
					mat[i][k]=tmp;
				}
				for (int k=0; k<n; k++) swap(mat[i][k],mat[j][k]);
				ans=-ans;
			}
		}
		if (mat[i][i]==0) return 0;	
		ans*=mat[i][i];
	}
	return ans;
}

