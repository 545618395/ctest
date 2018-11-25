//模拟实现strcat函数
char *my_strcat(char *dest,const char *src){
    char * ret = dest;
    //对接受到的两个指针进行断言
    assert(dest);
    assert(src);
    //将dest遍历至\0
    while(*dest){
        dest++;
    }
    //将src内容复制在dest之后
    while(*src){
        *dest++ = *src++;
    }
    //在dest后面追加\0
    *dest = '\0';
    return ret;
}