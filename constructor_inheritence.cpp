#include<iostream.h>
#include<conio.h>
#include<iomanip.h>

class Base1{
	int data1;

public:
	Base1(int a){
	data1=a;
	cout<<"Base 1 data is contructed "<<endl;
	}

	void get_data1(){
	
	cout<<"Base 1 data is : "<<data1<<endl;
	}
};

class Base2{
	int data2;

public:

	Base2(int b){
	data2=b;
	cout<<"Base 2 data is contructed "<<endl;
	}

	void get_data2(){

	cout<<"Base 2 data is : "<<data2<<endl;
	}
};


class Derive : public Base1,public Base2{
int add;

public:
	Derive(int ad,int a,int b):Base1(int a),Base2(int b){
	add=ad;

	cout<<"Derive contructed "<<endl;	
	}

	void get_derive(){
	
	get_data1();
	get_data2();
	cout<<"Addition is : "<<add<<endl;
	cout<<"Addition of Data1 and Data2 is : "<<data1+data2<<endl;
	}


};



void main()
{
Deriven d(10,5,12);
clrscr();

d.get_derive();

getch();
}