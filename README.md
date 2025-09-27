# 🔰 CPP Module 00 - Namespaces, Classes, Member Functions

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![Module](https://img.shields.io/badge/Module-00-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

*Your first steps into the world of C++*

</div>

## 📖 Overview

**CPP Module 00** serves as your gateway into C++ programming, introducing fundamental concepts that form the backbone of object-oriented programming. This module focuses on **namespaces**, **classes**, **member functions**, and the transition from C to C++.

### 🎯 Learning Objectives

- Master basic C++ syntax and conventions
- Understand the concept of classes and objects
- Learn about member functions and access specifiers
- Practice string manipulation and I/O operations
- Implement basic data structures (arrays of objects)
- Explore static members and class design

## 💡 Key Concepts Introduced

- **Classes and Objects**: Object-oriented programming fundamentals
- **Member Functions**: Methods that operate on class data
- **Constructors/Destructors**: Object initialization and cleanup
- **Access Specifiers**: Private, public, and protected members
- **Static Members**: Class-level variables and functions
- **String Manipulation**: Working with C++ strings
- **Input/Output Streams**: Using iostream for user interaction

## 🚀 Exercises

### 📢 Exercise 00: Megaphone
**File**: `megaphone.cpp`

A simple program that converts command-line arguments to uppercase, demonstrating:
- Basic C++ syntax
- Command-line argument handling
- String manipulation with `std::toupper()`
- Input/output operations

**Usage**:
```bash
./megaphone "hello world"
# Output: HELLO WORLD

./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**Key Learning Points**:
- Introduction to `std::cout` and `std::endl`
- Character manipulation functions
- Loop structures in C++
- Command-line argument processing

---

### 📞 Exercise 01: PhoneBook
**Files**: `PhoneBook.cpp`, `PhoneBook.hpp`, `Contact.cpp`, `Contact.hpp`, `main.cpp`

An interactive phonebook application that manages up to 8 contacts, showcasing:
- Class design and implementation
- Object arrays and management
- User input validation
- Data formatting and display

**Features**:
- **ADD**: Add new contacts (circular buffer of 8)
- **SEARCH**: Display and search through contacts
- **EXIT**: Quit the application

**Classes**:

#### `Contact` Class
```cpp
class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    unsigned int phone_number;
    std::string darkest_secret;

public:
    Contact(void);
    ~Contact(void);
    // Setters and getters...
};
```

#### `PhoneBook` Class
```cpp
class PhoneBook {
private:
    Contact contacts[8];
    int index;
    int contact_count;

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void addContact(void);
    void searchContact(void);
    // Other member functions...
};
```

**Key Learning Points**:
- Class design and member organization
- Constructor and destructor implementation
- Array management within classes
- Input validation and error handling
- String formatting and truncation
- Interactive user interface design

---

### 🏦 Exercise 02: Account
**Files**: `Account.cpp`, `Account.hpp`, `tests.cpp`

A banking simulation that implements account management with static members, demonstrating:
- Static member variables and functions
- Timestamp formatting
- Global state management
- Log formatting

**Features**:
- Account creation and management
- Deposit and withdrawal operations
- Transaction logging with timestamps
- Global account statistics

**Class Structure**:
```cpp
class Account {
private:
    static int _nbAccounts;
    static int _totalAmount;
    static int _totalNbDeposits;
    static int _totalNbWithdrawals;

    int _accountIndex;
    int _amount;
    int _nbDeposits;
    int _nbWithdrawals;

public:
    static int getNbAccounts(void);
    static int getTotalAmount(void);
    static void displayAccountsInfos(void);

    Account(int initial_deposit);
    ~Account(void);

    void makeDeposit(int deposit);
    bool makeWithdrawal(int withdrawal);
    int checkAmount(void) const;
    void displayStatus(void) const;
};
```

**Sample Output**:
```
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] accounts:2;total:96;deposits:0;withdrawals:0
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
```

**Key Learning Points**:
- Static member variables and functions
- Global state management
- Timestamp generation and formatting
- Const correctness
- Log formatting and output consistency

## 🛠️ Compilation

Each exercise includes a Makefile with standard targets:

```bash
# Compile the program
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

**Compilation flags**:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## 🎮 How to Run

### Exercise 00 - Megaphone
```bash
cd ex00
make
./megaphone "Hello World" "42 School"
./megaphone
```

### Exercise 01 - PhoneBook
```bash
cd ex01
make
./phonebook
# Follow interactive prompts:
# ADD - to add a contact
# SEARCH - to search contacts
# EXIT - to quit
```

### Exercise 02 - Account
```bash
cd ex02
make
./account
# Runs predefined test cases
```

## 🧪 Testing Examples

### PhoneBook Interactive Session
```
Welcome to your PhoneBook!
Available commands: ADD, SEARCH, EXIT
> ADD
First name: John
Last name: Doe
Nickname: JD
Phone number: 123456789
Darkest secret: Loves pineapple pizza

> SEARCH
|     Index|First Name| Last Name|  Nickname|
|         0|      John|       Doe|        JD|

Enter index to display: 0
First name: John
Last name: Doe
Nickname: JD
Phone number: 123456789
Darkest secret: Loves pineapple pizza

> EXIT
Goodbye!
```

## 🏗️ Project Structure

```
CPP_Module00/
├── README.md
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── PhoneBook.cpp
│   ├── PhoneBook.hpp
│   ├── Contact.cpp
│   └── Contact.hpp
└── ex02/
    ├── Makefile
    ├── Account.cpp
    ├── Account.hpp
    └── tests.cpp
```

## 💡 Key Takeaways

1. **Object-Oriented Design**: Understanding how to model real-world entities as classes
2. **Encapsulation**: Proper use of private/public access specifiers
3. **Static Members**: Managing class-level data and functionality
4. **Input Validation**: Handling user input safely and effectively
5. **Memory Management**: Basic understanding of object lifecycle
6. **Code Organization**: Separating interface (.hpp) from implementation (.cpp)

## 🎯 Skills Developed

- ✅ Class design and implementation
- ✅ Constructor and destructor usage
- ✅ Member function implementation
- ✅ Static member management
- ✅ String manipulation and formatting
- ✅ Input/output operations
- ✅ Interactive program design
- ✅ Code organization and file structure

## 🔗 Next Steps

After mastering Module 00, you'll be ready to tackle:
- **Module 01**: Memory allocation, references, and pointers
- **Module 02**: Operator overloading and Orthodox Canonical Form
- **Module 03**: Inheritance hierarchies

---

<div align="center">

*"Every expert was once a beginner. Every pro was once an amateur."*

**Module 00 Complete** ✨ | **Next**: [Module 01 →](github.com/melaniereis/CPP_Module01/)

</div>
