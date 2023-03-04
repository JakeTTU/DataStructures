//
//  Header.h
//  CPPprimer
//
//  Created by Jake Gonzalez on 1/28/19.
//

#ifndef Header_h
#define Header_h
#include <string>
using namespace std;

class Address {
    string street;
    string city;
public:
    int *zip;
    //constructer
    Address();
    //deconstructor
    ~Address();
    string get_street();
    string get_city();
    void set_street(string);
    void set_city(string);
};

#endif /* Header_h */
