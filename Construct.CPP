#include<iostream.h>
#include<conio.h>
#include<iomanip.h>

class sum{

public:
int a;
int b;
int c;

sum(int x,int y){
cout<<"constructtor is working"<<endl;
}

sum(int n=2/*constructor with default arguments*/);

void q(int n=2);

};

sum :: q(int n){
c=a+b;
}

sum :: sum(int n){
int i;
if(n==2){
cout<<"Getting Parameterrize value from default construct"<<endl;
}

for(i=1;i<=10;i++)
{
a=n*i;
cout<<n<<" X "<<i<<" : "<<a<<endl;
}

b=n+a;
cout<<"Your given number "<<n<<" Adding with "<<a<<" : "<<b<<endl;

}




void main()
{
int a=0;
clrscr();
//cin>>a;
sum s(4);
//sum s2;
//sum s();
cout<<"Class memebers :"<<endl<<" A "<<s.a<<endl<<" B "<<s.b<<endl<<" C "<<s.q()<<endl;

getch();
}