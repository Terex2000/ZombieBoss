#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <nlohmann/json.hpp> // Include the JSON library

class FileWriter {
public:
    FileWriter();
    virtual ~FileWriter();

    void saveGameState(const std::string& filename, const nlohmann::json& gameState);

private:
};

#endif // FILEWRITER_H