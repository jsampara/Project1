#include "RecruitDB.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Recruit.h"  


using namespace std;

int main() {
   /*

    vector<Recruit> data;

    ifstream inputFile("top100.txt");

    if (!inputFile.is_open()) {
        cout << "Error: Could not open input file" << endl;
        return 1;
    }
    
    while (true) {
        Recruit r;
        if (!r.read_txt(inputFile)){
            break;
        }
        data.push_back(r);
    }
    inputFile.close();

    ofstream outFile("output.txt");

    if (!outFile.is_open())
    {
        cout << "Error: Could not open output file" << endl;
        return 1;
    }
   

    // Loop over vector to print Recruit information
    cout << "\nAll recruits' information:\n";
    for (int i = 0; i < data.size(); i++) {
        outFile << i + 1 << ":" << endl;
        data[i].print_recruit();  // print_recruit prints all the recruit's information
        outFile << endl;
    }

    outFile.close();

    cout << "Recruits have been read from top100.txt and written to output.txt successfully." << endl;
*/
    RecruitDB db;
    db.read_txt("top100.txt");

    int choice;
    do {
        cout << "\n=== RecruitDB Search Menu ===\n";
        cout << "1. Search by State\n";
        cout << "2. Search by Position\n";
        cout << "3. Search by Stars\n";
        cout << "4. Search by Position and State\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string state;
                cout << "Enter state: ";
                cin >> state;
                db.searchState(state);
                break;
            }
            case 2: {
                string position;
                cout << "Enter position (e.g., PG, SG, SF): ";
                cin >> position;
                db.searchPosition(position);
                break;
            }
            case 3: {
                int minStars, maxStars;
                cout << "Enter minimum stars: ";
                cin >> minStars;
                cout << "Enter maximum stars: ";
                cin >> maxStars;
                db.searchByStars(minStars, maxStars);
                break;
            }
            case 4: {
                string position, state;
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter state: ";
                cin >> state;
                db.searchPositionAndState(position, state);
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);


    return 0;
}
