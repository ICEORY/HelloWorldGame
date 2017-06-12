#include <iostream>
#include <conio.h>
using namespace std;
const char xianshi_1[5][4]={"  ","¡ð","¡ñ","¡ï","¡ö"};
//const char xianshi_2[2][4]={"  ","¡ñ"};
int a[13][27]={1,0,0,0,1,0,1,1,1,1,1,2,1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,
			   1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,
               1,1,1,1,1,2,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,
               1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,
               1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,
               1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,2,1,1,1,1,2,2,1,1,1,0,
			   2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,2,0,0,
	           1,0,0,0,1,0,0,1,1,1,0,0,1,1,1,0,0,1,0,0,0,0,1,1,1,1,0,
			   1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,
			   1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,
			   1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,
			   1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,
			   0,1,0,1,0,0,0,1,1,1,0,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,3
			   };
int c[13][27];
void delay(int t);
void game();
void autogame();
void display();
void delay(int t)
{
    int i,j,k;
    for(i=0;i<=t;i++)
    {
        for(j=0;j<=10000;j++)
        {
            for(k=0;k<=1000;k++);
        }
    }
}
void display()
{
	int i,j;
	cout<<"welcom!!"<<endl;
	cout<<"use the key W/S/A/D to move"<<endl;
	cout<<"you must eat all the white circle"<<endl;
	cout<<"you could only move on the empty circle"<<endl;
	cout<<"use Q to quit the game"<<endl;
    for(j=0;j<=12;j++)
    {
        for(i=0;i<=26;i++)
        {
            cout<<xianshi_1[c[j][i]];
        }
        cout<<"\n";
    }
}
void game()
{
	int x=0,y=0;
	int lx=0,ly=0;
	int i,j;
	int b[13][27];
	for(i=0;i<=12;i++)
	{
		for(j=0;j<=26;j++)
		{
			b[i][j]=a[i][j];
			c[i][j]=a[i][j];
		}
	}
	char key='f';
	while(c[y][x]!=3&&key!='Q')
	{
		if(b[ly][lx]!=2)c[ly][lx]=b[ly][lx];
		else c[ly][lx]=0;
		if(c[y][x]!=3)c[y][x]=4;
		system("cls");
		display();
		char cin=getch();
		key=cin;
		lx=x;
		ly=y;
		if(key=='W')
		{
			if(y-1>=0&&c[y-1][x]!=0)y--;
		}
		if(key=='S')
		{
			if(y+1<=12&&c[y+1][x]!=0)y++;
		}
		if(key=='A')
		{
			if(x-1>=0&&c[y][x-1]!=0)x--;
		}
		if(key=='D')
		{
			if(x+1<=26&&c[y][x+1]!=0)x++;
		}
	}
	if(c[y][x]==3)cout<<"you win!"<<endl;
	else cout<<"you lose the game!try again!"<<endl;
}
void autogame()
{
	int x=0,y=0,n=0;
	int lx=0,ly=0;
	int i,j;
	int b[13][27];
	char ans[]="SSSSSSWWWWDDDDDDSSSDDSWAAWWWWWDDDDDDSSSSSDDSWDDDSWDDDDDDDSSAASSSSSDDDD";
	char key;
	for(i=0;i<=12;i++)
	{
		for(j=0;j<=26;j++)
		{
			b[i][j]=a[i][j];
			c[i][j]=a[i][j];
		}
	}
	while(c[y][x]!=3)
	{
		if(b[ly][lx]!=2)c[ly][lx]=b[ly][lx];	
		else c[ly][lx]=0;
		if(c[y][x]!=3)c[y][x]=4;
		system("cls");
		display();
		delay(10);
		key=ans[n];
		lx=x;
		ly=y;
		if(key=='W')y--;
		if(key=='S')y++;
		if(key=='A')x--;
		if(key=='D')x++;
		n++;
	}
}
int main()
{
	char choose;
	while(1)
	{
		cout<<"play game(P)or just watch(J)?"<<endl;	
		cin>>choose;
		switch(choose)
		{
			case 'P': system("cls");game();break;
			case 'J': system("cls");autogame();break;
			default: cout<<"error,please choose ones again";
		}
	}
}
