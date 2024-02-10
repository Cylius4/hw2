//
// Created by Cy on 2/9/24.
//

#include "movie.h"
#include "util.h"

std::set<std::string> Movie::keywords() const {
    // Get the keywords from the name and genre
    std::set<std::string> keywords = parseStringToWords(name_);
    keywords.insert(convToLower(genre));
    return keywords;
}

std::string Movie::displayString() const {
    return name_ + "\n" + "Genre: " + genre + " Rating: " + rating + "\n" + std::to_string(price_) + " " +
           std::to_string(qty_) + " left.";
}

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre,
             std::string rating) : Product(category, name, price, qty) {
    this->genre = genre;
    this->rating = rating;
}

void Movie::dump(std::ostream &ofile) const {
    ofile << "movie" << std::endl;
    ofile << name_ << std::endl;
    ofile << price_ << std::endl;
    ofile << qty_ << std::endl;
    ofile << genre << std::endl;
    ofile << rating << std::endl;
}