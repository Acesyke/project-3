#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Reservation {
    string name;
    string phone;
    string date;
    string time;
};

struct Table {
    vector<Reservation> reservations;
};

void showTables(vector<Table> &tables) {
    cout << "\n========== Restaurant Reservations ==========\n";

    for (int i = 0; i < tables.size(); i++) {
        cout << "\nTable " << i + 1 << ":\n";

        if (tables[i].reservations.empty()) {
            cout << "  No reservations.\n";
        } else {
            for (int j = 0; j < tables[i].reservations.size(); j++) {
                cout << "  " << j + 1 << ". "
                     << tables[i].reservations[j].name << " | "
                     << tables[i].reservations[j].phone << " | "
                     << tables[i].reservations[j].date << " | "
                     << tables[i].reservations[j].time << endl;
            }
        }
    }
}

int main() {
    vector<Table> tables(6);
    int choice;

    do {
        cout << "\n===== Restaurant Menu =====\n";
        cout << "1. Show Reservations\n";
        cout << "2. Reserve Table\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            showTables(tables);
        }

        else if (choice == 2) {
            int tableNumber;
            cout << "Enter table number (1-6): ";
            cin >> tableNumber;
            cin.ignore();

            if (tableNumber < 1 || tableNumber > 6) {
                cout << "Invalid table number!\n";
                continue;
            }

            Reservation r;

            cout << "Enter Name: ";
            getline(cin, r.name);

            cout << "Enter Phone: ";
            getline(cin, r.phone);

            cout << "Enter Date (DD/MM/YYYY): ";
            getline(cin, r.date);

            cout << "Enter Time (HH:MM): ";
            getline(cin, r.time);

            // Check if same date & time already exists
            bool conflict = false;
            for (auto &existing : tables[tableNumber - 1].reservations) {
                if (existing.date == r.date && existing.time == r.time) {
                    conflict = true;
                    break;
                }
            }

            if (conflict) {
                cout << "This table is already reserved at that date and time!\n";
            } else {
                tables[tableNumber - 1].reservations.push_back(r);
                cout << "Reservation successful!\n";
            }
        }

    } while (choice != 3);

    return 0;
}