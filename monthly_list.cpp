#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class MonthlyItemList 
{
private:
    struct Item 
    {
        std::string item_code;
        double price;
        std::string place_to_dealer;
    };
    
    std::unordered_map<std::string, Item> items;
    static int itemCount;

public:
    void addItem(const std::string& item_code, double price, const std::string& place_to_dealer) 
    {
        if (price <= 0) 
        {
            std::cout << RED << "Error: Price must be greater than zero.\n" << RESET;
            return;
        }
        if (items.find(item_code) != items.end()) 
        {
            std::cout << RED << "Error: Item code already exists.\n" << RESET;
            return;
        }

        items[item_code] = {item_code, price, place_to_dealer};
        itemCount++;
        std::cout << GREEN << "Item added successfully!\n" << RESET;
    }

    void deleteItem(const std::string& item_code) 
    {
        if (items.erase(item_code)) 
        {
            itemCount--;
            std::cout << YELLOW << "Item with code " << item_code << " deleted.\n" << RESET;
        } 
        else 
        {
            std::cout << RED << "Item with code " << item_code << " not found.\n" << RESET;
        }
    }

    void printItem(const std::string& item_code) const 
    {
        auto it = items.find(item_code);
        if (it != items.end()) 
        {
            const auto& item = it->second;
            std::cout << CYAN << "Item Code: " << BOLD << item.item_code << RESET << CYAN
                      << ", Price: " << BOLD << item.price << RESET << CYAN
                      << ", Dealer: " << BOLD << item.place_to_dealer << RESET << '\n';
        } 
        else 
        {
            std::cout << RED << "Item with code " << item_code << " not found.\n" << RESET;
        }
    }

    void displayAllItems() const 
    {
        if (items.empty()) 
        {
            std::cout << YELLOW << "No items in the list.\n" << RESET;
            return;
        }

        std::cout << BLUE << BOLD;
        std::cout << "---------------------------------------------------\n";
        std::cout << "| Item Code | Price      | Dealer                |\n";
        std::cout << "---------------------------------------------------\n" << RESET;
        
        for (const auto& pair : items) 
        {
            const auto& item = pair.second;
            std::cout << CYAN << "| " << std::left << std::setw(9) << item.item_code 
                      << " | " << std::setw(10) << item.price 
                      << " | " << std::setw(20) << item.place_to_dealer << " |" << RESET << '\n';
        }
        
        std::cout << BLUE << BOLD;
        std::cout << "---------------------------------------------------\n" << RESET;
    }

    void searchByDealer(const std::string& dealer) const 
    {
        bool found = false;
        std::cout << MAGENTA << "Searching for items from dealer: " << BOLD << dealer << RESET << "\n";
        
        for (const auto& pair : items) 
        {
            const auto& item = pair.second;
            if (item.place_to_dealer == dealer) 
            {
                std::cout << CYAN << "Item Code: " << BOLD << item.item_code 
                          << RESET << CYAN << ", Price: " << BOLD << item.price << RESET << '\n';
                found = true;
            }
        }
        if (!found) 
        {
            std::cout << YELLOW << "No items found for dealer: " << dealer << RESET << '\n';
        }
    }

    void sortItemsByPrice() 
    {
        std::vector<Item> sortedItems;
        for (const auto& pair : items) 
        {
            sortedItems.push_back(pair.second);
        }

        std::sort(sortedItems.begin(), sortedItems.end(), 
            [](const Item& a, const Item& b) { return a.price < b.price; });

        std::cout << MAGENTA << BOLD << "Items sorted by price:\n" << RESET;
        for (const auto& item : sortedItems) 
        {
            std::cout << CYAN << "Item Code: " << BOLD << item.item_code 
                      << RESET << CYAN << ", Price: " << BOLD << item.price 
                      << RESET << CYAN << ", Dealer: " << BOLD << item.place_to_dealer << RESET << '\n';
        }
    }

    void saveToFile() 
    {
        std::ofstream file("items.txt");
        if (!file) 
        {
            std::cout << RED << "Error opening file for writing!\n" << RESET;
            return;
        }
        
        for (const auto& pair : items) 
        {
            const auto& item = pair.second;
            file << item.item_code << "," << item.price << "," << item.place_to_dealer << "\n";
        }

        file.close();
        std::cout << GREEN << "Items saved successfully!\n" << RESET;
    }

    void loadFromFile() 
    {
        std::ifstream file("items.txt");
        if (!file) 
        {
            std::cout << YELLOW << "No existing data found.\n" << RESET;
            return;
        }

        items.clear();
        itemCount = 0;

        std::string line, item_code, place_to_dealer;
        double price;
        
        while (std::getline(file, line)) 
        {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            
            if (pos1 != std::string::npos && pos2 != std::string::npos) 
            {
                item_code = line.substr(0, pos1);
                price = std::stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
                place_to_dealer = line.substr(pos2 + 1);
                
                items[item_code] = {item_code, price, place_to_dealer};
                itemCount++;
            }
        }

        file.close();
        std::cout << GREEN << "Data loaded successfully!\n" << RESET;
    }

    static int getItemCount() 
    {
        return itemCount;
    }
};

int MonthlyItemList::itemCount = 0;

int main() 
{
    MonthlyItemList monthlyList;
    monthlyList.loadFromFile();

    int choice;
    std::string item_code, place_to_dealer;
    double price;

    do 
    {
        std::cout << "\n" << BLUE << BOLD << "Menu:\n" << RESET;
        std::cout << CYAN << "1. Add Item\n2. Delete Item\n3. Print Item\n4. Display All Items\n";
        std::cout << "5. Search by Dealer\n6. Sort by Price\n7. Exit\n" << RESET;
        std::cout << YELLOW << "Enter your choice: " << RESET;
        std::cin >> choice;

        switch(choice) 
        {
            case 1:
                std::cout << YELLOW << "Enter Item Code: " << RESET;
                std::cin >> item_code;
                std::cout << YELLOW << "Enter Price: " << RESET;
                std::cin >> price;
                std::cout << YELLOW << "Enter Place to Dealer: " << RESET;
                std::cin.ignore();
                std::getline(std::cin, place_to_dealer);
                monthlyList.addItem(item_code, price, place_to_dealer);
                break;
            case 2:
                std::cout << YELLOW << "Enter Item Code to Delete: " << RESET;
                std::cin >> item_code;
                monthlyList.deleteItem(item_code);
                break;
            case 3:
                std::cout << YELLOW << "Enter Item Code to Print: " << RESET;
                std::cin >> item_code;
                monthlyList.printItem(item_code);
                break;
            case 4:
                monthlyList.displayAllItems();
                break;
            case 5:
                std::cout << YELLOW << "Enter Dealer Name: " << RESET;
                std::cin.ignore();
                std::getline(std::cin, place_to_dealer);
                monthlyList.searchByDealer(place_to_dealer);
                break;
            case 6:
                monthlyList.sortItemsByPrice();
                break;
            case 7:
                monthlyList.saveToFile();
                std::cout << MAGENTA << "Exiting...\n" << RESET;
                break;
            default:
                std::cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }
    } while (choice != 7);

    return 0;
}
