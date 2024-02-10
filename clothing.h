//
// Created by Cy on 2/9/24.
//

#ifndef HW2_CLOTHING_H
#define HW2_CLOTHING_H

#include <string>
#include "product.h"
#include <set>

using namespace std;

class Clothing : public Product{
public:
    string size;
    string brand;
    Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
    set<std::string> keywords() const;
    string displayString() const;
    void dump(std::ostream& os) const;
};


#endif //HW2_CLOTHING_H
