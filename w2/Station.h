//
// Created by Dominic Nunes on 2017-09-28.
//

#ifndef W2_STATION_H
#define W2_STATION_H

namespace w2
{

enum PassType
{
    STUDENT, ADULT
};

class Station
{

public:
    Station();

    void set(const std::string &stationName, unsigned studentPassCount, unsigned adultPassCount);
    void update(PassType passType, int amount);
    unsigned int inStock(PassType passType) const;
    const std::string &getName() const;
    void display();

private:
    std::string m_stationName;
    unsigned m_studentPassCount;
    unsigned m_adultPassCount;
};

}

#endif //W2_STATION_H
