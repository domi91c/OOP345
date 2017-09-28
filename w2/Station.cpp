//
// Created by Dominic Nunes on 2017-09-28.
//

#include "iostream"
#include "Station.h"

w2::Station::Station()
{
    m_stationName = '\0';
    m_studentPassCount = 0u;
    m_adultPassCount = 0u;
}
void w2::Station::set(const std::string &stationName, unsigned studentPassCount, unsigned adultPassCount)
{
    m_stationName = stationName;
    m_studentPassCount = studentPassCount;
    m_adultPassCount = adultPassCount;
}
void w2::Station::display()
{
    std::cout << m_stationName << std::endl;
    std::cout << m_studentPassCount << std::endl;
    std::cout << m_adultPassCount << std::endl;
}

void w2::Station::update(PassType passType, int quantity)
{
    switch (passType) {
    case STUDENT:m_studentPassCount += quantity;
        break;
    case ADULT:m_adultPassCount += quantity;
        break;
    }
}

unsigned w2::Station::inStock(PassType passType) const
{
    switch (passType) {
    case STUDENT:return m_studentPassCount;
    case ADULT:return m_adultPassCount;
    }
}

const std::string &w2::Station::getName() const
{
    return m_stationName;
}
