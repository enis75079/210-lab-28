#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <algorithm> // min_element
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25;

int select_goat(const list<Goat>&);
void delete_goat(list<Goat>&);
void add_goat(list<Goat>&, string[], string[]);
void display_trip(const list<Goat>&);
void youngest_goat(const list<Goat>&);
void oldest_goat(const list<Goat>&);
void count_goat(const list<Goat>&);
void sort_goat(list<Goat>&);
void unique_color(const list<Goat>&);
void total_goat(const list<Goat>&);
void average_goat(const list<Goat>&);
void clear_goat(list<Goat>&);
int main_menu();

int main() {
    srand(time(0));

    // Read and populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // Create and populate a trip of Goats using std::list of random size 8-15
    int tripSize = rand() % 8 + 8;
    list<Goat> trip;
    for (int i = 0; i < tripSize; i++) {
        int age = rand() % MAX_AGE;  // defined in Goat.h
        string name = names[rand() % SZ_NAMES];
        string color = colors[rand() % SZ_COLORS];
        Goat tmp(name, age, color);
        trip.push_back(tmp);
    }
    
    // Goat Manager 3001 Engine
    int sel = main_menu();
    while (sel != 4) {
        switch (sel) {
            case 1:
                cout << "Adding a goat.\n";
                add_goat(trip, names, colors);
                break;
            case 2:    
                cout << "Removing a goat.\n";
                delete_goat(trip);
                break;
            case 3:    
                cout << "Displaying goat data.\n";
                display_trip(trip);
                break;
            case 5:
                youngest_goat(trip);
                break;
            case 6:
                oldest_goat(trip);
                break;
            case 7:
                count_goat(trip);
                break;
            default:
                cout << "Invalid selection.\n";
                break;
        }
        sel = main_menu();
    }

    return 0;
}

int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Quit\n";
    cout << "[5] Youngest Goat\n";
    cout << "[6] Oldest Goat\n";
    cout << "[7] How many goats\n";
    cout << "[8] Sort goats\n";
    cout << "[9] Unique goats by color\n";
    cout << "[10] Total goats\n";
    cout << "[11] Average age of current goats\n";
    cout << "[12] Delete all goats\n";
    cout << "Choice --> ";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 12) {
        cout << "Invalid, again --> ";
        cin >> choice;
    }
    return choice;
}

void delete_goat(list<Goat> &trip) {
    cout << "DELETE A GOAT\n";
    int index = select_goat(trip);
    auto it = trip.begin();
    advance(it, index - 1);
    trip.erase(it);
    cout << "Goat deleted. New trip size: " << trip.size() << endl;
}

void add_goat(list<Goat> &trip, string nms[], string cls[]) {
    cout << "ADD A GOAT\n";
    int age = rand() % MAX_AGE;
    string nm = nms[rand() % SZ_NAMES];
    string cl = cls[rand() % SZ_COLORS];
    Goat tmp(nm, age, cl);
    trip.push_back(tmp);
    cout << "Goat added. New trip size: " << trip.size() << endl;
}

void display_trip(const list<Goat>& trip) {
    int i = 1;
    for (const auto& gt : trip) {
        cout << "\t" 
             << "[" << i++ << "] "
             << gt.get_name() 
             << " (" << gt.get_age() 
             << ", " << gt.get_color() << ")\n";
    }
}

int select_goat(const list<Goat>& trip) {
    int input;
    cout << "Make a selection:\n";
    display_trip(trip);
    cout << "Choice --> ";
    cin >> input;
    while (input < 1 || input > trip.size()) {
        cout << "Invalid choice, again --> ";
        cin >> input;
    }
    return input;
}

// youngest_goat function. finds the youngest goat
void youngest_goat(const list<Goat>& trip) {
    auto it = min_element(trip.begin(), trip.end(), [](const Goat& a, const Goat& b) {
        return a.get_age() < b.get_age();
    });
    if (it != trip.end()) {
        cout << "Youngest goat:" << it->get_name() << ", Age: " << it->get_age() << "." << endl;
    }
}

// oldest_goat function. finds the oldest goat
void oldest_goat(const list<Goat>& trip) {
    auto it = max_element(trip.begin(), trip.end(), [](const Goat& a, const Goat& b) {
        return a.get_age() < b.get_age();
    });
    if (it != trip.end()) {
        cout << "Oldest goat:" << it->get_name() << ", Age: " << it->get_age() << "." << endl;
    }
}

// count)goat function. counts the total amount of goats in the list and outputs the number
void count_goat(const list<Goat>& trip) {
    int totalGoats = trip.size();
    cout << "Total Goats: " << totalGoats << endl;
}

// sort_goat function. sorts the goats by name using sort
void sort_goat(list<Goat>& trip) {
    trip.sort();
    cout << "Sorted Goats." << endl;
}

// unique_color function. displays all that are goats with user input color
void unique_color(const list<Goat>&) {

}

void total_goat(const list<Goat>&);
void average_goat(const list<Goat>&);
void clear_goat(list<Goat>&);