#ifndef PRODUCT_H
#define PRODUCT_H

#pragma once

using namespace std;
#include <iostream>
#include <cstdio>
#include <cstring>

const int MAX_LENGTH_BARCODE = 13;
const int MAX_LENGTH_DESCRIPTION = 50;

class Product
{
private:

    string  barCode;
    string  description;
    float   price;
    int     quantity;
    double  lpLat;
    double  lpLong;

public:

    Product();
    Product(int, string, float, int, double, double);
    Product(Product&);
    ~Product();

public:

    string getBarCode();
    string getDescription();
    float  getPrice();
    int    getQuantity();
    double getLpLat();
    double getLpLong();

    

    void setBarcode(int);
    void setDescription(string);
    void setPrice(float);
    void setQuantity(int);
    void setLpLat(double);
    void setLpLong(double);

    string toString(); // prints the product data
};

#endif