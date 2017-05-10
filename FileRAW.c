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

string woord(string zin, int N){ // vind het Nste woord/zin van de zin
	char temp[70] = {};
	int v = 0;
	int found = -1;
	while (v < N)
	{
		found = zin.find("&", found + 1); v++;
	}
	int found2 = zin.find("&", found + 1);
	int leng = found2 - found - 1;
	zin.copy(temp, leng, found + 1);
	return(temp);
}

int aantal(string lib) //telt het aanwal zinnen in een library.
{
	string strTemp;
	int count = 0;
	lib = lib + ".txt";
	ifstream Text;
	Text.open(lib, fstream::app);
	while (Text >> strTemp)
	{
		if (woord(strTemp, 1) != "aslkdnlsnf"){
			count++;
		}
	}
	return count;
}

void save(string name, string data) // staat een woord,'data', op in de library 'name'
{
	string strTemp;
	int count = 0;
	name = name + ".txt";
	replace(data.begin(), data.end(), ' ', '_');
	ifstream Text;
	Text.open(name, fstream::app);
	while (Text >> strTemp)
	{
		if (woord(strTemp, 1) == woord(data, 1)){
			count++;
		}
	}
	if (count > 0){
		Text.close();
	}
	else{
		Text.close();
		ofstream File;
		File.open(name, fstream::app);
		File << data << endl;
		File.close();
	}
}

void willekeurig(string name) // neemt een willekeurige zin uit de libary 'name' en zet hem op het scherm.
{
	ifstream LIB;
	srand(time(0));
	int num = aantal(name), count = 0;
	int wil = rand() % num + 1;
	string naam = name + ".txt", strTemp;
	LIB.open(naam);
	while (LIB >> strTemp)
	{
		if (woord(strTemp, 1) != "aslkdnlsnf"){
			count++;
			if (count == wil)
			{
				replace(strTemp.begin(), strTemp.end(), '_', ' ');
				cout << woord(strTemp, 1) << endl;

			}
		}
		exit;
	}
	LIB.close();
}
