#include<bits/stdc++.h>
using namespace std;
int main(){
	int num[6]={1,2,4,7,15,34}; 
	int x=7;
	sort(num,num+6);                           
	//����С�������� 
	int pos1=lower_bound(num,num+6,x)-num;    
	//���������е�һ�����ڻ���ڱ�������ֵ 
	int pos2=upper_bound(num,num+6,x)-num;    
	//���������е�һ�����ڱ�������ֵ
	sort(num,num+6,greater<int>());                      
	//���Ӵ�С����
	int pos3=lower_bound(num,num+6,x,greater<int>())-num; 
	//���������е�һ��С�ڻ���ڱ�������ֵ 
	int pos4=upper_bound(num,num+6,x,greater<int>())-num;  
	//���������е�һ��С�ڱ�������ֵ 
	return 0;	
} 
	
