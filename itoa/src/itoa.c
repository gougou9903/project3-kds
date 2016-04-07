//reference : baidu baike,
//http://baike.baidu.com/link?url=1HN02u5-ULP1mn8XfFa-T1HggdkPCB5iTj5Up1PKQ_y7OLvDO1WWJArQocc1vMflfXgURwxe4lADS974GHP6Iq
#include<stdio.h>
#include<stdint.h>
#include<math.h>

char* itoa(int num,char*str,int radix);

int main(void) {
//		int number = 123456;
//		char string[25];
//		itoa(number,string,10);
//		printf("integer=%d string=%s\n",number,string);
//		return 0;

	char ch[] = "Hello";
	int length = sizeof(ch);
	printf("%d", length);
}

char* itoa(int num,char*str,int radix)
{
char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
unsigned unum;
int i=0,j,k;

if(radix==10&&num<0)
{
unum=(unsigned)-num;
str[i++]='-';
}
else unum=(unsigned)num;

do{
str[i++]=index[unum % (unsigned)radix];
unum/=radix;
}while(unum);
str[i]='\0';

if(str[0]=='-')k=1;
else k=0;
char temp;
for(j=k;j<=(i-1)/2;j++)
{
temp=str[j];
str[j]=str[i-1+k-j];
str[i-1+k-j]=temp;
}
return str;
}

