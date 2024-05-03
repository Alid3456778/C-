#include<iostream.h>
#include<conio.h>
#include<iomanip.h>

class Complex{
int num1,num2;
public:

	void set_data(int a,int b){
	num1=a;
	num2=b;
	}

	void get_data(){
	cout<<"Number 1 is : "<<num1<<endl;
	cout<<"Number 2 is : "<<num2<<endl;
	}

};


void main(){
//creating a Dynamic pointer object for class with array
Complex *ptr=new Complex[3];
Complex *p=ptr;
int i;
int n1,n2;
clrscr();
//ptr->set_data(23,45);
//ptr->get_data();

//Geting input from user
for(i=0;i<3;i++){
cout<<"Enter the Numbers for "<<i+1<<endl;
cout<<"Enter the Number 1 "<<endl;
cin>>n1;
cout<<"Enter the Number 2 "<<endl;
cin>>n2;
ptr->set_data(n1,n2);
ptr++;
clrscr();
//cout<<endl<<endl;
}

for(i=0;i<3;i++){
cout<<endl<<"Round no : "<<i+1<<endl;
p->get_data();
p++;
}






getch();
}