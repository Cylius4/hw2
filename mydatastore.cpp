//
// Created by Cy on 2/9/24.
//

#include "mydatastore.h"
#include "util.h"
#include <algorithm>

void MyDataStore::addProduct(Product* p) {
    products.push_back(p);
    std::set<std::string> keys = p->keywords();
    for (std::set<std::string>::iterator it = keys.begin(); it != keys.end(); ++it) {
        keywords[*it].insert(p);
    }
}

void MyDataStore::addUser(User* u) {
    users.push_back(u);
    userMap[u->getName()] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    // Lower case
    for (unsigned int i = 0; i < terms.size(); i++) {
        terms[i] = convToLower(terms[i]);
    }
    std::set<Product*> hits;
    std::set<Product*> temp;
    for (unsigned int i = 0; i < terms.size(); i++) {
        if (keywords.find(terms[i]) != keywords.end()) {
            temp = keywords[terms[i]];
            if (i== 0) {
                hits = temp;
            } else {
                if (type == 0) {
                    hits = setIntersection(hits, temp);
                } else if (type == 1) {
                    hits = setUnion(hits, temp);
                }
            }
        }
    }
    return std::vector<Product*>(hits.begin(), hits.end());
}

void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>" << std::endl;
    for (unsigned int i = 0; i < products.size(); i++) {
        products[i]->dump(ofile);
    }
    ofile << "</products>" << std::endl;
    ofile << "<users>" << std::endl;
    for (unsigned int i = 0; i < users.size(); i++) {
        ofile << users[i]->getName() << " " << users[i]->getBalance() << std::endl;
    }
    ofile << "</users>" << std::endl;
}

void MyDataStore::addCart(User* u, Product* p) {
    userCart[u].push_back(p);
}

User* MyDataStore::getUser(std::string username) {
    if (userMap.find(username) != userMap.end()) {
        return userMap[username];
    } else {
        return nullptr;
    }
}

std::vector<Product*> MyDataStore::getCart(std::string username) {
    return userCart[userMap[username]];
}

void MyDataStore::buyCart(User* u) {
    std::vector<Product*> &cart = userCart[u];
    // If the user has enough money and the product is in stock,
    // then remove from cart, subtract 1 from the quantity, and deduct the price from the user's balance
    // otherwise keep the item
    std::vector<Product*> newCart;
    for (unsigned int i = 0; i < cart.size(); i++) {
        if (cart[i]->getPrice() <= u->getBalance() && cart[i]->getQty() > 0) {
            u->deductAmount(cart[i]->getPrice());
            cart[i]->subtractQty(1);
        }
        else {
            newCart.push_back(cart[i]);
        }
    }
    userCart[u] = newCart;
}
