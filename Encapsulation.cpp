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
class Boiler {
public:
    void turnOn() {
        std::cout << "Boiler turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Boiler turned off." << std::endl;
    }
};

class Thermostat {
private:
    double currentTemperature;
    Boiler* boiler;

public:
    Thermostat(double temperature, Boiler* contolledBoiler) : currentTemperature(temperature), boiler(contolledBoiler) {}

    void updateTemperature(double temperature) {
        currentTemperature = temperature;
        controlBoiler(); 
    }

    void controlBoiler() {
        if (currentTemperature < 20.0) {
            boiler->turnOn();
        }
        else {
            boiler->turnOff();
        }
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
        if (isAvailable) {
            isAvailable = false;
            std::cout << "Book borrowed successfully." << std::endl;
        }
        else {
            std::cout << "Book is not available for borrowing." << std::endl;
        }
    }

    void returnBook() {
        isAvailable = true;
        std::cout << "Book returned successfully." << std::endl;
    }
};

class Library {
public:
    void processBookBorrowing(Book& book) {
        // Violates Tell, Don't Ask
        if (book.checkAvailability()) {
            book.borrowBook();
          //  std::cout << "Book borrowed successfully." << std::endl;
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

    Boiler heating;
    Thermostat thermostat(18, &heating);

    // Simulate temperature changes
    thermostat.updateTemperature(18.5); // Heating system should turn on
    thermostat.updateTemperature(21.0); // Heating system should turn off


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
