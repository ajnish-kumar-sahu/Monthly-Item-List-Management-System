# Monthly Item List Management System

This C++ program implements a simple monthly item list management system. It allows users to add, delete, print, and display all items in the list.

## Features

*   Add items to the list with a unique item code, price, and place to dealer
*   Delete items from the list by item code
*   Print a specific item's details by item code
*   Display all items in the list

## Usage

1.  Compile the program using `g++ -o monthly_list monthly_list.cpp`
2.  Run the program using `./monthly_list`
3.  Follow the menu prompts to add, delete, print, or display all items

## Code Structure

The code is organized into the following files:

*   `monthly_list.cpp`: The main program file
*   `monthly_list.h`: The header file for the `MonthlyItemList` class (not included in this example)

## Classes

*   `MonthlyItemList`: A class representing a monthly item list
    *   `addItem`: Adds an item to the list
    *   `deleteItem`: Deletes an item from the list by item code
    *   `printItem`: Prints a specific item's details by item code
    *   `displayAllItems`: Displays all items in the list

## Variables

*   `itemCount`: A static variable keeping track of the number of items in the list

## Functions

*   `addItem`: Adds an item to the list
*   `deleteItem`: Deletes an item from the list by item code
*   `printItem`: Prints a specific item's details by item code
*   `displayAllItems`: Displays all items in the list
*   `getItemCount`: Returns the number of items in the list