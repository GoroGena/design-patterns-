#include <iostream>
#include <string>

// Існуючий клас, який ми хочемо використовувати
class OldGift {
public:
    void provideGift() {
        std::cout << "Вручення подарунка." << std::endl;
    }
};

// Інтерфейс нового класу, який ми хочемо використовувати
class NewGift {
public:
    virtual void presentGift() = 0;
};

// Адаптер для використання OldGift у контексті NewGift
class GiftAdapter : public NewGift {
private:
    OldGift* oldGift;

public:
    GiftAdapter(OldGift* old) : oldGift(old) {}

    void presentGift() override {
        oldGift->provideGift();
    }
};

int main() {
    // Використання адаптера для використання OldGift у контексті NewGift
    OldGift* oldGift = new OldGift();
    GiftAdapter* adapter = new GiftAdapter(oldGift);

    // Використання методу з інтерфейсу NewGift
    adapter->presentGift();

    // Звільнення ресурсів
    delete oldGift;
    delete adapter;

    return 0;
}
