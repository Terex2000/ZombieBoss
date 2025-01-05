#include "FileWriter.h"
#include <fstream>
#include <iostream>

// Constructor for FileWriter
FileWriter::FileWriter() {
    // Constructor body (currently empty)
}

// Destructor for FileWriter
FileWriter::~FileWriter() {
    // Destructor body (currently empty)
}

// Function to save the game state to a file in JSON format
void FileWriter::saveGameState(const std::string& filename, const nlohmann::json& gameState) {
    std::ofstream file(filename); // Open the file for writing
    if (file.is_open()) {
        file << gameState.dump(4); // Pretty print the JSON with 4 spaces indentation
        file.close(); // Close the file after writing
        std::cout << "Saved file: " << filename << std::endl; // Inform that the file has been saved
    } else {
        std::cerr << "Error: Unable to open file for writing: " << filename << std::endl; // Error message if the file cannot be opened
    }
}
