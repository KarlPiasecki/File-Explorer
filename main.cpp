#include <string>
#include <iostream>
#include <thread>
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>
#include "FileExplorer.h"

using namespace std;


int main(int argc, char const *argv[]){

    createDirectory(); //Used to create directories and text files for GTest testing

    string directory = argv[1];

    thread fileCounter(countFiles, directory);
    fileCounter.join();
    thread lineCounter(countLines, directory);
    lineCounter.join();

    printResults();

    return 0;
}