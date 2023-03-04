//
//  Main.cpp
//  CPPprimer
//
//  Created by Jake Gonzalez on 1/28/19.
//

#include <stdio.h>
#include "Address.h"
#include <iostream>

int main() {
    Address addr1;
    Address **addr1 = new Address;
    
    addr1.set_city("Lubbock");
    cout << "City is: " << addr1.get_city() << endl;
    cout << "Zip is: " << addr1.get_zip() << endl;
    cout << "City 2 is " << *addr2_.get_city() << endl;
    
    delete *addr2;
    
    return 0;
}
