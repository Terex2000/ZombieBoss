#ifndef LEVEL_H
#define LEVEL_H

#include <string>

class Level {
public:
    Level(const std::string& mapFile, const std::string& bossMapFile);

    const std::string& getMapFile() const;
    const std::string& getBossMapFile() const;

private:
    std::string mapFile;
    std::string bossMapFile;
};

#endif // LEVEL_H