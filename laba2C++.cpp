#include <iostream>
#include <string>

class Pivo 
{
public:
    std::string name_bear;
    unsigned price;
    void print()
    {
        std::cout << "Bear: " << name_bear << "\tprice: " << price << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Pivo pivo;
    pivo.name_bear = "Бавария";
    pivo.price = 45;
    pivo.name_bear = "Hoegaarden";
    pivo.price = 109;
    pivo.name_bear = "Stella Artois";
    pivo.price = 84;
    pivo.name_bear = "Kronenbourg";
    pivo.price = 67;
    pivo.print();
    pivo.print();
    pivo.print();
}