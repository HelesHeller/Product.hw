#include <iostream>
#include <string>
#include<Windows.h>

class Product
{
public:
    Product(const std::string& name, double price)
        : name(name), price(price) {}

    virtual void placeOrder() const = 0;

    const std::string& getName() const { return name; }
    double getPrice() const { return price; }

private:
    std::string name;
    double price;
};

class ElectronicProduct : public Product
{
public:
    ElectronicProduct(const std::string& name, double price, int warrantyPeriod, int stockQuantity)
        : Product(name, price), warrantyPeriod(warrantyPeriod), stockQuantity(stockQuantity) {}

    void placeOrder() const override
    {
        std::cout << "Замовлення для електронного товару: " << getName() << std::endl;
    }

private:
    int warrantyPeriod;
    int stockQuantity;
};

class Clothing : public Product
{
public:
    Clothing(const std::string& name, double price, const std::string& size, const std::string& color)
        : Product(name, price), size(size), color(color) {}

    void placeOrder() const override
    {
        std::cout << "Замовлення для одягу: " << getName() << std::endl;
    }

private:
    std::string size;
    std::string color;
};

void processOrder(const Product& product)
{
    product.placeOrder();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ElectronicProduct laptop("Ноутбук", 15000, 12, 5);
    Clothing shirt("Футболка", 500, "XL", "Червона");

    processOrder(laptop);
    processOrder(shirt);

    return 0;
}
