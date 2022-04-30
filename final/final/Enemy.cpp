#include "Enemy.h" // includes the enemy header

 enemy::enemy(string name, string Element) {
        string ebility = this -> ElementAbility(Element);
        string MonAb = "none";
        int HP = 0;
        int Mdmg = 0;
        int Pdmg = 0;
        int burnDmg = 2;



        //substantiations
        this->name = name;
        this->health = HP;
        this->element = Element;
        this->elementalAbility = ebility;
        this->BurnDamage = burnDmg;
        this->physicalDamage = Pdmg;
        this->magicDamage = Mdmg;
        this->monsterAbility = MonAb;



    }
  string enemy:: gethobby() {//gets the hobby variable out of the private section of the class
        return this->hobby;
    }
    void enemy :: setHobby(string h) {//sets the hobby of the enemy
        this->hobby = h;
    }

    string enemy::ElementAbility(string element) {//deterimes teh elemental ability
        string ebility;
        if (element == "ice") {
            ebility = "Freeze";
        }

        else if (element == "fire") {
            ebility = "Burn";
        }


        else {
            ebility = "nothing";
        }

        return ebility;
    }