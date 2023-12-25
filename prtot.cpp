#include <iostream>
#include <string>

// Абстрактний клас прототипа студента
class StudentPrototype {
public:
    virtual StudentPrototype* clone() const = 0;
    virtual void display() const = 0;
};

// Конкретна реалізація прототипа студента
class ConcreteStudent : public StudentPrototype {
private:
    std::string name;
    int age;
    std::string major;

public:
    ConcreteStudent(const std::string& studentName, int studentAge, const std::string& studentMajor)
        : name(studentName), age(studentAge), major(studentMajor) {}

    // Метод для клонування студента
    StudentPrototype* clone() const override {
        return new ConcreteStudent(*this);
    }

    // Метод для відображення інформації про студента
    void display() const override {
        std::cout << "Студент: " << name << ", Вік: " << age << ", Спеціальність: " << major << std::endl;
    }
};

int main() {
    // Створення прототипу студента
    ConcreteStudent* originalStudent = new ConcreteStudent("Іван Іванов", 20, "Інформатика");

    // Клонування студента
    StudentPrototype* clonedStudent = originalStudent->clone();

    // Відображення інформації про оригінального і клонованого студента
    std::cout << "Оригінальний студент:" << std::endl;
    originalStudent->display();

    std::cout << "\nКлонований студент:" << std::endl;
    clonedStudent->display();

    // Звільнення ресурсів
    delete originalStudent;
    delete clonedStudent;

    return 0;
}
