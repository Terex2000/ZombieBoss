#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>
#include <unordered_set>//Offers amortized constant-time search, 
                        //Inserting elements into an unordered_set is also amortized constant-time, O(1) 
                        //and does not allow duplicates.

// The FileReader class is responsible for reading map data and collision types from files.
class FileReader {
public:
    // Reads the map data from a file and returns it as a 2D vector of integers.
    std::vector<std::vector<int>> readMap(const std::string& filename);

    // Reads the collision types from a file and returns them as an unordered set of integers.
    std::unordered_set<int> readCollisionTypes(const std::string& filename);
};

#endif // FILEREADER_H