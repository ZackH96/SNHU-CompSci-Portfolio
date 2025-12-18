//CS210 Project 3 Version 4 header
//Zachary Halladay
//12-6-2025

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H //opening definition for header file

#include <iostream> //Input/Output functionality
#include <vector> //Vector functions, in place of map<string, int>
#include <string> //String functions
#include <fstream> //File input/output functionality (read & write)
#include <iomanip> // For std::setw, std::left

class GroceryTracker { //class for main to draw from
private: //private variables
    std::vector<std::string> items;
    std::vector<int> frequencies;
    std::string inputFileName = "CS210_Project_Three_Input_File.txt"; //reads input file
    std::string outputFileName = "frequency.dat"; //writes output file

    // Private helper to read and process the input file
    void readAndProcessInputFile() {
        std::ifstream inputFile(inputFileName);
        if (!inputFile.is_open()) {
            std::cerr << "Error: Unable to locate or open input file " << inputFileName << std::endl; //prints error message if input file is missing or unable to be opened
            return;
        }

        std::string item;
        while (inputFile >> item) {
            bool found = false;
            // Iterate through existing items to find a match
            for (size_t i = 0; i < items.size(); ++i) {
                if (items[i] == item) {
                    frequencies[i]++;
                    found = true;
                    break;
                }
            }

            // If item not found, add to the end of both vectors
            if (!found) {
                items.push_back(item);
                frequencies.push_back(1);
            }
        }
        inputFile.close(); //closes the input file
    }

    // Private helper to write frequency data to a backup file
    void writeFrequencyToFile() const {
        std::ofstream outputFile(outputFileName);
        if (!outputFile.is_open()) {
            std::cerr << "Error: Unable to create output file " << outputFileName << std::endl; //prints error message if output file cannot be created or written to
            return;
        }

        for (size_t i = 0; i < items.size(); ++i) {
            outputFile << items[i] << " " << frequencies[i] << std::endl;
        }
        outputFile.close();
    }

public:
    // Constructor
    GroceryTracker() {
        readAndProcessInputFile(); //reads and processes input file
        writeFrequencyToFile(); // Write the backup file upon initialization
    }

    // Public method to search for a specific item's frequency
    void searchItemFrequency(const std::string& itemToFind) const {
        bool found = false;
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i] == itemToFind) {
                std::cout << itemToFind << " found " << frequencies[i] << " times" << std::endl; //prints message if search term is located and how many times it occurs
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << itemToFind << " not found" << std::endl; //prints if search term is not in input file
        }
    }

    // Public method to print the frequency list
    void printFrequencyList() const {
        std::cout << "\nItem Frequency List:" << std::endl;
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << std::left << std::setw(15) << items[i] << frequencies[i] << std::endl; //bumps output to left side
        }
    }

    // Public method to print a histogram
    void printHistogram() const {
        std::cout << "\nItem Frequency Histogram:" << std::endl;
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << std::left << std::setw(15) << items[i] << " "; //bumps output to left side
            for (int j = 0; j < frequencies[i]; ++j) {
                std::cout << "*"; //prints asteriks for item counts
            }
            std::cout << std::endl;
        }
    }
};

#endif // GROCERYTRACKER_H