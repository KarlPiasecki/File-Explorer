#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <thread>
#include "FileExplorer.h"




/*
Create the application that will analyze and show statistics of specified directory that will handle recursive 
directories. It should print number of files and total number of lines (might as well count non-empty and empty 
lines). Provide unit tests for solutions.- Application should use multithreading (keep in mind system 
limitations, you might need to control number of concurrent calls, e.g., use thread pool).
- Use std::filesystem
- Use GTest for Unit Tests
- As a bonus, you could also count words and letters and provide performance benchmarks (e.g., measure the 
impact of using the different number of threads)
*/

using namespace std;
namespace fs = std::filesystem;

string line;
int lineCount = 0;
int totalLineCount = 0;
int fileCount = 0;


void createDirectory(){

    string directory = "Directory/";
    string anotherDirectory = "AnotherDirectory/";
    string thirdDirectory = "ThirdDirectory";

    fs::create_directories(directory + anotherDirectory + thirdDirectory);
    ofstream txtFile(directory + "txtFile.txt");
    txtFile << "line\n line\n line\n line";
    ofstream txtFile2(directory + anotherDirectory + "txtFile2.txt");
    txtFile2 << "line 1 \n line 2 \n line 3";
}

int countFiles(string dir){

    for(auto & p: fs::recursive_directory_iterator(dir)){
        ifstream file(p.path().c_str());
        fs::directory_entry f = p;
        fileCount ++;

        if (f.fs::directory_entry::is_directory()){
            cout << "File path: " << p.path() << endl;
            cout << "File type: directory" << endl << endl;
        } 
    }

    return fileCount;
}


int countLines(string directory){
    
    for (auto& p: fs::recursive_directory_iterator(directory)){
        ifstream file(p.path().c_str());
        fs::directory_entry f = p;
        lineCount = 0;

        if (f.fs::directory_entry::is_regular_file()){
            while(getline(file, line)){
                lineCount ++;
                totalLineCount ++;
            }
            cout << "File path: " << p.path() << endl;
            cout << "File type: regular file  |  " << "Number of lines: " << lineCount << endl << endl;
        }
    }

    return totalLineCount;
}

void printResults(){
    cout << "Total file count: " << fileCount << endl;
    cout << "Total line count: " << totalLineCount << endl;
}