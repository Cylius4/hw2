//
// Created by Cy on 2/9/24.
//

#ifndef HW2_MYDATASTORE_H
#define HW2_MYDATASTORE_H

#include "datastore.h"
#include <vector>
#include <map>

/**
 * @class MyDataStore
 * @brief A class that extends the DataStore class, implementing its pure virtual functions.
 */
class MyDataStore : public DataStore {
public:
    /**
     * @brief Destructor for the MyDataStore class.
     */
    ~MyDataStore();

    /**
     * @brief Adds a product to the datastore.
     * @param p Pointer to the product to be added.
     */
    void addProduct(Product *p);

    /**
     * @brief Adds a user to the datastore.
     * @param u Pointer to the user to be added.
     */
    void addUser(User *u);

    /**
     * @brief Searches for products in the datastore.
     * @param terms Vector of search terms.
     * @param type Type of search (0 for AND, 1 for OR).
     * @return Vector of pointers to the found products.
     */
    std::vector<Product *> search(std::vector<std::string> &terms, int type);

    /**
     * @brief Dumps the contents of the datastore to an output stream.
     * @param ofile Output stream to dump the contents to.
     */
    void dump(std::ostream &ofile);

    /**
     * @brief Adds a product to a user's cart.
     * @param u Pointer to the user.
     * @param p Pointer to the product to be added.
     */
    void addCart(User *u, Product *p);

    /**
     * @brief Retrieves a user from the datastore.
     * @param username The username of the user to be retrieved.
     * @return Pointer to the user, or nullptr if the user does not exist.
     */
    User *getUser(std::string username);

    /**
     * @brief Retrieves the contents of a user's cart.
     * @param u Pointer to the user.
     * @return Vector of pointers to the products in the user's cart.
     */
    std::vector<Product *> getCart(User *u);

    /**
     * @brief Purchases the products in a user's cart.
     * @param u Pointer to the user.
     */
    void buyCart(User *u);

protected:
    std::vector<Product *> products; ///< Vector of pointers to the products in the datastore.
    std::vector<User *> users; ///< Vector of pointers to the users in the datastore.
    std::map<User *, std::vector<Product *> > userCart; ///< Map of users to their carts.
    std::map<std::string, std::set<Product *> > keywords; ///< Map of keywords to the products they are associated with.
    std::map<std::string, User *> userMap; ///< Map of usernames to the corresponding users.
};


#endif //HW2_MYDATASTORE_H