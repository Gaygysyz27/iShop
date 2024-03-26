//
// Created by Lenovo on 22.03.2024.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
        private:
        string name;

        public:

        Customer(const string& _name) : name(_name) {}

        void setName(const string& _name) {
            name = _name;
        }

        string getName() const {
            return name;
        }

        void greet() const {
            cout <<"-----Hello dear, " << name << "!-----" << endl;
        }
};

class Product {
private:
    string code;
    string name;
    float price;

public:
    Product(string _code, string _name, float _price) : code(_code), name(_name), price(_price) {}

    string getCode() const { return code; }
    string getName() const { return name; }
    float getPrice() const { return price; }
};

class Section {
private:
    string name;
    vector<Product> products;

public:
    Section(string _name, const vector<Product>& _products) : name(_name), products(_products) {}

    string getName() const { return name; }
    vector<Product> getProducts() const { return products; }
};

float calculateTotalCost(int quantity, float price, float taxRate, float cost) {
    float total = quantity * price;
    float taxAmount = total * taxRate;
    total += taxAmount;
    cout << "Total (including tax): $" << total << endl;
    cout << "Enter your cost: $";
    cin >> cost;
    float refund = cost - total;
    return refund;
}

int main() {
    string customerName;

    cout << "What is your name? ";
    cin >> customerName;

    Customer customer(customerName);

    customer.greet();

    vector<Product> iPhones = {
            Product("1", "iPhone 15         8/256", 900.00),
            Product("2", "iPhone 15         8/512", 1000.00),
            Product("3", "iPhone 15 pro     8/512", 1200.00),
            Product("4", "iPhone 15 pro     8/1TB", 1300.00),
            Product("5", "iPhone 15 pro max 8/512", 1500.00),
            Product("6", "iPhone 15 pro max 8/1TB", 1700.00),

    };

    vector<Product> macBooks = {
            Product("1", "MacBook Air 15-inch(M3,2024)      24/2TB", 2500.00),
            Product("2", "MacBook Pro 16-inch(M3 pro,2023) 16/1TB", 1750.00),
    };


    vector<Product> iPods = {
            Product("1", "iPad(2022) 3/256",   200.00),
            Product("2", "iPad Air   6/512",   550.00),
            Product("3", "iPad Pro   8/1TB",   750.00),
            Product("4", "iPad Mini  4/256",   350.00),
    };

    vector<Product> appleWatches = {
            Product("1", "Apple Watch Series 9",    400.00),
            Product("2", "Apple Watch SE (2nd Gen)",250.00),
            Product("3", "Apple Watch Ultra ",      600.00),
            Product("4", "Apple Watch Series 8",    300.00),
            // Add other Apple Watch products
    };

    Section iPhoneSection("iPhones", iPhones);
    Section macBookSection("MacBooks", macBooks);
    Section iPodSection("iPods", iPods);
    Section appleWatchSection("Apple Watches", appleWatches);

    cout << "--------WELCOME TO iShop--------" << endl;
    cout << ">>>>>>>>>HAPPY SHOPPING<<<<<<<<<" << endl;
    cout << endl << endl;
    cout << "YOU CAN CHOOSE OUR SECTION BELOW" << endl;

    cout << "1. " << iPhoneSection.getName() << endl;
    cout << "2. " << macBookSection.getName() << endl;
    cout << "3. " << iPodSection.getName() << endl;
    cout << "4. " << appleWatchSection.getName() << endl;

    int choice;
    cout << "Enter section number: ";
    cin >> choice;

    const vector<Section> sections = { iPhoneSection, macBookSection, iPodSection, appleWatchSection };
    if (choice >= 1 && choice <= sections.size()) {
        Section selectedSection = sections[choice - 1];
        vector<Product> products = selectedSection.getProducts();

        cout << "-----WELCOME TO THE " << selectedSection.getName() << " SECTION-----" << endl;
        cout << "CHOOSE OUR PRODUCTS BELOW" << endl;

        for (const auto& product : products) {
            cout << product.getCode() << ". " << product.getName() << " - $" << product.getPrice() << endl;
        }

        string productCode;
        cout << "Enter product code: ";
        cin >> productCode;

        float cost;
        for (const auto& product : products) {
            if (product.getCode() == productCode) {
                cout << "You selected: " << product.getName() << endl;
                int quantity;
                cout << "Enter quantity: ";
                cin >> quantity;
                float refund = calculateTotalCost(quantity, product.getPrice(), 0.1, cost);
                cout << "Refund: $" << refund << endl;
                break;
            }
        }
    } else {
        cout << "Invalid section number!" << endl;
    }

    cout << "\n\n"
         << "----------------THANK YOU!!!----------------" << endl;
    cout << "----------iShop ONLINE MARKETPLACE----------" << endl
         << endl;

    return 0;
}
