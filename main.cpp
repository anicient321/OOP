#include "container.h"
#include <iostream>

void funkcija_po_vrijednosti(container c) {
    std::cout << "funkcija po vrijednosti: primljen container s " << c.size() << " elemenata" << std::endl;
}

container funkcija_koja_vraca() {
    container temp;
    temp.push_back(100);
    temp.push_back(200);
    temp.push_back(300);
    return temp;
}

int main() {
    //napravija container i dodava elemenate
    container original;
    original.push_back(10);
    original.push_back(20);
    original.push_back(30);
    std::cout << "original size: " << original.size() << ", capacity: " << original.capacity() << std::endl;
    
    //kopiranje containera (copy konstruktor)
    container kopija(original);
    std::cout << "kopija size: " << kopija.size() << ", capacity: " << kopija.capacity() << std::endl;
    
    //move konstruktor
    container novi = std::move(original);
    std::cout << "novi size: " << novi.size() << ", capacity: " << novi.capacity() << std::endl;
    std::cout << "original size nakon move: " << original.size() << ", capacity: " << original.capacity() << std::endl;
    
    //prosljedivanje po vridnnosti
    funkcija_po_vrijednosti(kopija);
    
    //vracanje iz funkcije;
    container vracen = funkcija_koja_vraca();
    std::cout << "vracen size: " << vracen.size() << ", capacity: " << vracen.capacity() << std::endl;
    
    //mem realloc
    container test(2);
    test.push_back(1);
    test.push_back(2);
    std::cout << "prije realokacije - size: " << test.size() << ", capacity: " << test.capacity() << std::endl;
    test.push_back(3);
    std::cout << "nakon realokacije - size: " << test.size() << ", capacity: " << test.capacity() << std::endl;
    test.push_back(4);
    test.push_back(5);
    std::cout << "nakon jos jedne realokacije - size: " << test.size() << ", capacity: " << test.capacity() << std::endl;
    
    std::cout << "elementi containera 'novi':" << std::endl; //ispis svih novih elem
    for (size_t i = 0; i < novi.size(); ++i) {
        std::cout << "  indeks " << i << ": " << novi.at(i) << std::endl;
    }
    
    std::cout << "\nelementi containera 'vracen':" << std::endl;
    for (size_t i = 0; i < vracen.size(); ++i) {
        std::cout << "  indeks " << i << ": " << vracen.at(i) << std::endl;
    }
    
    std::cout << "\nelementi containera 'test':" << std::endl;
    for (size_t i = 0; i < test.size(); ++i) {
        std::cout << "  indeks " << i << ": " << test.at(i) << std::endl;
    }
    
    std::cout << "test prije clear - size: " << test.size() << ", capacity: " << test.capacity() << std::endl;
    test.clear();
    std::cout << "test nakon clear - size: " << test.size() << ", capacity: " << test.capacity() << std::endl;
        return 0;
}
