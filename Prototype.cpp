#include <iostream>
#include <string>

// Абстрактний клас прототипа подарунка
class GiftPrototype {
public:
    virtual GiftPrototype* clone() const = 0;
    virtual void display() const = 0;
};

// Конкретна реалізація прототипа квіткового подарунка
class FlowerGiftPrototype : public GiftPrototype {
public:
    GiftPrototype* clone() const override {
        return new FlowerGiftPrototype(*this);
    }

    void display() const override {
        std::cout << "Це прототип квіткового подарунка!" << std::endl;
    }
};

// Конкретна реалізація прототипа подарунка з солодощами
class CandyGiftPrototype : public GiftPrototype {
public:
    GiftPrototype* clone() const override {
        return new CandyGiftPrototype(*this);
    }

    void display() const override {
        std::cout << "Це прототип подарунка з солодощами!" << std::endl;
    }
};

int main() {
    // Використання прототипа для створення нових подарунків
    GiftPrototype* flowerPrototype = new FlowerGiftPrototype();
    GiftPrototype* candyPrototype = new CandyGiftPrototype();

    GiftPrototype* newFlowerGift = flowerPrototype->clone();
    GiftPrototype* newCandyGift = candyPrototype->clone();

    // Відображення нових подарунків
    newFlowerGift->display();
    newCandyGift->display();

    // Звільнення ресурсів
    delete flowerPrototype;
    delete candyPrototype;
    delete newFlowerGift;
    delete newCandyGift;

    return 0;
}