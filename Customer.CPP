#include<iostream.h>
#include<conio.h>
#include<string.h>

class Basic{
public:
int c_id,c_salary,tem,sum,i;
char c_name[20];
static int ss;

	void get_data(){
	cout<<"Enter the Id of Customer "<<endl;
	cin>>c_id;
	cout<<"Enter the name of Customer "<<endl;
	cin>>c_name;
	cout<<"Enter the Salary of Customer "<<endl;
	cin>>c_salary;
	ss=0;
	}

	void put_data(){
	cout<<"The Id of Customer is "<<c_id<<endl;
	cout<<"The Name of Customer is "<<c_name<<endl;
	cout<<"The Salary of Customer is "<<c_salary<<endl;
	}

	int max(int n){
	sum=0;
	tem=c_salary;
	for(i=0;i<n;i++){
	if(tem < c_salary){
	tem=c_salary;
	sum=i;
	}
	}
	       //	put_data();
	       clrscr();
	       cout<<"Sum is "<<tem;
	       return sum;

	}


};

int Basic::ss=0;


void main(){
clrscr();
int n=0;
cout<<"Enter the Numbe of Customer "<<endl;
cin>>n;
Basic b[20];
for(int i=0;i<n;i++){
cout<<endl<<"Entering the "<<i+1<<" customer Details"<<endl<<endl;
b[i].get_data();
}
int sum;
sum=b[i].max(n);



getch();
}