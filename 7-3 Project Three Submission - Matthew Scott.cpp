/*
  Name: Matthew Scott
  Class: SNHU - CS 210
  Project: 7-3 Project Three
  Date: 6/22/2025

  This is the main entry point of the grocery tracking program.
  It shows the menu, handles user input, and calls the functions
  from the GroceryTracker class.
*/

#include <iostream>
#include <string>
#include "GroceryTracker.h"

using namespace std;

int main() {
    GroceryTracker tracker;
    string inputFile = "CS210_Project_Three_Input_File.txt";
    string backupFile = "frequency.dat";
    string userItem;
    int choice = 0;

    // load grocery data and save backup
    tracker.loadItems(inputFile);
    tracker.saveToFile(backupFile);

    // keep showing the menu until user exits
    while (true) {
        cout << endl;
        cout << "===== Grocery Tracker Menu =====" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Show all item frequencies" << endl;
        cout << "3. Show item frequency histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1 - 4): ";
        cin >> choice;

        // handle invalid input
        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            continue;
        }

        // option 1: look for a specific item
        if (choice == 1) {
            cout << "Enter item name to search: ";
            cin >> userItem;
            int count = tracker.getFrequency(userItem);

            if (count == -1) {
                cout << userItem << " was not found in the list." << endl;
            }
            else {
                cout << userItem << " was bought " << count << " times." << endl;
            }
        }

        // option 2: show all items and counts
        else if (choice == 2) {
            tracker.printAllItems();
        }

        // option 3: show histogram
        else if (choice == 3) {
            tracker.printHistogram();
        }

        // option 4: exit
        else if (choice == 4) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}