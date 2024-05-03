#include<iostream.h>
#include<conio.h>
#include<iomanip.h>

void main(){
int a=5;
int *ptr=&a;
int *arr=new int[3];
int i;
clrscr();


//For pointer Explanation
cout<<"*ptr is : "<<*ptr<<endl;
cout<<"ptr is : "<<ptr<<endl;
cout<<"a is : "<<a<<endl;




//Array with Dynamic initilazation

//getting the data for array
for(i=0;i<3;i++){
cout<<"Enter the number for "<<i+1<<endl;
cin>>arr[i];
}
cout<<endl<<"Printing the array"<<endl;
//printing the data
for(i=0;i<3;i++){
cout<<i+1<<" is : "<<arr[i]<<endl;
}


getch();
}





