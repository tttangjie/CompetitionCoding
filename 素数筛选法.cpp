#include <iostream>
#include<math.h>

using namespace std;

int main()
{
bool judge[10001]={true} ;
for(int i=0;i<10001;i++)
{
	judge[i]=true;
} 

for (int m=2;m<sqrt(10000);++m)
{
    if(judge[m])
    {
        for(int n=2*m;n<10001;n+=m)
        {
            judge[n]=false;
        }
    }
}
for(int a = 2;a<10001;++a)
{
    if(judge[a])
        cout<<a<<endl;
}

    return 0;
}
