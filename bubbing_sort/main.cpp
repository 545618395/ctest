#include <iostream>

using namespace std;

void bubbingSort(int* p,int n)
{
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - 1 - i;j++)
		{
			if (p[j] > p[j + 1])
			{
				p[j] ^= p[j+1];
				p[j + 1] ^= p[j];
				p[j] ^= p[j + 1];
			}
		}
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

//序而不排   有序则不排
void bubbingSortAndCheck(int* p, int n)
{
	bool flag = false;
	for (int i = 0;i < n - 1;i++)
	{
		flag = true;
		for (int j = 0;j < n - 1 - i;j++)
		{
			if (p[j] > p[j + 1])
			{
				p[j] ^= p[j + 1];
				p[j + 1] ^= p[j];
				p[j] ^= p[j + 1];
				flag = false;
			}
		}
		if (flag)
			break;
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,10};
	bubbingSort(arr,sizeof(arr)/sizeof(*arr));
	dis(arr, sizeof(arr) / sizeof(*arr));

	system("pause");
	return 0;
}