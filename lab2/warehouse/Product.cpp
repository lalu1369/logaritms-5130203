#include "Product.h"

//default
Product::Product()
{
    setBarcode(460);
    price    = 0;
    quantity = 0;
    lpLat    = 0;
    lpLong   = 0;
}

//parameter
Product::Product(int _countryCode, string _description, float _price, int _quantity, double _lpLat, double _lpLong)
{
    setDescription(_description);
    setBarcode(_countryCode);
    price = _price;
    quantity = _quantity;
    setLpLat(_lpLat);
    setLpLong(_lpLong);
}

//copy
Product::Product(Product &other){
    description = other.getDescription();
    barCode     = other.getBarCode();
    price       = other.getPrice();
    quantity    = other.getQuantity();
    lpLat       = other.getLpLat();
    lpLong      = other.getLpLong(); 
}

Product::~Product()
{
}

string Product::getBarCode()
{
    return barCode;
}

string Product::getDescription()
{
    return description;
}

float Product::getPrice()
{
    return price;
}

int Product::getQuantity()
{
    return quantity;
}

double Product::getLpLat()
{
    return lpLat;
}

double Product::getLpLong()
{
    return lpLong;
}

void Product::setBarcode(int countryCode)
{
    if (countryCode % 1000 == 0)
    {
        throw std::runtime_error("The country code must be of 3 digits...");
    }

    int randonNumber4Digits = (1 + (std::rand() % (9 - 1 + 1))) * 1000;
    int randonNumber6Digits = (100000 + (std::rand() % (999999 - 100000 + 1)));

    barCode = to_string(countryCode) + to_string(randonNumber4Digits) + to_string(randonNumber6Digits);
}

void Product::setDescription(string _description)
{
    if (_description.length() > MAX_LENGTH_DESCRIPTION)
    {
        throw std::runtime_error("Description cannot be bigger than " + to_string( MAX_LENGTH_DESCRIPTION) + " Characters....");
    }
    description = _description;
}

void Product::setPrice(float _price)
{
    price = _price;
}

void Product::setQuantity(int _quantity)
{
    quantity = _quantity;
}

void Product::setLpLat(double _lpLat)
{
    // 19 - 169
    if (_lpLat < 19 || _lpLat > 169){
        throw std::runtime_error("LPLat Out Of Range [19 - 69] ...");
    }
    lpLat = _lpLat;
}

void Product::setLpLong(double _lpLong)
{
    // 41 - 82
    if (_lpLong < 41 || _lpLong > 82){
        throw std::runtime_error("LPLong Out Of Range [41 - 82] ...");
    }
    lpLong = _lpLong;
}

string Product::toString()
{
    return  "{\n barcode: "      +  barCode 
            + "\n price: "       +  to_string(price)
            + "\n description: " +  description
            + "\n quantity: "    +  to_string(quantity)
            + "\n lpLat: "       +  to_string(lpLat)
            + "\n lpLong:"       +  to_string(lpLong)
            + "\n}\n";
}
