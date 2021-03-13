#include <iostream>
#include <vector>

class Character {
    private:
        std::string name;
        int attackPower;
        int magicPower;
        int defense;
        int health;
        int mana;

        std::vector<std::string> abilities;

    public:
        Character(std::string n, int a, int magic, int d, int hp, int mp);

        // Accessors
        std::string getName();
        int getAttackPower();
        int getMagicPower();
        int getDefense();
        int getHealth();
        int getMana();

        // Mutators
        void setName(std::string n);
        void setAttackPower(int a);
        void setMagicPower(int m);
        void setDefense(int d);
        void setHealth(int h);
        void setMana(int m);

        // Utility
        void addAbility(std::string ability);
        void attack();
        void defend();
        void cast();
        void heal();
};