# Monthly Item Management System

## Description
A robust C++ console application designed for managing monthly item inventory with support for colored output and file persistence. This system allows users to perform various operations on items including addition, deletion, searching, and sorting functionalities.

## Features

### Core Functionality
- ✨ Add new items with unique item codes
- 🗑️ Delete existing items
- 🔍 Search items by dealer name
- 💰 Sort items by price
- 📋 Display comprehensive item listings
- 💾 Automatic data persistence

### User Interface
- 🎨 Color-coded console output for enhanced readability
- 📝 Interactive menu system
- ⚡ Real-time feedback for all operations
- 📊 Formatted table display for item listings

### Data Management
- 📁 Automatic file-based data persistence
- 📥 Data loading on startup
- 📤 Auto-save on exit
- 🔐 Input validation for data integrity

## Technical Details

### Dependencies
- C++11 or higher
- Standard C++ libraries
- ANSI-compatible terminal

### Data Structure
- Uses `unordered_map` for O(1) item lookups
- CSV file format for data storage
- Structured item representation with code, price, and dealer info

### File Format
```csv
item_code,price,dealer_name
```

## Building and Running

### Windows
```bash
g++ Item.cpp -o Item.exe
./Item.exe
```

## Usage Guide

1. **Add Item (Option 1)**
   - Enter item code
   - Specify price
   - Input dealer information

2. **Delete Item (Option 2)**
   - Enter item code to remove

3. **Print Item (Option 3)**
   - View specific item details

4. **Display All Items (Option 4)**
   - View formatted table of all items

5. **Search by Dealer (Option 5)**
   - Enter dealer name to filter items

6. **Sort by Price (Option 6)**
   - Display items sorted by price

7. **Exit (Option 7)**
   - Save and exit program

## Error Handling
- Duplicate item code prevention
- Price validation (must be positive)
- File operation error handling
- Input validation

## Data Persistence
- Items automatically saved to `items.txt`
- Data loaded on program start
- Fail-safe file operations

## Contributing
Feel free to submit issues and enhancement requests!

<!--## License
This project is open source and available under the MIT License.-->
