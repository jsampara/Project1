#include "RecruitDB.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Default Constructor
RecruitDB::RecruitDB() {}

// Copy Constructor
RecruitDB::RecruitDB(const RecruitDB &other) : recruits(other.recruits) {}

// Destructor
RecruitDB::~RecruitDB() {}

// Read recruits from a file
void RecruitDB::read_txt(const string &filename) {
    ifstream input(filename);
    if (!input) {
        cerr << "Error: Could not open file for reading!" << endl;
        return;
    }

    Recruit recruit;
    while (input.peek() != EOF) {
        recruit.read_txt(input);
        recruits.push_back(recruit);
    }

    input.close();
}

// Print recruits to a file
void RecruitDB::print_txt(const string &filename) const {
    ofstream output(filename);
    if (!output) {
        cerr << "Error: Could not open file for writing!" << endl;
        return;
    }

    for (const auto &recruit : recruits) {
        recruit.print_txt(output);
    }

    output.close();
}

// Search by state
void RecruitDB::searchState(const string &state) const {
    for (const auto &recruit : recruits) {
        if (recruit.getState() == state) {
            recruit.print();
        }
    }
}

// Search by school
void RecruitDB::searchSchool(const string &school) const {
    for (const auto &recruit : recruits) {
        if (recruit.getSchool() == school) {
            recruit.print();
        }
    }
}

// Search by stars
void RecruitDB::searchStars(const string &stars) const {
    for (const auto &recruit : recruits) {
        if (recruit.getStars() == stars) {
            recruit.print();
        }
    }
}

void RecruitDB::searchCity(const std::string& city) const {
    bool found = false;
    for (const auto& recruit : recruits) {
        if (recruit.getCity() == city) {
            recruit.print(); // Assuming `print()` prints all details of the recruit
            found = true;
        }
    }
    if (!found) {
        std::cout << "No recruits found in " << city << "." << std::endl;
    }
}

