//CS210 Project 3 Version 4 main
//Zachary Halladay
//12-6-2025

#include <iostream> //Input/Output functionality
#include <limits> // For input validation
#include "GroceryTracker.h" //Pulls functions from header file

void displayMenu() { //displays menu for user input
    std::cout << "\nPlease select from the following options:" << std::endl;
    std::cout << "1. Search for a specific item" << std::endl;
    std::cout << "2. Print all items with their frequencies" << std::endl;
    std::cout << "3. Print histogram of all items" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your selection: "; //asks for user input
}

int main() {
    // The constructor reads the input file and creates the frequency data
    GroceryTracker tracker;

    int choice = 0;
    std::string itemToFind;

    do {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid selection. Please enter a valid selection (1-4)." << std::endl; //outputs error message
            std::cin.clear(); // Clears error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards bad input
            continue;
        }

        switch (choice) { //switch for menu selection
        case 1:
            std::cout << "Enter item for search: "; //asks for input to search for
            std::cin >> itemToFind;
            tracker.searchItemFrequency(itemToFind);
            break;
        case 2:
            tracker.printFrequencyList(); //prints list of all items and their appearances
            break;
        case 3:
            tracker.printHistogram(); //prints graphic histogram of all items
            break;
        case 4:
            std::cout << "Exiting program. Data backed up to frequency.dat" << std::endl; //exits program
            break;
        default:
            std::cout << "Invalid selection. Please select options 1-4." << std::endl; //outputs error message for invalid selection
            break;
        }
    } while (choice != 4);

    return 0;
}