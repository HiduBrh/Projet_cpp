//
// Created by idu on 16/07/17.
//

#ifndef PROJET_CPP_UTILS_H
#define PROJET_CPP_UTILS_H


#include <array>
#include "../platforms/Platform.h"

class Utils {
public:
    Utils();

    Utils(int gamewidth, int gameHeight);
    Utils(Utils const &);
    int getGamewidth() const;

    void setGamewidth(int gamewidth);

    int getGameHeight() const;

    void setGameHeight(int gameHeight);

    Platform generatePlatform();

private:
public:
    std::vector<Platform> &getPlatforms();

    void setPlatforms(const std::vector<Platform> &platforms);

private:
    int gamewidth;
    int gameHeight;
    std::vector<Platform> platforms;
};


#endif //PROJET_CPP_UTILS_H
