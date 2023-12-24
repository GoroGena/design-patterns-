#include <iostream>
#include <string>

// Абстракція - Подарунок
class Gift {
protected:
    std::string type;

public:
    Gift(const std::string& giftType) : type(giftType) {}

    virtual void manufacture() = 0;
};

// Реалізація - Квітковий подарунок
class FlowerGift : public Gift {
public:
    FlowerGift() : Gift("Квітковий подарунок") {}

    void manufacture() override {
        std::cout << "Виготовлено квітковий подарунок." << std::endl;
    }
};

// Реалізація - Подарунок з солодощами
class CandyGift : public Gift {
public:
    CandyGift() : Gift("Подарунок з солодощами") {}

    void manufacture() override {
        std::cout << "Виготовлено подарунок з солодощами." << std::endl;
    }
};

// Абстракція - Спосіб виготовлення подарунка
class GiftImplementation {
public:
    virtual void produce() = 0;
};

// Реалізація - Виготовлення квіткового подарунка
class FlowerGiftImplementation : public GiftImplementation {
public:
    void produce() override {
        std::cout << "З використанням квітів." << std::endl;
    }
};

// Реалізація - Виготовлення подарунка з солодощами
class CandyGiftImplementation : public GiftImplementation {
public:
    void produce() override {
        std::cout << "З використанням солодощів." << std::endl;
    }
};

// Міст між абстракцією і реалізацією
class GiftBridge {
protected:
    GiftImplementation* implementation;

public:
    GiftBridge(GiftImplementation* impl) : implementation(impl) {}

    virtual void manufacture() = 0;
};

// Контекст - Подарунок
class RefinedGift : public GiftBridge {
public:
    RefinedGift(GiftImplementation* impl) : GiftBridge(impl) {}

    void manufacture() override {
        implementation->produce();
    }
};

int main() {
    // Створення квіткового подарунка і його виготовлення
    GiftImplementation* flowerImplementation = new FlowerGiftImplementation();
    RefinedGift* flowerGift = new RefinedGift(flowerImplementation);

    std::cout << "Виробництво квіткового подарунка: ";
    flowerGift->manufacture();

    // Створення подарунка з солодощами і його виготовлення
    GiftImplementation* candyImplementation = new CandyGiftImplementation();
    RefinedGift* candyGift = new RefinedGift(candyImplementation);

    std::cout << "Виробництво подарунка з солодощами: ";
    candyGift->manufacture();

    // Звільнення ресурсів
    delete flowerImplementation;
    delete flowerGift;
    delete candyImplementation;
    delete candyGift;

    return 0;
}
