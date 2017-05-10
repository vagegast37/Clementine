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

//I is input, de vraag die je krijgd is input. O is output de vroeeg word geuitput
void Iinspectie(string vraag)// krijgd een vraag en bepaald of er een antwoord of een wedervraag word gesteld.
{
	int x = rand()%10;
	getline(cin, vraag);
	if (x > 4)
	{
		//OFantwoord(vraag);// er word een antwoord gegeven op de vraag.
	}
	else
	{
		//OFvraag(vraag);//er wordd gevraagd waarom die vrag er is.
	}
}

void Oinspectie(string vraag)
{
	int x = rand();
	getline(cin, vraag);
	if (x = 0)
	{
		//antwoord(vraag);
	}
	else
	{
		//Fvraag(vraag);
	}
}
//nivo 1
void IFantwoord(string vraag)
{

}

void IFvraag(string vraag)
{

}

void OFantwoord(string vraag)
{

}

void OFvraag(string vraag)
{

}
//nivo 2
void Ireactie()
{

}

void IRreactie()
{

}

void IFFvraag()
{

}

void Oreactie()
{

}

void ORreactie()
{

}

void OFFvraag()
{

}

void map(string mapnaam)
{
	ofstream out(mapnaam + "/filesmt.txt");
	if (out.is_open())
	{
	out << "dit is text" << endl;
	out.close();
	cout << "het is gelukt" << endl;
	}
	else
	{
		cout << "no dir" << endl;
	}
}
