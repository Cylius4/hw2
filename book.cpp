//
// Created by Cy on 2/9/24.
//

#include "book.h"
#include "util.h"

std::set <std::string> Book::keywords() const {
    std::set<std::string> keywords = setUnion(parseStringToWords(name_), parseStringToWords(author));
    keywords.insert(convToLower(isbn));
    return keywords;
}


Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author) : Product(category, name, price, qty) {
    this->isbn = isbn;
    this->author = author;
}

void Book::dump(std::ostream& os) const {
    os << "book" << std::endl;
    os << name_ << std::endl;
    os << price_ << std::endl;
    os << qty_ << std::endl;
    os << isbn << std::endl;
    os << author << std::endl;
}

std::string Book::displayString() const {
    return name_ + "\n" + "Author: " + author + " ISBN: " + isbn + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
}