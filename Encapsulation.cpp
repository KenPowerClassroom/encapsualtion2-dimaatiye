#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}


    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        }
        else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
            std::cout << "New balance: $" << balance << std::endl;
        }
        else {
            std::cout << "Withdrawal failed: Insufficient funds or invalid amount." << std::endl;
        }
    }
    void displayBalance() const {
        std::cout << "Current balance: $" << balance << std::endl;
    }

};
class HeatingSystem {
public:
    void turnOn() {
        std::cout << "Heating system turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Heating system turned off." << std::endl;
    }
};

class Thermostat {
private:
    double currentTemperature;

public:
    Thermostat(double temperature) : currentTemperature(temperature) {}

    double getCurrentTemperature() const {
        return currentTemperature;
    }
};
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    bool isAvailable;

public:
    Book(const std::string& title) : title(title), isAvailable(true) {}

    bool checkAvailability() const {
        return isAvailable;
    }

    void borrowBook() {
        isAvailable = false;
    }

    void returnBook() {
        isAvailable = true;
    }
};

class Library {
public:
    void processBookBorrowing(Book& book) {
        // Violates Tell, Don't Ask
        if (book.checkAvailability()) {
            book.borrowBook();
            std::cout << "Book borrowed successfully." << std::endl;
        }
        else {
            std::cout << "Book is not available for borrowing." << std::endl;
        }
    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    int getHealth() const {
        return health;
    }

    int getAmmo() const {
        return ammo;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    void useAmmo() {
        ammo--;
    }
};

class Game {
public:
    void enemyAttack(Player& player) {
        if (player.getHealth() > 0 && player.getAmmo() > 0) {
            player.takeDamage(10);
            player.useAmmo();
            std::cout << "Player attacked and used ammo." << std::endl;
        }
        else {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }
};


int main() {
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////

    BankAccount account(1000.0);

    // Violation of Tell, Don't Ask

    account.withdraw(500);
    account.displayBalance();
    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5);
    HeatingSystem heating;

    if (thermostat.getCurrentTemperature() < 20.0) {
        heating.turnOn();
    }
    else {
        heating.turnOff();
    }

    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////

    Book myBook("1984");
    Library library;

    library.processBookBorrowing(myBook);  // First borrow should succeed
    library.processBookBorrowing(myBook);  // Second attempt should show not available

    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////
    Player player;
    Game game;

    game.enemyAttack(player); // Player can respond to attack

    return 0;
}
