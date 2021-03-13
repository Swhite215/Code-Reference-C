#include <iostream>
#include <vector>
#include "Character.h"

// Constructor
Character::Character(std::string n, int a, int magic, int d, int hp, int mp){
    name = n;
    attackPower = a;
    magicPower = magic;
    defense = d;
    health = hp;
    mana = mp;
};

// Accessors
std::string Character::getName() { return name; }
int Character::getAttackPower() { return attackPower; }
int Character::getMagicPower() { return magicPower; }
int Character::getDefense() { return defense; }
int Character::getHealth() { return health; }
int Character::getMana() { return mana; }

// Mutators
void Character::setName(std::string n) { name = n; }
void Character::setAttackPower(int a) { attackPower = a; }
void Character::setMagicPower(int m) { magicPower = m; }
void Character::setDefense(int d) { defense = d; }
void Character::setHealth(int h) { health = h; }
void Character::setMana(int m) { mana = m; }

// Utility
void Character::addAbility(std::string ability) {
    abilities.push_back(ability);
}

// Abilities
void Character::attack() { std::cout<<"ATTACK"<<std::endl; }
void Character::defend() { std::cout<<"DEFEND"<<std::endl; }
void Character::cast() { std::cout<<"CAST"<<std::endl; }
void Character::heal() { std::cout<<"HEAL"<<std::endl; }