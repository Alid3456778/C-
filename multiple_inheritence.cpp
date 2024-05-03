#include<iostream.h>
#include<conio.h>
#include<iomanip.h>

class Base1{
protected:
	int base1;

public:

	void set_base1(int a){
		base1=a;
	}

	void show_base1(){
	cout<<"Showing the Base 1 "<<base1<<endl;
	}

};

class Base2{
protected:
	int base2;

public:

	void set_base2(int a){
		base2=a;
	}

};


class Derive : public Base1, public Base2 {

public:

	void show(){
	cout<<"Base One is "<<base1<<endl;
	cout<<"Base Two is "<<base2<<endl;
	cout<<"Addition of Base1 and Base2 is "<<base1+base2<<endl;
	}

};





void main()
{
Derive d;
Base1 b1;
d.set_base1(12);
d.set_base2(12);
clrscr();

d.show();



getch();
}



