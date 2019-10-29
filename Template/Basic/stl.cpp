#include<bits/stdc++.h>
using namespace std;
int main(){
	int num[6]={1,2,4,7,15,34},x=7;
	sort(num,num+6);//从小到大排序 
	lower_bound(num,num+6,x);//第一个大等于x的指针 
	upper_bound(num,num+6,x);//第一个大于x的指针 
	sort(num,num+6,greater<int>());//从大到小排序
	lower_bound(num,num+6,x,greater<int>());//第一个小等于x的指针 
	upper_bound(num,num+6,x,greater<int>());//第一个小于x的指针 
	return 0;	
} 
	
