#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>
#include<string.h>
using namespace std;
map<char,int>letter;
void guide() //向导 
{
    system("cls");
    printf("Welcome to Caesar password program！\n");
}

void init()
{
    for(int i=0;i<=26;i++)
    {
        char l='a'+i;
        letter[l]=i;
    }
}

void enc(char s[],int k)  //加密算法
{
    int len=strlen(s);
    string enc="";
    for(int i=0;i<len;i++)
    {
        int a=letter[s[i]];
        int b=(a+k)%26;
        enc+=('a'+b);
    }
    cout<<enc<<endl;
}

void dec(char s[],int k)  //解密算法
{
    int len=strlen(s);
    string dec="";
    for(int i=0;i<len;i++)
    {
        int a=letter[s[i]];
        int b=(a+26-k)%26;
        dec+=('a'+b);
    }
    cout<<dec<<"  "<<endl;
}

void enc1()
{
    printf("Please enter cleartext:\n");
    char s[15000];
    scanf("%s",&s);
    int k;
    printf("Please enter the key:\n");
    scanf("%d",&k);
    printf("Output ciphertext:\n");
    enc(s,k);

}

void dec1()
{
    printf("Please enter ciphertext:\n");
    char m[15000];
    scanf("%s",&m);
    printf("Please enter the key:\n");
    int k;
    scanf("%d",&k);
    dec(m,k);
}

void attrack()
{
	printf("Please enter the ciphertext:\n");
    char n[15000];
    scanf("%s",&n);
    int len=strlen(n);
    for(int k=0;k<=25;k++)
    {
		int key=(26-k)%26;
        string ans="";
        for(int i=0;i<len;i++)
        {
            int a=letter[n[i]];
            int b=(a+k)%26;
            ans+=('a'+b);
        }
        cout<<ans<<"  "<<"key="<<key<<endl;
    }
}

void choose()
{
    int test=1;
    while(test)//对于菜单的选择
    {
        printf("Please select the function you want to use:\n");
        printf("1:encryption  2:decrypt  3:break a code  0：exit\n");
        int n;
        scanf("%d",&n);
        if(n==1)
        {
            enc1();
        }
        else if(n==2)
        {
            dec1();
        }
        else if(n==0)
        {
            printf("The program has exited safely！\n");
            test=0;
            return;
        }
		else if(n==3)
		{
			attrack();
		}
        else
        {
            printf("ERROR!\nPlease re-enter！");
            choose();
        }
    }
}

int main()
{
    init();
    guide();
    choose();
	cout<<" "<<endl;
    system("pause");
    return 0;

}
