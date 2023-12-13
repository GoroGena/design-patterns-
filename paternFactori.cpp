#include <iostream>
#include <string>

// Базовий клас для подарунків
class Gift {
public:
    virtual void display() const = 0;
};

// Клас для подарунка "Квіти"
class FlowerGift : public Gift {
public:
    void display() const override {
        std::cout << "Це букет квітів!" << std::endl;
    }
};

// Клас для подарунка "Солодощі"
class CandyGift : public Gift {
public:
    void display() const override {
        std::cout << "Це коробка солодощів!" << std::endl;
    }
};

// Фабричний метод для створення подарунків
class GiftFactory {
public:
    virtual Gift* createGift() const = 0;
};

// Фабрика для створення квіткових подарунків
class FlowerGiftFactory : public GiftFactory {
public:
    Gift* createGift() const override {
        return new FlowerGift();
    }
};

// Фабрика для створення подарунків з солодощами
class CandyGiftFactory : public GiftFactory {
public:
    Gift* createGift() const override {
        return new CandyGift();
    }
};

int main() {
    // Використання фабричного методу для створення квіткового подарунка
    GiftFactory* flowerFactory = new FlowerGiftFactory();
    Gift* flowerGift = flowerFactory->createGift();
    flowerGift->display();

    // Використання фабричного методу для створення подарунка з солодощами
    GiftFactory* candyFactory = new CandyGiftFactory();
    Gift* candyGift = candyFactory->createGift();
    candyGift->display();

    // Звільнення ресурсів
    delete flowerFactory;
    delete flowerGift;
    delete candyFactory;
    delete candyGift;

    return 0;
}
