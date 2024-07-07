#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <string>
#include "Receipt.h"
using namespace std;

// Needs: Exclude people option

int main() {
    cout << "ReceiptZ P.O.C." << "\n\n";

    Receipt receipt;
    receipt.setOwner();
    receipt.setPayees();

    while (true) {
        bool r = receipt.setItem();
        if (r != 1) {
            break;
        }
    }

    receipt.setDiscount();

    receipt.read();
    cout << "Subtotal: $" << receipt.subtotal() << "\n";
    cout << "Total (Discount Applied): $" << receipt.total << "\n";

    receipt.calculate();
    receipt.debtors();

    return 0;
}