#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream myfile("table.txt");

    std::string mytext;

    while ( getline(myfile, mytext) ) {

        printf("%s\n", mytext.c_str());

    }


    myfile.close();
    return 0;
}
