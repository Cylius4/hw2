//
// Created by Cy on 2/9/24.
//

#include "clothing.h"
#include "util.h"

std::set<std::string> Clothing::keywords() const {
    std::set<std::string> keywords = setUnion(parseStringToWords(brand), parseStringToWords(name_));
    return keywords;
}

std::string Clothing::displayString() const {
    return name_ + "\n" + "Size: " + size + " Brand: " + brand + "\n" + std::to_string(price_) + " " +
           std::to_string(qty_) + " left.";

}

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size,
                   std::string brand) : Product(category, name, price, qty) {
    this->size = size;
    this->brand = brand;
}

void Clothing::dump(std::ostream &ofile) const {
    ofile << "clothing" << std::endl;
    ofile << name_ << std::endl;
    ofile << price_ << std::endl;
    ofile << qty_ << std::endl;
    ofile << size << std::endl;
    ofile << brand << std::endl;
}