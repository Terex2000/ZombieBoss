// FileReader.h
#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>
#include <unordered_set>

class FileReader {
public:
    std::vector<std::vector<int>> readMap(const std::string& filename);
    std::unordered_set<int> readCollisionTypes(const std::string& filename);
};

#endif // FILEREADER_H