#include "Warehouse.h"

using namespace std;


//default constructor
Warehouse::Warehouse()
{
    id          = "";
    type        = CategoryEnum::Center;
    latitude    = 0;
    longitude   = 0;
    maxCapacity = 0;
    indexListOfProducts = 0;
    totalStock  = 0;
}

//parameters constructor
Warehouse::Warehouse(int _id, CategoryEnum _type, double _latitude, double _longitude, int _maxCapacity)
{
    if (_id < 100 || _id > 999){
        throw runtime_error("Invalid ID Format for Warehouse");
    }
    id = "W"+ to_string(_id);
    type = _type;
    latitude = _latitude;
    longitude = _longitude;
    maxCapacity = _maxCapacity;
    indexListOfProducts = 0;
    totalStock = 0;
}

//copy constructor
Warehouse::Warehouse(Warehouse &other)
{
    id = other.getId();
    type = other.getType();
    latitude = other.getLatitude();
    longitude = other.getLongitude();
    maxCapacity = other.getMaxCapacity();
    indexListOfProducts = 0;
    totalStock = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        listOfProducts[i] = other.getListOfProducts()[i];
    }
}

Warehouse::~Warehouse()
{
}

string Warehouse::getId()
{
    return id;
}

CategoryEnum Warehouse::getType()
{
    return type;
}

double Warehouse::getLongitude()
{
    return longitude;
}

double Warehouse::getLatitude()
{
    return latitude;
}

int Warehouse::getMaxCapacity()
{
    return maxCapacity;
}

int Warehouse::getTotalStock()
{
    return totalStock;
}

Product *Warehouse::getListOfProducts()
{
    return listOfProducts;
}

void Warehouse::addProduct(Product newProduct)
{
    cout << totalStock << endl;
    cout << newProduct.getQuantity() << endl;
    if (totalStock + newProduct.getQuantity() > maxCapacity)
    {
        throw runtime_error("The Warehouse is full...");
    }

    totalStock += newProduct.getQuantity();
    listOfProducts[indexListOfProducts] = newProduct;
    indexListOfProducts++;
}

bool Warehouse::searchProduct(string _description, Product &productFounded)
{
    bool isProductFounded = false;
    for (int i = 0; i < indexListOfProducts; i++)
    {
        if (listOfProducts[i].getDescription().compare(_description) == 0)
        {
            productFounded = listOfProducts[i];
            isProductFounded = true;
        }
    }
    return isProductFounded;
}

// return quantity of product
int Warehouse::deleteProduct(Product _product)
{
    totalStock -= _product.getQuantity();
    indexListOfProducts--;
    return _product.getQuantity();
}

// [4]
float Warehouse::getDistanceBetweenPT(Product _product)
{
    return abs(latitude - _product.getLpLat()) + abs(longitude - _product.getLpLong());
}

int Warehouse::getSizeListOfProducts(){
    return indexListOfProducts;
}