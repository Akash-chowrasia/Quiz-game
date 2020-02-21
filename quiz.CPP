/*
 This is a quiz game programm. you can just put all the modules
 and the main file into bin folder of your turboc3 and execute it. */

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
#include<dos.h>
#define ENTER 13
#define TAB 9
#define BKSP 8
void intro();
void set1();
void set2();
void set3();
void menu();
void loading();
void reset();
void ACET();
void description();
void checkset1();
void checkset2();
void playanswer1();
void playanswer2();
void playanswer3();
void changequestion1();
void changequestion2();
void changequestion3();
void certificate();
void checkanswer1();
void checkanswer2();
void checkanswer3();
void gotolevel();
void gotolevel2();
void gotolevel3();
void checkset3();
void owner();
void changeset();
void changeset1();
void changeset2();
void changeset3();
void checkresult();
void checkdetails();
void ownersmenu();
void checkquestion();
void changequestion();
void playerregistration();
void game();
void registrationplayer();
void registration();
void registered();
void currentstatus();
void player();
void play1();
void play2();
void play3();
void rules();
void play();

struct player
{
	char name[30],nation[20],gender[5],contact[20],pass[10],cheqpass[10];
	long int registrationno,setplayed;
	void output1()
	{
		textbackground(5);
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n\n\n\t\tName:\t"<<name<<"\n\n\t\tGender:\t"<<gender<<"\n\n\t\tContact:\t"<<contact<<"\n\n\t\tNationality:\t"<<nation<<"\n\n\t\tRegistration number:\t"<<registrationno;
		cout<<"\n\n\n--------------------------------------------------------------------------------";
	}
} ob1;

struct playera
{
	char namea[30],nationa[20],gendera[5],contacta[20],passa[10],cheqpassa[10];
	long int registrationnoa,setplayeda;
	void input1s()
	{
		again:
		sound(5000);
		textbackground(5);
		ACET();
		delay(300);
		nosound();
		cout<<"\n\n\n\t\tName:\t";
		gets(namea);
		cout<<"\n\n\t\t\Gender(m / f):\t";
		gets(gendera);
		cout<<"\n\n\t\tContact:\t";
		gets(contacta);
		if(strlen(contacta)!=10)
		{
			clrscr();
			cout<<"\n\n\n\n\n\t\t\tplease enter a valid contact number...";
			delay(1000);
			clrscr();
			goto again;
		}
		cout<<"\n\n\t\tNationality:\t";
		gets(nationa);
	}
	void output1s()
	{
		textbackground(5);
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n\n\n\t\tName:\t"<<namea<<"\n\n\t\tGender:\t"<<gendera<<"\n\n\t\tContact:\t"<<contacta<<"\n\n\t\tNationality:\t"<<nationa<<"\n\n\t\tRegistration number:\t"<<registrationnoa;
		cout<<"\n\n\n---------------------------------------------------------------------------------";
	}
	long int setpasswords(long int);
} ob1a;

long int playera::setpasswords(long int x)
{
	clrscr();
	registrationnoa=x;
	clrscr();
	ACET();
	cout<<"\n\n\n\n\tEnter a password in in less than 10  digits:\t";
	int z3=0;
	char ch1;
	while(1)
	{
		ch1=getch();
		if(ch1== ENTER || ch1== TAB)
		{
			passa[z3]='\0';
			break;
		}
		else if(ch1==BKSP)
		{
			if(z3>0)
			{
				z3--;
				cout<<"\b \b";
			}
		}
		else
		{
			passa[z3++]=ch1;
			cout<<"* \b";
		}
	}
	cout<<"\n\n\n\n\tEnter again to confirm:";
	int run=0;
	char ch2;
	while(1)
	{
		ch2=getch();
		if(ch2==  ENTER || ch2== TAB)
		{
			cheqpassa[run]='\0';
			break;
		}
		else if(ch2==BKSP)
		{
			if(run>0)
			{
				run--;
				cout<<"\b \b";
			}
		}
		else
		{
			cheqpassa[run++]=ch2;
			cout<<"* \b";
		}
	}
	if(strcmp(passa,cheqpassa)==0)
	{
		registrationnoa++;
		setplayeda=0;
		loading();
		cout<<"\n\n\n\n\t\t\t\t Confirmed.....";
		getch();
		clrscr();
		ACET();
		cout<<"\n\n\n\n\t\t\t Your registration number is:\t"<<registrationnoa;
		cout<<"\n\n\n\t\t\t Your password is:\tXXXXXX";
		cout<<"\n\n\n--------------------------------------------------------------------------------";
		cout<<"\n\n\n\n\t\t\t\t Press any key to continue.......";
		getch();
		strcpy(cheqpassa,'\0');
		return 1;
	}
	else
	{
		loading();
		cout<<"\n\n\n\n\n\n\t\t\tPassword should be same:...";
		delay(500);
		cout<<"\n\n\n\nPress any key....";
		getch();
		return 0;
	}
}

struct quizz
{
	char qn[5],con[5];
	char q[80],o1[30],o2[30],o3[30],o4[30];
	void input()
	{
		textbackground(4);
		cout<<"\n\n--------------------------------------------------------------------------------";
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n\n\tEnter question number:";
		cin>>qn;
		cout<<"\n\tEnter question:";
		gets(q);
		cout<<"\n\tEnter first option:";
		gets(o1);
		cout<<"\n\tEnter second option:";
		gets(o2);
		cout<<"\n\tEnter third option:";
		gets(o3);
		cout<<"\n\tEnter fourth option:";
		gets(o4);
		cout<<"\n\tEnter correct option in terms of digit:";
		cin>>con;
		sound(5000);
		cout<<"\n\n--------------------------------------------------------------------------------";
		delay(500);
		nosound();
	}
	void outputa()
	{
		textbackground(6);
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n\tQ."<<qn<<") "<<q;
		cout<<"\n\t\t(1) "<<o1;
		cout<<"\n\t\t(2) "<<o2;
		cout<<"\n\t\t(3) "<<o3;
		cout<<"\n\t\t(4) "<<o4;
		cout<<"\n\n--------------------------------------------------------------------------------";
	}
	void output()
	{
		textbackground(5);
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n\tQ."<<qn<<") "<<q;
		cout<<"\n\t\t(1) "<<o1;
		cout<<"\n\t\t(2) "<<o2;
		cout<<"\n\t\t(3) "<<o3;
		cout<<"\n\t\t(4) "<<o4;
		cout<<"\n\n\t\tCorrect option is:\t"<<con;
		cout<<"\n\n--------------------------------------------------------------------------------";
	}
} ob2;

struct result
{
	long int registrationid,score,crr,incrr,score1,score2,score3,crr1,crr2,crr3,incrr1,incrr2,incrr3;
	void output2()
	{
		clrscr();
		ACET();
		textbackground(6);
		delay(300);
		cout<<"\n\n\n\t\tYou have answered correctly "<<crr<<" questions";
		delay(300);
		cout<<"\n\n\t\tYou have answered wrong "<<incrr<<" questions";
		delay(300);
		cout<<"\n\n\t\tYour total scores:\t"<<score;
		cout<<"\n\n--------------------------------------------------------------------------------";
	}
	void input2()
	{
		registrationid=0;score=0;crr=0;incrr=0;score1=0;score2=0;score3=0;crr1=0;crr2=0;crr3=0;incrr1=0;incrr2=0;incrr3=0;
	}
	void input2a(long int a11,long int a12,long int a13,long int a14,long int a15,long int a16,long int a17)
	{
		registrationid=a11;score1=a12;crr1=a13;incrr1=a14;score=a15;crr=a16;incrr=a17;score2=0;score3=0;crr2=0;crr3=0;incrr2=0;incrr3=0;
	}
	void input2b(long int b11,long int b12,long int b13,long int b14,long int b15,long int b16)
	{
		score2=b11;crr2=b12;incrr2=b13;score=score+b14;crr=crr+b15;incrr=incrr+b16;
	}
	void input2c(long int c11,long int c12,long int c13,long int c14,long int c15,long int c16)
	{
		score3=c11;crr3=c12;incrr3=c13;score=score+c14;crr=crr+c15;incrr=incrr+c16;
	}
	void output2a()
	{
		clrscr();
		ACET();
		textbackground(5);
		delay(300);
		cout<<"\n\n\n\t\t\tRegistration number:\t "<<registrationid;
		delay(500);
		cout<<"\n\n\t\tYou have answered correctly "<<crr1<<" questions for level 1";
		delay(500);
		cout<<"\n\n\t\tYou have answered wrong "<<incrr1<<" questions for level 1";
		delay(500);
		cout<<"\n\n\t\tYour total scores for level 1:\t"<<score1;
		cout<<"\n\n--------------------------------------------------------------------------------";
	}
	void output2b()
	{
		clrscr();
		ACET();
		textbackground(4);
		delay(300);
		cout<<"\n\n\n\t\t\tRegistration number:\t"<<registrationid;
		delay(500);
		cout<<"\n\n\t\tYou have answered correctly "<<crr2<<" questions for level 2";
		delay(300);
		cout<<"\n\n\t\tYou have answered wrong "<<incrr2<<" questions for level 2";
		delay(300);
		cout<<"\n\n\t\tYour total scores for level 2:\t"<<score2;
		cout<<"\n\n--------------------------------------------------------------------------------";
	}
	void output2c()
	{
		clrscr();
		ACET();
		textbackground(4);
		delay(300);
		cout<<"\n\n\n\t\t\tRegistration number:\t"<<registrationid;
		delay(500);
		cout<<"\n\n\t\tYou have answered correctly "<<crr3<<" questions for level 3";
		delay(300);
		cout<<"\n\n\t\tYou have answered wrong "<<incrr3<<" questions for level 3";
		delay(300);
		cout<<"\n\n\t\tYour total scores for level 3:\t"<<score3;
		cout<<"\n\n--------------------------------------------------------------------------------";
	}
	void output2d()
	{
		textbackground(6);
		clrscr();
		ACET();
		cout<<"\n            Registration number:\t"<<registrationid;
		cout<<"\n  ////////////////////////////////////////////////////////////////////////////";
		cout<<"\n            Level 1..........................................................";
		cout<<"\n  Correct answers:\t"<<crr1;
		cout<<"\n  Incorrect answers:\t"<<incrr1;
		cout<<"\n  Scores:\t"<<score1;
		cout<<"\n            Level 2..........................................................";
		cout<<"\n  Correct answers:\t"<<crr2;
		cout<<"\n  Incorrect answers:\t"<<incrr2;
		cout<<"\n  Scores:\t"<<score2;
		cout<<"\n            Level 3........................................................";
		cout<<"\n  Correct answers:\t"<<crr3;
		cout<<"\n  Incorrect answers:\t"<<incrr3;
		cout<<"\n  Scores:\t"<<score3;
		cout<<"\n            Total..........................................................";
		cout<<"\n  Correct answers:\t"<<crr;
		cout<<"\n  Incorrect answers:\t"<<incrr;
		cout<<"\n  Total scores:\t"<<score;
		cout<<"\n--------------------------------------------------------------------------------";
	}
} ob3;

void main()
{
	textbackground(5);
	clrscr();
	intro();
	menu();
}

void loading()
{
	int it;
	clrscr();
	cout<<"\n\n\n\n\t\t\t\t**LOADING**\n\n\n\n\t";
	for(it=0;it<=67;it++)
	{
		delay(50);
		cout<<"!";
	}
}

void ACET()
{
	cout<<"\n  **************************************************************************";
	cout<<"\n  ------------------------------ACET QUIZ GAME------------------------------";
	cout<<"\n  **************************************************************************";
}

void intro()
{
	clrscr();
	textcolor(WHITE);
	textbackground(5);
	cout<<"\n  **************************************************************************";
	cout<<"\n  ---------------------------COMPUTER SCIENCE PROJECT-----------------------";
	ACET();
	sound(2000);
	delay(600);
	nosound();
	sound(3000);
	cout<<"\nInstitutional training task";
	cout<<"\n\t\tACET,Amritsar";
	delay(600);
	nosound();
	sound(4000);
	cout<<"\n\n\t\t\tDesigned by...";
	cout<<"\n\t\t\t\tAkash chowrasia(1701223)";
	delay(600);
	nosound();
	sound(5000);
	cout<<"\n\t\t\t\t\t\tSubmitted to.....";
	cout<<"\n\t\t\t\t\t\t\tEr.Ajay sharma";
	cout<<"\n\t\t\t\t\t\t\tEr.Sakshi mahajan";
	cout<<"\n\t\t\t\t\t\t\tEr.Priya sharma";
	delay(600);
	nosound();
	cout<<"\n\n\t\tPress any key to continue.........";
	getch();
}

void menu()
{
	textbackground(4);
	while(1)
	{
		char ch;
		clrscr();
		textbackground(4);
		ACET();
		cout<<"\n\n\n\n\t\t**1** Open as owner.";
		cout<<"\n\n\n\t\t**2** Open as player.";
		cout<<"\n\n\n\t\t**3** Exit";
		cout<<"\n\n--------------------------------------------------------------------------------";
		delay(1000);
		cout<<"\n\n\n\n\t...Enter your choice...";
		ch=getch();
		cout<<ch;
		delay(200);
		switch(ch)
		{
			case '1':
				owner();
				break;
			case '2':
				player();
				break;
			case '3':
				exit(0);
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\n\t\tPlease enter correct choice";
				delay(2000);
				nosound();
		}
	}
}

void owner()
{
	ahead:
	clrscr();
	textbackground(6);
	ACET();
	FILE *fp;
	char a[10],ch;
	fp=fopen("ownpass.txt","r");
	if(fp== NULL)
	{
		exit(0);
	}
	ch=fgetc(fp);
	a[0]=ch;

	int i=0;
	while(!feof(fp))
	{
		i++;
		ch=fgetc(fp);
		a[i]=ch;
	}
	a[i]='\0';
	fclose(fp);
	char b[10];
	while(1)
	{
		cout<<"\n\n\n\t\tEnter password:";
		int z=0;
		char ch;
		while(1)
		{
			ch=getch();
			if(ch== ENTER || ch==TAB)
			{
				  b[z]='\0';
				  break;
			}
			else if(ch==BKSP)
			{
				 if(z>0)
				 {
					 z--;
					 cout<<"\b \b";
				 }
			}
			else
			{
				b[z++]=ch;
				cout<<"* \b";
			}
		}
		if(strcmp(a,b)==0)
		{
			loading();
			cout<<"\n\n\n\n\n\n\t\t\t\t\t*****Access granted*****";
			delay(2000);
			ownersmenu();
		}
		else
		{
			loading();
			cout<<"\n\n\tPlease enter correct password";
			ahead1:
			sound(1000);
			cout<<"\n\t\t\tEnter 1 to try again";
			cout<<"\n\n\t\t\tEnter 2 to goto menu";
			cout<<"\nEnter choice:";
			nosound();
			char pre;
			pre=getch();
			cout<<pre;
			delay(200);
			if(pre=='2')
				menu();
			else if(pre=='1')
				goto ahead;
			else
			{
				clrscr();
				goto ahead1;
			}
		}
	}
}

void ownersmenu()
{
	textbackground(5);
	char choice;
	clrscr();
	textbackground(5);
	while(1)
	{
		clrscr();
		ACET();
		delay(300);
		cout<<"\n\n\t**1** Check the questions.";
		delay(300);
		cout<<"\n\n\t**2** Change the question.";
		delay(300);
		cout<<"\n\n\t**3** Change a set of questions.";
		delay(300);
		cout<<"\n\n\t**4** Check details of registered player";
		delay(300);
		cout<<"\n\n\t**5** Check result of player";
		delay(300);
		cout<<"\n\n\t**6** Check the description of the project";
		delay(300);
		cout<<"\n\n\t**7** Reset your password.";
		delay(300);
		cout<<"\n\n\t**8** Go to the main menu.";
		delay(300);
		cout<<"\n\n\t**9** Exit.";
		delay(1000);
		cout<<"\n\t\t\tPlease enter any choice:";
		choice=getch();
		cout<<choice;
		delay(200);
		switch(choice)
		{
			case '1':
				clrscr();
				checkquestion();
				break;
			case '2':
				clrscr();
				changequestion();
				break;
			case '3':
				clrscr();
				changeset();
				break;
			case '4':
				clrscr();
				checkdetails();
				break;
			case '5':
				clrscr();
				checkresult();
				break;
			case '6':
				clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\tHere is a short description for this project";
				delay(2000);
				description();
				break;
			case '7':
				reset();
				break;
			case '8':
				clrscr();
				menu();
				break;
			case '9':
				exit(0);
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\t\tEnter a valid choice.";
				delay(2000);
				nosound();
		}
	}
}

void checkquestion()
{
	textbackground(5);
	char cx;
	while(1)
	{
		clrscr();
		ACET();
		cout<<"\n\n\t\t**1** Check questions of set 1";
		cout<<"\n\n\t\t**2** Check questions of set 2";
		cout<<"\n\n\t\t**3** Check questions of set 3";
		cout<<"\n\n\t\t**4** Go back";
		cout<<"\n\n--------------------------------------------------------------------------------";
		delay(1000);
		cout<<"\n\n\n\t\t\tEnter a option:\t";
		cx=getch();
		cout<<cx;
		delay(200);
		switch(cx)
		{
			case '1':
				clrscr();
				checkset1();
				break;
			case '2':
				clrscr();
				checkset2();
				break;
			case '3':
				clrscr();
				checkset3();
				break;
			case '4':
				clrscr();
				ownersmenu();
				break;
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\n\t\tPlease enter a valid choice......";
				delay(2000);
				nosound();
		}
	}
}

void checkset1()
{
	textbackground(5);
	clrscr();
	fstream f;
	f.open("temp.dat",ios::in);
	while(f.read((char*)&ob2,sizeof(ob2)))
	{
		ob2.output();
		getch();
		clrscr();
	}
	f.clear();
	f.close();
	getch();
	checkquestion();
}

void checkset2()
{
	textbackground(6);
	clrscr();
	fstream g;
	g.open("temp1.dat",ios::in);
	while(g.read((char*)&ob2,sizeof(ob2)))
	{
		ob2.output();
		getch();
		clrscr();
	}
	g.clear();
	g.close();
	getch();
	checkquestion();
}

void checkset3()
{
	textbackground(4);
	clrscr();
	fstream g1;
	g1.open("temp2.dat",ios::in);
	while(g1.read((char*)&ob2,sizeof(ob2)))
	{
		ob2.output();
		getch();
		clrscr();
	}
	g1.clear();
	g1.close();
	getch();
	checkquestion();
}

void changequestion()
{
	clrscr();
	textbackground(5);
	char ca;
	while(1)
	{
		clrscr();
		ACET();
		cout<<"\n\n\t\t**1** Change question in set 1";
		cout<<"\n\n\t\t**2** Change question in set 2";
		cout<<"\n\n\t\t**3** Change question in set 3";
		cout<<"\n\n\t\t**4** Go back";
		cout<<"\n\n--------------------------------------------------------------------------------";
		delay(1000);
		cout<<"\n\n\n\t\t\tEnter your choice:\t";
		ca=getch();
		cout<<ca;
		delay(200);
		switch(ca)
		{
			case '1':
				clrscr();
				changequestion1();
				break;
			case '2':
				clrscr();
				changequestion2();
				break;
			case '3':
				clrscr();
				changequestion3();
				break;
			case '4':
				clrscr();
				ownersmenu();
				break;
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\n\t\tPlease enter a correct choice......";
				delay(2000);
				nosound();
		}
	}
}

void changequestion1()
{
	textbackground(5);
	char cb[5];
	int cd=0;
	while(1)
	{
		clrscr();
		fstream g2;
		g2.open("temp.dat",ios::in|ios::out|ios::ate);
		g2.seekg(0);
		cout<<"\n\n\n\n\n\t\tEnter question number which you want to change:";
		gets(cb);
		while(g2.read((char*)&ob2,sizeof(ob2)))
		{
			if(strcmp(ob2.qn,cb)==0)
			{
				cd=1;
				break;
			}
		}
		g2.clear();
		if(cd==1)
		{
			g2.seekg(g2.tellp()-sizeof(ob2));
			clrscr();
			ob2.input();
			g2.write((char*)&ob2,sizeof(ob2));
			g2.close();
			cout<<"\n\t\t\t\tQuestion changed......";
			getch();
			changequestion();
		}
		else
		{
			g2.close();
			clrscr();
			cout<<"\n\n\n\n\tQuestion number should be between 1 to 10";
		}
	}
}

void changequestion2()
{
	textbackground(4);
	char ce[5];
	int cf=0;
	while(1)
	{
		clrscr();
		fstream g3;
		g3.open("temp1.dat",ios::in|ios::out|ios::ate);
		g3.seekg(0);
		cout<<"\n\n\n\n\n\t\tEnter question number which you want to change:";
		gets(ce);
		while(g3.read((char*)&ob2,sizeof(ob2)))
		{
			if(strcmp(ob2.qn,ce)==0)
			{
				cf=1;
				break;
			}
		}
		g3.clear();
		if(cf==1)
		{
			g3.seekg(g3.tellp()-sizeof(ob2));
			clrscr();
			ob2.input();
			g3.write((char*)&ob2,sizeof(ob2));
			g3.close();
			cout<<"\n\t\t\t\tQuestion changed......";
			getch();
			changequestion();
		}
		else
		{
			g3.close();
			cout<<"\n\n\n\n\t\tQuestion number should be between 1 to 10";
		}
	}
}

void changequestion3()
{
	textbackground(6);
	char cg[5];
	int ch=0;
	while(1)
	{
		clrscr();
		fstream g4;
		g4.open("temp2.dat",ios::in|ios::out|ios::ate);
		g4.seekg(0);
		cout<<"\n\n\n\n\n\t\tEnter question number which you want to change:";
		gets(cg);
		while(g4.read((char*)&ob2,sizeof(ob2)))
		{
			if(strcmp(ob2.qn,cg)==0)
			{
				ch=1;
				break;
			}
		}
		g4.clear();
		if(ch==1)
		{
			g4.seekg(g4.tellp()-sizeof(ob2));
			ob2.input();
			g4.write((char*)&ob2,sizeof(ob2));
			g4.close();
			cout<<"\n\tQuestion changed......";
			getch();
			changequestion();
		}
		else
		{
			g4.close();
			cout<<"\n\n\n\n\t\tQuestion number should be between 1 to 10";
		}
	}
}

void changeset()
{
	clrscr();
	textbackground(4);
	char cn;
	while(1)
	{
		clrscr();
		ACET();
		cout<<"\n\n\t\t**1** Change set 1";
		cout<<"\n\n\t\t**2** Change set 2";
		cout<<"\n\n\t\t**3** Change set 3";
		cout<<"\n\n\t\t**4** Go back";
		cout<<"\n\n--------------------------------------------------------------------------------";
		delay(1000);
		cout<<"\n\n\n\t\t\tEnter a choice:\t";
		cn=getch();
		cout<<cn;
		delay(200);
		switch(cn)
		{
			case '1':
				clrscr();
				changeset1();
				break;
			case '2':
				clrscr();
				changeset2();
				break;
			case '3':
				clrscr();
				changeset3();
				break;
			case '4':
				clrscr();
				ownersmenu();
				break;
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\n\t\tPlease enter a correct option";
				delay(2000);
				nosound();
		}
	}
}

void changeset1()
{
	textbackground(4);
	int ci=0;
	remove("temp.dat");
	while(ci<10)
	{
		clrscr();
		fstream g5;
		g5.open("temp.dat",ios::out|ios::ate);
		ob2.input();
		g5.write((char*)&ob2,sizeof(ob2));
		g5.close();
		ci++;
		getch();
		cout<<"\n\n\t\t\t\t\tSaved.....";
		delay(2000);
	}
	ownersmenu();
}

void changeset2()
{
	textbackground(4);
	int cj=0;
	remove("temp1.dat");
	while(cj<10)
	{
		clrscr();
		fstream g6;
		g6.open("temp1.dat",ios::out|ios::ate);
		ob2.input();
		g6.write((char*)&ob2,sizeof(ob2));
		g6.close();
		cj++;
		getch();
		cout<<"\n\n\t\t\t\t\tsaved.....";
		delay(2000);
	}
	ownersmenu();
}

void changeset3()
{
	textbackground(5);
	int ck=0;
	remove("temp2.dat");
	while(ck<10)
	{
		clrscr();
		fstream g6;
		g6.open("temp2.dat",ios::out|ios::ate);
		ob2.input();
		g6.write((char*)&ob2,sizeof(ob2));
		g6.close();
		ck++;
		getch();
		cout<<"\n\n\t\t\t\t\tSaved.....";
		delay(2000);
	}
	ownersmenu();
}

void checkdetails()
{
	textbackground(6);
	clrscr();
	fstream g7;
	g7.open("player.bin",ios::in|ios::binary);
	while(g7.read((char*)&ob1,sizeof(ob1)))
	{
		ob1.output1();
		getch();
		clrscr();
	}
	g7.clear();
	g7.close();
	getch();
	ownersmenu();
}

void checkresult()
{
	textbackground(4);
	fstream g8;
	g8.open("result.bin",ios::in|ios::binary);
	while(g8.read((char*)&ob3,sizeof(ob3)))
	{
		ob3.output2d();
		getch();
		clrscr();
	}
	g8.clear();
	g8.close();
	ownersmenu();
}

void reset()
{
	textbackground(4);
	clrscr();
	ACET();
	FILE *fp;
	char a[10],b[10],c[10],ch;
	fp=fopen("ownpass.txt","r");
	if(fp== NULL)
	{
		exit(0);
	}
	ch=fgetc(fp);
	a[0]=ch;
	int i=0;
	while(!feof(fp))
	{
		i++;
		ch=fgetc(fp);
		a[i]=ch;
	}
	a[i]='\0';
	cout<<"\n\n\n\n\n\t\tEnter old password:";
	int z=0;
	while(1)
	{
		ch=getch();
		if(ch== ENTER || ch==TAB)
		{
			b[z]='\0';
			break;
		}
		else if(ch==BKSP)
		{
			if(z>0)
			{
				z--;
				cout<<"\b \b";
			}
		}
		else
		{
			b[z++]=ch;
			cout<<"* \b";
		}
	}
	if(strcmp(a,b)==0)
	{
		cout<<"\n\n\t\tEnter new password in upto 10 letters:";
		z=0;
		while(1)
		{
			ch=getch();
			if(ch== ENTER || ch==TAB)
			{
				c[z]='\0';
				break;
			}
			else if(ch==BKSP)
			{
				if(z>0)
				{
					z--;
					cout<<"\b \b";
				}
			}
			else
			{
				c[z++]=ch;
				cout<<"* \b";
			}
		}
		fclose(fp);
		remove("ownpass.txt");
	       /*	FILE *pf;
		pf=fopen("ownpass.txt","w");
		for(i=0;i<strlen(c);i++)
			fputc(c[i],pf);
		fclose(pf);*/
		ofstream fout;
		fout.open("ownpass.txt");
		fout.seekp(0);
		for(i=0;i<strlen(c);i++)
			fout<<c[i];
		fout.close();
		cout<<"\n\n\nPassword reseted successfully";
		cout<<"\n\n\t\t\t\t\t\t\tpress any key";
		getch();
	}
	else
	{

	}

}

void player()
{
	clrscr();
	textbackground(5);
	ACET();
	cout<<"\n  ----------------------------------WELCOME---------------------------------";
	cout<<"\n  **************************************************************************";
	cout<<"\n\n\t\tHello......you are most wecome to our quiz game...";
	cout<<"\n      This is a game made by us under ACET,amritsar which provides you a good    platform to judge your knowledge in c++ language and  gives you an opportunity    to develope your basic knowledge in languages.";
	cout<<"\n\tOnce you complete the game successfully you are provided a certificate   which will show your level of knowledge in languages.";
	sound(200);
	delay(600);
	nosound();
	sound(400);
	delay(600);
	nosound();
	sound(600);
	delay(600);
	nosound();
	sound(800);
	delay(600);
	nosound();
	sound(2000);
	delay(600);
	nosound();
	sound(3000);
	delay(600);
	nosound();
	sound(4000);
	delay(600);
	nosound();
	sound(5000);
	delay(600);
	nosound();
	cout<<"\n\n\n\t\t\t\tPress any key to continue......";
	getch();
	playerregistration();
}

void playerregistration()
{
	char choose;
	while(1)
	{
		clrscr();
		textbackground(6);
		ACET();
		cout<<"\n\n\n\n\t\t**1** New player.";
		delay(500);
		cout<<"\n\n\n\t\t**2** Registered player.";
		delay(500);
		cout<<"\n\n\n\t\t**3** Go back.";
		delay(500);
		cout<<"\n\n\n\t\t**4** exit";
		cout<<"\n\n--------------------------------------------------------------------------------";
		delay(1000);
		cout<<"\n\n\n\t\t\t\tEnter your choice....";
		choose=getch();
		cout<<choose;
		delay(200);
		switch(choose)
		{
			case '1':
				registration();
				break;
			case '2':
				registered();
				break;
			case '3':
				menu();
				break;
			case '4':
				exit(0);
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\n\tPlease enter a correct option";
				delay(2000);
				nosound();
		}
	}
}

void registration()
{
	textbackground(5);
	int b;
	clrscr();
	fstream f;
	int mz;
	long int c;
	f.open("player.bin",ios::out|ios::ate|ios::binary);
	ob1a.input1s();
	c=f.tellp()/sizeof(ob1);
	mz=ob1a.setpasswords(c);
	if(mz==1)
	{
		f.write((char*)&ob1a,sizeof(ob1a));
		f.close();
		registrationplayer();
	}
	else
	{
		f.close();
		playerregistration();
	}
}

void registrationplayer()
{
	textbackground(4);
	char chic;
	while(1)
	{
		clrscr();
		ACET();
		cout<<"\n\n\n\t\t**1** You want to start the level 1:\t";
		cout<<"\n\n\n\t\t**2** Go back";
		cout<<"\n\n\n\t\t**3** Exit.";
		delay(1000);
		cout<<"\n\n\n\n\t\t\t\tEnter any choice......";
		chic=getch();
		cout<<chic;
		delay(200);
		switch(chic)
		{
			case '1':
				rules();
				set1();
				break;
			case '2':
				playerregistration();
				break;
			case '3':
				exit(0);
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\n\t\tPlease enter the correct option....";
				delay(2000);
				nosound();
		}
	}
}

void registered()
{
	textbackground(6);
	clrscr();
	fstream k;
	int tempreg,ac=0;
	char temppass[10];
	sound(5000);
	clrscr();
	ACET();
	cout<<"\n\n\t\t........Enter registration number.......\t";
	cin>>tempreg;
	cout<<"\n\n\t\t........Enter password.............\t";
	int z4=0;
	char ch4;
	while(1)
	{
		ch4=getch();
		if(ch4== ENTER || ch4== TAB)
		{
			 temppass[z4]='\0';
			 break;
		}
		else if(ch4==BKSP)
		{
			if(z4>0)
			{
			z4--;
			cout<<"\b \b";
			}
		}
		else
		{
			temppass[z4++]=ch4;
			cout<<"* \b";
		}
	}
	nosound();
	k.open("player.bin",ios::in|ios::binary);
	while(k.read((char*)&ob1a,sizeof(ob1a)))
	{
		if(strcmp(ob1a.passa,temppass)==0 && tempreg==ob1a.registrationnoa)
		{
			ac=1;
			break;
		}
	}
	k.clear();
	if(ac==1)
	{
		loading();
		cout<<"\n\n\n\n\t\t\tACCESSED.......";
		delay(2000);
		k.close();
		play();
	}
	else
	{
		k.close();
		loading();
		sound(1000);
		cout<<"\n\n\n\n\tSorry\n\n\n\n\n\t\t\t\tCan't be accessed";
		delay(2000);
		nosound();
		playerregistration();
	}
}

void play()
{
	textbackground(5);
	clrscr();
	char ci;
	clrscr();
	ACET();
	cout<<"\n\n\tHELLO..."<<ob1a.namea<<"\n\t\t\tyou are most welcome to the game.....";
	delay(500);
	cout<<"\n\n\n\t\t**1** Check your corrent status in game";
	cout<<"\n\n\n\t\t**2** Proceed to play the game";
	cout<<"\n\n\n\t\t**3** Get certificate.";
	cout<<"\n\n\n\t\t**4** Go back";
	cout<<"\n\n\n\t\t**5** Exit";
	delay(1000);
	cout<<"\n\n\t\t\t\t\tEnter your choice....";
	ci=getch();
	cout<<ci;
	delay(200);
	switch(ci)
	{
		case '1':
			currentstatus();
			break;
		case '2':
			game();
			break;
		case '3':
			certificate();
			break;
		case '4':
			playerregistration();
			break;
		case '5':
			exit(0);
		default:
			clrscr();
			sound(1000);
			cout<<"\n\n\n\n\t\tPlease enter a correct option";
			delay(2000);
			nosound();
			play();
	}
}

void game()
{
	textbackground(4);
	clrscr();
	char a8;
	rules();
	while(1)
	{
		clrscr();
		ACET();
		delay(300);
		cout<<"\n\n\n\t\t**1** Play level 1";
		delay(400);
		cout<<"\n\n\n\t\t**2** Play level 2";
		delay(400);
		cout<<"\n\n\n\t\t**3** Play level 3";
		delay(400);
		cout<<"\n\n\n\t\t**4** Go to the players menu";
		delay(1000);
		cout<<"\n\n\n\n\n\t\t\t\t Choose your option:\t";
		a8=getch();
		cout<<a8;
		delay(200);
		switch(a8)
		{
			case '1':
				play1();
				break;
			case '2':
				play2();
				break;
			case '3':
				play3();
				break;
			case '4':
				playerregistration();
				break;
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\n\n\t\tEnter a correct option please....";
				delay(2000);
				nosound();
		}
	}
}

void play1()
{
	textbackground(6);
	clrscr();
	if(ob1a.setplayeda==0)
	{
		set1();
	}
	else
	{
		char b8;
		while(1)
		{
			clrscr();
			sound(1000);
			cout<<"\n\n\tYou can't play this level\n\n\n\n\n\t\t\t Press 1 to check the answer of this level";
			delay(500);
			nosound();
			cout<<"\n\n\t\t\t Press 2 to go back ";
			cout<<"\n\n\t\t\t Press 3 to exit";
			delay(1000);
			cout<<"\n\n\n\t\t\tEnter a choice...";
			b8=getch();
			cout<<b8;
			delay(200);
			switch(b8)
			{
				case '1':
					if(ob1a.setplayeda==1||ob1a.setplayeda==2||ob1a.setplayeda==3)
					{
						playanswer1();
					}
					else
					{
						clrscr();
						sound(1000);
						cout<<"\n\n\t\tSorry......\n\n\n\t\t\tUnable to show the answer";
						delay(2000);
						nosound();
						game();
					}
					break;
				case '2':
					game();
					break;
				case '3':
					exit(0);
				default:
					clrscr();
					sound(1000);
					cout<<"\n\t\t Error!....\n\t\t\tPlease enter a valid choice";
					delay(2000);
					nosound();
			}
		}
	}
}

void play2()
{
	textbackground(5);
	clrscr();
	if(ob1a.setplayeda==1)
	{
		set2();
	}
	else
	{
		char e9;
		while(1)
		{
			clrscr();
			sound(1000);
			cout<<"\n\n\tYou can't play this level\n\n\n\t\t\t Press 1 to check the answer of this level";
			delay(500);
			nosound();
			cout<<"\n\n\t\t\t Press 2 to go back ";
			cout<<"\n\n\t\t\t Press 3 to exit";
			delay(1000);
			cout<<"\n\n\n\t\tEnter a choice...";
			e9=getch();
			cout<<e9;
			delay(200);
			switch(e9)
			{
				case '1':
					if(ob1a.setplayeda==2||ob1a.setplayeda==3)
					{
						playanswer2();
					}
					else
					{
						clrscr();
						sound(1000);
						cout<<"\n\n\t\tSorry.....\n\n\n\t\t\tUnable to show the answer";
						delay(2000);
						nosound();
						game();
					}
					break;
				case '2':
					game();
					break;
				case '3':
					exit(0);
				default:
					clrscr();
					sound(1000);
					cout<<"\n\t\t Error!....\n\t\t\tPlease enter a valid choice";
					delay(2000);
					nosound();
			}
		}
	}
}

void play3()
{
	textbackground(4);
	clrscr();
	if(ob1a.setplayeda==2)
	{
		set3();
	}
	else
	{
		char f2;
		while(1)
		{
			clrscr();
			sound(1000);
			cout<<"\n\n\tYou can't play this level\n\n\n\t\t\t press 1 to check the answer of this level";
			delay(500);
			nosound();
			cout<<"\n\n\t\t\t Press 2 to go back ";
			cout<<"\n\n\t\t\t Press 3 to exit";
			delay(1000);
			cout<<"\n\n\n\t\tEnter a choice.....";
			f2=getch();
			cout<<f2;
			delay(200);
			switch(f2)
			{
				case '1':
					if(ob1a.setplayeda==3)
					{
						playanswer3();
					}
					else
					{
						clrscr();
						sound(1000);
						cout<<"\n\n\tSorry......\n\n\n\t\t\tUnable to show the answer";
						delay(2000);
						nosound();
						game();
					}
					break;
				case '2':
					game();
					break;
				case '3':
					exit(0);
				default:
					clrscr();
					sound(1000);
					cout<<"\n\t\t Error!....\n\t\t\tPlease enter a valid choice";
					delay(2000);
					nosound();
			}
		}
	}
}

void set1()
{
	textbackground(6);
	char getchoice[5],temper;
	fstream c1,c2,c3;
	c1.open("temp.dat",ios::in);
	c2.open("player.bin",ios::in|ios::out|ios::ate|ios::binary);
	c2.seekg(0);
	c3.open("result.bin",ios::out|ios::ate|ios::binary);
	while(c2.read((char*)&ob1,sizeof(ob1)))
	{
		if(ob1.registrationno==ob1a.registrationnoa)
		{
			break;
		}
	}
	c2.clear();
	long int d11=0,d12=0,d13=0,d14=0,d15=0,d16=0,d17;
	int tum=0;
	while(c1.read((char*)&ob2,sizeof(ob2)))
	{
		int iter;
		for(iter=15;iter>=0;iter--)
		{
			clrscr();
			cout<<"\n\t\t\t\t\t\t\t\tTime: "<<iter<<" sec";
			ob2.outputa();
			cout<<"\n\n\n\n\nFor EXIT enter 0...";
			cout<<"\nFor skip enter 5";
			cout<<"\n\n\n\n\t\t\t\t\t\tEnter your choice:\t";
			if(kbhit())
			{
				temper=getch();
				getchoice[0]=temper;
				getchoice[1]='\0';
				goto label;
			}
			delay(1000);
			if(iter==0)
			{
				getchoice[0]='5';
				getchoice[1]='\0';
				break;
			}
		}
		label:
		if(strcmp(ob2.con,getchoice)==0)
		{
			d11=d11+3;
			d14=d14+3;
			d12++;
			d15++;
		}
		else if(strcmp(getchoice,"0")==0)
		{
			break;
		}
		else if(strcmp(getchoice,"5")==0)
		{
			tum++;
			tum--;
		}
		else
		{
			d11=d11-1;
			d14=d14-1;
			d13++;
			d16++;
		}
	}
	c1.clear();
	ob1.setplayed=1;
	ob1a.setplayeda=1;
	d17=ob1a.registrationnoa;
	ob3.input2a(d17,d11,d12,d13,d14,d15,d16);
	clrscr();
	ACET();
	cout<<"\n\n\n\n\n\t\t\t\tYou have completed first level......";
	cout<<"\n\n\n\n\n\tPress any key to see your result....";
	getch();
	clrscr();
	ACET();
	ob3.output2a();
	delay(400);
	cout<<"\n\n\n\n\n\tPlease press any key to continue......";
	c2.seekg(c2.tellp()-sizeof(ob1));
	c2.write((char*)&ob1,sizeof(ob1));
	c3.write((char*)&ob3,sizeof(ob3));
	c1.close();
	c2.close();
	c3.close();
	getch();
	gotolevel2();
}

void set2()
{
	textbackground(5);
	char getchoice1[5],temper1;
	fstream d1,d2,d3;
	d1.open("temp1.dat",ios::in);
	d2.open("player.bin",ios::in|ios::out|ios::ate|ios::binary);
	d2.seekg(0);
	d3.open("result.bin",ios::in|ios::out|ios::ate|ios::binary);
	d3.seekg(0);
	while(d2.read((char*)&ob1,sizeof(ob1)))
	{
		if(ob1.registrationno==ob1a.registrationnoa)
		{
			break;
		}
	}
	d2.clear();
	while(d3.read((char*)&ob3,sizeof(ob3)))
	{
		if(ob3.registrationid==ob1a.registrationnoa)
		{
			break;
		}
	}
	d3.clear();
	long int e11=0,e12=0,e13=0,e14=0,e15=0,e16=0;
	int rum=0;
	if(ob3.score1>=16)
	{
		while(d1.read((char*)&ob2,sizeof(ob2)))
		{
			int iter1;
			for(iter1=15;iter1>=0;iter1--)
			{
				clrscr();
				cout<<"\n\t\t\t\t\t\t\t\tTime: "<<iter1<<" sec";
				ob2.outputa();
				cout<<"\n\n\n\n\nFor EXIT enter 0...";
				cout<<"\nFor skip enter 5";
				cout<<"\n\n\n\n\t\t\t\t\t\tEnter your choice:\t";
				if(kbhit())
				{
					temper1=getch();
					getchoice1[0]=temper1;
					getchoice1[1]='\0';
					goto label3;
				}
				delay(1000);
				if(iter1==0)
				{
					getchoice1[0]='5';
					getchoice1[1]='\0';
				}
			}
			label3:
			if(strcmp(ob2.con,getchoice1)==0)
			{
				e11=e11+3;
				e14=e14+3;
				e12++;
				e16++;
			}
			else if(strcmp(getchoice1,"0")==0)
			{
				break;
			}
			else if(strcmp(getchoice1,"0")==0)
			{
				rum++;
				rum--;
			}
			else
			{
				e11=e11-1;
				e14=e14-1;
				e13++;
				e16++;
			}
		}
		d1.clear();
		ob1.setplayed=2;
		ob1a.setplayeda=2;
		ob3.input2b(e11,e12,e13,e14,e15,e16);
		clrscr();
		ACET();
		cout<<"\n\n\n\n\n\t\t\t\tYou have completed second level......";
		cout<<"\n\n\n\n\n\tPress any key to see your result....";
		getch();
		clrscr();
		ACET();
		ob3.output2b();
		delay(500);
		cout<<"\n\n\n\n\tPlease press any key to continue......";
		d2.seekg(d2.tellp()-sizeof(ob1));
		d3.seekg(d3.tellp()-sizeof(ob3));
		d2.write((char*)&ob1,sizeof(ob1));
		d3.write((char*)&ob3,sizeof(ob3));
		d1.close();
		d2.close();
		d3.close();
		getch();
		gotolevel3();
	}
	else
	{
		clrscr();
		d1.close();
		d2.close();
		d3.close();
		sound(1000);
		cout<<"\n\n\n\n\t\t\tYou are not qualified the previous level";
		delay(400);
		cout<<"\n\n\n\n\n\t\t\t\tPlease press any key........";
		getch();
		nosound();
		exit(0);
	}
}

void set3()
{
	textbackground(4);
	char getchoice2[5],temper2;
	fstream e1,e2,e3;
	e1.open("temp2.dat",ios::in);
	e2.open("player.bin",ios::in|ios::out|ios::ate|ios::binary);
	e2.seekg(0);
	e3.open("result.bin",ios::in|ios::out|ios::ate|ios::binary);
	e3.seekg(0);
	while(e2.read((char*)&ob1,sizeof(ob1)))
	{
		if(ob1.registrationno==ob1a.registrationnoa)
		{
			break;
		}
	}
	e2.clear();
	while(e3.read((char*)&ob3,sizeof(ob3)))
	{
		if(ob3.registrationid==ob1a.registrationnoa)
		{
			break;
		}
	}
	e3.clear();
	long int f11=0,f12=0,f13=0,f14=0,f15=0,f16=0;
	int bum=0;
	if(ob3.score2>=13)
	{
		while(e1.read((char*)&ob2,sizeof(ob2)))
		{
			int iter2;
			for(iter2=15;iter2>=0;iter2--)
			{
				clrscr();
				cout<<"\n\t\t\t\t\t\t\t\tTime: "<<iter2<<" sec";
				ob2.outputa();
				cout<<"\n\n\n\n\nFor EXIT enter 0...";
				cout<<"\nFor skip enter 5";
				cout<<"\n\n\n\n\t\t\t\t\t\tEnter your choice:\t";
				if(kbhit())
				{
					temper2=getch();
					getchoice2[0]=temper2;
					getchoice2[1]='\0';
					goto label5;
				}
				delay(1000);
				if(iter2==0)
				{
					getchoice2[0]='5';
					getchoice2[0]='\0';
				}
			}
			label5:
			if(strcmp(ob2.con,getchoice2)==0)
			{
				f11=f11+3;
				f14=f14+3;
				f12++;
				f15++;
			}
			else if(strcmp(getchoice2,"0")==0)
			{
				break;
			}
			else if(strcmp(getchoice2,"0")==0)
			{
				bum++;
				bum--;
			}
			else
			{
				f11=f11-1;
				f14=f14-1;
				f13++;
				f16++;
			}
		}
		e1.clear();
		ob1.setplayed=3;
		ob1a.setplayeda=3;
		ob3.input2c(f11,f12,f13,f14,f15,f16);
		clrscr();
		ACET();
		cout<<"\n\n\n\n\n\t\t\t\tYou have completed third level......";
		delay(300);
		cout<<"\n\n\t\tPress any key to see your result....";
		getch();
		clrscr();
		ACET();
		ob3.output2c();
		delay(500);
		cout<<"\n\n\n\tPlease press any key to continue...";
		e2.seekg(e2.tellp()-sizeof(ob1));
		e3.seekg(e3.tellp()-sizeof(ob3));
		e2.write((char*)&ob1,sizeof(ob1));
		e3.write((char*)&ob3,sizeof(ob3));
		e1.close();
		e2.close();
		e3.close();
		getch();
		gotolevel();
	}
	else
	{
		clrscr();
		e1.close();
		e2.close();
		e3.close();
		sound(1000);
		cout<<"\n\n\n\t\t\tYou are not qualified the previous level";
		delay(400);
		cout<<"\n\n\n\t\t\t\tPlease press any key";
		getch();
		nosound();
		exit(0);
	}
}

void rules()
{
	textbackground(6);
	clrscr();
	ACET();
	cout<<"\n  -------------------------------INSTRUCTIONS-------------------------------";
	cout<<"\n  **************************************************************************";
	cout<<"\n\t1.This quiz game contains three level";
	cout<<"\n\t2.Each level contains 10 questions";
	cout<<"\n\t3.Each question contains four options";
	cout<<"\n\t4.Each correct answer carry three marks and wrong choice will deduct one \tmarks and there is no marks for unattempted questions";
	cout<<"\n\t5.You must have to score atleast 16 marks in level 1 to reach level 2";
	cout<<"\n\t6.You must have to score atleast 13 marks in level 2 to reach level 3";
	cout<<"\n\t7.Once you complete a level,can't play again";
	cout<<"\n\t8.Once you pick up a choice,can't be changed";
	cout<<"\n\t9.Every question will be given 15 seconds.";
	cout<<"\n\t10.After 10 second question will be autoskipped";
	cout<<"\n\n\t\tPress any key to continue......";
	getch();
}

void currentstatus()
{
	textbackground(5);
	if(ob1a.setplayeda==0)
	{
		clrscr();
		sound(1000);
		cout<<"\n\n\n\n\t\tSorry \n\n\t\t\tyou haven't played any level";
		delay(2000);
		nosound();
		play();
	}
	else
	{
		clrscr();
		fstream h2;
		h2.open("result.bin",ios::in|ios::binary);
		while(h2.read((char*)&ob3,sizeof(ob3)))
		{
			if(ob1a.registrationnoa==ob3.registrationid)
			{
				ob3.output2d();
				getch();
				clrscr();
				break;
			}
		}
		h2.clear();
		h2.close();
		getch();
		play();
	}
}

void checkanswer1()
{
	textbackground(4);
	clrscr();
	fstream l;
	l.open("temp.dat",ios::in);
	while(l.read((char*)&ob2,sizeof(ob2)))
	{
		ob2.output();
		getch();
		clrscr();
	}
	l.clear();
	l.close();
	getch();
	gotolevel2();
}

void checkanswer2()
{
	textbackground(6);
	clrscr();
	fstream l1;
	l1.open("temp1.dat",ios::in);
	while(l1.read((char*)&ob2,sizeof(ob2)))
	{
		ob2.output();
		getch();
		clrscr();
	}
	l1.clear();
	l1.close();
	getch();
	gotolevel3();
}

void checkanswer3()
{
	textbackground(5);
	clrscr();
	fstream l2;
	l2.open("temp2.dat",ios::in);
	while(l2.read((char*)&ob2,sizeof(ob2)))
	{
		ob2.output();
		getch();
		clrscr();
	}
	l2.clear();
	l2.close();
	getch();
	gotolevel();
}

void gotolevel()
{
	textbackground(4);
	while(1)
	{
		clrscr();
		ACET();
		cout<<"\n\n\n\n\t\t\t**1** Check correct answers for level 3";
		cout<<"\n\n\n\t\t\t**2** Go back to play menu";
		cout<<"\n\n\n\t\t\t**3** Exit";
		char l5;
		delay(1000);
		cout<<"\n\n\tEnter your choice.";
		l5=getch();
		cout<<l5;
		delay(200);
		switch(l5)
		{
			case '1':
				checkanswer3();
				break;
			case '2':
				game();
				break;
			case '3':
				exit(0);
			default:
				clrscr();
				cout<<"\n\n\n\t\tPlease enter a correct option";
				delay(2000);
		}
	}
}

void gotolevel3()
{
	textbackground(6);
	while(1)
	{
		clrscr();
		ACET();
		cout<<"\n\n\n\n\t\t\t**1** Check correct answers for level 2";
		cout<<"\n\n\n\t\t\t**2** Move to the next level";
		cout<<"\n\n\n\t\t\t**3** Go back to play menu";
		cout<<"\n\n\n\t\t\t**4** Exit";
		char d6;
		delay(1000);
		cout<<"\n\n\tEnter your choice.";
		d6=getch();
		cout<<d6;
		delay(200);
		switch(d6)
		{
			case '1':
				checkanswer2();
				break;
			case '2':
				set3();
				break;
			case '3':
				game();
				break;
			case '4':
				exit(0);
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\n\n\tPlease enter a correct option";
				delay(2000);
				nosound();
		}
	}
}

void gotolevel2()
{
	textbackground(5);
	while(1)
	{
		clrscr();
		ACET();
		cout<<"\n\n\n\n\t\t\t**1** Check correct answers for level 1";
		cout<<"\n\n\n\t\t\t**2** Move to the next level";
		cout<<"\n\n\n\t\t\t**3** Go back to play menu";
		cout<<"\n\n\n\t\t\t**4** Exit";
		char c8;
		delay(1000);
		cout<<"\n\n\tEnter your choice.";
		c8=getch();
		cout<<c8;
		delay(200);
		switch(c8)
		{
			case '1':
				checkanswer1();
				break;
			case '2':
				set2();
				break;
			case '3':
				game();
				break;
			case '4':
				exit(0);
			default:
				clrscr();
				sound(1000);
				cout<<"\n\n\n\n\n\tPlease enter a correct option";
				delay(2000);
				nosound();
		}
	}
}

void playanswer1()
{
	textbackground(4);
	clrscr();
	fstream n6;
	n6.open("temp.dat",ios::in);
	while(n6.read((char*)&ob2,sizeof(ob2)))
	{
		ob2.output();
		getch();
		clrscr();
	}
	n6.clear();
	n6.close();
	getch();
	play1();
}

void playanswer2()
{
	textbackground(6);
	clrscr();
	fstream n7;
	n7.open("temp1.dat",ios::in);
	while(n7.read((char*)&ob2,sizeof(ob2)))
	{
		ob2.output();
		getch();
		clrscr();
	}
	n7.clear();
	n7.close();
	getch();
	play2();
}

void playanswer3()
{
	textbackground(5);
	clrscr();
	fstream n8;
	n8.open("temp2.dat",ios::in);
	while(n8.read((char*)&ob2,sizeof(ob2)))
	{
		ob2.output();
		getch();
		clrscr();
	}
	n8.clear();
	n8.close();
	getch();
	play3();
}

void certificate()
{
	clrscr();
	textbackground(5);
	if(ob1a.setplayeda==3)
	{
		cout<<"\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                         QUIZ WINNER CERTIFICATE                        ~";
		cout<<"\n  ~                         -----------------------                        ~";
		cout<<"\n  ~                         -----------------------                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~          Is   hereby   granted   to                                    ~";
		cout<<"\n                                             "<<ob1a.namea<<"               ";
		cout<<"\n  ~                                  For outstanding performance in        ~";
		cout<<"\n  ~                                                     Quiz Game....      ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~       At,                                                              ~";
		cout<<"\n  ~             ACET,Amritsar                                              ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                     DR.V.K.BANGA       ~";
		cout<<"\n  ~                                                    --------------      ~";
		cout<<"\n  ~                                                     certified by       ~";
		cout<<"\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		getch();
		clrscr();
		cout<<"\n\n\n\n\n\t\t\tACET WISHES YOU..... \n\n\n\n\t\t\t\t\tFOR BEST FUTURE...";
		getch();
		menu();
	}
	else if(ob1a.setplayeda==1||ob1a.setplayeda==2)
	{
		cout<<"\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                     QUIZ PARTICIPATION CERTIFICATE                     ~";
		cout<<"\n  ~                     ------------------------------                     ~";
		cout<<"\n  ~                     ------------------------------                     ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~          Is   hereby   granted   to                                    ~";
		cout<<"\n                                             "<<ob1a.namea<<"               ";
		cout<<"\n  ~                                  For good performance in               ~";
		cout<<"\n  ~                                                     Quiz Game....      ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~       At,                                                              ~";
		cout<<"\n  ~             ACET,Amritsar                                              ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                                        ~";
		cout<<"\n  ~                                                    DR.V.K.BANGA        ~";
		cout<<"\n  ~                                                    -------------       ~";
		cout<<"\n  ~                                                    certified by        ~";
		cout<<"\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		getch();
		clrscr();
		cout<<"\n\n\n\n\n\t\t\tACET WISHES YOU..... \n\n\n\n\t\t\t\t\tFOR BEST FUTURE...";
		getch();
		menu();
	}
	else
	{
		sound(5000);
		cout<<"\n\n\n\n\tYou have to first complete all the levels";
		delay(2000);
		nosound();
		play();
	}
}

void description()
{
	clrscr();
	textbackground(5);
	cout<<"\n** Total number of files used: 5";
	cout<<"\n   1) player.dat...to store players data";
	cout<<"\n   2) result.dat...to store players result";
	cout<<"\n   3) temp.dat...to store 1st set of question";
	cout<<"\n   4) temp1.dat...to store 2nd set of question";
	cout<<"\n   5) temp2.dat...to store 3rd set of question";
	cout<<"\n**Total number of classes used:4";
	cout<<"\n   1) player...to store players detail";
	cout<<"\n   2) playera...for registration of player";
	cout<<"\n   3) result...to handling of result of the players";
	cout<<"\n   4) quiz...to handling the question sets";
	getch();
	clrscr();
	cout<<"\n**Total number of header files used: 7";
	cout<<"\n   1) iostream...for use of cout,<<,cin,>> objects";
	cout<<"\n   2) stdio...for use of gets function";
	cout<<"\n   3) conio...for use of getch and clrscr function";
	cout<<"\n   4) string...for use of string handling functions";
	cout<<"\n   5) fstream..for use of file handling function";
	cout<<"\n   6) process..for use of exit function";
	cout<<"\n   7) dos...for use of delay,sound and nosound functions";
	getch();
	clrscr();
	cout<<"\n\n\n**Total internet sources used for idea:3";
	cout<<"\n\n   1) youtube video(ASHISH KHULBEY) for background colour";
	cout<<"\n\n   2) youtube video(PROGRAMMING DESIRE) for sound effect";
	cout<<"\n\n   3) http://WWW.le.ac.uk for password setting";
	getch();
	clrscr();
	cout<<"\n\n\n  This is our first project on the basis of languages";
	delay(1500);
	cout<<"\n\n  From this project we got knowledge.....";
	delay(1500);
	cout<<"\n\n  1) how to work for a large project in a team";
	cout<<"\n\n  2) how to think for a long term coading effect in an project";
	cout<<"\n\n  3) how to clearout the errors by self learning ";
	getch();
	clrscr();
	cout<<"\n\n\n\n\n\n\n\tThis is all about this project";
	delay(3000);
	clrscr();
	cout<<"\n\n\n\n\n\n\n\tHopping for a smile on our teachers face";
	delay(3000);
	clrscr();
	cout<<"\n\n\n\n\n\n\n\tAfter looking at our project";
	delay(3000);
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\tT";
	delay(400);
	cout<<"H";
	delay(400);
	cout<<"A";
	delay(400);
	cout<<"N";
	delay(400);
	cout<<"K";
	delay(400);
	cout<<"\tY";
	delay(400);
	cout<<"O";
	delay(400);
	cout<<"U";
	delay(400);
	cout<<"\n\n\n\n\n\tPlease press any key.......";
	getch();
	exit(0);
}