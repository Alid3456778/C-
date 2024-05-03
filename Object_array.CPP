#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>

class employee{
int id;
char name[15];

public:

void getdata(int i){
i++;
cout<<endl<<"Enter the Id for "<<i<<endl;
cin>>id;
cout<<endl<<"Enter the name for"<<i<<endl;
cin>>name;
clrscr();
}

void putdata(){
cout<<"id : "<<id<<endl;
cout<<"Name is : "<<name<<endl;
}

};




void main()
{
int i=0;
int n=0;
employee emp[14];
clrscr();
cout<<"Enter the number of Employee you need "<<endl;
cin>>n;
clrscr();

for(i=0;i<n;i++){
     emp[i].getdata(i);
}

clrscr();

for(i=0;i<n;i++){
	emp[i].putdata();
}

getch();

}