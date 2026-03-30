#include <iostream>
#include <string>

class Label 
{
public:
    std::string brand;
    Label() {
        brand = "Unknown";
        std::cout << "Label created" << std::endl;
    }

    Label(std::string brand) {
        this -> brand = brand;
        std::cout << "Label created: " << brand << std::endl; 
    }
    ~Label(){
        std::cout << "Label destroyed: " << brand << std::endl;
    }
};

class Bottle {
private:
    std::string size;
    Label label;  // ← объект
public:
    Bottle(std::string size, std::string brand) : label(brand) {
        this->size = size;
        std::cout << "Bottle created: " << size << std::endl;
    }
    ~Bottle() {
        std::cout << "Bottle destroyed: " << size << std::endl;
    }
    void print() {
        std::cout << "Bottle size: " << size << ", Brand: " << label.brand << std::endl;
    }
};

class BottlePtr
{
private:
    std::string size;
    Label *label;
public:
    BottlePtr(std::string size, std::string brand) {
        this -> size = size;
        label = new Label(brand);
        std::cout << "Bottle created:" << size << std::endl;
        
    }

    ~BottlePtr(){
        std::cout << "Bottle destroyed:" << size << std::endl;
        delete label;
    }

    void print() {
        std::cout << "Bottle size: " << size << ", Brand: " << label -> brand << std::endl;
     }

};

int main() {
    std::cout << "---Object inside an object---" << std::endl;
    Bottle b("0.5L", "Bavaria");
    b.print(); 
    std::cout <<"---Pointer inside an object---" << std::endl;
    BottlePtr bp("1.0L", "Heineken");
    bp.print();
    return 0;
}