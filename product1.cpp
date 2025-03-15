// product.cpp
#include "product1.h"   
#include <stdexcept>

// Конструктор
Product::Product(int id, const char* name, double cost, Supplier s) 
    : id(id), cost(cost), supplier(s), name(nullptr) {
    copyString(this->name, name);
}

// Конструктор копирования
Product::Product(const Product& other) 
    : id(other.id), cost(other.cost), supplier(other.supplier), name(nullptr) {
    copyString(name, other.name);
}

// Деструктор
Product::~Product() {
    delete[] name;
}

// Сеттер для имени с обработкой динамической памяти
void Product::setName(const char* newName) {
    copyString(name, newName);
}

// Вывод краткой информации (ID и название)
void Product::printShort() const {
    std::cout << "[" << id << "] " << name << "\n";
}

// Вывод полной информации о товаре
void Product::printFull() const {
    std::cout << "article number: " << id << "\n"
              << "Name: " << name << "\n"
              << "Cost of production: $" << cost << "\n"
              << "The supplier: ";

    switch(supplier) {
        case Supplier::SUPPLIER_A: std::cout << "The supplier A"; break;
        case Supplier::SUPPLIER_B: std::cout << "The supplier B"; break;
        case Supplier::SUPPLIER_C: std::cout << "The supplier C"; break;
        default: std::cout << "Неизвестный";
    }
    std::cout << "\n\n";
}

// Вспомогательная функция для безопасного копирования строк
void Product::copyString(char*& dest, const char* src) {
    delete[] dest; // Удаляем старые данные
    
    if(src) {
        size_t length = strlen(src) + 1;
        dest = new char[length];
        strcpy(dest, src);
    } else {
        dest = nullptr;
    }
}
