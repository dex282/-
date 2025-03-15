#include <iostream>
#include <string>
using namespace std;

// Базовый класс для всех игровых персонажей
class Character {
protected:
    string name;    // Имя персонажа
    int health;     // Количество здоровья

public:
    // Конструктор для инициализации имени и здоровья
    Character(string n, int h) : name(n), health(h) {}

    // Виртуальный метод для атаки (может быть переопределен)
    virtual void attack() {
        cout << name << " performs a basic attack!" << endl;
    }

    // Метод для получения урона
    void takeDamage(int damage) {
        health -= damage;
        cout << name << " takes " << damage 
             << " damage. Remaining health: " << health << endl;
    }

    // Виртуальный деструктор для корректной работы полиморфизма
    virtual ~Character() {}
};

// Производный класс: Воин
class Warrior : public Character {
    int strength;  // Сила атаки

public:
    // Конструктор с параметрами для воина
    Warrior(string n, int h, int str) 
        : Character(n, h), strength(str) {}

    // Переопределенный метод атаки с учетом силы
    void attack() override {
        cout << name << " lashes with sword (strength: " 
             << strength << ")!" << endl;
    }

    // Уникальная способность: активация щита
    void activateShield() {
        cout << name << "   qraises shield (+50  defense)" << endl;
    }
};

// Производный класс: Маг
class Mage : public Character {
    int mana;  // Магическая энергия

public:
    // Конструктор с параметрами для мага
    Mage(string n, int h, int m) 
        : Character(n, h), mana(m) {}

    // Переопределенный метод атаки с проверкой маны
    void attack() override {
        if(mana >= 15) {
            cout << name << "casts fireball (mana: -15)" << endl;
            mana -= 15;
        } else {
            cout << "Not enough mana!" << endl;
        }
    }

    // Метод восстановления маны
    void restoreMana(int amount) {
        mana += amount;
        cout << name << " restores " << amount << " mana" << endl;
    }
};

// Производный класс: Лучник
class Archer : public Character {
    int agility;  // Ловкость

public:
    // Конструктор с параметрами для лучника
    Archer(string n, int h, int agi) 
        : Character(n, h), agility(agi) {}

    // Переопределенный метод атаки с использованием ловкости
    void attack() override {
        cout << name << " shoots arrow (agility:  " 
             << agility << ")" << endl;
    }

    // Способность уклонения (уникальная для лучника)
    void dodge() {
        cout << name << " dodges the attack!" << endl;
    }
};

// Пользовательский класс: Берсерк
class Berserker : public Character {
    int rage;  // Уровень ярости

public:
    // Конструктор с параметрами для берсерка
    Berserker(string n, int h, int r) 
        : Character(n, h), rage(r) {}

    // Переопределенный метод атаки с использованием ярости
    void attack() override {
        cout << name << "  unleashes furious attack (+" 
             << rage << " damage)" << endl;
        rage = max(0, rage - 10);  // Защита от отрицательных значений
    }

    // Уникальная способность: берсеркерская ярость
    void berserkRage() {
        rage += 25;
        cout << name << "  enters berserker rage!" << endl;
    }
};

int main() {
    // Создание экземпляров персонажей
    Warrior conan("Conan", 150, 35);
    Mage merlin("Merlin", 80, 100);
    Archer legolas("Legolas", 110, 90);
    Berserker kratos("Kratos", 200, 50);

    // Демонстрация возможностей персонажей
    conan.attack();          // Атака воина
    conan.activateShield();  // Активация щита
    conan.takeDamage(20);    // Получение урона

    merlin.attack();         // Атака мага
    merlin.restoreMana(30);  // Восстановление маны
    merlin.takeDamage(15);   // Получение урона

    legolas.attack();        // Атака лучника
    legolas.dodge();         // Уклонение
    legolas.takeDamage(25);  // Получение урона

    kratos.attack();         // Атака берсерка
    kratos.berserkRage();    // Активация ярости
    kratos.attack();         // Повторная атака

    return 0;
}
