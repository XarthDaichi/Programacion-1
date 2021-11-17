#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Dado {
    private:
        int cara;
    public:
        Dado();
        virtual ~Dado();
        int rodar();  // movimiento aleatorio.
};
