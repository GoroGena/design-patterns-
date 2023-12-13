#include <iostream>
#include <string>

// Абстрактний клас квіткового подарунка
class FlowerGift {
public:
    virtual void display() const = 0;
};

// Абстрактний клас подарунка з солодощами
class CandyGift {
public:
    virtual void show() const = 0;
};

// Абстрактна фабрика
class GiftFactory {
public:
    virtual FlowerGift* createFlowerGift() const = 0;
    virtual CandyGift* createCandyGift() const = 0;
};

// Конкретна реалізація квіткового подарунка
class RoseFlowerGift : public FlowerGift {
public:
    void display() const override {
        std::cout << "Це букет троянд!" << std::endl;
    }
};

// Конкретна реалізація подарунка з солодощами
class ChocolateCandyGift : public CandyGift {
public:
    void show() const override {
        std::cout << "Це коробка шоколадних цукерок!" << std::endl;
    }
};

// Конкретна реалізація абстрактної фабрики
class RomanticGiftFactory : public GiftFactory {
public:
    FlowerGift* createFlowerGift() const override {
        return new RoseFlowerGift();
    }

    CandyGift* createCandyGift() const override {
        return new ChocolateCandyGift();
    }
};

int main() {
    // Використання абстрактної фабрики для створення комплексного подарунка
    GiftFactory* romanticFactory = new RomanticGiftFactory();
    FlowerGift* romanticFlowerGift = romanticFactory->createFlowerGift();
    CandyGift* romanticCandyGift = romanticFactory->createCandyGift();

    romanticFlowerGift->display();
    romanticCandyGift->show();

    // Звільнення ресурсів
    delete romanticFactory;
    delete romanticFlowerGift;
    delete romanticCandyGift;

    return 0;
}
