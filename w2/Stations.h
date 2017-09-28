//
// Created by Dominic Nunes on 2017-09-26.
//

#ifndef W2_STATIONS_H
#define W2_STATIONS_H

#include <string>
#include "Station.h"

namespace w2
{
class Stations
{

public:
    explicit Stations(char *fileName);
    virtual ~Stations();
    void update();
    void restock();
    void report();
private:
    std::string m_fileName;
    int m_stationCount;
    Station* m_stations;

};
}

#endif //W2_STATIONS_H
