#include <iostream>

using namespace std;

void insertSort(int* arr,int n)
{
	int j;
	for (int i = 1;i < n;i++)
	{
		int t = arr[i];
		for (j = i;j - 1 >= 0 && t < arr[j - 1];j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = t;
	}
}

void dis(int* arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	insertSort(arr, sizeof(arr) / sizeof(*arr));
	dis(arr, sizeof(arr) / sizeof(*arr));

	system("pause");
	return 0;
}