#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<int>> FileReader::readMap(const std::string& filename) {
    std::vector<std::vector<int>> map;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        std::string tile;
        while (iss >> tile) {
            try {
                row.push_back(std::stoi(tile));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid tile value: " << tile << std::endl;
            }
        }
        map.push_back(row);
    }

    return map;
}