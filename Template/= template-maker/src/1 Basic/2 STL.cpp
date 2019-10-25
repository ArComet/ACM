#include<bits/stdc++.h>
using namespace std;
int main(){
	int num[6]={1,2,4,7,15,34}; 
	int x=7;
	sort(num,num+6);                           
	//按从小到大排序 
	int pos1=lower_bound(num,num+6,x)-num;    
	//返回数组中第一个大于或等于被查数的值 
	int pos2=upper_bound(num,num+6,x)-num;    
	//返回数组中第一个大于被查数的值
	sort(num,num+6,greater<int>());                      
	//按从大到小排序
	int pos3=lower_bound(num,num+6,x,greater<int>())-num; 
	//返回数组中第一个小于或等于被查数的值 
	int pos4=upper_bound(num,num+6,x,greater<int>())-num;  
	//返回数组中第一个小于被查数的值 
	return 0;	
} 
	
