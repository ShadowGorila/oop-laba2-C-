#include <iostream>
#include <string>
 
class Pivo {
private:
    std::string name;
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
        std:: cout << "Manufacturer copy" << std::endl;
    }

    void printManufacturer() {
        std::cout << "Manufacturer: " << getName()
        << ", Alchol: " << getAlcohol() << "%"
        << ", Country: " << country << std::endl;
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
   Pivo pivo1;
   Pivo pivo2("Bavaria", 7.9);
   Pivo pivo3(pivo2);
    pivo1.print();
    pivo2.print();
    pivo3.print();

    return 0;
}
