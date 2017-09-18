#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
using namespace std;

void extern disp_menu();
void extern initcounter();
void main_page();

int main()
{
 	srand(time(0));
 	initcounter();
	initwindow(1000, 700, "ATCAS");
	main_page();
	disp_menu();
	system("pause");
}

void main_page()
{
 	 readimagefile("Cover.bmp", 0, 0, 1000, 700);
 	 int a = getch();
}

