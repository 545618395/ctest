//求字符串长度函数

int my_strlen(const char*str) 
{ 
    assert(str != NULL); 
    int count = 0;//计数器 
    while (*str++ != '\0') 
    { 
        count++;
    } 
    return count; 
}

