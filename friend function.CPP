#include<iostream.h>
#include<conio.h>
#include<iomanip.h>

class sum{
int a,b;
public:
//friend function declaration inside of class , to make sure the compiler understand that addition is an friend and you can share information with that
friend sum addition(sum s1, sum s2);

void suml(int n1,int n2)
{
a=n1;
b=n2;
}

void print(){
cout<<" "<<a<<" "<<b<<endl;
}

};

//friend function outside of class
sum addition(sum s1,sum s2)
{
cout<<"Addition of 1st is "<<s1.a+s2.a<<endl;
cout<<"Addition of 2nd is "<<s1.b+s2.b<<endl;
}


void main()
{
sum s1,s2;
clrscr();

s1.suml(2,5);
s1.print();

s2.suml(3,5);
s2.print();


addition(s1,s2);




  getch();


}