#include<stdio.h>
 
#define BUCKETS 101
 
 
unsigned int SDBMHash(char *str)
{
    unsigned int hash = 0;
 
    while (*str)
    {
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }
 
    return (hash & 0x7FFFFFFF) % BUCKETS;
}
 
int main(void)
{
    char *keywords[] =
    {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
 
    // 哈希表每个地址的映射次数
    // 0地址的映射次数用count[0]表示
    int count[BUCKETS] = {0};
    int i;
    int size = sizeof(keywords) / sizeof(keywords[0]);
    for (i = 0; i < size; i++)
    {
 
        int pos = SDBMHash(keywords[i]);
        count[pos]++;
    }
 
    for (i = 0; i < size; i++)
    {
 
        int pos = SDBMHash(keywords[i]);
        printf("%-10s %d %d\n", keywords[i], pos, count[pos]);
    }
 
    return 0;
}

