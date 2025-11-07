Bank Management System - C++ OOP Project
 Project Overview
A comprehensive Bank Management System built using C++ and Object-Oriented Programming principles. This console-based application provides complete banking operations with multi-user support, transaction management, and currency exchange capabilities.

 Architecture & Design Patterns
Core OOP Principles Implemented
Encapsulation: Private data members with public interfaces

Inheritance: Class hierarchies (clsPerson → clsBankClient)

Polymorphism: Virtual functions and method overriding

Abstraction: Clean separation between interface and implementation

System Architecture
Layered Architecture: Presentation → Business Logic → Data Access

Modular Design: Independent components for each banking operation

Singleton Pattern: Global session management

Factory Pattern: Object creation (CreateNewClient, AddNewUser)

 Security Features
Password Encryption System
cpp
// Current Implementation (Plain Text - Needs Enhancement)
class clsUser {
private:
    string _Password; // Currently stored in plain text
public:
    //  PLANNED ENCRYPTION IMPLEMENTATION:
    string EncryptPassword(const string& password) {
        // AES-256 or bcrypt implementation needed
        // Hash + salt for secure storage
    }
    
    bool VerifyPassword(const string& inputPassword) {
        // Compare encrypted input with stored hash
    }
};
Authentication & Authorization
Multi-layer login system with attempt limiting

Role-based permissions with granular access control

Session management with automatic logout

Activity logging for security auditing

 Banking Modules
1. Client Management
Add New Clients with account number generation

Update Client Information (personal details, balance)

Delete Client Accounts with confirmation

Find Clients by account number

Client List Display with sorting and filtering

2. Account Operations
Deposit Transactions with balance updating

Withdrawal Processing with overdraft protection

Fund Transfers between accounts

Balance Inquiries with transaction history

PIN Code Management

3. Transaction System
Complete Audit Trail for all transactions

Transfer Logging with timestamps

Balance Tracking with real-time updates

Receipt Generation for all operations

 User Management System
Permission Levels
cpp
enum enPermission {
    All = -1,
    ShowClientsList = 1,
    AddClient = 2,
    DeleteClient = 4,
    UpdateClient = 8,
    FindClient = 16,
    Transaction = 32,
    ManageUsers = 64,
    LogIn = 128
};
User Operations
Add New Users with role assignment

Modify User Permissions

Delete User Accounts

User Activity Monitoring

Login Session Tracking

🌍 Currency Exchange System
Features
Real-time Currency Rates management

Multi-currency Support (USD, EUR, GBP, etc.)

Currency Conversion Calculator

Exchange Rate Updates

International Transfer Support

Currency Operations
List All Currencies with current rates

Find Currency by country or code

Update Exchange Rates

Cross-currency Calculations

 Data Management
File-Based Storage System
Clients Data: Clients.txt

Users Data: Users.txt

Currency Rates: Currency.txt

Transaction Logs: TransferLog.txt

Login Records: LoginLog.txt

Data Persistence
CSV-style formatting with custom delimiters (#//#)

Automatic backup during operations

Data validation before storage

Error recovery mechanisms

 Security Implementation Details
Current Security Features
Input Validation against injection attacks

Session Timeout protection

Access Control Lists (ACL)

Activity Logging for audit trails

Attempt Limiting for login security

Planned Security Enhancements
cpp
// FUTURE SECURITY UPGRADES:
class SecurityManager {
public:
    static string HashPassword(const string& password);
    static bool ValidatePassword(const string& password);
    static string GenerateSessionToken();
    static void AuditLog(const string& action);
};
 User Interface
Console Interface Features
Menu-driven Navigation with intuitive options

Form Validation with error messages

Data Display with formatted tables

Confirmation Dialogs for critical operations

Progress Indicators for long operations

Screen Management
Login Screen with secure authentication

Main Dashboard with role-based menus

Transaction Screens with step-by-step guidance

Admin Panels for system management

 Technical Specifications
Built With
C++17 Standard

Standard Template Library (STL)

File I/O Operations

Object-Oriented Design

Modular Programming
