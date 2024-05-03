#include<iostream.h>
#include<conio.h>
#include<iomanip.h>

class Student{
protected:
	int roll_no;

public:

	void set_roll(int a){
	roll_no=a;
	}

	void display_roll(){
	cout<<"Roll number is "<<roll_no<<endl;
	}

};

class Marks : virtual public Student{
protected:
	float math;
	float science;

public:

	void get_marks(float m,float s){
	math=m;
	science=s;
	}

	void display_marks(){
	cout<<"Maths marks is : "<<math<<endl <<"Science marks is : "<<science<<endl;
	}

};

class Sports : virtual public Student{
protected:
	int score;

public:

	void get_score(int scr){
	score=scr;
	}

	void display_score(){
	cout<<"Sports Score is : "<<score<<endl;
	}
};

class Result : public Marks, public Sports{
protected:
	int total;

public:

	void total(){
	total=math+science+score;

	display_roll();
	display_marks();
	display_score();

	cout<<"Total is Result is : "<<total<<endl;
	}
	

};



void main()
{
Result r;
r.get_id(1);
r.get_marks(27,45);
r.get_score(56);
clrscr();

r.total();


getch();
}



