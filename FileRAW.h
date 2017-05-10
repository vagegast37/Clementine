#ifndef _FILERAW_H_ // Include Guards
#define _FILERAW_H_ 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <ctime>
#include <Windows.h>
#include <algorithm>
using namespace std;

// Function prototypes
extern void save(string name, string data);
extern int aantal(string lib);
extern string woord(string zin, int N);
extern void willekeurig(string name);

#endif 
