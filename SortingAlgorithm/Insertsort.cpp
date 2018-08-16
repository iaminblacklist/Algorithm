#include<iostream>
using namespace std;

template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array)/sizeof(array[0]));
}

// void Insertsort(int array[], int n)
// {
// 	int i, j, temp;
// 	for(int i = 1; i < n; i++)
// 	{
// 		if(array[i] < array[i-1])
// 		{
// 			int temp = array[i];
// 			for(j = i; array[j-1] > temp; j--)
// 			{
// 				array[j] = array[j-1];
// 			}
// 			array[j] = temp;
// 		}
// 	} 
// }

void Insertsort(int array[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int temp = array[i];
		int j = i-1;
		while(j >= 0 && array[j] > temp)
		{
			array[j+1] = array[j];
			--j;
		}
		array[j+1] = temp;
	}
}

int main()
{
	int a[] = {23, 67, 45, 33, 89, 7, 66};
	int n = getArrayLen(a);
	Insertsort(a, n);
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
