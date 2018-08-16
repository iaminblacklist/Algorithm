#include<iostream>
using namespace std;

template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array)/sizeof(array[0]));
}

void Selectsort(int array[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		int min = i;
		for(int j = i + 1; j < n; j++)
		{
			if(array[min] > array[j])
			{
				min = j;
			}
		}
		if(min != i)
		{
			int k = array[min];
			array[min] = array[i];
			array[i] = k;
		}
	}
}

int main()
{
	int a[] = {23, 67, 45, 33, 89, 7, 66};
	int n = getArrayLen(a);
	Selectsort(a, n);
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}