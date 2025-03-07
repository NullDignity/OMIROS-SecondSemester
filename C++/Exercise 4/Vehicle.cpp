#include "Vehicle.h"

Vehicle::Vehicle() { // DEFAULT CONSTRUCTOR
    setAll("Recon",30,1,1,1);
}

Vehicle::Vehicle(string id, int speed, int attack, int defense, int range) { // CUSTOM CONSTUCTOR
    setAll(id, speed, attack, defense, range);
}

Vehicle::Vehicle(Vehicle &existing_object) { // COPY CONSTRUCTOR
    setAll(existing_object.id, existing_object.speed, existing_object.attack, existing_object.defense, existing_object.range);
}

void Vehicle::setAll(string id, int speed, int attack, int defense, int range) {
    setId(id);
    setSpeed(speed);
    setAttack(attack);
    setDefense(defense);
    setRange(range);
}

void Vehicle::setId(string id) {
    if (id != "Recon" && id != "Light" && id != "Medium" && id != "Tank")
        this->id = "\0";
    else
        this->id = id;
}

void Vehicle::setSpeed(int speed) {
    if (speed < 30 || speed > 100)
        this->speed = 30;
    else
        this->speed = speed;
}

void Vehicle::setAttack(int attack) {
    if (attack < 1 || attack > 10)
        this->attack = 1;
    else
        this->attack = attack;
}

void Vehicle::setDefense(int defense) {
    if (defense < 1 || defense > 20)
        this->defense = 1;
    else
        this->defense = defense;
}

void Vehicle::setRange(int range) {
    if (range < 1 || range > 6)
        this->range = 1;
    else
        this->range = range;
}

string Vehicle::getId() const {
    return this->id;
}

int Vehicle::getSpeed() const {
    return this->speed;
}

int Vehicle::getAttack() const {
    return this->attack;
}

int Vehicle::getDefense() const {
    return this->defense;
}

int Vehicle::getRange() const {
    return this->range;
}

void Vehicle::print() const {
    cout << "Player Vehicle: " << getId() << endl;
    cout << "Player Speed: " << getSpeed() << endl;
    cout << "Player Attack: " << getAttack() << endl;
    cout << "Player Defense: " << getDefense() << endl;
    cout << "Player Range: " << getRange() << endl;
}

