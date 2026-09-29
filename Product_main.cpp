#include <iostream>

#include "Product.h"
using namespace std;

int main() {
    Product product("Keyboard", 30000, 5);
    product.sell(2);
    product.addStock(1);
    if (!product.sell(10))
        cout << "판매 실패" << '\n';
    cout << product.getStock();
    return 0;
}