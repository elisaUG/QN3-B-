#include <iostream>
using namespace std;

int main() {
    float balance, totalCost = 0;
    int unitsConsumed;

    // Prompt user for input
    cout << "Enter the amount of money loaded onto your account (UGX): ";
    cin >> balance;

    cout << "Enter the number of water units consumed: ";
    cin >> unitsConsumed;

    // Calculate the total cost based on the tiered pricing structure
    if (unitsConsumed <= 10) {
        totalCost = unitsConsumed * 150;  // First 10 units
    } else if (unitsConsumed <= 20) {
        totalCost = (10 * 150) + ((unitsConsumed - 10) * 175);  // Next 10 units
    } else {
        totalCost = (10 * 150) + (10 * 175) + ((unitsConsumed - 20) * 200);  // Above 20 units
    }

    // Apply a 15% surcharge
    float surcharge = totalCost * 0.15;
    totalCost += surcharge;

    // Apply 18% VAT
    float vat = totalCost * 0.18;
    totalCost += vat;

    // Check if balance is sufficient
    if (balance >= totalCost) {
        // Calculate remaining balance
        balance -= totalCost;
        cout << "Transaction successful!" << endl;
        cout << "Total cost (with surcharge and VAT): " << totalCost << " UGX" << endl;
        cout << "Remaining balance: " << balance << " UGX" << endl;
    } else {
        // Insufficient balance
        cout << "Error: Insufficient balance!" << endl;
        cout << "Total cost (with surcharge and VAT): " << totalCost << " UGX" << endl;
        cout << "Your current balance: " << balance << " UGX" << endl;
    }

    return 0;
}
