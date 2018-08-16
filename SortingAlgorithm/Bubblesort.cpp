//
// Created by OAA on 2018/8/16.
//
#include<iostream>
using namespace std;

template <class T>
int getArrayLen(T& array)
{
    return (sizeof(array) / sizeof(array[0]));
}

void BubbleSort(int array[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                int t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
            }
        }
    }
}

int main()
{
    int a[]={12, 25, 9, 66, 55, 33, 42};
    int n=getArrayLen(a);
    BubbleSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}