# Monthly Item Management System

## 🚀 Overview
A C++ console application for managing inventory items with colored output, file persistence, and real-time updates.

## ✨ Features

### Core Functionalities
- ✅ Add new items with validation
- 🗑️ Delete existing items
- 🔍 Search specific items
- 📋 Display formatted item listings
- 💾 Automatic data persistence
- 🎨 Color-coded console interface

### Item Properties
- Item Code (unique identifier)
- Price
- Dealer Information
- Category
- Date Added

## 🛠️ Technical Requirements

### Prerequisites
- C++11 compatible compiler
- Windows terminal with ANSI color support
- Visual Studio Code (recommended)

### Dependencies
```cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <sstream>
```

## 📦 Installation

1. Clone the repository:
```bash
git clone https://github.com/ajnish-kumar-sahu/monthly-item-management.git
cd monthly-item-management
```

2. Compile the program:
```bash
g++ -std=c++11 Item.cpp -o Item.exe
```

3. Run the application:
```bash
./Item.exe
```

## 📝 Usage Guide

### Main Menu Options
1. **Add Item**
   - Enter item code
   - Specify price
   - Add dealer information
   - Set category
   - Input date

2. **Delete Item**
   - Remove items using their unique code

3. **Print Item**
   - View detailed information of specific items

4. **Display All Items**
   - See complete inventory in tabulated format

5. **Save to File**
   - Persist data to items.txt

6. **Load from File**
   - Restore data from items.txt

7. **Exit**
   - Save and close application

## 💾 Data Storage

Items are stored in `items.txt` using CSV format:
```
item_code,price,dealer_name,category,date_added
```

## 🔒 Data Validation
- Unique item code verification
- Positive price validation
- Required field checks
- File operation error handling

## 📁 Project Structure
```
monthly-item-management/
├── Item.cpp
├── items.txt
└── README.md
```

## 🤝 Contributing
1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Open a Pull Request

## 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
