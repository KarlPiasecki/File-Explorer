#ifndef FileExplorer_H
#define FileExplorer_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

void createDirectory();

void printResults();

int countFiles(string directory);

int countLines(string directory);


#endif