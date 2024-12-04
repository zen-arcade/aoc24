#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>

int main(){
    int a = 0, b = 0;
    long mult_sum = 0;
    std::ifstream file("data.txt");
    std::stringstream data;
    data << file.rdbuf();

    std::string datastr = data.str();
    std::regex match("mul\\([0-9]*,[0-9]*\\)");
    std::regex_iterator<std::string::iterator> rit(datastr.begin(), datastr.end(), match);
    std::regex_iterator<std::string::iterator> rend;

    while(rit != rend){
        sscanf(rit->str().c_str(),"mul(%d,%d)", &a, &b);
        std::cout << rit->str() << "\n";
        mult_sum += a * b;
        rit++;
    }

    std::cout << "sum of all mults: " << mult_sum << "\n";
    return 0;
}