#ifndef RECRUIT_H
#define RECRUIT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Recruit {
private:
    string name;
    string state;
    string school;
    string height;
    string stars;
    string city;
    // other private members

public:
    // Constructors, destructor, and other methods
    Recruit();
    Recruit(const Recruit &other);
    ~Recruit();
    
    void read_txt(ifstream &input);
    void print_txt(ofstream &output) const;
    void print() const; // Declaration of the print method

    // Getters
    string getState() const;
    string getSchool() const;
    string getStars() const;
    string getHeight() const;
    string getCity() const;
};

#endif
