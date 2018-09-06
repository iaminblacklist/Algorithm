#include<iostream>
#include<vector>
using namespace std;

bool binary_search(int arr[], int n, int key, vector<int> &target)
{
	int left = 0;
	int right = n-1;

	while(left <= right)
	{
		int mid = left + ((right-left)>>1);
		if(arr[mid] > key)
		{
			right = mid - 1;
		}
		else if(arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			target.push_back(mid);
			if(mid > 0)
			{
				if(arr[mid-1] == key)
				{
					for(int i=mid-1;i>=0;i--)
					{
						if(arr[i] == key)
						{
							target.push_back(i);
						}
						else break;
					}
				}
			}
			if(mid < right)
			{
				if(arr[mid+1] == key)
				{
					for(int i=mid+1;i<=right;i++)
					{
						if(arr[i] == key)
						{
							target.push_back(i);
						}
						else break;
					}
				}
			}
			return true;
		}
	}
	return false;
}

int main()
{
	int arr[7] = {1, 3, 5, 5, 5, 9, 10};
/*	int ret = 0;
	ret = binary_search(arr, 6, 5);
	cout<<ret<<endl;*/
	
	vector<int> tmp;
	binary_search(arr, 7, 5, tmp);
	for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
	{ 
        cout << *it << " ";
    }
}
