#pragma once
#include <iostream>//include the iostream library
#include<cstring>//include the cstring library
#include<string>//include the string library
#include <stdlib.h>// indcludes the stdlib.h
#include<ctime>// includes the ctime library
using namespace std;// includes the std namespace




class enemy {//declares the enemy class
public:
    enemy(string name, string Element);
    
    string gethobby();//declares the gethobby function
    void setHobby(string h);//declares the setHobby function

public:
    int health;
    string name;
    string element;
    int BurnDamage;
    int physicalDamage;
    int magicDamage;
    string elementalAbility;
    string monsterAbility;

private:
    string hobby;
    string ElementAbility(string element);//declares the elementAbility function
};

