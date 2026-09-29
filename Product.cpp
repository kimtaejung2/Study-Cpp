#include "Product.h"

#include <iostream>
#include <string>

using namespace std;

Product::Product(string n, int p, int s) : name{n}, price{p}, stock{s} {
    cout << "Product »ý¼º" << endl;
}

Product::~Product() { cout << endl
                           << "Product ¼Ò¸ê" << endl; }

void Product::addStock(int s) {
    stock += s;
}
bool Product::sell(int s) {
    if (s <= stock) {
        stock -= s;
        return true;
    }
    return false;
}
int Product::getStock() const {
    return stock;
}