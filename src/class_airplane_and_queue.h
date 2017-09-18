#include <iostream>
#include <string.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <graphics.h>
#include <fstream>
using namespace std;

int counter=0;
void initcounter()
{
	 char str[100];
	 int i=0;
	 ifstream ifile("notifications.txt");
	while(ifile)
	{
		ifile.getline(str, 100, '\n');
		if(ifile.eof())
			break;
		i++;
  }
	ifile.close();
	if(i>17)
	counter=17;
	else
	counter=i;
}
	
class gate
{
	public:
	char gatename[20], airplaneno[7], status[30];
public:
	void get_gatename(char c[])
	{
		strcpy(c, gatename);
	}
	void get_airplaneno(char c[])
	{
		strcpy(c, airplaneno);
	}
	void get_status(char c[])
	{
		strcpy(c, status);
	}
};

class baggage_claim
{
public:
	char cname[20], airplaneno[7], status[30];
public:
	void get_name(char c[])
	{
		strcpy(c, cname);
	}
	void get_airplaneno(char c[])
	{
		strcpy(c, airplaneno);
	}
	void get_status(char c[])
	{
		strcpy(c, status);
	}
};

//gate_front = gate_rear = departure_front = departure_rear = NULL;

//######################################################################################################### Airplane class

class airplane:public gate, public baggage_claim
{
public:
	airplane()
	{
		int x, y;
		y=rand()%10+1;
		x=rand()%9000+1000;

		strcpy(status, "ARRIVING");
		switch(y){
			case 1:
				flight_no[0]='A';
				flight_no[1]='I';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			case 2:
				flight_no[0]='L';
				flight_no[1]='U';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			case 3:
				flight_no[0]='A';
				flight_no[1]='A';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			case 4:
				flight_no[0]='S';
				flight_no[1]='A';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			case 5:
				flight_no[0]='F';
				flight_no[1]='R';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			case 6:
				flight_no[0]='E';
				flight_no[1]='M';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			case 7:
				flight_no[0]='T';
				flight_no[1]='A';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			case 8:
				flight_no[0]='B';
				flight_no[1]='A';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			case 9:
				flight_no[0]='C';
				flight_no[1]='P';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			case 10:
				flight_no[0]='C';
				flight_no[1]='A';
				flight_no[2]=char(x%10+48);
				x/=10;
				flight_no[3]=char(x%10+48);
				x/=10;
				flight_no[4]=char(x%10+48);
				x/=10;
				flight_no[5]=char(x%10+48);
				flight_no[6]='\0';
				break;
			}

		x=int(rand()%10)+1;

		switch(x){
				case 1:
					strcpy(destination, "New Delhi");
					break;
				case 2:
					strcpy(destination, "Mumbai");
					break;
				case 3:
					strcpy(destination, "Chennai");
					break;
				case 4:
					strcpy(destination, "Kolkata");
					break;
				case 5:
					strcpy(destination, "London");
					break;
				case 6:
					strcpy(destination, "Singapore");
					break;
				case 7:
					strcpy(destination, "New York");
					break;
				case 8:
					strcpy(destination, "Barcelona");
					break;
				case 9:
					strcpy(destination, "Paris");
					break;
				case 10:
					strcpy(destination, "Rio De Janeiro");
					break;
			}
		}
public:
	char flight_no[7], status[25], destination[50];
public:
	void obj_tofile()
	{
		int x=rand()%100;

		int ctr=0;
		airplane airp;
		ifstream ifile("flights.dat");
		while(ifile)
		{
			ifile.read((char*)&airp,sizeof(airp));
			if(ifile.eof())
				break;
			ctr++;
		}
		ifile.close();

		if(x<=50 && ctr<14)
		{
			airplane obj;
			ofstream ofile("flights.dat", ios::app);
			ofile.write((char*)&obj, sizeof(obj));
			ofile.close();

			char str[5];
			ofstream fout("notifications.txt", ios::app);

			if(counter<17)
			{
				char strin[100];
				strcpy(strin, "Flight ");
				strcat(strin, obj.flight_no);
				strcat(strin," has ARRIVED.\n");

				for(int i=0; i<strlen(strin); i++)
					fout<<strin[i];

				counter++;
			}

			fout.close();
		}
	}
	void statusmod()
	{
	   char str1[5];
	   str1[0]='(';
	   str1[3]=')';
	   char strin[100];
		 airplane p;
		 int i;
	   ofstream note("notifications.txt", ios::app);
	   ifstream ifile("flights.dat");
	   ofstream ofile("flights2.dat");
	   while(ifile)
	   { 
			   strcpy(strin, "Flight ");

		   ifile.read((char*)&p,sizeof(p));

		   if(ifile.eof())
			break;
			
		strcat(strin, p.flight_no);
		   int x=rand()%100;

		   if(!(strcmp(p.status,"ARRIVING")))
		   {	
			if(x>=75)
			{
				 gate g;
				 bool found=false;
				 strcpy(p.status,"TAXIING FROM ARRIVAL");
				 
				 strcat(strin," has TAXIED FROM ARRIVAL.\n");
				 
				 if(counter<17)
				 {
					   counter++;
					   
					   str1[2]=counter%10+48;
					   str1[1]=counter/10+48;
					   str1[4]='\0';
					   settextstyle(8,0,2);
					   outtextxy(575,70,str1);
				}
				 
				 ifstream ifile2("gates.dat");
				 ofstream ofile2("gates2.dat");
				 while(ifile2)
				 {
					 ifile2.read((char*)&g,sizeof(g));

					 if(ifile2.eof())
							break;

					 if((strcmp(g.status,"AVAILABLE")==0)&&(found==false))
					 {     
						  strcpy(g.status,"IN USE");
						  strcpy(g.airplaneno,p.flight_no);
						  found=true;
					 }
					 ofile2.write((char*)&g,sizeof(g));
				 }
				 ofile2.close();
				 ifile2.close();
				 remove("gates.dat");
				 rename("gates2.dat","gates.dat");
			}
		   }             
		   else if(strcmp(p.status,"TAXIING FROM ARRIVAL")==0)
		   {
			if(x>=60)
			{
				 strcpy(p.status,"DEBOARDING");
				 
				 strcat(strin," has DEBOARDED.\n");
				 
				 if(counter<17)
				 {
							   counter++;
							   
							   str1[2]=counter%10+48;
							   str1[1]=counter/10+48;
							   str1[4]='\0';
							   settextstyle(8,0,2);
							   outtextxy(575,70,str1);
							   //settextstyle(8,0,2);
							   //cout<<str1<<endl;
							   }

				 baggage_claim b;
				 ifstream ifile2("bclaim.dat");
				 ofstream ofile2("bclaim2.dat");
				 bool found=false;
				 while(ifile2)
				 {
					 ifile2.read((char*)&b,sizeof(b));

					 if(ifile2.eof())
							break;

					 if(strcmp(b.status,"AVAILABLE")==0&&(found==false))
					 {
							strcpy(b.status,"IN USE");
							strcpy(b.airplaneno,p.flight_no);
							found=true;
					 }
					 ofile2.write((char*)&b,sizeof(b));
				 }
				 ifile2.close();
				 ofile2.close();
				 remove("bclaim.dat");
				 rename("bclaim2.dat","bclaim.dat");
			
			}
		}
				 
		  else if(strcmp(p.status,"DEBOARDING")==0)
		  {
			if(x>=92)
					{strcpy(p.status,"REFUELLING");
					strcat(strin," has REFUELLED.\n");
					if(counter<17)
				 {
							   counter++;
							   
							   str1[2]=counter%10+48;
							   str1[1]=counter/10+48;
							   str1[4]='\0';
							   settextstyle(8,0,2);
							   outtextxy(575,70,str1);
							   //settextstyle(8,0,2);
							   //cout<<str1<<endl;
							   }
				  }
					
		}
		   else if(strcmp(p.status,"REFUELLING")==0)
		   {
			
			if(x>=77)
			{
				 baggage_claim g;                            
				 strcpy(p.status,"BOARDING");
				 
				 strcat(strin," has foutISHED BOARDING.\n");
				 
				 if(counter<17)
				 {
							   counter++;
							   
							   str1[2]=counter%10+48;
							   str1[1]=counter/10+48;
							   str1[4]='\0';
							   settextstyle(8,0,2);
							   outtextxy(575,70,str1);
							   //settextstyle(8,0,2);
							   //cout<<str1<<endl;
							   }
				  
				 bool found=false;
				 int x;

				 ifstream ifile2("bclaim.dat");
				 ofstream ofile2("bclaim2.dat");

				 while(ifile2)
				 {
						x = rand()%20+1;
						ifile2.read((char*)&g,sizeof(g));

						if(ifile2.eof())
							break;

						if((strcmp(g.airplaneno,p.flight_no)==0)&&(found==false))
						{     
						  if(x<=5)
						  {
								strcpy(g.status,"UNDER MAINTENANCE");
								strcpy(g.airplaneno,"");
						  }   
						  else
						  {
							  strcpy(g.status,"AVAILABLE");
							  strcpy(g.airplaneno,"");
						  }
						  found=true;
					 }
					 ofile2.write((char*)&g,sizeof(g));
				 }  
				 ofile2.close();
				 ifile2.close();
				 remove("bclaim.dat");    
				 rename("bclaim2.dat","bclaim.dat");
										   
			 }
			}     
		   else if(strcmp(p.status,"BOARDING")==0)
		   {
	   
			if(x>=70)
			{
				 gate g;                            
				 strcpy(p.status,"TAXIING FOR DEPARTURE");
				 
				 strcat(strin," has TAXIED FOR DEPARTURE\n");
				 
				 if(counter<17)
				 {
							   counter++;
							   
							   str1[2]=counter%10+48;
							   str1[1]=counter/10+48;
							   str1[4]='\0';
							   settextstyle(8,0,2);
							   outtextxy(575,70,str1);
							   //settextstyle(8,0,2);
							   //cout<<str1<<endl;
							   }
				 
				 bool found=false;
				 int x;

				 ifstream ifile2("gates.dat");
				 ofstream ofile2("gates2.dat");
				 for(int i=0;i<14;i++)
				 {
							x =int(rand()%20)+1;
						  ifile2.read((char*)&g,sizeof(g));

						  if(ifile2.eof())
								break;

						  if((strcmp(g.airplaneno,p.flight_no)==0)&&(found==false))
						  {     
							   if(x<=5)
							   {
										strcpy(g.status,"UNDER MAINTENANCE");
										strcpy(g.airplaneno,"");
							   }   
							   else
							   {
										strcpy(g.status,"AVAILABLE");
										strcpy(g.airplaneno,"");
							   }
							   found=true;
						  }
						  ofile2.write((char*)&g,sizeof(g));
				 }
				 ofile2.close();
				 ifile2.close();
				 remove("gates.dat");
				 rename("gates2.dat","gates.dat");
				  
			 }
		  }
		   else if(strcmp(p.status,"TAXIING FOR DEPARTURE")==0)
		   {
			
			if(x>=80)
			{
				 strcpy(p.status,"HOLD SHORT RUNWAY");  
				 strcat(strin," is HOLDING SHORT OF RUNWAY.\n");
				 
				 if(counter<17)
				 {
							   counter++;
							   
							   str1[2]=counter%10+48;
							   str1[1]=counter/10+48;
							   str1[4]='\0';
							   settextstyle(8,0,2);
							   outtextxy(575,70,str1);
							   //settextstyle(8,0,2);
							   //cout<<str1<<endl;
							   }
			} 
		}
		   else if(strcmp(p.status,"HOLD SHORT RUNWAY")==0)
		   {
			
			if(x>=60)
			{
				 strcpy(p.status,"DEPARTED");
				 strcat(strin," has DEPARTED.\n");
				 if(counter<17)
				 {
							   counter++;
							   
							   str1[2]=counter%10+48;
							   str1[1]=counter/10+48;
							   str1[4]='\0';
							   settextstyle(8,0,2);
							   outtextxy(575,70,str1);
							   //settextstyle(8,0,2);
							   //cout<<str1<<endl;
				 }
			}
		}
		   else if(strcmp(p.status,"DEPARTED")==0)
		   {
				//strcat(strin," is taxiing from arrival\n");
				 continue;
		   }
		   ofile.write((char*)&p,sizeof(p));

		   for(int k=0;k<strlen(strin);k++)
		   {
			if(strin[13]!=' ')
				break;
			note<<strin[k];
		}
	   }
	   note.close();
	   ofile.close();
	   ifile.close();
	   remove ("flights.dat");
	   rename("flights2.dat","flights.dat");
	}
	void freer()
	{
		 baggage_claim b;
		 gate g;
		 int x = rand()%99+1;

		 ifstream ifile1("gates.dat");
		 ofstream ofile1("gates2.dat");
		 ifstream ifile2("bclaim.dat");
		 ofstream ofile2("bclaim2.dat");

		 for(int i=0;i<14;i++)
		 {
			ifile2.read((char*)&b,sizeof(b));
			ifile1.read((char*)&g,sizeof(g));
			if(!(strcmp(g.status,"UNDER MAINTENANCE"))&&(x<=40))
				strcpy(g.status,"AVAILABLE");
			if(!(strcmp(b.status,"UNDER MAINTENANCE"))&&(x>=60))
				strcpy(b.status,"AVAILABLE");
			ofile1.write((char*)&g,sizeof(g));
			ofile2.write((char*)&b,sizeof(b));
		 }
		 ofile2.close();
		 ifile2.close();
		 ofile1.close();
		 ifile1.close();
		 remove("gates.dat");
		 rename("gates2.dat","gates.dat");
		 remove("bclaim.dat");
		 rename("bclaim2.dat","bclaim.dat");
		 
	}
	void initcounter()
	{
		 counter=0;
 }
public:
	void get_flight_no(char c[])
	{
		strcpy(c, flight_no);
	}
	void get_status(char c[])
	{
		strcpy(c, status);
	}

	void get_destination(char c[])
	{
		strcpy(c, destination);
	}

};
