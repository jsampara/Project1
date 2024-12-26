#include "Recruit.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Default Constructor
Recruit::Recruit() : name(""), state(""), school(""), height(""), stars("") {}

// Copy Constructor
Recruit::Recruit(const Recruit &other)
    : name(other.name), state(other.state), school(other.school), height(other.height), stars(other.stars) {}

// Destructor
Recruit::~Recruit() {}

// Read Recruit information from an input file
void Recruit::read_txt(ifstream &input) {
    if (!input) {
        cerr << "Error: File not open!" << std::endl;
        return;
    }

    string line;
    // Skip the rank line
    getline(input, line);

    // Read Recruit details
    if (getline(input, name) &&
        getline(input, state) &&
        getline(input, school) &&
        getline(input, height) &&
        getline(input, stars)) {
        // Successfully read recruit data
    }

    // Skip the blank line between recruits
    getline(input, line);
}

// Print Recruit information to an output file
void Recruit::print_txt(ofstream &output) const {
    if (!output) {
        cerr << "Error: File not open!" << endl;
        return;
    }

    // Print Recruit details
    output << name << endl;
    output << state << endl;
    output << school << endl;
    output << height << endl;
    output << stars << endl;

    // Add a blank line between recruits
    output << endl;
}

// Print Recruit information to the standard output
void Recruit::print() const {
    cout << "Name: " << name << endl;
    cout << "State: " << state << endl;
    cout << "School: " << school << endl;
    cout << "Height: " << height << endl;
    cout << "Stars: " << stars << endl;
    cout << endl; // Add a blank line for better readability
}

// Getters
string Recruit::getState() const {
    return state;
}

string Recruit::getSchool() const {
    return school;
}

string Recruit::getStars() const {
    return stars;
}

string Recruit::getHeight() const {
    return height;
}

string Recruit::getCity() const {
    return city; 
}
