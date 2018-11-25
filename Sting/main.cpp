//https://www.cnblogs.com/zhizhan/p/4876093.html

#include <iostream>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class String
{
public:
	String(char* str = NULL); //默认构造
	String(const String& other);//拷贝构造
	String(String&& other);    //移动拷贝
	String& operator=(const String& other); //运算符重载拷贝构造
	String& operator=( String&& other);     //运算符重载移动拷贝构造
	~String();

	//String 类的扩展接口
	String operator+(const String &str) const;	//重载+
	String& operator=(const String &str);		//重载=
	String& operator+=(const String &str);		//重载+=
	bool operator==(const String &str) const;	//重载==
	char& operator[](int n) const;				//重载[]

	size_t size() const;		//获取长度
	const char* c_str() const;	//获取C字符串

	friend istream& operator>>(istream &is, String &str);//输入
	friend ostream& operator<<(ostream &os, String &str);//输出

private:
	char* str_ptr_;
};


String::String(char* str)
{
	//new方法
	//	str_ptr_ = new char[len];

	if (!str)
	{
		str_ptr_ = (char*)malloc(1);
		str_ptr_ = '\0';
	}else
	{
		//malloc 方法
		str_ptr_ = (char*)malloc(strlen(str) + 1);

		strcpy(str_ptr_, str);
	}
}

String::String(const String& other)
{
	if (this != &other)
	{
		str_ptr_ = (char*)malloc(strlen(other.str_ptr_) + 1);
		strcpy(str_ptr_, other.str_ptr_);
	}
}

String::String(String&& other)
{
	str_ptr_ = other.str_ptr_;
	other.str_ptr_ = NULL;
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		String temp(other);

		char* str = temp.str_ptr_;
		temp.str_ptr_ = str_ptr_;
		str_ptr_ = str;
	}
	return *this;
}

String& String::operator=(String&& other)
{
	if (this != &other)
	{
		free(str_ptr_);
		str_ptr_ = NULL;

		str_ptr_ = other.str_ptr_;
		other.str_ptr_ = NULL;
	}
	return *this;
}

String::~String()
{
	if (str_ptr_)
	{
		free(str_ptr_);
		str_ptr_ = NULL;
	}
}

//以下是String类的扩展接口
String String::operator+(const String &other) const
{
	String newString;
	size_t newLen = strlen(str_ptr_) + strlen(other.str_ptr_);

	newString.str_ptr_ = (char*)malloc(newLen + 1);

	strcpy(newString.str_ptr_, str_ptr_);

	strcat(newString.str_ptr_, other.str_ptr_);

	return newString;

}




int main()
{


	system("pause");
	return 0;
}
