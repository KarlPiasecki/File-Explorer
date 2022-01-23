#include <iostream>
#include <gtest/gtest.h>
#include "FileExplorer.h"

namespace fs = std::filesystem;

//Note: create the directories and files for testing by running the main executable before testing

//Test the countFiles() function
TEST(Test_FileExplorer, test_countFiles){

    string directory = "Directory";
    int fileCount = 0;
    
    for(auto & p: fs::recursive_directory_iterator(directory)){
        ifstream file(p.path().c_str());
        fs::directory_entry f = p;
        fileCount ++;
    }

    EXPECT_EQ(fileCount, 4);
}

//Test the countLines() function
TEST(Test_FileExplorer, test_countLines){

    string line;
    string directory = "Directory";
    int totalLineCount = 0;
    
    for(auto & p: fs::recursive_directory_iterator(directory)){
        ifstream file(p.path().c_str());
        fs::directory_entry f = p;
        
        if(f.fs::directory_entry::is_regular_file()){
            while(getline(file, line)){
                totalLineCount ++;
            }
        }
    }

    EXPECT_EQ(totalLineCount, 7);
}



int main(int argc, char **argv){

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
