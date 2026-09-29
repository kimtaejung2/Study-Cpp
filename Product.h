#include <string>
#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product {
   private:
    string name;
    int price;
    int stock;

   public:
    Product() = delete;
    Product(string n, int p, int s);
    void addStock(int s);
    bool sell(int s);
    int getStock() const;
    ~Product();
};

#endif