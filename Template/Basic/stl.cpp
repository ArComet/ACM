#include<bits/stdc++.h>
using namespace std;
int main(){
	int num[6]={1,2,4,7,15,34},x=7;
	sort(num,num+6);//��С�������� 
	lower_bound(num,num+6,x);//��һ�������x��ָ�� 
	upper_bound(num,num+6,x);//��һ������x��ָ�� 
	sort(num,num+6,greater<int>());//�Ӵ�С����
	lower_bound(num,num+6,x,greater<int>());//��һ��С����x��ָ�� 
	upper_bound(num,num+6,x,greater<int>());//��һ��С��x��ָ�� 
	return 0;	
} 
	
