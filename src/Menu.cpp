#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include <math.h>
#include <string.h>
#include <fstream.h>
#include <ctype.h>
#include "class_airplane_and_queue.h"
using namespace std;

void start();
void disp_menu();
void View_Notifications();
void baggage_claim_status();
void gate_status();
void airplane_status();
void search();
	void Search_by_aircompany();
	void Search_by_destination();
	void Search_by_status();
void EXIT();

airplane airp;

//######################################################################################################### start()

void start()
{
	bool click = false;
	int x_co, y_co;
	clearmouseclick(WM_LBUTTONDOWN);

	while(true)
	{ 
		int x=rand()%100;
		if(x<=40)
		{
			airp.obj_tofile();
			airp.statusmod();
		}

		airp.freer();

		getmouseclick(WM_LBUTTONDOWN, x_co, y_co);

		if(x_co>=95 && x_co<=572 && y_co>=77 && y_co<=125)
			View_Notifications();
		else if(x_co>=95 && x_co<=572 && y_co>=177 && y_co<=225)
			airplane_status();
		else if(x_co>=95 && x_co<=520 && y_co>=277 && y_co<=325)
			gate_status();
		else if(x_co>=95 && x_co<=755 && y_co>=377 && y_co<=425)
			baggage_claim_status();
		else if(x_co>=95 && x_co<=260 && y_co>=477 && y_co<=525)
			search();
		else if(x_co>=95 && x_co<=208 && y_co>=577 && y_co<=625)
			EXIT();
	}
}

//######################################################################################################### disp_menu()

void disp_menu()
{ 
     settextstyle(8,0,2);
     char str1[5];
     str1[0]='(';
     str1[3]=')';
     str1[2]=counter%10+48;
     str1[1]=counter/10+48;
     str1[4]='\0';
	cleardevice();

	settextstyle(8, 0, 5);
	setcolor(YELLOW);
	outtextxy(450, 20, "ATCAS");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	//Boxes
	outtextxy(575,70,str1);
	setfillstyle(SOLID_FILL, rand()%15+1);
	bar(95, 77, 572, 125);
	setfillstyle(SOLID_FILL, rand()%15+1);
	bar(95, 177, 572, 225);
	setfillstyle(SOLID_FILL, rand()%15+1);
	bar(95, 277, 520, 325);
	setfillstyle(SOLID_FILL, rand()%15+1);
	bar(95, 377, 755, 425);
	setfillstyle(SOLID_FILL, rand()%15+1);
	bar(95, 477, 260, 525);
	setfillstyle(SOLID_FILL, rand()%15+1);
	bar(95, 577, 208, 625);


	settextstyle(8, 0, 5);
	outtextxy(100, 80, "View Notifications");
	outtextxy(100, 180, "View Flight Status");
	outtextxy(100, 280, "View Gate Status");
	outtextxy(100, 380, "View Baggage Claim Status");
	outtextxy(100, 480, "Search");
	outtextxy(100, 580, "Exit");
	settextstyle(8, 0, 2);

	start();
}

//######################################################################################################### View_Notifications()

void View_Notifications()
{
	cleardevice();
	airp.initcounter();
	settextstyle(8, 0, 1);
	setcolor(LIGHTBLUE);
	outtextxy(525, 680, "Press 'Backspace' to go back to main menu.");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	char c[2], *str;
	int i = 0;
	str[0] = '\0';
	c[1] = '\0';

	ifstream ifile("notifications.txt");
	while(ifile)
	{
		ifile.getline(str, 100, '\n');
		if(ifile.eof())
			break;
		outtextxy(100, 100+i, str);
		i+=30;

		if(i>=500)
			break;

	}
	ifile.close();

	ofstream ofile("notifications.txt", ios::out);
	ofile.close();

	char choice = '\0';
	while(choice == '\0')
	{
		choice = getch();
		if(choice == '\b')
			disp_menu();
		else
			choice = '\0';
	}
}

//######################################################################################################### gate_status()

void gate_status()
{
	cleardevice();

	settextstyle(8, 0, 1);
	setcolor(LIGHTBLUE);
	outtextxy(525, 680, "Press 'Backspace' to go back to main menu.");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	int i=0;
	gate obj;
    char str[7],str2[7];
	ifstream ifile("gates.dat");

	settextstyle(8, 0, 4);
	setcolor(YELLOW);
	outtextxy(350, 40, "Gate Status");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	outtextxy(90, 100, "Logo");
	outtextxy(200, 100, "Gate No.");
	outtextxy(450, 100, "Flight Number");
	outtextxy(700, 100, "Status");

	setcolor(YELLOW);
	line(80, 80, 950, 80);
	line(80, 135, 950, 135);
	line(80, 650, 950, 650);

	line(80, 80, 80, 650);
	line(190, 80, 190, 650);
	line(440, 80, 440, 650);
	line(690, 80, 690, 650);
	line(950, 80, 950, 650);
	setcolor(WHITE);

	while(ifile)
	{
		char x[20], y[7], z[30];
		ifile.read((char*)&obj, sizeof(obj));

		if(ifile.eof())
			break;

		obj.get_gatename(x);
		obj.get_airplaneno(y);
		obj.get_status(z);
		obj.get_airplaneno(str2);

		str[0]=str2[0];
		str[1]=str2[1];
		str[2]='.';
		str[3]='b';
		str[4]='m';
		str[5]='p';
		str[6]='\0';
		readimagefile(str, 90, 150+i,2,170+i);

		outtextxy(200, 150+i, x);
		outtextxy(450, 150+i, y);

		if(!(strcmp(z, "AVAILABLE")))
			setcolor(GREEN);
		else if(!(strcmp(z, "IN USE")))
			setcolor(RED);
		else 
			setcolor(YELLOW);	

		outtextxy(700, 150+i, z);
		setcolor(WHITE);
		i+=35;
	}
	ifile.close();

	char choice = '\0';
	while(choice == '\0')
	{
		choice = getch();
		if(choice == '\b')
			disp_menu();
		else
			choice = '\0';
	}
}

//######################################################################################################### baggage_claim_Status()

void baggage_claim_status()
{
    char str2[7];
    char str[7];
	cleardevice();

	settextstyle(8, 0, 1);
	setcolor(LIGHTBLUE);
	outtextxy(525, 680, "Press 'Backspace' to go back to main menu.");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	int i=0;
	baggage_claim obj;

	settextstyle(8, 0, 4);
	setcolor(YELLOW);
	outtextxy(300, 40, "Baggage Claim Status");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	setcolor(YELLOW);
	line(80, 80, 950, 80);
	line(80, 135, 950, 135);
	line(80, 650, 950, 650);

	line(80, 80, 80, 650);
	line(190, 80, 190, 650);
	line(440, 80, 440, 650);
	line(690, 80, 690, 650);
	line(950, 80, 950, 650);
	setcolor(WHITE);

	ifstream ifile("bclaim.dat");
	outtextxy(90, 100, "Logo");
	outtextxy(200, 100, "Baggage claim No.");
	outtextxy(450, 100, "Flight Number");
	outtextxy(700, 100, "Status");
	while(ifile)
	{
		char x[20], y[7], z[30];
		ifile.read((char*)&obj, sizeof(obj));

		if(ifile.eof())
			break;

		obj.get_name(x);
		obj.get_airplaneno(y);
		obj.get_status(z);
		obj.get_airplaneno(str2);

		str[0]=str2[0];
		str[1]=str2[1];
		str[2]='.';
		str[3]='b';
		str[4]='m';
		str[5]='p';
		str[6]='\0';
		readimagefile(str, 90, 150+i,2,170+i);
		outtextxy(200, 150+i, x);
		outtextxy(450, 150+i, y);

		if(!(strcmp(z, "AVAILABLE")))
			setcolor(GREEN);
		else if(!(strcmp(z, "IN USE")))
			setcolor(RED);
		else 
			setcolor(YELLOW);	

		outtextxy(700, 150+i, z);
		setcolor(WHITE);
		i+=35;
	}
	ifile.close();

	char choice = '\0';
	while(choice == '\0')
	{
		choice = getch();
		if(choice == '\b')
			disp_menu();
		else
			choice = '\0';
	}
}

//######################################################################################################### airplane_status()

void airplane_status()
{
	cleardevice();

	settextstyle(8, 0, 1);
	setcolor(LIGHTBLUE);
	outtextxy(525, 680, "Press 'Backspace' to go back to main menu.");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	int i=0;
	airplane obj;

	setcolor(WHITE);
    char str[7],str2[7];
	ifstream ifile("flights.dat");

	settextstyle(8, 0, 4);
	setcolor(YELLOW);
	outtextxy(350, 40, "Flight Status");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	setcolor(YELLOW);
	line(80, 80, 950, 80);
	line(80, 135, 950, 135);
	line(80, 650, 950, 650);

	line(80, 80, 80, 650);
	line(190, 80, 190, 650);
	line(390, 80, 390, 650);
	line(690, 80, 690, 650);
	line(950, 80, 950, 650);
	setcolor(WHITE);

	outtextxy(90, 100, "Logo");
	outtextxy(200, 100, "Flight Number");
	outtextxy(400, 100, "Status");
	outtextxy(700, 100, "Destination");
	while(ifile)
	{
		char w[7], x[25], z[50];
		ifile.read((char*)&obj, sizeof(obj));

		if(ifile.eof())
			break;

		obj.get_flight_no(w);
		obj.get_status(x);
		obj.get_destination(z);

		obj.get_flight_no(str2);
		str[0]=str2[0];
		str[1]=str2[1];
		str[2]='.';
		str[3]='b';
		str[4]='m';
		str[5]='p';
		str[6]='\0';
		readimagefile(str, 90, 150+i, 2, 170+i);
		

		outtextxy(200, 150+i, w);
		outtextxy(400, 150+i, x);
		outtextxy(700, 150+i, z);
		
		i+=35;
	}
	ifile.close();

	char choice = '\0';
	while(choice == '\0')
	{
		choice = getch();
		if(choice == '\b')
			disp_menu();
		else
			choice = '\0';
	}
}

//######################################################################################################### search()

void search()
{
    char ch;

    cleardevice();

    settextstyle(8, 0, 1);
	setcolor(LIGHTBLUE);
	outtextxy(525, 680, "Press 'Backspace' to go back to main menu.");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

    settextstyle(8, 0, 5);
    outtextxy(100, 100, "1. Search by aircompany");
    outtextxy(100, 250, "2. Search by destination");
    outtextxy(100, 400, "3. Search by status");
    settextstyle(8, 0, 2);

    char choice = '\0';
    while(choice == '\0')
    {
        choice = getch();
        if(choice == '\b')
            disp_menu();
        else if(choice == '1')
        	Search_by_aircompany();
        else if(choice == '2')
        	Search_by_destination();
        else if(choice == '3')
        	Search_by_status();
        else
            choice = '\0';
    }   
}

//######################################################################################################### Search_by_aircompany()

void Search_by_aircompany()
{
	cleardevice();

    settextstyle(8, 0, 1);
	setcolor(LIGHTBLUE);
	outtextxy(525, 680, "Press 'Backspace' to go back to Search.");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	outtextxy(100, 100, "a. American Airlines");
	outtextxy(100, 150, "b. Air India");
	outtextxy(100, 200, "c. British Airways");
	outtextxy(100, 250, "d. Air Canada");
	outtextxy(100, 300, "e. Cathay Pacific");
	outtextxy(100, 350, "f. Emirates");
	outtextxy(100, 400, "g. Air France");
	outtextxy(100, 450, "h. Lufthansa");
	outtextxy(100, 500, "i. Singapore Airlines");
	outtextxy(100, 550, "j. Thai");

	char str[3];

	char choice = '\0';
    while(choice == '\0')
    {
        choice = getch();
        if(choice == '\b')
            search();
        else if(choice == 'a')
        	strcpy(str, "AA");
        else if(choice == 'b')
        	strcpy(str, "AI");
        else if(choice == 'c')
        	strcpy(str, "BA");
        else if(choice == 'd')
        	strcpy(str, "CA");
        else if(choice == 'e')
	        strcpy(str, "CP");
	    else if(choice == 'f')
	        strcpy(str, "EM");
	    else if(choice == 'g')
	        strcpy(str, "FR");
	    else if(choice == 'h')
	        strcpy(str, "LU");
	    else if(choice == 'i')
	        strcpy(str, "SA");
	    else if(choice == 'j')
	        strcpy(str, "TA");
        else
        {
            choice = '\0';  
            continue;      	
        }

        cleardevice();

		settextstyle(8, 0, 1);
		setcolor(LIGHTBLUE);
		outtextxy(350, 680, "Press 'Backspace' to go back to Search by aircompany.");
		settextstyle(8, 0, 2);
		setcolor(WHITE);

	    //Table
	    settextstyle(8, 0, 4);
	    setcolor(YELLOW);
	    outtextxy(350, 40, "Flight Status");
	    settextstyle(8, 0, 2);
	    setcolor(WHITE);

	    setcolor(YELLOW);
	    line(80, 80, 950, 80);
	    line(80, 135, 950, 135);
	    line(80, 650, 950, 650);

	    line(80, 80, 80, 650);
	    line(190, 80, 190, 650);
	    line(390, 80, 390, 650);
	    line(690, 80, 690, 650);
	    line(950, 80, 950, 650);
	    setcolor(WHITE);

	    outtextxy(90, 100, "Logo");
	    outtextxy(200, 100, "Flight Number");
	    outtextxy(400, 100, "Status");
	    outtextxy(700, 100, "Destination");

	    airplane a;
        ifstream ifile("flights.dat");

        int i=0;
        while(ifile)
        {
            ifile.read((char*)&a,sizeof(a));

            if(ifile.eof())
                break;

            
            if((a.flight_no[0]==str[0])&&(a.flight_no[1]==str[1]))
            {
                setcolor(WHITE);
                char str[7],str2[7];

                strcpy(str2, a.flight_no);
                str[0]=str2[0];
                str[1]=str2[1];
                str[2]='.';
                str[3]='b';
                str[4]='m';
                str[5]='p';
                str[6]='\0';
                readimagefile(str, 90, 150+i, 2, 170+i);
                
                outtextxy(200, 150+i, a.flight_no);
                outtextxy(400, 150+i, a.status);
                outtextxy(700, 150+i, a.destination);
                
                i+=35;
            }
        }
        ifile.close();

        char s = '\0';
        while(s == '\0')
        {
        	s = getch();
        	if(s == '\b')
        		Search_by_aircompany();
        	else
        		s = '\0';
        }
    }
}

//######################################################################################################### Search_by_destination()

void Search_by_destination()
{
    cleardevice();

    settextstyle(8, 0, 1);
	setcolor(LIGHTBLUE);
	outtextxy(525, 680, "Press 'Backspace' to go back to Search.");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	outtextxy(100, 100, "a. New Delhi");
	outtextxy(100, 150, "b. Mumbai");
	outtextxy(100, 200, "c. Chennai");
	outtextxy(100, 250, "d. Kolkata");
	outtextxy(100, 300, "e. London");
	outtextxy(100, 350, "f. Singapore");
	outtextxy(100, 400, "g. New York");
	outtextxy(100, 450, "h. Barcelona");
	outtextxy(100, 500, "i. Paris");
	outtextxy(100, 550, "j. Rio De Janeiro");

	char str[50];

	char choice = '\0';
    while(choice == '\0')
    {
        choice = getch();
        if(choice == '\b')
            search();
        else if(choice == 'a')
        	strcpy(str, "New Delhi");
        else if(choice == 'b')
        	strcpy(str, "Mumbai");
        else if(choice == 'c')
        	strcpy(str, "Chennai");
        else if(choice == 'd')
        	strcpy(str, "Kolkata");
        else if(choice == 'e')
	        strcpy(str, "London");
	    else if(choice == 'f')
	        strcpy(str, "Singapore");
	    else if(choice == 'g')
	        strcpy(str, "New York");
	    else if(choice == 'h')
	        strcpy(str, "Barcelona");
	    else if(choice == 'i')
	        strcpy(str, "Paris");
	    else if(choice == 'j')
	        strcpy(str, "Rio De Janeiro");
        else
        {
            choice = '\0';  
            continue;      	
        }

        cleardevice();

		settextstyle(8, 0, 1);
		setcolor(LIGHTBLUE);
		outtextxy(350, 680, "Press 'Backspace' to go back to Search by Destination.");
		settextstyle(8, 0, 2);
		setcolor(WHITE);

	    //Table
	    settextstyle(8, 0, 4);
	    setcolor(YELLOW);
	    outtextxy(350, 40, "Flight Status");
	    settextstyle(8, 0, 2);
	    setcolor(WHITE);

	    setcolor(YELLOW);
	    line(80, 80, 950, 80);
	    line(80, 135, 950, 135);
	    line(80, 650, 950, 650);

	    line(80, 80, 80, 650);
	    line(190, 80, 190, 650);
	    line(390, 80, 390, 650);
	    line(690, 80, 690, 650);
	    line(950, 80, 950, 650);
	    setcolor(WHITE);

	    outtextxy(90, 100, "Logo");
	    outtextxy(200, 100, "Flight Number");
	    outtextxy(400, 100, "Status");
	    outtextxy(700, 100, "Destination");

		airplane a;
        char temp[50];
        ifstream ifile("flights.dat");

        int i=0;
        while(ifile)
        {
            ifile.read((char*)&a,sizeof(a));

            if(ifile.eof())
                break;

            
            strcpy(temp,a.destination);   
            if(strcmp(temp,str)==0)
            {
                setcolor(WHITE);
                char str[7],str2[7];

                strcpy(str2, a.flight_no);
                str[0]=str2[0];
                str[1]=str2[1];
                str[2]='.';
                str[3]='b';
                str[4]='m';
                str[5]='p';
                str[6]='\0';
                readimagefile(str, 90, 150+i, 2, 170+i);
                
                outtextxy(200, 150+i, a.flight_no);
                outtextxy(400, 150+i, a.status);
                outtextxy(700, 150+i, a.destination);
                
                i+=35;
            }   
        }
        ifile.close();

        char s = '\0';
        while(s == '\0')
        {
        	s = getch();
        	if(s == '\b')
        		Search_by_destination();
        	else
        		s = '\0';
        }
    }
}

//######################################################################################################### Search_by_status()

void Search_by_status()
{
    cleardevice();

    settextstyle(8, 0, 1);
	setcolor(LIGHTBLUE);
	outtextxy(525, 680, "Press 'Backspace' to go back to Search.");
	settextstyle(8, 0, 2);
	setcolor(WHITE);

	outtextxy(100, 100, "a. ARRIVING");
	outtextxy(100, 150, "b. TAXIING FROM ARRIVAL");
	outtextxy(100, 200, "c. DEBOARDING");
	outtextxy(100, 250, "d. REFUELLING");
	outtextxy(100, 300, "e. TAXIING FOR DEPARTURE");
	outtextxy(100, 350, "f. HOLD SHORT RUNWAY");
	outtextxy(100, 400, "g. DEPARTED");

	char str[25];

	char choice = '\0';
    while(choice == '\0')
    {
        choice = getch();
        if(choice == '\b')
            search();
        else if(choice == 'a')
        	strcpy(str, "ARRIVING");
        else if(choice == 'b')
        	strcpy(str, "TAXIING FROM ARRIVAL");
        else if(choice == 'c')
        	strcpy(str, "DEBOARDING");
        else if(choice == 'd')
        	strcpy(str, "REFUELLING");
        else if(choice == 'e')
	        strcpy(str, "TAXIING FOR DEPARTURE");
	    else if(choice == 'f')
	        strcpy(str, "HOLD SHORT RUNWAY");
	    else if(choice == 'g')
	        strcpy(str, "DEPARTED");
        else
        {
            choice = '\0';  
            continue;      	
        }

        cleardevice();

		settextstyle(8, 0, 1);
		setcolor(LIGHTBLUE);
		outtextxy(350, 680, "Press 'Backspace' to go back to Search by Status.");
		settextstyle(8, 0, 2);
		setcolor(WHITE);

	    //Table
	    settextstyle(8, 0, 4);
	    setcolor(YELLOW);
	    outtextxy(350, 40, "Flight Status");
	    settextstyle(8, 0, 2);
	    setcolor(WHITE);

	    setcolor(YELLOW);
	    line(80, 80, 950, 80);
	    line(80, 135, 950, 135);
	    line(80, 650, 950, 650);

	    line(80, 80, 80, 650);
	    line(190, 80, 190, 650);
	    line(390, 80, 390, 650);
	    line(690, 80, 690, 650);
	    line(950, 80, 950, 650);
	    setcolor(WHITE);

	    outtextxy(90, 100, "Logo");
	    outtextxy(200, 100, "Flight Number");
	    outtextxy(400, 100, "Status");
	    outtextxy(700, 100, "Destination");

        airplane a;
        ifstream ifile("flights.dat");

        int i=0;
        while(ifile)
        {
            ifile.read((char*)&a,sizeof(a));

            if(ifile.eof())
                break;

            
            if(strcmp(a.status,str)==0)
            {
                setcolor(WHITE);
                char str[7],str2[7];

                strcpy(str2, a.flight_no);
                str[0]=str2[0];
                str[1]=str2[1];
                str[2]='.';
                str[3]='b';
                str[4]='m';
                str[5]='p';
                str[6]='\0';
                readimagefile(str, 90, 150+i, 2, 170+i);
                
                outtextxy(200, 150+i, a.flight_no);
                outtextxy(400, 150+i, a.status);
                outtextxy(700, 150+i, a.destination);
                
                i+=35;
            }
        }
        ifile.close();

        char s = '\0';
        while(s == '\0')
        {
        	s = getch();
        	if(s == '\b')
        		Search_by_status();
        	else
        		s = '\0';
        }
    }
}

//######################################################################################################### EXIT()

void EXIT()
{
	cleardevice();

	setcolor(YELLOW);
	settextstyle(8, 0, 7);
	outtextxy(380, 80, "CREDITS");

	settextstyle(8, 0, 4);
	outtextxy(100, 200, "Designed by:");

	outtextxy(150, 250, "Ashwin Joisa");
	outtextxy(150, 300, "Daivat Bhatt");
	outtextxy(150, 350, "Sagar B Manjunath");

	settextstyle(8, 0, 6);
	outtextxy(300, 500, "THANK YOU !!!");

	settextstyle(8, 0, 2);
	setcolor(LIGHTBLUE);
	outtextxy(730, 670, "Press any key to exit.");

	char a = getch();
	exit(0);
}