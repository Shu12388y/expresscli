#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <direct.h>

#define SIZE 30

using namespace std;

/*
        create the project folder
    Builded the function that create the project directory
    argument will the foldername or "."
    if not passes throw error
*/


bool createStandardExpressApp(const std::string& dist);


bool createProjectDir(const char foldername[])
{
    if (strlen(foldername) > 0 && strcmp(foldername, ".") != 0)
    {
        std::string command = "mkdir ";
        command += foldername;
        if (system(command.c_str()) == 0)
        {
            int opt;
            cout << "1. Create a Standard express app \n";
            cout << "2. Create a Event driven express app \n";
            cout << "3. Create a serverless express app \n";
            cout << "Choose your option ";
            cin >> opt;
            if (opt == 1)
            {
                createStandardExpressApp(foldername);
            }
            }
        }
        else
        {
            std::cout << "Error creating folder." << std::endl;
        }
    }




bool createStandardExpressApp(const std::string& dist) {
    if (dist.empty()) {
        std::cerr << "Error: Destination path is empty." << std::endl;
        return false;
    }

    std::string command = "copy content\\server.js ";  // Notice the space after "server.js"
    command += dist;

    if (system(command.c_str()) == 0) {
        std::cout << "File copied successfully." << std::endl;
        return true;
    } else {
        std::cerr << "Error copying file." << std::endl;
        return false;
    }
}



int main()
{
    char filename[SIZE];
    cout << "Welcome to express-cli \n";
    cout << "Enter the project name: ";
    cin >> filename;

    // Check if the filename is not empty
    bool result = createProjectDir(filename);

    return 0;
}
