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

	free(newString.str_ptr_);

	newString.str_ptr_ = (char*)malloc(newLen + 1);

	strcpy(newString.str_ptr_, str_ptr_);

	strcat(newString.str_ptr_, other.str_ptr_);

	return newString;

}

String& String::operator+=(const String &other)		//重载+=
{
	char* newStr = (char*)malloc(strlen(str_ptr_)+strlen(other.str_ptr_) + 1);

	strcpy(newStr, str_ptr_);

	strcat(newStr, other.str_ptr_);

	free(str_ptr_);

	str_ptr_ = newStr;

	return *this;
}

bool String::operator==(const String &other) const//重载==
{
	if (strlen(str_ptr_) != strlen(other.str_ptr_))	return false;
	return strcmp(str_ptr_, other.str_ptr_) ? false : true;
}

inline char& String::operator[](int n) const//重载[]
{
	size_t length = strlen(str_ptr_);
	if (n >= length) return str_ptr_[length - 1]; //错误处理
	else return str_ptr_[n];
}

inline size_t String::size() const//获取长度
{
	return strlen(str_ptr_);
}

inline const char* String::c_str() const//获取C字符串
{
	return str_ptr_;
}

istream& operator>>(istream &is, String &other)//输入
{
	char tem[1000];  //简单的申请一块内存
	is >> tem;

	free(other.str_ptr_);

	other.str_ptr_ = (char*)malloc(strlen(tem) + 1);

	strcpy(other.str_ptr_, tem);
	return is;
}

ostream& operator<<(ostream &os, String &other)//输出
{
	os << other.str_ptr_;
	return os;
}

int main()
{
	{
		String s;
		cin >> s;
		cout << s << ": " << s.size() << endl;

		char a[] = "Hello", b[] = "World!";
		String s1(a), s2(b);
		cout << s1 << " + " << s2 << " = " << s1 + s2 << endl;

		String s3 = s1 + s2;
		if (s1 == s3)	cout << "First: s1 == s3" << endl;
		s1 += s2;
		if (s1 == s3)	cout << "Second: s1 == s3" << endl;

		String s6(s1);

		String s4(std::move(s));//移动构造
		
		String s5;
		s5 = std::move(s4); //移动拷贝构造
	}

	system("pause");
	return 0;
}
