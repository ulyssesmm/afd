#ifndef __AFD_HPP__
#define __AFD_HPP__

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#include "tokens.hpp"

class Afd{
public:
    Afd()=default;
    Afd(string filename);
    ~Afd()=default;
    TOKEN yylex();
    string get_token_value();
    void error(string msg);
private:
    // TODO: Agregar variables para contar las líneas del archivo
    ifstream file;
    string token_value;
    char c;
    int edo;
    map<int, map<int, int>> afd;
    map<char, int> cols;
    vector<int, bool> accept;
    char get_char();
    void open_file(string filename);    
    void close_file();
};
#endif