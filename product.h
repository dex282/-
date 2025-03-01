
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <cstring>

// Перечисление поставщиков
enum class Supplier {
    UNKNOWN,
    SUPPLIER_A,
    SUPPLIER_B,
    SUPPLIER_C
};

class Product {
private:
    int id;             // Артикул/ID
    char* name;         // Динамическая строка для названия
    double cost;        // Себестоимость
    Supplier supplier;  // Поставщик

public:
    // Конструкторы
    Product(int id = 0, const char* name = "", double cost = 0.0, Supplier s = Supplier::UNKNOWN);
    Product(const Product& other); // Конструктор копирования
    
    // Деструктор
    ~Product();

    // Геттеры
    int getId() const { return id; }
    const char* getName() const { return name; }
    double getCost() const { return cost; }
    Supplier getSupplier() const { return supplier; }

    // Сеттеры
    void setId(int id) { this->id = id; }
    void setName(const char* newName);
    void setCost(double cost) { this->cost = cost; }
    void setSupplier(Supplier s) { supplier = s; }

    // Методы вывода информации
    void printShort() const;
    void printFull() const;

private:
    void copyString(char*& dest, const char* src); // Утилита для копирования строк
};

#endif // PRODUCT_H
