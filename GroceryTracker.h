/*
  Name: Matthew Scott
  Class: SNHU - CS 210
  Project: 7-3 Project Three
  Date: 6/22/2025

  This header file defines the GroceryTracker class.
  It lists all the functions we use in the main program.
  These handle reading the file, checking item frequency,
  printing items and stars, and saving to a file.
*/

#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <string>
#include <map>

using namespace std;

class GroceryTracker {
public:
    void loadItems(string filename);              // reads the file and fills the map
    int getFrequency(string itemName);            // gets how many times an item shows up
    void printAllItems();                         // prints each item with how many times it was bought
    void printHistogram();                        // prints items with stars showing their frequency
    void saveToFile(string filename);             // writes everything to a backup file

private:
    map<string, int> itemMap;                     // this map stores each item and how many times it shows up
};

#endif