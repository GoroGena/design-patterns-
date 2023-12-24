#include <iostream>
#include <string>

class GiftCatalog {
private:
    // Приватний конструктор, запобігає створенню екземплярів ззовні
    GiftCatalog() {}

    // Єдиний екземпляр каталогу подарунків
    static GiftCatalog* instance;

public:
    // Метод для отримання єдиного екземпляра каталогу подарунків
    static GiftCatalog* getInstance() {
        if (!instance) {
            instance = new GiftCatalog();
        }
        return instance;
    }

    // Метод для відображення каталогу подарунків
    void displayCatalog() {
        std::cout << "Каталог подарунків: квіти, солодощі, іграшки тощо." << std::endl;
    }
};

// Ініціалізація єдиного екземпляра каталогу подарунків
GiftCatalog* GiftCatalog::instance = nullptr;

int main() {
    // Використання шаблону Singleton для отримання каталогу подарунків
    GiftCatalog* catalogInstance1 = GiftCatalog::getInstance();
    catalogInstance1->displayCatalog();

    // Якщо інші об'єкти також спробують отримати екземпляр, вони отримають той самий екземпляр
    GiftCatalog* catalogInstance2 = GiftCatalog::getInstance();
    catalogInstance2->displayCatalog();

    // Адреси об'єктів будуть однакові
    std::cout << "Адреса catalogInstance1: " << catalogInstance1 << std::endl;
    std::cout << "Адреса catalogInstance2: " << catalogInstance2 << std::endl;

    return 0;
}
