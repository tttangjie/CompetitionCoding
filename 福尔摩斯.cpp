#include <iostream>

using namespace std;

int main()
{
    char string1[65],string2[65],string3[65],string4[65];
    cin>>string1>>string2>>string3>>string4;
    int i,time=0;


    for(i=0; string1[i]&&string2[i]; ++i)
    {

        if(string1[i]==string2[i]&&string1[i]<='G'&&string1[i]>='A'&&time==0)
        {
            time=1;
            switch(string1[i])
            {
            case 'A':
                cout<<"MON ";
                break;
            case 'B':
                cout<<"TUE ";
                break;
            case 'C':
                cout<<"WED ";
                break;
            case 'D':
                cout<<"THU ";
                break;
            case 'E':
                cout<<"FRI ";
                break;
            case 'F':
                cout<<"SAT ";
                break;
            case 'G':
                cout<<"SUN ";
                break;

            }
        }
        if(string1[i]==string2[i]&&((string1[i]<='9'&&string1[i]>='0')||(string1[i]<='N'&&string1[i]>='A'))&&time==1)
        {
            if(string1[i]<='9'&&string1[i]>='0')
            {
                cout<<0<<string1[i]<<':';
            }
            else
                cout<<(string1[i]-'A'+11)<<':';
            break;
        }
    }
    for(i=0;string3[i]&&string4[i]; ++i)
    {
        if(string3[i]==string4[i]&&((string3[i]>='a'&&string3[i]<='z')||(string3[i]>='A'&&string3[i]<='Z')))
        {
            if(i<10)
                cout<<0<<i;
            else cout<<i;
            break;
        }
    }
    return 0;
}

