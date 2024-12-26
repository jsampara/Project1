#include <iostream>
#include <fstream>
#include "Recruit.h"
#include <vector>
#include "RecruitDB.h"

using namespace std;

int main() {
    // Input file stream for reading recruits
    ifstream inputFile("top100.txt");
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    // Vector to hold Recruit objects
    vector<Recruit> recruits;
    Recruit recruit;
    int rank = 1;

    // Read recruits from file
    while (!inputFile.eof()) {
        recruit.read_txt(inputFile);
        recruits.push_back(recruit);
        rank++;
    }

    inputFile.close();

    // Output file stream for writing recruits
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    // Print recruits to output file
    rank = 1;
    for (const auto& rec : recruits) {
        rec.print_txt(outputFile);
        rank++;
    }

    outputFile.close();

    RecruitDB db;
    
    // Read data from file
    db.read_txt("top100.txt");
    
    // Test search methods
    cout << "Search by state (CA):" << endl;
    db.searchState("CA");
    
    cout << "Search by school (Oak Ridge High School):" << endl;
    db.searchSchool("Oak Ridge High School");
    
    cout << "Search by stars (****):" << endl;
    db.searchStars("****");
    
    cout << "Search by city (Fayetteville):" << endl;
    db.searchCity("Fayetteville");

    return 0;
}
