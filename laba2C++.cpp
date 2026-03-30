#include <iostream>
#include <string>
 
class Pivo {
protected:
    std::string name;
private:    
    double alcoholContent;
public:
    Pivo(std::string name, double alcoholContent)
    {
        this -> name = name;
        this -> alcoholContent = alcoholContent;
        std::cout << "Pivo " << name << std::endl;
    }

    ~Pivo()
    {
        std::cout << "Pivo " << name << " destroyed" << std::endl;
    }

    Pivo() {
        name = "Unknown";
        alcoholContent = 0.0;
        std::cout << "Default Pivo created" << std::endl;
    }

    Pivo(const Pivo& other){
        name = other.name;
        alcoholContent = other.alcoholContent;
        std::cout << "Pivo " << name << " copied" << std::endl;
    }

    void print()
    {
        std::cout << "Pivo: " << name 
        << ", Alchol Content: " << alcoholContent << "%" << std::endl;
    }

    std::string getName() {
        return name;
    }
    double getAlcohol() {
        return alcoholContent;
    }

    void setName(std::string newName) {
        name = newName;
    }
    
    void setAlcohol(double newAlcohol) {
        alcoholContent = newAlcohol;
    }
};

class Manufacturer : public Pivo {
private:
    std::string country;
public:
    // Создан без параметров. 
    Manufacturer() : Pivo () {
        country = "Unknown";
        std::cout << "Default Manufacturer created" << std::endl;
    }

    // Создан с параметрами.
    Manufacturer(std::string name, double alcoholContent,std::string country) : Pivo(name, alcoholContent) 
    {
        this -> country = country;
        std::cout << "Manufacturer " << name << " from " << country << std::endl;
    }
    
    // Конструктор копирования.
    Manufacturer(const Manufacturer& other) : Pivo(other) {
        country = other.country;
        std::cout << "Manufacturer " << getName() << " copied" << std::endl;
    }

    // Диструктор.
    ~Manufacturer() {
        std::cout << "Manufacturer " << country << " destroyed" << std::endl;;
    }

    void printManufacturer() {
        std::cout << "Manufacturer: " << getName()
        << ", Alchol: " << getAlcohol() << "%"
        << ", Country: " << country << std::endl;
    }
    void testAccess() {
        std::cout << name << std::endl;
        std::cout << getAlcohol() << std::endl;
    }

    void print() {
        Pivo::print();
        std::cout << "country:" << country << std::endl;

    }
    
};

int main() {
    Manufacturer m1;
    Manufacturer m2("Bavaria", 5.0, "Germany");
    Manufacturer m3(m2);
    m1.printManufacturer();
    m2.printManufacturer();
    m3.printManufacturer();
    std::cout << "------------------------------" << std::endl;
    m2.testAccess();
    std::cout << "------------------------------" << std::endl; 
   Pivo pivo1;
   Pivo pivo2("Bavaria", 7.9);
   Pivo pivo3(pivo2);
    pivo1.print();
    pivo2.print();
    pivo3.print();
    std::cout << "--------Dynamic Creation-------" << std::endl;
    Pivo *p1 = new Pivo("Heineken", 5.0);
    Pivo *p2 = new Manufacturer("Hoegaarden", 4.9, "Belgium");
    p1->print();
    p2->print();
    // удаление врунчную
    delete p1;
    delete p2;
    std::cout << "---Переопределение метода---" << std::endl;
    Pivo *p = new Manufacturer("Kozel", 4.5, "Chech Republic");
    p -> print();
    Manufacturer *m = new Manufacturer("Kralovsky", 5.0, "Chechoslovakia");
    m -> print();
    delete p;
    delete m;
    return 0;
}
