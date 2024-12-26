#ifndef RECRUITDB_H
#define RECRUITDB_H

#include "Recruit.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class RecruitDB {
private:
    vector<Recruit> recruits;

public:
    // Default Constructor
    RecruitDB();

    // Copy Constructor
    RecruitDB(const RecruitDB &other);

    // Destructor
    ~RecruitDB();

    // Method to read recruits from a file
    void read_txt(const string &filename);

    // Method to print recruits to a file
    void print_txt(const string &filename) const;

    // Search methods
    void searchState(const string &state) const;
    void searchSchool(const string &school) const;
    void searchStars(const string &stars) const;
    void searchCity(const string& city) const; 

};

#endif // RECRUITDB_H
