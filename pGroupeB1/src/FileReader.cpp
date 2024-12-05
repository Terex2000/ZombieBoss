// FileReader.cpp
#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<int>> FileReader::readMap(const std::string& filename) {
    std::vector<std::vector<int>> map;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("#COLLISION") == std::string::npos) {
            std::vector<int> row;
            std::istringstream iss(line);
            int tile;
            while (iss >> tile) {
                row.push_back(tile);
            }
            map.push_back(row);
        }
    }
    return map;
}

std::unordered_set<int> FileReader::readCollisionTypes(const std::string& filename) {
    std::unordered_set<int> collisionTypes;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("#COLLISION") != std::string::npos) {
            std::istringstream iss(line);
            std::string temp;
            int type;
            iss >> temp; // Skip the "#COLLISION" part
            while (iss >> type) {
                collisionTypes.insert(type);
                std::cout << "Collision type detected: " << type << std::endl; // Debug message
            }
        }
    }
    return collisionTypes;
}