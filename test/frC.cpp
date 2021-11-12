#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("table.txt");

    char mytext;

    file >> mytext;
    printf("%c", mytext);

    file >> mytext;
    printf("%c", mytext);


    file.close();
    return 0;
}
