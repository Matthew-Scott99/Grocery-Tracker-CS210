/*
  Name: Matthew Scott
  Class: SNHU - CS 210
  Project: 7-3 Project Three
  Date: 6/22/2025

  This file contains the logic for reading grocery item data,
  storing it in a map, and printing frequency counts or a histogram.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "GroceryTracker.h"

using namespace std;

// reads the grocery file and loads item counts into the map
void GroceryTracker::loadItems(string filename) {
    ifstream inFile(filename);
    string item;

    while (inFile >> item) {
        itemMap[item]++;
    }

    inFile.close();
}

// gets how many times an item was bought
int GroceryTracker::getFrequency(string itemName) {
    // Check if the item exists in the map before accessing it
    if (itemMap.find(itemName) != itemMap.end()) {
        return itemMap[itemName];
    }
    else {
        return -1; // Return -1 to mean "not found"
    }
}

// prints every item and how many times it was bought
void GroceryTracker::printAllItems() {
    for (map<string, int>::iterator it = itemMap.begin(); it != itemMap.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

// prints every item and a row of stars to match how many times it was bought
void GroceryTracker::printHistogram() {
    for (map<string, int>::iterator it = itemMap.begin(); it != itemMap.end(); ++it) {
        cout << it->first << " ";
        for (int i = 0; i < it->second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

// writes the frequency list to a file for backup
void GroceryTracker::saveToFile(string filename) {
    ofstream outFile(filename);
    for (map<string, int>::iterator it = itemMap.begin(); it != itemMap.end(); ++it) {
        outFile << it->first << " " << it->second << endl;
    }
    outFile.close();
}