#include<iostream>
using namespace std;

template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0])); //ע��洢�ַ������� ������ĩβ��һ��'/0'�ַ�����Ҫȥ���������Ҫreturn (sizeof(array) / sizeof(array[0]));
}

void quicksort(int a[], int left, int right){
	int i = left;
	int j = right;
	int temp = a[left];  				//��׼�� 
	
	if(left > right)
	{
		return;
	}
	
	while(i != j)
	{
		while(a[j]>=temp&&i<j){			//�ȴ��ұ߿�ʼ 
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
	
	a[left] = a[i];						//����׼����λ 
	a[i] = temp;	
	
	quicksort(a, left, i-1);			//����д�� "--i",�����Լ���ı� i ��ֵ 
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










