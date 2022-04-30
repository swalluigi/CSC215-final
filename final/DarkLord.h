#pragma once
#include "Enemy.h"//includes the enemy header
#include <iostream>//includes the iostream library
#include<cstring>//includes the cstring library
#include<string>//includes the string library
#include <stdlib.h>// includes the stdlib.h
#include<ctime>// includes the ctime library

using namespace std;// includes the std namespace

class DarkLord : public enemy {//declares the Dark Lord enemy subclass
public: DarkLord(string name, string Element) : enemy(name, Element) {
    health = 50;
    physicalDamage = 10;
    magicDamage = 12;
    monsterAbility = "Weaken"; //gives the enemy the "Weaken" ability


}

};