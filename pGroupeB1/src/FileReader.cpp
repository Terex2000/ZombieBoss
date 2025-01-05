#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Function to read the map data from a file
std::vector<std::vector<int>> FileReader::readMap(const std::string& filename) {
    std::vector<std::vector<int>> map;
    std::ifstream file(filename);
    std::string line;

    // Read each line from the file
    while (std::getline(file, line)) {
        // Skip lines that contain special markers
        if (line.find("#COLLISION") == std::string::npos && line.find("#TELEPORT") == std::string::npos && line.find("#INSTANTDEATH") == std::string::npos) {
            std::vector<int> row;
            std::istringstream iss(line);
            int tile;
            // Read each integer (tile) from the line and add it to the row
            while (iss >> tile) {
                row.push_back(tile);
            }
            // Add the row to the map
            map.push_back(row);
        }
    }
    return map;
}

// Function to read collision types from a file
std::unordered_set<int> FileReader::readCollisionTypes(const std::string& filename) {
    std::unordered_set<int> collisionTypes;
    std::ifstream file(filename);
    std::string line;

    // Read each line from the file
    while (std::getline(file, line)) {
        // Check if the line contains the "#COLLISION" marker
        if (line.find("#COLLISION") != std::string::npos) {
            std::istringstream iss(line);
            std::string temp;
            int type;
            iss >> temp; // Skip the "#COLLISION" part
            // Read each integer (collision type) from the line and add it to the set
            while (iss >> type) {
                collisionTypes.insert(type);
            }
        }
    }
    return collisionTypes;
}

// Function to read teleport tiles from a file
std::unordered_set<int> FileReader::readTeleportTiles(const std::string& filename) {
    std::unordered_set<int> teleportTiles;
    std::ifstream file(filename);
    std::string line;

    // Read each line from the file
    while (std::getline(file, line)) {
        // Check if the line contains the "#TELEPORT" marker
        if (line.find("#TELEPORT") != std::string::npos) {
            std::istringstream iss(line);
            std::string temp;
            int type;
            iss >> temp; // Skip the "#TELEPORT" part
            // Read each integer (teleport tile type) from the line and add it to the set
            while (iss >> type) {
                teleportTiles.insert(type);
            }
        }
    }
    return teleportTiles;
}

// Function to read instant death tiles from a file
std::unordered_set<int> FileReader::readInstantDeathTiles(const std::string& filename) {
    std::unordered_set<int> instantDeathTiles;
    std::ifstream file(filename);
    std::string line;

    // Read each line from the file
    while (std::getline(file, line)) {
        // Check if the line contains the "#INSTANTDEATH" marker
        if (line.find("#INSTANTDEATH") != std::string::npos) {
            std::istringstream iss(line);
            std::string temp;
            int type;
            iss >> temp; // Skip the "#INSTANTDEATH" part
            // Read each integer (instant death tile type) from the line and add it to the set
            while (iss >> type) {
                instantDeathTiles.insert(type);
            }
        }
    }
    return instantDeathTiles;
}
