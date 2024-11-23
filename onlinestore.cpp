#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<string>
#include<ctime>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct Product {
    int productID;
    string name;
    string category;
};

struct Order {
    int orderID;
    int productID;
    int quantity;
    string customerID;
    time_t orderDate;
};

int main() {
    
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "Smartphone", "Electronics"},
        {103, "Coffee Maker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Desk Lamp", "Home"}
    };

    
    deque<string> recentCustomers = {"C001", "C002", "C003"};
    recentCustomers.push_back("C004"); 
    recentCustomers.push_back("C005");


    list<Order> orderHistory;
    orderHistory.push_back(Order{1, 101, 1, "C001", time(0)});  
    orderHistory.push_back(Order{2, 102, 2, "C002", time(0)});
    orderHistory.push_back(Order{3, 103, 3, "C003", time(0)});

    
    set<string> categories;
    for (const auto &product : products) {
        categories.insert(product.category);
    }

    
    map<int, int> productStock = {
        {101, 10},
        {102, 20},
        {103, 7},
        {104, 4},
        {105, 16}
    };

    
    multimap<string, Order> customerOrders;
    for (const auto &order : orderHistory) {
        customerOrders.insert({order.customerID, order});
    }

    
    unordered_map<string, string> customerData = {
        {"C001", "Rohan"},
        {"C002", "Ram"},
        {"C003", "Ritesh"},
        {"C004", "Rahul"},
        {"C005", "Rayn"}
    };

    
    unordered_set<int> uniqueProductIDs;
    for (const auto &product : products) {
        uniqueProductIDs.insert(product.productID);
    }
//Print all products
cout << "Products:" << endl;
for (const auto& product : products) {
    cout << "ID: " << product.productID << ", Name: " << product.name << ", Category: " << product.category << endl;
}

// Print recent customers
cout << "\nRecent Customers:" << endl;
for (const auto& customer : recentCustomers) {
    cout << customer << endl;
}

// Print orders
cout << "\nOrder History:" << endl;
for (const auto& order : orderHistory) {
    cout << "OrderID: " << order.orderID << ", ProductID: " << order.productID << ", Quantity: " << order.quantity << ", CustomerID: " << order.customerID << endl;
}

// Print categories
cout << "\nCategories:" << endl;
for (const auto& category : categories) {
    cout << category << endl;
}

// Print product stock
cout << "\nProduct Stock:" << endl;
for (const auto& stock : productStock) {
    cout << "ProductID: " << stock.first << ", Stock: " << stock.second << endl;
}

// Print customer orders
cout << "\nCustomer Orders:" << endl;
for (const auto& entry : customerOrders) {
    cout << "CustomerID: " << entry.first << ", OrderID: " << entry.second.orderID << endl;
}

// Print customer data
cout << "\nCustomer Data:" << endl;
for (const auto& customer : customerData) {
    cout << "CustomerID: " << customer.first << ", Name: " << customer.second << endl;
}

// Print unique product IDs
cout << "\nUnique Product IDs:" << endl;
for (const auto& id : uniqueProductIDs) {
    cout << id << endl;
}
    return 0;
}
