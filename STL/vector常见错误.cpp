#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int*> inType;
	for(int i = 0;i<9;i++)
	{
		int temp = i;
		inType.push_back(&temp);     //这里放的都是同一块地址
	}
	for(std::vector<int*>::iterator it = inType.begin();it!=inType.end();it++)
	{
		cout<<*(*it)<<endl;   //这里会发现打印出来的值全部一样
	}  


	//修改
	vector<int*> v1;

	for (int i = 0; i < 10; i++)
	{
		int* a = new int;
		v1.push_back(a);
	}

	//错误删除  迭代器失效
	for (int i = 0; i < v1.size();i++)
	{
		if (i % 2 == 0)
		{
			delete v1[i];
			v1[i] = NULL;
			v1.erase(v1.begin() + i);
		}
	}

	//正确方式  反向删除
	for (int i = v1.size()-1; i > 0; --i)
	{
		if (i % 2 == 0)
		{
			delete v1[i];
			v1[i] = NULL;
			v1.erase(v1.begin() + i);
		}
	}
	cout << v1.size() << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << endl;
	}

	system("pause");
	return 0;
}