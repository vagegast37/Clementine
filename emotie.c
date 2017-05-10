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

void emotievraag(void)
{
	//lees conditie
	ifstream check;
	check.open("emotie.txt", fstream::app);
	string cijver, ttemp;
	check >> ttemp;
	cijver = woord(ttemp, 1);
	check.close();
	//vind passende emotie
	ifstream zoek;
	string tempp;
	zoek.open("emotieO.txt", fstream::app);
	while (zoek >> tempp)
	{
		if (woord(tempp, 2) == cijver){
			replace(tempp.begin(), tempp.end(), '_', ' ');
			cout << woord(tempp, 1) << endl;
			zoek.close();
			return;
		}
	}
	zoek.close();
}

int emotievraagcheck(string vraag)//kijkt of de vraag vraagd naar emotie en revereerd naar emotievraag()
{
	ifstream check;
	check.open("emotievragen.txt", fstream::app);
	string cttemp;
	while (check >> cttemp)
	{
		replace(vraag.begin(), vraag.end(), ' ', '_');
		if (woord(cttemp, 1) == vraag)
		{
			check.close();
			emotievraag();
			return 1;
		}
	}
	check.close();
	return 0;
}
