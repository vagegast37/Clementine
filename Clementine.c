#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <ctime>
#include <Windows.h>
#include <algorithm>
#include "class2.h"
#include "FileRAW.h"
#include "emotie.h"
using namespace std;

void groetbegin(void) // neemt je groet, slaat hem op en geet een groet terug
{

	string begin;
	int B = 0;
	getline(cin, begin);
	begin = "&" + begin + "&";
	save("groet", begin);
	Sleep(1000);

	willekeurig("groet");
}

void antwoord(string input) // beantwoord je vraag dor een library te raadplegen of aan te vullen.
{
	if (input.find_last_of("?") < 10000) // het is een vraag
	{
		input = input.erase(input.size() - 1);
		if (emotievraagcheck(input) == 1){ return; }
		ifstream bieb;
		string naam = input + ".txt";
		bieb.open(naam);
		int num = aantal(input);
		srand(time(0));
		int up = num + 1;
		if (rand() % up + 1 > num) // input vragen
		{
			string Y;
			Sleep(1000);
			willekeurig("sorry");
			Sleep(1000);
			cout << input << "?" << endl;
			getline(cin, Y);
			Y = "&" + Y + "&";
			save(input, Y);
		}
		else // input geven
		{
			Sleep(1000);
			willekeurig(input);
		}
	}
	else
	{
		cout << "geen vraag" << endl;
	}
}

void main(void)//groet en wacht op vragen
{
	string cdf = { "emotie" };
	map(cdf);
	system("PAUSE");
	string vraag, antwoord1, antwoord2, antwoord3;
	groetbegin();
	Sleep(2000);
	while (1)
	{
		getline(cin, vraag);
		if (vraag == "exit"){ return; }
		antwoord(vraag);
	}
	system("PAUSE");
}
