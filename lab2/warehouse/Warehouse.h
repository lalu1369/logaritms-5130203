#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#pragma once

using namespace std;
#include "Product.h"
#include <iostream>
#include <cstdio>
#include <cstring>


const int MAX_PRODUCTS = 100;

enum CategoryEnum{
    Center,
    West,
    East
};

class Warehouse
{
private:
    string id;
    CategoryEnum type;
    double latitude;
    double longitude;
    int maxCapacity;
    int totalStock;
    
    Product listOfProducts[MAX_PRODUCTS];
    int indexListOfProducts;


public:
    Warehouse();
    Warehouse(int,CategoryEnum,double,double,int);
    Warehouse(Warehouse&);
    ~Warehouse();

    string getId();
    CategoryEnum getType();
    double getLongitude();
    double getLatitude();
    int getMaxCapacity();
    int getTotalStock();
    Product* getListOfProducts();

    void addProduct(Product);
    bool searchProduct(string,Product&);
    int deleteProduct(Product _product); //return quantity of product
    float getDistanceBetweenPT(Product);

    int getSizeListOfProducts();
};



#endif