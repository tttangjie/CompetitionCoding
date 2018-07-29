#include <stdio.h>
#include <string.h>
#define N 1000001
int find_string(char str[],char substr[]);
void Suffix(char c[],int n);
char s[N];
int main()
{
	int T,sublen,result,i,k,x;
	char ch1[N],ch2[N];
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		result=0;
		gets(ch1);
		gets(ch2);
		sublen=strlen(ch2);
		k=sublen;
		while(sublen!=0)
		{
			Suffix(ch2,k-sublen);
			x=find_string(ch1,s);
			result=result+(sublen*x)%1000000007;	
			sublen--;
		}	
		printf("%d\n",result);	
	}
	
    return 0;
}

void Suffix(char c[],int n)
{
	int i,len;
	len=strlen(c);
	for(i=n;i<len;i++)
	{
		s[i-n]=c[i];
	}
	s[i-n]='\0';

}

int find_string(char str[], char substr[])
{
    int count = 0,i,j,check;
    int len = strlen(str);
    int sublen = strlen(substr);
    for(i = 0; i <= len-sublen; i++)
    {
       check = 1;
        for(j = 0; j + i < len && j < sublen; j++)
        {
            if(str[i+j] != substr[j])
            {
                check = 0;
                break;
            }
        }
        if(check == 1)
        {
            count++;
            //i = i + sublen;
        }
    }

    return count;
}
