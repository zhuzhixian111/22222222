#include <iostream>
#include <vector>
#include <new>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>

using namespace std;


#define M  249997
#define M1 1000003
#define M2 10000019
//大素数

// RS Hash Function
unsigned int RSHash(char*str)
{
    unsigned int b=378551 ;
    unsigned int a=63689 ;
    unsigned int hash=0 ;

    while(*str)
    {
        hash=hash*a+(*str++);
        a*=b ;
    }

    return(hash % M2);
}

// JS Hash Function
unsigned int JSHash(char*str)
{
    unsigned int hash=1315423911 ;

    while(*str)
    {
        hash^=((hash<<5)+(*str++)+(hash>>2));
    }

    return(hash % M2);
}

// P. J. Weinberger Hash Function
unsigned int PJWHash(char*str)
{
    unsigned int BitsInUnignedInt=(unsigned int)(sizeof(unsigned int)*8);
    unsigned int ThreeQuarters=(unsigned int)((BitsInUnignedInt*3)/4);
    unsigned int OneEighth=(unsigned int)(BitsInUnignedInt/8);
    unsigned int HighBits=(unsigned int)(0xFFFFFFFF)<<(BitsInUnignedInt-OneEighth);
    unsigned int hash=0 ;
    unsigned int test=0 ;

    while(*str)
    {
        hash=(hash<<OneEighth)+(*str++);
        if((test=hash&HighBits)!=0)
        {
            hash=((hash^(test>>ThreeQuarters))&(~HighBits));
        }
    }

    return(hash % M2);
}

// ELF Hash Function
unsigned int ELFHash(char*str)
{
    unsigned int hash=0 ;
    unsigned int x=0 ;

    while(*str)
    {
        hash=(hash<<4)+(*str++);
        if((x=hash&0xF0000000L)!=0)
        {
            hash^=(x>>24);
            hash&=~x ;
        }
    }

    return(hash % M2);
}

// BKDR Hash Function
unsigned int BKDRHash(char*str)
{
    unsigned int seed=131 ;// 31 131 1313 13131 131313 etc..
    unsigned int hash=0 ;

    while(*str)
    {
        hash=hash*seed+(*str++);
    }

    return(hash % M2);
}

// SDBM Hash Function
unsigned int SDBMHash(char*str)
{
    unsigned int hash=0 ;

    while(*str)
    {
        hash=(*str++)+(hash<<6)+(hash<<16)-hash ;
    }

    return(hash % M2);
}

// DJB Hash Function
unsigned int DJBHash(char*str)
{
    unsigned int hash=5381 ;

    while(*str)
    {
        hash+=(hash<<5)+(*str++);
    }

    return(hash % M2);
}

// AP Hash Function
unsigned int APHash(char*str)
{
    unsigned int hash=0 ;
    int i ;

    for(i=0;*str;i++)
    {
        if((i&1)==0)
        {
            hash^=((hash<<7)^(*str++)^(hash>>3));
        }
        else
        {
            hash^=(~((hash<<11)^(*str++)^(hash>>5)));
        }
    }

    return(hash % M2);
}

int main()
{
	char *str = "abcdefg";
	cout<<"RSHash:"<<RSHash(str)<<endl;
	cout<<"JSHash:"<<JSHash(str)<<endl;
	cout<<"PJWHash:"<<PJWHash(str)<<endl;
	cout<<"ELFHash:"<<ELFHash(str)<<endl;
	cout<<"BKDRHash:"<<BKDRHash(str)<<endl;
	cout<<"SDBMHash:"<<SDBMHash(str)<<endl;
	cout<<"DJBHash:"<<DJBHash(str)<<endl;
	cout<<"APHash:"<<APHash(str)<<endl;
	return 0;
}

