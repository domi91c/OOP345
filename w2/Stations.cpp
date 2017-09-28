//
// Created by Dominic Nunes on 2017-09-26.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Stations.h"

using namespace std;
w2::Stations::Stations(char *fileName)
{
    string stationName;
    unsigned studentPassCount;
    unsigned adultPassCount;

    m_fileName = fileName;
    ifstream ifs(m_fileName);

    if (ifs.fail()) {
        cout << "FAIL" << endl;
        return;
    }

    ifs >> m_stationCount;
    m_stations = new Station[m_stationCount];
    int i = 0;
    ifs.ignore();
    while (ifs.good()) {
        ifs.ignore();
        getline(ifs, stationName, ';');
        ifs >> studentPassCount >> adultPassCount;
        m_stations[i].set(stationName, studentPassCount, adultPassCount);
        i++;
    }
    ifs.close();

}

w2::Stations::~Stations()
{

}

void w2::Stations::report()
{
    cout << "Passes in Stock : Student Adult" << endl;
    cout << "-------------------------------" << endl;
    for (int i = 0; i < m_stationCount; ++i) {
        cout << setw(19) << std::left << m_stations[i].getName();
        cout << setw(6) << std::right << m_stations[i].inStock(STUDENT);
        cout << setw(6) << m_stations[i].inStock(ADULT);
        cout << endl;
    }

}

void w2::Stations::restock()
{
    int studentPassesAdded, adultPassesAdded;
    cout << "Passes Added :" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < m_stationCount; ++i) {
        cout << m_stations[i].getName() << endl;
        cout << " Student Passes added : ";
        cin >> studentPassesAdded;
        m_stations[i].update(STUDENT, studentPassesAdded);
        cout << " Adult Passes added : ";
        cin >> adultPassesAdded;
        m_stations[i].update(ADULT, adultPassesAdded);
    }
    cout << endl;
}

void w2::Stations::update()
{
    int studentPassesSold, adultPassesSold;
    cout << "Passes Sold :" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < m_stationCount; ++i) {
        cout << m_stations[i].getName() << endl;
        cout << " Student Passes sold : ";
        cin >> studentPassesSold;
        m_stations[i].update(STUDENT, -studentPassesSold);
        cout << " Adult Passes sold : ";
        cin >> adultPassesSold;
        m_stations[i].update(ADULT, -adultPassesSold);
    }
    cout << endl;
}
