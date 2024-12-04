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
    bool enable = true;
    data << file.rdbuf();

    std::string datastr = data.str();
    std::string doit("do()");
    std::string dont("don't()");
    std::regex match("mul\\([0-9]*,[0-9]*\\)|do\\(\\)|don't\\(\\)");
    std::regex_iterator<std::string::iterator> rit(datastr.begin(), datastr.end(), match);
    std::regex_iterator<std::string::iterator> rend;

    while(rit != rend){
        if(rit->str() == dont){
            enable = false;
        } 
        else if(rit->str() == doit){
            enable = true;
        } else {
            sscanf(rit->str().c_str(),"mul(%d,%d)", &a, &b);
            if(enable) mult_sum += a * b;        
        }
        rit++;
    }

    std::cout << "sum of all mults: " << mult_sum << "\n";
    return 0;
}