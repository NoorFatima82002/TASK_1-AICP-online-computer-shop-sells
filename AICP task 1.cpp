#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Struct to represent computer components
struct ComputerComponent {
    string itemCode;
    string description;
    double price;
};

int main() {
    // Define arrays to store item information
    ComputerComponent cases[] = {
        {"A1", "Compact", 75.00},
        {"A2", "Tower", 150.00}
    };

    ComputerComponent ram[] = {
        {"B1", "8 GB", 79.99},
        {"B2", "16 GB", 149.99},
        {"B3", "32 GB", 299.99}
    };

    ComputerComponent hdd[] = {
        {"C1", "1 TB HDD", 49.99},
        {"C2", "2 TB HDD", 89.99},
        {"C3", "4 TB HDD", 129.99}
    };

    // Variables to store user's choices
    string choosenCase, choosenRam, choosenHDD;
    vector<ComputerComponent> additionalItems;

    // Prompt user to choose components
    cout << "Choose a case (A1 - Compact / A2 - Tower): ";
    cin >> choosenCase;

    cout << "Choose RAM (B1 - 8 GB / B2 - 16 GB / B3 - 32 GB): ";
    cin >> choosenRam;

    cout << "Choose Main Hard Disk Drive (C1 - 1 TB HDD / C2 - 2 TB HDD / C3 - 4 TB HDD): ";
    cin >> choosenHDD;

    // Calculate the base price
    double basePrice = 200.00;
    double computerPrice = basePrice;

    // Find the prices of chosen components and add to the computerPrice
    for (const ComputerComponent &component : cases) {
        if (component.itemCode == choosenCase) {
            computerPrice += component.price;
            break;
        }
    }

    for (const ComputerComponent &component : ram) {
        if (component.itemCode == choosenRam) {
            computerPrice += component.price;
            break;
        }
    }

    for (const ComputerComponent &component : hdd) {
        if (component.itemCode == choosenHDD) {
            computerPrice += component.price;
            break;
        }
    }

    // Prompt the user to choose additional items
    char addMoreItems;
    cout << "Do you want to purchase more items (Y/N)? ";
    cin >> addMoreItems;

    while (addMoreItems == 'Y' || addMoreItems == 'y') {
        // Display the available additional items and their prices
        cout << "Additional Items Categories:\n";
        cout << "A - Solid State Drive\n";
        cout << "B - Second Hard Disk Drive\n";
        cout << "C - Optical Drive\n";
        cout << "D - Operating System\n";

        char category;
        cout << "Enter the category letter (A/B/C/D): ";
        cin >> category;

        string chosenItem; // Define chosenItem here

        switch (category) {
            case 'A': {
                ComputerComponent ssd[] = {
                    {"D1", "240 GB SSD", 59.99},
                    {"D2", "480 GB SSD", 119.99}
                };
                cout << "Choose Solid State Drive (D1 - 240 GB SSD / D2 - 480 GB SSD): ";
                cin >> chosenItem;
                for (const ComputerComponent &component : ssd) {
                    if (component.itemCode == chosenItem) {
                        additionalItems.push_back(component);
                        computerPrice += component.price;
                        break;
                    }
                }
                break;
            }
            case 'B': {
                ComputerComponent secondHDD[] = {
                    {"E1", "1 TB HDD", 49.99},
                    {"E2", "2 TB HDD", 89.99},
                    {"E3", "4 TB HDD", 129.99}
                };
                cout << "Choose Second Hard Disk Drive (E1 - 1 TB HDD / E2 - 2 TB HDD / E3 - 4 TB HDD): ";
                cin >> chosenItem;
                for (const ComputerComponent &component : secondHDD) {
                    if (component.itemCode == chosenItem) {
                        additionalItems.push_back(component);
                        computerPrice += component.price;
                        break;
                    }
                }
                break;
            }
            case 'C': {
                ComputerComponent opticalDrives[] = {
                    {"F1", "DVD/Blu-Ray Player", 50.00},
                    {"F2", "DVD/Blu-Ray Re-writer", 100.00}
                };
                cout << "Choose Optical Drive (F1 - DVD/Blu-Ray Player / F2 - DVD/Blu-Ray Re-writer): ";
                cin >> chosenItem;
                for (const ComputerComponent &component : opticalDrives) {
                    if (component.itemCode == chosenItem) {
                        additionalItems.push_back(component);
                        computerPrice += component.price;
                        break;
                    }
                }
                break;
            }
            case 'D': {
                ComputerComponent operatingSystems[] = {
                    {"G1", "Standard Version", 100.00},
                    {"G2", "Professional Version", 175.00}
                };
                cout << "Choose Operating System (G1 - Standard Version / G2 - Professional Version): ";
                cin >> chosenItem;
                for (const ComputerComponent &component : operatingSystems) {
                    if (component.itemCode == chosenItem) {
                        additionalItems.push_back(component);
                        computerPrice += component.price;
                        break;
                    }
                }
                break;
            }
            default:
                cout << "Invalid category. Please choose from D, E, F, or G.\n";
        }

        cout << "Do you want to add more items (Y/N)? ";
        cin >> addMoreItems;
    }

    // Calculate discounts based on the number of additional items
    double discount = 0.0;
    if (additionalItems.size() == 1) {
        discount = 0.05; // 5% discount for one additional item
    } else if (additionalItems.size() >= 2) {
        discount = 0.10; // 10% discount for two or more additional items
    }

    // Calculate the discounted price
    double discountedPrice = computerPrice - (discount * computerPrice);

    // Display chosen items, total price, and discounts
    cout << "Chosen Case: " << choosenCase << " - ";
    for (const ComputerComponent &component : cases) {
        if (component.itemCode == choosenCase) {
            cout << component.description << " $" << component.price << endl;
            break;
        }
    }

    cout << "Chosen RAM: " << choosenRam << " - ";
    for (const ComputerComponent &component : ram) {
        if (component.itemCode == choosenRam) {
            cout << component.description << " $" << component.price << endl;
            break;
        }
    }

    cout << "Chosen Main Hard Disk Drive: " << choosenHDD << " - ";
    for (const ComputerComponent &component : hdd) {
        if (component.itemCode == choosenHDD) {
            cout << component.description << " $" << component.price << endl;
            break;
        }
    }

    cout << "Additional Items:\n";
    for (const ComputerComponent &component : additionalItems) {
        cout << component.description << " $" << component.price << endl;
    }

    cout << "Total Price: $" << fixed << setprecision(2) << computerPrice << endl;

    // Check if a discount is applied and display the discount and discounted price
    if (discount > 0.0) {
        double discountAmount = computerPrice * discount;
        cout << "Discount Applied: " << (discount * 100) << "%\n";
        cout << "Amount Saved: $" << fixed << setprecision(2) << discountAmount << endl;
        cout << "Discounted Price: $" << fixed << setprecision(2) << discountedPrice << endl;
    }

    return 0; }
