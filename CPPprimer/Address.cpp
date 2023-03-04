//
//  Address.cpp
//  CPPprimer
//
//  Created by Jake Gonzalez on 1/28/19.
//

#include <stdio.h>
#include "Address.h"

Address::Address(){
    this->zip = new int;
}

Address:: ~Address(){
    delete this->zip;
}

string Address::get_street(){
    return this->street;
}

string Address::get_city(){
    return this->city;
}

void Address::set_street(string street) {
    this->street = street;
}

void Address::set_city(string city) {
    this->city = city;
}
