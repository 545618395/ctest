//字符串比较函数

int my_strcmp(char* dest,char* src)
{
   assert((str1 != NULL) && (str2 != NULL));
   while(*str1 && *str2 && (*str1++ == *str2++)){}
   return *str1-*str2;
}