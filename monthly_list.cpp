#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <sstream>

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
        std::string category;      
        std::string date_added;    
    };
    
    std::unordered_map<std::string, Item> items;
    static int itemCount;

public:
    void addItem(const std::string& item_code, double price, const std::string& place_to_dealer, const std::string& category, const std::string& date_added) 
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

        items[item_code] = {item_code, price, place_to_dealer, category, date_added};
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
                      << ", Dealer: " << BOLD << item.place_to_dealer << RESET << CYAN
                      << ", Category: " << BOLD << item.category << RESET << CYAN
                      << ", Date Added: " << BOLD << item.date_added << RESET << '\n';
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
        std::cout << "-----------------------------------------------------------------------\n";
        std::cout << "| Item Code | Price      | Dealer           | Category    | Date Added |\n";
        std::cout << "-----------------------------------------------------------------------\n" << RESET;
        
        for (const auto& pair : items) 
        {
            const auto& item = pair.second;
            std::cout << CYAN << "| " << std::left << std::setw(9) << item.item_code 
                      << " | " << std::setw(10) << item.price 
                      << " | " << std::setw(15) << item.place_to_dealer 
                      << " | " << std::setw(10) << item.category 
                      << " | " << std::setw(10) << item.date_added << " |\n" << RESET;
        }
        
        std::cout << BLUE << BOLD;
        std::cout << "--------------------------------------------------------------------------4\n" << RESET;
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
            file << item.item_code << "," 
                 << item.price << "," 
                 << item.place_to_dealer << "," 
                 << item.category << "," 
                 << item.date_added << "\n";
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

        std::string line, item_code, place_to_dealer, category, date_added;
        double price;

        while (std::getline(file, line)) 
        {
            std::stringstream ss(line);
            std::getline(ss, item_code, ',');
            ss >> price;
            ss.ignore();  
            std::getline(ss, place_to_dealer, ',');
            std::getline(ss, category, ',');
            std::getline(ss, date_added);

            items[item_code] = {item_code, price, place_to_dealer, category, date_added};
            itemCount++;
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
    std::string item_code, place_to_dealer, category, date_added;
    double price;

    do 
    {
        std::cout << "\n" << BLUE << BOLD << "Menu:\n" << RESET;
        std::cout << CYAN 
                  << "1. Add Item\n2. Delete Item\n3. Print Item\n4. Display All Items\n"
                  << "5. Save to File\n6. Load from File\n7. Exit\n" << RESET;
        std::cout << YELLOW << "Enter your choice: " << RESET;
        std::cin >> choice;

        switch(choice) 
        {
            case 1:
                std::cout << YELLOW << "Enter Item Code: " << RESET;
                std::cin >> item_code;
                std::cout << YELLOW << "Enter Price: " << RESET;
                std::cin >> price;
                std::cin.ignore();  
                std::cout << YELLOW << "Enter Dealer: " << RESET;
                std::getline(std::cin, place_to_dealer);
                std::cout << YELLOW << "Enter Category: " << RESET;
                std::getline(std::cin, category);
                std::cout << YELLOW << "Enter Date Added (YYYY-MM-DD): " << RESET;
                std::getline(std::cin, date_added);
                monthlyList.addItem(item_code, price, place_to_dealer, category, date_added);
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
                monthlyList.saveToFile();
                break;
            case 6:
                monthlyList.loadFromFile();
                break;
            case 7:
                std::cout << MAGENTA << "Exiting...\n" << RESET;
                break;
            default:
                std::cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }
    } while (choice != 7);

    return 0;
}
