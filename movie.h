//
// Created by Cy on 2/9/24.
//

#ifndef HW2_MOVIE_H
#define HW2_MOVIE_H

#include <string>
#include "product.h"
#include <set>

using namespace std;

class Movie: public Product {
public:
    string genre;
    string rating;
    Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
    set<std::string> keywords() const;
    string displayString() const;
    void dump(std::ostream& os) const;
};


#endif //HW2_MOVIE_H
