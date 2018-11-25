//https://www.cnblogs.com/zhizhan/p/4876093.html

#include <iostream>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class String
{
public:
	String(char* str = NULL); //Ĭ�Ϲ���
	String(const String& other);//��������
	String(String&& other);    //�ƶ�����
	String& operator=(const String& other); //��������ؿ�������
	String& operator=( String&& other);     //����������ƶ���������
	~String();

	//String �����չ�ӿ�
	String operator+(const String &str) const;	//����+
	String& operator=(const String &str);		//����=
	String& operator+=(const String &str);		//����+=
	bool operator==(const String &str) const;	//����==
	char& operator[](int n) const;				//����[]

	size_t size() const;		//��ȡ����
	const char* c_str() const;	//��ȡC�ַ���

	friend istream& operator>>(istream &is, String &str);//����
	friend ostream& operator<<(ostream &os, String &str);//���

private:
	char* str_ptr_;
};


String::String(char* str)
{
	//new����
	//	str_ptr_ = new char[len];

	if (!str)
	{
		str_ptr_ = (char*)malloc(1);
		str_ptr_ = '\0';
	}else
	{
		//malloc ����
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

//������String�����չ�ӿ�
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
