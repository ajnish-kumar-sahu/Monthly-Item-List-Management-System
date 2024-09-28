#include <iostream>
#include <vector>
#include <string>

class MonthlyItemList 
{
private:
    struct Item 
    {
        std::string item_code;
        double price;
        std::string place_to_dealer;
    };
    
    std::vector<Item> items;
    static int itemCount;

public:
    void addItem(const std::string& item_code, double price, const std::string& place_to_dealer) 
    {
        Item newItem = {item_code, price, place_to_dealer};
        items.push_back(newItem);
        itemCount++;
    }

    void deleteItem(const std::string& item_code) 
    {
        for (auto it = items.begin(); it != items.end(); ++it) 
        {
            if (it->item_code == item_code) 
            {
                items.erase(it);
                itemCount--;
                std::cout << "Item with code " << item_code << " deleted.\n";
                return;
            }
        }
        std::cout << "Item with code " << item_code << " not found.\n";
    }

    void printItem(const std::string& item_code) const 
    {
        for (const auto& item : items) 
        {
            if (item.item_code == item_code) 
            {
                std::cout << "Item Code: " << item.item_code << ", Price: " << item.price 
                          << ", Dealer: " << item.place_to_dealer << '\n';
                return;
            }
        }
        std::cout << "Item with code " << item_code << " not found.\n";
    }

    void displayAllItems() const 
    {
        if (items.empty()) 
        {
            std::cout << "No items in the list.\n";
            return;
        }
        for (const auto& item : items) 
        {
            std::cout << "Item Code: " << item.item_code << ", Price: " << item.price << ", Dealer: " << item.place_to_dealer << '\n';
        }
    }

    static int getItemCount() 
    {
        return itemCount;
    }
};

// Initialize static member
int MonthlyItemList::itemCount = 0;

int main() 
{
    MonthlyItemList monthlyList;
    int choice;
    std::string item_code, place_to_dealer;
    double price;

    do 
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Delete Item\n";
        std::cout << "3. Print Item\n";
        std::cout << "4. Display All Items\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) 
        {
            case 1:
                std::cout << "Enter Item Code: ";
                std::cin >> item_code;
                std::cout << "Enter Price: ";
                std::cin >> price;
                std::cout << "Enter Place to Dealer: ";
                std::cin.ignore();  // To ignore the newline character left in the buffer
                std::getline(std::cin, place_to_dealer);
                monthlyList.addItem(item_code, price, place_to_dealer);
                break;

            case 2:
                std::cout << "Enter Item Code to Delete: ";
                std::cin >> item_code;
                monthlyList.deleteItem(item_code);
                break;

            case 3:
                std::cout << "Enter Item Code to Print: ";
                std::cin >> item_code;
                monthlyList.printItem(item_code);
                break;

            case 4:
                monthlyList.displayAllItems();
                break;

            case 5:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}