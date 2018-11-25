//c 库函数  strcpy 拷贝字符串


char *my_strcpy(char *t,char *s){
    char *strDest=t;
    assert((*t)!=NULL && (*s)!=NULL);
    while((*t++=*s++));
    return strDest;
}

