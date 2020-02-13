#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<process.h>

int LIFELN1=0;     //USED FOR LIFE LINE
int LIFELN2=0;
int LIFELN3=0;

FILE *Ques;      // FOR FILE USED

struct QuesList     // QUESTION LIST  STRUCT
{
	char Q_NM[100],Q_OP1[25],Q_OP2[25],Q_OP3[25],Q_OP4[25];
	char Q_ANS;
	char Q_FB1,Q_FB2,Q_FB3;
	int Q_CL1,Q_CL2,Q_CL3,Q_CL4;
};

struct QuesList Q;              //For FILE Used
struct QuesList T; 		//TEMP
struct QuesList QL[13];         //Add From FILE

struct Player         // PLAYER INFO STRUCT
{

	char P_NM[15],P_WIN[15];
	int P_LV;
};

struct Player TP,PP;      		//Player Record

void startMenu();         		//START MENU
void gamePlay();         		//START GAME FOR PLAY
int setTimer();          	        //SET TIMER
void displayMlist();      		//DESIGN TIMER LAYOUT
int stage(int q,int t);   		//START GAME WITH [GUI]
void designQuiz();        		//DESIGN OF GAME LAYOUT
char quizQuestn(int n);   		//DISPLAY QUESTION & OPTION RETURN ANS.
void lifeline();          		//DISPLAY LIFE LINE
void TimerQuiz();          		//TIMER CODE
void ansBlink(int i,int n,char c);      //YOUR ANSWER DISPLAY WITH BLINK
char twox1();
char twox2();
void phonefri(char x,char y,char z);         /*	PHONE FRIEND FUNCTION	*/
void chartDisplay(int w,int xx,int y,int z); /* CHART DISPLAY */
void winQuiz(int a);
int displayBlist(char q);
void wrongAns(int q);              //BACKGROUND ON TIMER AND NEXT WITH RETURN INT
void exitQuiz(int q);              //QUIT FROM GAME
void AdminQuestChang();              //ADMIN CHANGE QUESTION
int authorize();         	  //CHECK AUTHORIZATION WITH ASK QUES
void AdminDesignOps();            //ADMIN INPUT FOR FEATURE
void AdminEnterQuestion();        //ADMIN ENTER QUESTION
void AdminEnterOption(int it);    //ADMIN ENTER OPTION
int passwd();                     //PASSWORD PATEN WITH RETURN 0 & 1
void Score(); 	 		  /*	Display Score		*/
void Help();   			  /*	Display Help		*/
void updateQues(int Qi);          // UPDATE QUESTION FROM FILE
void addPlayer();                 // ADD PLAYER RECORD IN FILE
void AddQuestFile();              // STORE QUES ON STRUCT FROM FILE

/*	EXTRA FUNCTION		*/
int AreUsure(int i,int j);       // ASK FOR SURE 1-Y 2-N
/*	DISPLAY SQUARE ON SCREE */
void displaySqDL(int i1,int i2,int j1,int j2,int k1,int k2,int l1,int l2);
void displaySq(int i1,int i2,int j1,int j2,int k1,int k2,int l1,int l2);
/*	DISPLAY BAR		*/
void displayRbar(int i1,int j1,int sz);
void displayLbar(int i1,int j1,int sz);
void displayDbar(int i1,int j1,int sz);
char convCh(int q);        // CONVER INTO CHARACTER


void main()
{
	int tmp;
	AddQuestFile();        /*	ADD QUESTION FROM FILE 	*/
	startMenu();   	      /*	START MENU	*/
	clrscr();
}

/*	START-MENU LAYOUT	*/

void startMenu()
{
	int i,ch,cfch='1';    //'ch' CHOICE FROM USER  //'cfch' conform choice
	clrscr();
	gotoxy(35,4);
	textcolor(1); cprintf("<<"); textcolor(15); cprintf(" QUIZ-GAME"); textcolor(1); cprintf(" >>");
	textcolor(1);  displaySqDL(12,6,70,6,12,18,70,18);
	textcolor(15);
	gotoxy(22,8); cprintf(" 1. PLAY GAME ");
	gotoxy(22,10); cprintf(" 2. View-SCORE  ");
	gotoxy(22,12); cprintf(" 3. HELP ");
	gotoxy(22,14); cprintf(" 4. Change Question ");
	gotoxy(22,16); cprintf(" 5. EXIT ");
	textcolor(8);
	gotoxy(54,25); cprintf("Devloped By, Bh@vy@ & M@l@v");
	textcolor(7);
	gotoxy(18,19); cprintf(" << Enter Your Choice : - ");
	ch=getch();
	cprintf(" %c",ch);
	textbackground(1); textcolor(10);
	switch(ch)            //CHECK CHOICE
	{
		case '1':
			gotoxy(18,7); cprintf(" È>> 1. PLAY GAME        ");
			break;
		case '2':
			gotoxy(18,9); cprintf(" È>> 2. View-SCORE        ");
			break;
		case '3':
			gotoxy(18,11); cprintf(" È>>  3. HELP            ");
			break;
		case '4':
			gotoxy(18,13); cprintf(" È>>  4. Change Question ");
			break;
		case '5':
			gotoxy(18,15); cprintf(" È>>  5. EXIT            ");
			break;

	}
	textbackground(0);

	if(ch == '1')  /*	CHECK FOR MATCH		*/
	{
		cfch=AreUsure(48,8);
		if(cfch == '1')
		{
			LIFELN1=0;    //BEFORE PLAY GAME ASSIGN '0'
			LIFELN2=0;
			LIFELN3=0;
			gamePlay();

		}
		startMenu();
	}
	else if(ch == '4')
	{
		cfch=AreUsure(48,8);
		if(cfch == '1')
		{
			AdminQuestChang();
		}
		startMenu();
	}
	else if(ch == '5')
	{
		cfch=AreUsure(48,8);
		if(cfch == '2')
		{
			startMenu();
		}
	}
	else if(ch == '2')
	{
		sleep(1);
		Score();
	}
	else if(ch == '3')
	{
		sleep(1);
		Help();
	}
	else
	{
	       gotoxy(45,19);	cprintf(" Wrong Choice !!");
		sleep(1);
		startMenu();
	}
}

/*	GAME START TO PLAY	*/

void gamePlay()
{
	int i,t=0,q;       // TIMER HOW MANY QUESTION  //'q' TEMP
	int qp=0,qus=1;   //qp 	QUESTION T/F 'QUE' FOR GAME START FROM '1'
	t=setTimer();       // SET TIMER
	if(t==0)            //t = 0 EXIT FROM GAME
	{	return;  }
	for(qus=1;qus<=13;qus++)       //QUESTION 1 TO 13 DISPLAY
	{
		qp=stage(qus,t);
		if(qp==0)    //EXIT FROM GAME OR WRONG
		{
			return ;
		}
		qp=0;      //SET qp
	}
}


/* 	TIMER-SET ASK FROM USER		*/

int setTimer()
{
	int i,rt=0; // RETURN  rt
	char q,ch;
TIMER: displayMlist();      //DISPLAY LIST
	textcolor(15);
	gotoxy(3,9);cprintf("Enter Name >> ");
	textcolor(1);
	displaySqDL(3,10,30,10,3,12,30,12);
	displayLbar(30,11,9);
	gotoxy(8,11); gets(PP.P_NM);       //ENTER NAME
	textcolor(15);
	gotoxy(70,24);
	cprintf("E :"); textcolor(4); cprintf(" Exit");
	gotoxy(5,15); textcolor(1);
	cprintf("<< "); textcolor(15); cprintf("Enter Your Choice :- ");
	fflush(stdin);
	q=getche(); //INPUT FROM USER
	if(q=='e'||q=='E')
	{ return 0; }
	else
	{
		rt=displayBlist(q);    //DISPLAY LIST BEFORE PLAY GAME with 'T' Question
		if(rt==15) // WRONG CHOICE
		{ setTimer(); }
	}
	textcolor(15);
	ch=AreUsure(9,19);   //FOR CONFORMATION
	if(ch=='2')
	{	setTimer();  }
	else
	{ return rt; }
	return rt;
}

/* 	TIMER SET LAYOUT	*/

void displayMlist()
{
	int i;
	clrscr();
	gotoxy(12,5); textcolor(1);
	cprintf("<< "); textcolor(15); cprintf("QUIZ-GAME"); textcolor(1); cprintf(" >>");
	textcolor(1); displaySqDL(7,16,33,16,7,18,33,18);   //Square Draw
	displayRbar(1,17,6);
	displayLbar(33,17,6);
	textcolor(15);
	for(i=1;i<=25;i++)
	{
		gotoxy(40,i); cprintf("∫");
	}
	gotoxy(50,2); textcolor(1);
	cprintf("<< "); textcolor(15); cprintf("TIMER-SELECT"); textcolor(1); cprintf(" >>");
	textcolor(1);
	gotoxy(50,21); cprintf("1.     5,000");
	gotoxy(50,20); cprintf("2.    10,000");
	gotoxy(50,19); cprintf("3.    20,000");
	gotoxy(50,18); cprintf("4.    40,000");
	gotoxy(50,17); cprintf("5.    80,000");
	gotoxy(50,14); cprintf("7.  3,20,000");
	gotoxy(50,13); cprintf("8.  6,40,000");
	gotoxy(49,10); cprintf("A. 25,00,000");
	gotoxy(49,9);  cprintf("B. 50,00,000");
	textcolor(15);
	gotoxy(50,16); cprintf("6.  1,60,000");
	gotoxy(50,12); cprintf("9. 12,50,000");
	gotoxy(49,7);  cprintf("C.   1 CRORE");
	gotoxy(49,5);  cprintf("D.   5 CRORE");
	textcolor(15);

}

/*    [GAME CODE] QUESTION - ASK ANSWER FROM USER AND CHECK 	*/

int stage(int q,int t)
{
	int i;
	int qp=0;                  //'qp' FOR WIN AFTER NEW QUESTION
	char c,c1='z',A,a;         //'c1' USED FOR  X2 FEATURE 'c' ANSWER
	clrscr();
	designQuiz();   //DESIGN GAME LAYOUT
	textcolor(15); A=quizQuestn(q); //DISPLAY QUESTION WITH RETURN VALUE
	a=A+32;    //CAP & SMALL BOTH
	lifeline();// LIFE LINE'S
	if(t>=q)         //CHECK TIMER
	{ TimerQuiz(); }
	Timer:if(t>=q)     //DEPAND ON TIMER DECISION
	{
		designQuiz(); //FUNCTION
		lifeline();
	}
	else
	{
		designQuiz();
		lifeline();
		textcolor(15);
		A=quizQuestn(q);
		a=A+32;
	}
	textcolor(15);
	gotoxy(5,23); cprintf("E : "); textcolor(10); cprintf("Exit");
	textcolor(15);
	gotoxy(55,23); cprintf("Enter Your Choice: "); textcolor(15);
	c=getch();      //ENTER ANSWER
	cprintf("%c",c);
	if(c=='1'&& LIFELN1==0)  //CHECK 2X
	{
		c=twox1();
		c1=twox2();
		ansBlink(q,1,c1);       //EXTRA ANSWER
	}
	qp++;
	ansBlink(q,1,c);      //SELECT QUESTION LIST
	sleep(2);
	if(c=='2'&& LIFELN2==0)
	{
		phonefri(QL[q-1].Q_FB1,QL[q-1].Q_FB2,QL[q-1].Q_FB3);
		goto Timer;

	}
	else if(c=='3'&& LIFELN3==0)
	{
		chartDisplay(QL[q-1].Q_CL1,QL[q-1].Q_CL2,QL[q-1].Q_CL3,QL[q-1].Q_CL4);
		goto Timer;
	}
	else if(c=='e'||c=='E')
	{
		exitQuiz(q);
		return 0;
	}
	else if(c==a||c==A||c1==a||c1==A)   //CORRECT ANSWER
	{
		ansBlink(q,2,c);
		sleep(5);
		textcolor(15);
		qp=q+1;
		winQuiz(qp);
		return 1;
	}
	else if(c=='A'||c=='a'||c=='B'||c=='b'||c=='D'||c=='d'||c=='c'||c=='C')
	{
		ansBlink(q,2,a);
		ansBlink(q,3,c);
		sleep(5);
		textcolor(15);
		wrongAns(q);

		return 0;
	}
	else
	{
		goto Timer;
	}
}

/*	DESIGN QUIZ QUESTION LAYOUT	*/

void designQuiz()
{
	int i;
	clrscr();
	gotoxy(35,8); textcolor(1); cprintf("<< "); textcolor(15); cprintf("QUIZ-GAME"); textcolor(1); cprintf(" >>");
	textcolor(15);
	gotoxy(1,3); cprintf("1:");
	displaySq(4,1,10,1,4,5,10,5);
	gotoxy(15,3); cprintf("2:");
	displaySq(18,1,24,1,18,5,24,5);
	gotoxy(30,3); cprintf("3:");
	displaySq(33,1,39,1,33,5,39,5);
	gotoxy(60,3); cprintf("Timer:");
	displaySq(67,1,77,1,67,5,77,5);
	textcolor(1);
	displaySqDL(10,10,71,10,10,14,71,14);
	displayRbar(1,12,9);
	displayLbar(71,12,9);
	displaySqDL(10,16,38,16,10,18,38,18);
	displaySqDL(10,19,38,19,10,21,38,21);
	displaySqDL(43,16,71,16,43,18,71,18);
	displaySqDL(43,19,71,19,43,21,71,21);
	displayRbar(1,17,9);
	displayLbar(71,17,9);
	displayRbar(1,20,9);
	displayLbar(71,20,9);
	displayDbar(38,17,4);
	displayDbar(38,20,4);
}

/*	DISPLAY QUESTION/ANSWER ON DESIGN  FROM STRUCT */

char quizQuestn(int n)
{
	int i=n-1;
	int j;
	if(strlen(QL[i].Q_NM)<=50)    //CHECK LEGTH G <= 50
	{
		gotoxy(12,12); cprintf("%s",QL[i].Q_NM);
	}
	else      // MORE THEN 50 CODE
	{
		gotoxy(12,11);
		for(j=0;j<50;j++)     //1ST LINE
		{
			cprintf("%c",QL[i].Q_NM[j]);
		}
		cprintf(" -"); //BREAK
		gotoxy(15,12);
		for(j=50;j<strlen(QL[i].Q_NM);j++) //SECOND LINE
		{
			 cprintf("%c",QL[i].Q_NM[j]);
		}
	}

	/* ALL OPTION DISPLAY */
	gotoxy(12,17); cprintf("%s",QL[i].Q_OP1);
	gotoxy(45,17); cprintf("%s",QL[i].Q_OP2);
	gotoxy(12,20); cprintf("%s",QL[i].Q_OP3);
	gotoxy(45,20); cprintf("%s",QL[i].Q_OP4);

	return QL[i].Q_ANS;     //RETURN ANSWER
}
/*	DISPLAY LIFE LINE WITH ENABLE / DECEBLE   (COLOR)	*/

void lifeline()    //LifelineDisplay
{
	if(LIFELN1==0)     //CHECK FOR TEXTCOLOR
	textcolor(10);
	else
	textcolor(8);
	gotoxy(6,3); cprintf("2x");
	if(LIFELN2==0)    //CHECK FOR TEXTCOLOR
	textcolor(10);
	else
	textcolor(8);
	gotoxy(20,2); cprintf("…Õ@");
	gotoxy(20,3);  cprintf("∫");
	gotoxy(20,4); cprintf("»Õ@");
	if(LIFELN3==0)    //CHECK FOR TEXTCOLOR
	textcolor(10);
	else
	textcolor(8);
	gotoxy(34,2); cprintf("€");
	gotoxy(34,3);  cprintf("€ €");
	gotoxy(34,4); cprintf("€ € €");
	textcolor(15);
}

/*	TIMER CODE	*/

void TimerQuiz()
{
	int i;
	textcolor(10);
	for(i=20;i>=0;i--)           //LOOP 20 - 0
	{
		if(i<6)              // LESS THAN 5 COLOR CHANGE
		{
			textcolor(4);
		}
		gotoxy(69,3); cprintf("00 : %02d",i);
		sleep(1);  //HOLD SECOND
	}
	textcolor(15);
}

/* BLINK ANSWER (WRONG/SELECT/CORRECT)	*/

void ansBlink(int i,int n,char c)
{
	if(n==1)       //SELECT
	{
		textbackground(1); textcolor(15);
	}
	else if(n==2)  //CORRECT
	{
		textbackground(10); textcolor(15);
	}
	else if(n==3)  //WRONG
	{
		textbackground(4); textcolor(15);
	}
	/*	DISPLAY OPTION BACKGROUND   */
	if(c=='a'||c=='A')
	{
		gotoxy(11,17); cprintf(" %s   ",QL[i-1].Q_OP1);
	}
	else if(c=='b'||c=='B')
	{
		gotoxy(44,17); cprintf(" %s   ",QL[i-1].Q_OP2);
	}
	else if(c=='c'||c=='C')
	{
		gotoxy(11,20); cprintf(" %s   ",QL[i-1].Q_OP3);
	}
	else if(c=='d'||c=='D')
	{
		gotoxy(44,20); cprintf(" %s   ",QL[i-1].Q_OP4);
	}
	textcolor(15);
	textbackground(0);
}



/*	2X LIFE LINE 1ST	*/

char twox1()
{
	char c;
	textcolor(8);
	gotoxy(6,3); cprintf("2x"); textcolor(15);
      TWOXC:  gotoxy(55,23);
       cprintf("Enter Your Choice [1]: ");
	c=getch();        //ENTER OPTION 1
	if(!(c=='a'||c=='A'||c=='b'||c=='b'||c=='c'||c=='C'||c=='d'||c=='D'))
	goto  TWOXC;
	printf("%c",c);
	return c;
}

/*	2X LIFE LINE 2ND    */

char twox2()
{
	char c1;
	textcolor(15);
      TWOXC1:  gotoxy(55,24);
	cprintf("Enter Your Choice [2]: ");
	c1=getch();  //ENTER OPTION 2
	if(!(c1=='a'||c1=='A'||c1=='b'||c1=='b'||c1=='c'||c1=='C'||c1=='d'||c1=='D'))
	goto  TWOXC1;
	printf("%c",c1); textcolor(15);
	LIFELN1++;  //LL1 GLOBAL VARIABLE ++
	return c1;
}

/* 	PHONE FRIEND 	*/

void phonefri(char x,char y,char z)
{
	char c;
	int i;
   PHF:	clrscr();
	gotoxy(22,8); textcolor(1); cprintf("<< "); textcolor(15); cprintf("PHONE-FRIEND"); textcolor(1); cprintf(" >>");
	textcolor(15); displaySq(48,6,54,6,48,10,54,10);
	textcolor(10);
	gotoxy(50,7); cprintf("…Õ@");
	gotoxy(50,8);  cprintf("∫");
	gotoxy(50,9); cprintf("»Õ@");
	textcolor(6);
	gotoxy(25,12); cprintf("1. Mr. Shah");
	gotoxy(25,15); cprintf("2. Mrs. Deshai");
	gotoxy(25,18); cprintf("3. Mr. Patil");
	textcolor(1);displaySq(20,10,45,10,20,20,45,20);
	textcolor(10);
	gotoxy(52,23); cprintf("<< Enter Your Choice: ");
	LIFELN2++;  // LL2 GLOBAL VARIABLE ++
	textcolor(15); c=getch(); //CHOICE FOR ENTER
	clrscr();
	gotoxy(15,8);
	textcolor(15);
	if(c=='1')
	{ cprintf("Mr. Shah"); }
	else if(c=='2')
	{ cprintf("Mrs. Deshai"); }
	else if(c=='3')
	{ cprintf("Mr. Patil"); }
	else
	{ goto PHF; }
	textcolor(1); cprintf(" >>");
	textcolor(6);           //DEMO CALLING ON SAME PLACE
	gotoxy(25,12); cprintf("Calling: "); sleep(1);
	gotoxy(25,12); cprintf("Calling: .. "); sleep(1);
	gotoxy(25,12); cprintf("Calling: .... "); sleep(1);
	gotoxy(25,12); cprintf("Calling: ..... "); sleep(1);
	gotoxy(25,12); cprintf("Calling: .... "); sleep(1);
	gotoxy(25,12); cprintf("Calling: ..   "); sleep(1);
	gotoxy(25,12); cprintf("Calling: ..... "); sleep(1);
	gotoxy(25,12); cprintf("Calling: ......");
	textcolor(10);
	gotoxy(55,23);
	/*	DISPLAY ANSWER	*/
	if(c=='1')
	{ cprintf("ANSWER: %c ",x); }
	else if(c=='2')
	{ cprintf("ANSWER: %c ",y); }
	else if(c=='3')
	{ cprintf("ANSWER: %c ",z); }
	textcolor(15);
	EXITPF: sleep(5);
}

/* 	   AUDIENCE POLE       */

void chartDisplay(int w,int xx,int y,int z)
{
	int i,k,j,l,Scl=5,s;       //SCALE VALUE
	char x1[5]={"A: "},x2[5]={"B: "},x3[5]={"C: "},x4[5]={"D: "};
	clrscr();
	LIFELN3++; // LL3 GLOBAL VARIABLE ++
	gotoxy(5,1); cprintf("Y\n");
	gotoxy(1,4);
	for(i=20;i>=1;i--) //DISPLAY CHART VALUE
	{
		printf("%d\n",i*Scl);
	}
	gotoxy(25,3);
	textcolor(1); cprintf("<< "); printf("AUDIENCE-POLE"); cprintf(" >>");
	gotoxy(1,24); printf("X ƒƒ");
	for(i=2;i<=23;i++)    //DISPLAY LINE Y
	{
		gotoxy(5,i); printf("≈");
	}
	textcolor(4); gotoxy(5,i); cprintf("%c",21); textcolor(15);
	for(i=1;i<=74;i++) // DISPLAY LINE OF X
	{
		cprintf("ƒ");
	}
	cprintf("X"); cprintf("  0 Y'"); //DISPLAY FOR BREAK CHARAT
	textcolor(10);
	cprintf("   %s   %s   %s   %s",x1,x2,x3,x4);
	l=4+5+(strlen(x1)/2); //COUNT LEN FOR CHART DISPLAY
	textcolor(2);
	for(i=1;i<=w/Scl; i++)
	{
		gotoxy(l,24-i); cprintf("±±±  ");
	}
	gotoxy(l,24-i); printf(" %d",w);
	l+=5+(strlen(x2)/2); //COUNT LEN FOR CHART DISPLAY
	textcolor(9);
	for(i=1;i<=xx/Scl; i++)
	{
		gotoxy(l,24-i); cprintf("≤≤≤  ");
	}
	gotoxy(l,24-i);
	printf(" %d",xx); //COUNT LEN FOR CHART DISPLAY
	l+=5+(strlen(x3)/2);
	textcolor(4);
	for(i=1;i<=y/Scl; i++)
	{
		gotoxy(l,24-i); cprintf("∞∞∞  ");
	}
	gotoxy(l,24-i);
	cprintf(" %d",y); //COUNT LEN FOR CHART DISPLAY
	l+=5+(strlen(x4)/2);
	textcolor(6);
	for(i=1;i<=z/Scl; i++)
	{
		gotoxy(l,24-i);
		cprintf("€€€ ");

	}
	gotoxy(l,24-i); printf(" %d",z);       //DISPLAY DIALOG-BOX
	textcolor(15);
	displaySqDL(60,5,80,5,60,16,80,16);
	textcolor(2);
	gotoxy(65,7); cprintf("±±± :%s",x1);
	textcolor(9);
	gotoxy(65,9); cprintf("≤≤≤ :%s",x2);
	textcolor(4);
	gotoxy(65,11); cprintf("∞∞∞ :%s",x3);
	textcolor(6);
	gotoxy(65,13); cprintf("€€€ :%s",x4);
	gotoxy(60,2); textcolor(10); cprintf("scale :");
	gotoxy(70,25); cprintf("PERCENT");
	gotoxy(62,3); textcolor(1); cprintf("1 c.m. = %d",Scl);
	textcolor(15);
	getch();
}

/*	WIN AND MOVE NEXT LEVEL PAGE	*/

void winQuiz(int a)
{
	int i,q=a,tp;
	char qc;
	if(q==14)            //ALL QUESTION CORRECT
	{
		exitQuiz(q);      //EXIT FROM QUIZ
		return;
	}
	clrscr();
	displayMlist();    //DISPLAY LIST LEVEL
	gotoxy(11,11);
	textcolor(10); cprintf("<< CONGRATULATIONS >>");
	gotoxy(8,15); textcolor(1);
	textcolor(15); cprintf("NEXT LEVEL:"); textcolor(1); cprintf(" >>");
	qc=convCh(q);     //CONVERT IN CHARACTER FOR displayBlink
	tp=displayBlist(qc);         //DISPLAY LEVEL LIST
	sleep(5);
	tp--; //TEMP IGNORE WARNING!!
}

/*	DISPLAY AFTER SELECT TIMER/NEXT LEVEL  BACKGROUD LIST	*/

int displayBlist(char q)
{
	int rt; //FOR RETURN
	/*	MATCH CHOICE 	*/
	if(q=='1')
	{
		textcolor(15); textbackground(1);
		gotoxy(45,21); cprintf(" È>> 1.     5,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   5,000 "); rt=1;
	 }
	else if(q=='2')
	{
		textcolor(15); textbackground(1);
		gotoxy(45,20); cprintf(" È>> 2.    10,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   10,000 ");  rt=2;
	 }
	else if(q=='3')
	{
		textcolor(15); textbackground(1);
		gotoxy(45,19); cprintf(" È>> 3.    20,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   20,000 "); rt=3;
	}
	else if(q=='4')
	{
		textcolor(15); textbackground(1);
		gotoxy(45,18); cprintf(" È>> 4.    40,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   40,000 "); rt=4;
	 }
	else if(q=='5')
	{
		textcolor(15); textbackground(1);
		gotoxy(45,17); cprintf(" È>> 5.    80,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   80,000 "); rt=5;
	 }
	else if(q=='6')
	{
		textcolor(15); textbackground(1);
		gotoxy(45,16); cprintf(" È>> 6.   1,60,000 ");textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-  1,60,000 "); rt=6;
	 }
	else if(q=='7')
	{
		textcolor(15); textbackground(1);
		gotoxy(45,14); cprintf(" È>> 7.  3,20,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   3,20,000 "); rt=7;
	 }
	else if(q=='8')
	{
		textcolor(15); textbackground(1);
		gotoxy(45,13); cprintf(" È>> 8.  6,40,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   6,40,000 "); rt=8;

	}
	else if(q=='9')
	{
		textcolor(15); textbackground(1);
		gotoxy(45,12); cprintf(" È>> 9. 12,50,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-  12,50,000 "); rt=9;
	}
	else if(q=='A'||q=='a')
	{
		textcolor(15); textbackground(1);
		gotoxy(44,10); cprintf(" È>> A. 25,00,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   25,00,000 ");  rt=10;
	}
	else if(q=='B'||q=='b')
	{
		textcolor(15); textbackground(1);
		gotoxy(44,9); cprintf(" È>> B. 50,00,000 "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   50,00,000 "); rt=11;
	}
	else if(q=='c'||q=='C')
	{
		textcolor(15); textbackground(1);
		gotoxy(44,7); cprintf(" È>> C.  1 CRORE "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   1 CRORE ");  rt=12;
	}
	else if(q=='d'||q=='D')
	{
		textcolor(15); textbackground(1);
		gotoxy(44,5); cprintf(" È>> D.  5 CRORE "); textbackground(0);
		textcolor(6);
		gotoxy(10,17); cprintf("Rs:-   5 CRORE "); rt=13;
	}
	else
	{ rt=15; }
	return rt;

}

/*	ANSWER WRONG THEN WIN MONEY GUI */

void wrongAns(int q)
{
	int i;
	clrscr();
	textcolor(1); gotoxy(33,8);
	cprintf("<< "); textcolor(4); cprintf("WRONG-Answer"); textcolor(1); cprintf(" >>");
	displaySqDL(10,10,70,10,10,14,70,14);
	displayRbar(1,12,9);
	displayLbar(70,12,9);
	textcolor(15);	gotoxy(33,12);
	switch (q-1)     //SWITCH FOR CHECK WIN MONEY BY LEVEL
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		{
			strcpy(PP.P_WIN," 0 ");
			PP.P_LV=--q;
			cprintf("Rs:-     0 ");
			break;
		}
		case 6:
		case 7:
		case 8:
		{
			strcpy(PP.P_WIN," 1,60,000 ");
			PP.P_LV=--q;
			cprintf("Rs:-  1,60,000 ");
			break;
		}
		case 9:
		case 10:
		case 11:
		{
			strcpy(PP.P_WIN," 12,50,000 ");
			PP.P_LV=--q;
			cprintf("Rs:-   12,50,000 ");
			break;
		}
		case 12:
		{
			strcpy(PP.P_WIN," 1 CRORE ");
			PP.P_LV=--q;
			cprintf("Rs:-   1 CRORE ");
			break;
		}
		case 13:
		{
			strcpy(PP.P_WIN," 5 CRORE ");     //COPY ON PLAYER STRUCT
			PP.P_LV=--q;                      //PLAYER LEVEL
			cprintf("Rs:-   5 CRORE ");
			break;
		}
	}
	addPlayer();     //STORE RECORD ON FILR
	gotoxy(65,19); textcolor(10); cprintf("Thank you,");
	gotoxy(55,24); textcolor(6); cprintf("PRESS ANY KEY TO EXIT:"); textcolor(15);
	getch();
}

/*	EXIT FROM QUIZ  [MONEY LAYOUT]	 	 */

void exitQuiz(int q)
{
	int i;
	clrscr();
	textcolor(1); gotoxy(33,8); cprintf("<< "); textcolor(15); cprintf("Exit"); textcolor(1); cprintf(" >>");
	displaySqDL(10,10,70,10,10,14,70,14);
	displayRbar(1,12,9);
	displayLbar(70,12,9);
	textcolor(15);	gotoxy(35,12);
	switch (q)                  //CHECK FOR WIN MONEY DIRECT
	{
		case 1:
			strcpy(PP.P_WIN," 0 ");
			cprintf("Rs:-     0 ");
			break;
		case 2:
			strcpy(PP.P_WIN," 5,000 ");
			cprintf("Rs:-   5,000 ");
			break;
		case 3:
			strcpy(PP.P_WIN," 10,000 ");
			cprintf("Rs:-   10,000 ");
			break;
		case 4:
			strcpy(PP.P_WIN," 20,000 ");
			cprintf("Rs:-   20,000 ");
			break;
		case 5:
			strcpy(PP.P_WIN," 40,000 ");
			cprintf("Rs:-   40,000 ");
			break;
		case 6:
			strcpy(PP.P_WIN," 80,000 ");
			cprintf("Rs:-   80,000 ");
			break;
		case 7:
			strcpy(PP.P_WIN," 1,60,000 ");
			cprintf("Rs:-   1,60,000 ");
			break;
		case 8:
			strcpy(PP.P_WIN," 3,20,000 ");
			cprintf("Rs:-   3,20,000 ");
			break;
		case 9:
			strcpy(PP.P_WIN," 6,40,000 ");
			cprintf("Rs:-   6,40,000 ");
			break;
		case 10:
			strcpy(PP.P_WIN," 12,50,000 ");
			cprintf("Rs:-   12,50,000 ");
			break;
		case 11:
			strcpy(PP.P_WIN," 25,00,000 ");
			cprintf("Rs:-   25,00,000 ");
			break;
		case 12:
			strcpy(PP.P_WIN," 50,00,000 ");
			cprintf("Rs:-   50,00,000 ");
			break;
		case 13:
			strcpy(PP.P_WIN," 1 CRORE ");
			cprintf("Rs:-   1 CRORE ");
			break;
		case 14:
			strcpy(PP.P_WIN," 5 CRORE "); //COPY WIN MONEY
			cprintf("Rs:-   5 CRORE ");
			break;
	}
			PP.P_LV=--q;    //CHECK LEVEL
       addPlayer();
       //	gotoxy(50,18); textcolor(10); cprintf("%s-%s-%d",PP.P_NM,PP.P_WIN,PP.P_LV);
	gotoxy(65,19); textcolor(10); cprintf("Thank you,");
	gotoxy(55,24); textcolor(6); cprintf("PRESS ANY KEY TO EXIT:"); textcolor(15);
	getch();
}

/***************************************/
/*	ADMIN ENTER QUESTION IN FILE	*/

void AdminQuestChang()
{
	int a,i,j,que;
	char Q[100],Q1[25],Q2[25],Q3[25],Q4[25];
	char ctemp;
       ADMIN:	que=authorize();       //MATCH PASSWORD AND ENTER QUEST. NO
	if(que==-1)
	{  goto ADMIN; }
	designQuiz();          //DESIGN LAYOUT
	AdminEnterQuestion();  //ENTER QUESTION
	for(i=1;i<=4;i++)      //ENTER OPTION
	{
		fflush(stdin);
		AdminEnterOption(i);
	}

	gotoxy(50,24);
	cprintf("Enter To Continue >>");
	getch();
	AdminDesignOps();   //ENTER FEATURE
	i=AreUsure(48,16);  //CONFORMATION
	if(i=='1')         //CORRECT
	{
		updateQues(que); //UPDATE ON FILE
		gotoxy(50,24);
		cprintf("Update  Successful >> ");
		getch();
	}
}

/*	CHECK PASSWORD PAGE FOR CHANGE QUESTION		*/

int authorize()
{
	int tmp,que;       // 'TMP'
     AUTH: clrscr();
	textcolor(15);
	displaySq(3,3,70,3,3,7,70,7);
	textcolor(14);
	gotoxy(25,5); cprintf("<< Change Question >>");
	textcolor(15);
	gotoxy(15,10); cprintf("User Name >>");
	displaySq(32,9,55,9,32,11,55,11);
	textcolor(6);
	gotoxy(40,10); cprintf(" ADMIN");
	textcolor(15);
	gotoxy(15,14); cprintf("Password >>");
	displaySq(32,13,55,13,32,15,55,15);
	textcolor(6);
	gotoxy(40,14);
	tmp=passwd(); //PASSWORD MATH 0-N 1-Y
	if(tmp==0)
	{ goto AUTH;}

	textcolor(10);
	gotoxy(8,19); cprintf("Enter Question No.>>");
	textcolor(15); displaySq(32,18,40,18,32,20,40,20);
	textcolor(4); cprintf("[Only 1 to 13]");
	gotoxy(35,19);
	cscanf("%d",&que);
	if(que > 0 && que < 14)
	{
		return que;
	}
	else
	{
		textcolor(4);
		gotoxy(25,22);
		cprintf(" Wrong Choice !!");
		sleep(1);
	}
	return -1; //TEMP FOR IGNORE WORNING!!

}

/*	ADMIN ENTER LIFE-LINE & ANSWER IN FILE	*/

void AdminDesignOps()
{
	char i;
	clrscr();
	gotoxy(35,2); textcolor(1); cprintf("<< "); textcolor(15); cprintf(" Enter Option "); textcolor(1); cprintf(" >>");
	textcolor(15);
	displaySq(10,5,16,5,10,9,16,9);
	textcolor(10);
	gotoxy(11,6);   cprintf("€");
	gotoxy(11,7);  cprintf("€ €");
	gotoxy(11,8); cprintf("€ € €");
	textcolor(15);
	displaySq(10,14,16,14,10,18,16,18);
	textcolor(10);
	gotoxy(12,15); cprintf("…Õ@");
	gotoxy(12,16);  cprintf("∫");
	gotoxy(12,17); cprintf("»Õ@");
	textcolor(15);

	gotoxy(20,6); cprintf (" A: ");
	gotoxy(40,6); cprintf (" B: ");
	gotoxy(20,9); cprintf (" C: ");
	gotoxy(40,9); cprintf (" D: ");

	gotoxy(22,13); cprintf (" Mr. Shah : ");
	gotoxy(22,16); cprintf (" Mrs. Deshi : ");
	gotoxy(22,19); cprintf (" Mr. Patile : ");
	gotoxy(10,22); cprintf (" Answer : ");
	textcolor(15);
	displaySq(25,5,32,5,25,7,32,7);
	displaySq(45,5,52,5,45,7,52,7);
	displaySq(25,8,32,8,25,10,32,10);
	displaySq(45,8,52,8,45,10,52,10);

	textcolor(4); cprintf("[Only 1 to 100]");
	textcolor(15);
	displaySq(35,12,42,12,35,14,42,14);
	displaySq(35,15,42,15,35,17,42,17);
	displaySq(35,18,42,18,35,20,42,20);
	displaySq(22,21,30,21,22,23,30,23);
	textcolor(4);
	gotoxy(45,13);cprintf("[Only A to D]");

	/*	AUDIENCE POLE VALUE	*/
	gotoxy(27,6); cscanf("%d",&T.Q_CL1);
	gotoxy(47,6); cscanf("%d",&T.Q_CL2);
	gotoxy(27,9); cscanf("%d",&T.Q_CL3);
	gotoxy(47,9); cscanf("%d",&T.Q_CL4);
	fflush(stdin);
	getch();
	/*	PHONE FRIEND VALUE	*/
	gotoxy(38,13);cscanf("%c",&T.Q_FB1);
	fflush(stdin);
	gotoxy(38,16);cscanf("%c",&T.Q_FB2);
	fflush(stdin);
	getch();
	gotoxy(38,19);cscanf("%c",&T.Q_FB3);
	fflush(stdin);
	/*	ANSWER	*/
	gotoxy(25,22);cscanf("%c",&T.Q_ANS);
	fflush(stdin);

}


/*	ADMIN ENTER QUESTION IN FILE	*/

void AdminEnterQuestion()
{
	int a,i,j;
	char Q[100];
	getch();
	fflush(stdin);
	textcolor(4);
	gotoxy(50,9); cprintf("[Only 90 Char. Enter]");
	textcolor(15);
	gotoxy(12,11); cprintf("Q: ");
	Q[0]='Q';Q[1]=':';Q[2]=' ';          //FILE STORE with
	for(i=3;i<=95;i++)          //ENTER QUESTION     'ONLY'
	{
		Q[i]=getch();
		if(i==50)     // MORE THAN 50
		{
			cprintf(" - "); gotoxy(16,12);
		}
		if(Q[i]==13 || i==92)  //LAST CHAR & ENTER PRESS
		{
			if(i==92 && Q[i]!='?')
			Q[i]='?';
			Q[i]='\0';
			break;
		}
		else if(Q[i]==8)    //BACKSPACE
		{
			cprintf("\b \b"); i-=2;
		}
		else        //ALL
		{
			cprintf("%c",Q[i]);
		}
	}
	strcpy(T.Q_NM,Q);  //COPY ON STRUCT VARIABLE

}

/*	ADMIN ENTER QUESTION IN FILE	*/

void AdminEnterOption(int it)
{
	int a,j,i;
	char Q[25];   //ENTER OPTION
	textcolor(15);
	textcolor(4);
	gotoxy(50,9); cprintf("[Only 25 Char. Enter]");textcolor(15);
	 switch(it)    //CHECK OPTION WITH GOTOXY
	 {
		case 1:
			gotoxy(12,17); cprintf("A: ");
			Q[0]='A';Q[1]=':';Q[2]=' ';
			break;
		case 2:
			Q[0]='B';Q[1]=':';Q[2]=' ';
			gotoxy(45,17); cprintf("B: ");
			break;
		case 3:
			Q[0]='C';Q[1]=':';Q[2]=' ';
			gotoxy(12,20); cprintf("C: ");
			break;
		case 4:
			Q[0]='D';Q[1]=':';Q[2]=' ';
			gotoxy(45,20); cprintf("D: ");
			break;
		default:
			gotoxy(50,9); cprintf("Wrong Choice!!");
	 }
	for(i=3;i<20;i++)
	{
		Q[i]=getch();
		if(Q[i]==13 || i==19)   //ENTER AND 19 CHAR
		{
			Q[i]='\0';
			break;
		}
		else if(Q[i]==8)       //BACK SPACE
		{
			cprintf("\b \b"); i-=2;
		}
		else
		{
			cprintf("%c",Q[i]);
		}
	}
	switch(it)    // COPY ON STRUCTURE
	 {
		case 1:
			strcpy(T.Q_OP1,Q);
			break;
		case 2:
			strcpy(T.Q_OP2,Q);
			break;
		case 3:
			strcpy(T.Q_OP3,Q);
			break;
		case 4:
			strcpy(T.Q_OP4,Q);
			break;
	 }

}

/*	ENTET PASSWORD FORMATE	*/

int passwd()
{
	int i;
	char PW[10];

	for(i=0;i<10;i++)  //DISPLAY PASSWORD
	{
		PW[i]=getch();
		if(PW[i]==13 || i==9)       //ENTER & MORE 9
		{
			PW[i]='\0';
			break;
		}
		else if(PW[i]==8)         //BACK SPACE
		{
			cprintf("\b \b"); i-=2;
		}
		else
		{
			cprintf("*");
		}

	}
	if(strcmp("ADMIN",PW)!=0)           //CHECK PASSWORD CODE
	{
		textcolor(4);
		gotoxy(25,17);
		cprintf(" Wrong Password !!");
		sleep(1);
		 return 0;
	}
	return 1;

}


/************************/
/*	DISPLAY SCORE	*/

void Score()
{
	int i,j=1;
	FILE *gets;
	gets=fopen("Player.txt","rb+");    //READ FILE FOR DISPLAY
	fseek(gets,SEEK_SET,0);

       DIV:clrscr();
	i=1;
	textcolor(15);
	displaySqDL(2,2,66,2,2,4,66,4);
	textcolor(10);
	gotoxy(25,3); cprintf(" << Display Sccore >> ");
	textcolor(8);
	displaySq(2,5,8,5,2,7,8,7);
	displaySq(10,5,30,5,10,7,30,7);
	displaySq(32,5,52,5,32,7,52,7);
	displaySq(54,5,66,5,54,7,66,7);
	displaySq(2,8,8,8,2,22,8,22);
	displaySq(10,8,30,8,10,22,30,22);
	displaySq(32,8,52,8,32,22,52,22);
	displaySq(54,8,66,8,54,22,66,22);

	textcolor(15);
	gotoxy(4,6); cprintf(" NO");
	gotoxy(17,6); cprintf(" NAME ");
	gotoxy(40,6); cprintf(" WIN ");
	gotoxy(57,6); cprintf(" LEVEL ");

       textcolor(14);
       while(fread(&TP,sizeof(TP),1,gets))    //READ FROM FILE & DISPLAY
       {
			gotoxy(4,9+i); cprintf(" %2d",j);
			gotoxy(15,9+i); cprintf(" %s ",TP.P_NM);
			gotoxy(35,9+i); cprintf(" %10s ",TP.P_WIN);
			gotoxy(57,9+i); cprintf(" %d ",TP.P_LV);

			if(i%10==0)      //CHECK FOR NOT MORE THAN 10
			{
				gotoxy(55,24); textcolor(6); cprintf("PRESS ANY KEY TO Continue:"); textcolor(15);
				getch();
				j++;
				goto DIV;
			}
			i++;  j++; //'I'CHECK & GOTOXY AND 'J' FOR NUMBERING
       }
       fclose(gets);
       gotoxy(55,24); textcolor(6); cprintf("PRESS ANY KEY TO EXIT:"); textcolor(15);
       getch();
       startMenu();
}
/********************************/
/*	DISPLAY HELP OPTION	*/

void Help()
{
	clrscr();
	textcolor(15);
	displaySqDL(2,2,66,2,2,4,66,4);
	textcolor(4);
	gotoxy(27,3); cprintf(" << HELP >> ");
	textcolor(8);
	displaySqDL(2,6,66,6,2,22,66,22);
	textcolor(15);
	gotoxy(5,8);	cprintf("This is Simply Quiz Game ");
	gotoxy(5,9);	cprintf("In, This Game There are 1 to 13 Questions");
	gotoxy(5,10);	cprintf("In, this game Facility of Timer ");
	gotoxy(5,11);	cprintf("You Win Money & Display Your Score");
	gotoxy(5,12);   cprintf("Also, ADMIN can Change Question");
	gotoxy(5,13);   cprintf("There is Nothing Use of Graphics");
	gotoxy(5,14);   cprintf("Also, Facility of Graph And Pho. friend");
	gotoxy(5,15);   cprintf("Also, Facility of Double Answer ");
	gotoxy(5,16);   cprintf("Look similer like KBC ");
	gotoxy(5,17);   cprintf("User easy to play without Mouse");
	gotoxy(5,18);   cprintf("User friendly Layout");
	gotoxy(5,19); textcolor(4); cprintf("Thank You!!");
	gotoxy(55,24); textcolor(6); cprintf("PRESS ANY KEY TO EXIT:"); textcolor(15);
	getch();
	startMenu();
}

/*	UPDATE QUESTION IN FILE	*/

void updateQues(int Qi)
{
	int no=1;
	long int size=sizeof(T);
	FILE *Update;
	Update=fopen("QuizQues.txt","rb+");    //OPEN FILE FOR READ & WRITE
	fflush(stdin);
	while(fread(&Q,sizeof(T),1,Update))
	{
		if(no==Qi)    //CHECK FOR MATCH OPTION
		{
			fseek(Update,-size,SEEK_CUR);  //Current FILE POINET MOVE BACK AND OVERWRITE
			fwrite(&T,sizeof(T),1,Update); //WRITE
		}
		no++;   //QUES. NO++
	}
	fclose(Update);    //CLSOE
	AddQuestFile();    //UPDATE ALSO ON STRUCTURE
}

/*	PLAYER RECORD STORE IN FILE	*/


void addPlayer()
{
	FILE *fp;
	fp=fopen("Player.txt","ab+");
	fwrite(&PP,sizeof(PP),1,fp);     //STORE PLAYER ON FILE
	fclose(fp);
}

/*	LOAD QUESTION FROM FILE INTO STRUCTURE	*/

void AddQuestFile()
{
	int i=0;
	FILE *gets;

       gets=fopen("QuizQues.txt","rb");    //FILE OPEN
       fseek(gets,SEEK_SET,0);
       while(fread(&Q,sizeof(Q),1,gets))   //READ AND STORE IN STRUCT
       {
		QL[i++]=Q;
       }
       fclose(gets);

}


/*	EXTRA USEDFUL FUNCTION		*/
/*	ASK FOR CONFORMATION	*/

int AreUsure(int i,int j)        /* DISPLAY WITH BOX 1-Y & 2-N */
{
	int ch;
	textcolor(4);displaySq(i,j,i+20,j,i,j+6,i+20,j+6);
	textcolor(15);
	gotoxy(i+4,j+1); cprintf("Are You Sure ?");
	textcolor(4);
	gotoxy(i+8,j+2); cprintf("1. Yes");
	gotoxy(i+8,j+3); cprintf("2. No");
	textcolor(7);
	gotoxy(i+2,j+5); cprintf("<< Enter (1/2): ");
AreUSure: ch=getch();
	if(!(ch=='1'|| ch=='2'))  //CHECK
	{ goto AreUSure; }
	return ch;

}


/*	DESIGN SQUARE FUNCTION		*/

void displaySq(int i1,int i2,int j1,int j2,int k1,int k2,int l1,int l2)
{
	int i;
	gotoxy(i1,i2); cprintf("⁄");
	gotoxy(j1,j2);  cprintf("ø");
	gotoxy(k1,k2); cprintf("¿");
	for(i=1;i<=j1-(i1+1);i++)        //LOOP FOR '-'
	{
		gotoxy(i1+i,i2); cprintf("ƒ");
		gotoxy(k1+i,k2); cprintf("ƒ");
	}
	for(i=1;i<=k2-(i2+1);i++)      //LOOP FOR  '|'
	{
		gotoxy(i1,i2+i);  cprintf("≥");
		gotoxy(j1,j2+i); cprintf("≥");
	}
	gotoxy(l1,l2); cprintf("Ÿ");
}

/*	DESIGN DOUBLE LINE SQUARE FUNCTION		*/


void displaySqDL(int i1,int i2,int j1,int j2,int k1,int k2,int l1,int l2)
{
	int i;
	gotoxy(i1,i2); cprintf("…");
	gotoxy(j1,j2);  cprintf("ª");
	gotoxy(k1,k2); cprintf("»");
	for(i=1;i<=j1-(i1+1);i++)
	{
		gotoxy(i1+i,i2); cprintf("Õ");
		gotoxy(k1+i,k2); cprintf("Õ");
	}
	for(i=1;i<=k2-(i2+1);i++)
	{
		gotoxy(i1,i2+i); cprintf("∫");
		gotoxy(j1,j2+i);  cprintf("∫");
	}
	gotoxy(l1,l2); cprintf("º");
}

/*	DESIGN "π"   FUNCTION	  */

void displayRbar(int i1,int j1,int sz)
{
	int i;
	gotoxy(i1,j1);
	for(i=1;i<=sz;i++)
	{ cprintf("Õ");}
	cprintf("π");

}

/*	DESIGN "Ã"   FUNCTION	  */

void displayLbar(int i1,int j1,int sz)
{
	int i;
	gotoxy(i1,j1); cprintf("Ã");
	for(i=1;i<=sz;i++)
	{ cprintf("Õ");}
}

/*	DESIGN "π" "Ã"   FUNCTION	  */

void displayDbar(int i1,int j1,int sz)
{
	int i;
	gotoxy(i1,j1); cprintf("Ã");
	for(i=1;i<=sz;i++)
	{ cprintf("Õ");}
	gotoxy(i1+i,j1); cprintf("π");
}

/*	CONVERT INTEGER INTO CHARACTER 	*/

char convCh(int q)
{
	char  qc;
	qc=(q==1?'1':q==2?'2':q==3?'3':q==4?'4':q==5?'5':q==6?'6':q==7?'7':q==8?'8':q==9?'9':q==10?'A':q==11?'B':q==12?'C':'D');
	return qc;
}
