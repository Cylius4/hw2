//
// Created by Cy on 2/9/24.
//

#ifndef HW2_MYDATASTORE_H
#define HW2_MYDATASTORE_H

#include "datastore.h"
#include <vector>
#include <map>

class MyDataStore : public DataStore{
public:
    ~MyDataStore();
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
    void addCart(User* u, Product* p);
    User* getUser(std::string username);
    std::vector<Product*> getCart(std::string username);
    void buyCart(User* u);
protected:
    std::vector<Product*> products;
    std::vector<User*> users;
    std::map<User*, std::vector<Product*> > userCart;
    std::map<std::string, std::set<Product*> > keywords;
    std::map<std::string, User*> userMap;
};


#endif //HW2_MYDATASTORE_H
