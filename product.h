/*
    product.h
    Samuel Lamb
    cop3330
    project 2
    2/8/2019
*/

#ifndef _Product_H
#define _Product_H

#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdint>



class Product //Initializing a new class, Product
{
    public: 
    void SetName(const char*);
    void SetCost(float);
    void SetBarCode (uint32_t);
    uint32_t GetBarCode() const;
    const char* GetName() const;
    float GetCost() const;
    Product(); //Constructor
    Product(const char* name, uint32_t, float cost); //2 Argument-Constructor
    ~Product(); //Deconstructor
    Product(const Product&); //Copy Constructor
    Product& operator= (const Product&); //Assignment Opperator
    private:
    uint32_t BarCode_;
    char * name_;
    float cost_;
};

std::ostream& operator<< (std::ostream& os, const Product& p);

#endif 
