//
// Created by Cy on 2/9/24.
//

#ifndef HW2_BOOK_H
#define HW2_BOOK_H

#include <string>
#include <set>
#include "product.h"


class Book: public Product{
public:
    std::string isbn;
    std::string author;
    Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
};

#endif //HW2_BOOK_H
