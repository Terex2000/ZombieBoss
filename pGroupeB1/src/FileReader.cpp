#include "FileReader.h"
#include <fstream>
#include <sstream>

std::vector<std::vector<int>> FileReader::readMap(const std::string& filename) {
    std::vector<std::vector<int>> map;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        char tile;
        while (iss >> tile) {
            row.push_back(tile - '0');
        }
        map.push_back(row);
    }

    return map;
}