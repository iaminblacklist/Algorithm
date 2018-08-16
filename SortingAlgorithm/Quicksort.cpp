#include<iostream>
using namespace std;

template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0])); //注意存储字符串的字 符数组末尾有一个'/0'字符，需要去掉它，因此要return (sizeof(array) / sizeof(array[0]));
}

void quicksort(int a[], int left, int right){
	int i = left;
	int j = right;
	int temp = a[left];  				//基准数 
	
	if(left > right)
	{
		return;
	}
	
	while(i != j)
	{
		while(a[j]>=temp&&i<j){			//先从右边开始 
			j--;
		} 
		while(a[i]<=temp&&i<j){
			i++;
		}
		if(i<j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;			
		}
	}
	
	a[left] = a[i];						//将基准数归位 
	a[i] = temp;	
	
	quicksort(a, left, i-1);			//不能写成 "--i",自增自减会改变 i 的值 
	quicksort(a, i+1, right);
//	quicksort(a, left, --i);
//	quicksort(a, ++i, right);
}

int main()
{
	int a[]={4,3,6,5,8,9,7,2,1}; 
	int left = 0;
	int n = getArrayLen(a);
	int right = n-1; 
	quicksort(a,left,right);
	for(int i=0;i<9;i++){
		cout<<a[i]<<endl;
	} 
	return 0;
}










