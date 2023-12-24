#include <iostream>
#include <string>

// Компонент подарунка - квіти
class Flowers {
public:
    std::string type;

    Flowers(const std::string& flowerType) : type(flowerType) {}
};

// Компонент подарунка - солодощі
class Sweets {
public:
    std::string type;

    Sweets(const std::string& sweetType) : type(sweetType) {}
};

// Клас для побудови подарунка
class GiftBuilder {
public:
    virtual void buildFlowers() = 0;
    virtual void buildSweets() = 0;
    virtual std::string getResult() const = 0;
};

// Конкретний будівельник подарунка
class RomanticGiftBuilder : public GiftBuilder {
private:
    Flowers* flowers;
    Sweets* sweets;

public:
    RomanticGiftBuilder() : flowers(nullptr), sweets(nullptr) {}

    void buildFlowers() override {
        flowers = new Flowers("Рожі");
    }

    void buildSweets() override {
        sweets = new Sweets("Шоколадні цукерки");
    }

    std::string getResult() const override {
        std::string result = "Романтичний подарунок із " + flowers->type + " та " + sweets->type;
        return result;
    }
};

// Клас режисера (Director), який використовує будівельник для створення подарунка
class GiftDirector {
private:
    GiftBuilder* builder;

public:
    GiftDirector(GiftBuilder* giftBuilder) : builder(giftBuilder) {}

    void construct() {
        builder->buildFlowers();
        builder->buildSweets();
    }

    std::string getResult() const {
        return builder->getResult();
    }
};

int main() {
    // Використання шаблону Builder для створення романтичного подарунка
    GiftBuilder* romanticGiftBuilder = new RomanticGiftBuilder();
    GiftDirector* director = new GiftDirector(romanticGiftBuilder);

    director->construct();
    std::string result = director->getResult();

    // Відображення результату
    std::cout << result << std::endl;

    // Звільнення ресурсів
    delete romanticGiftBuilder;
    delete director;

    return 0;
}
