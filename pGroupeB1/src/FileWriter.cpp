#include "FileWriter.h"
#include <fstream>
#include <iostream>

FileWriter::FileWriter() {
    //ctor
}

FileWriter::~FileWriter() {
    //dtor
}

void FileWriter::saveGameState(const std::string& filename, const nlohmann::json& gameState) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << gameState.dump(4); // Pretty print with 4 spaces
        file.close();
        std::cout << "save file" << filename << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
    }
}
