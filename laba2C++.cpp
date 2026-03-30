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

int main() {
   Pivo pivo1;
   Pivo pivo2("Bavaria", 7.9);
   Pivo pivo3(pivo2);
    pivo1.print();
    pivo2.print();
    pivo3.print();

    return 0;
}
