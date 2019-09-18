/*
    product.cpp
    Samuel Lamb
    cop3330
    project 2
    2/8/2019
*/

#include <iomanip>
#include <iostream>
#include <product.h>
#include <cstring>

void Product::SetName(const char* name)
{
    if(name_ != NULL)
    {
        delete[] name_;
    }
    size_t size = strlen(name);
    name_ = new char [1+size];
    name_[size] = '\0';
    strcpy(name_, name);
}

void Product::SetCost(float cost)
{
    cost_ = cost;
}


void Product::SetBarCode (uint32_t BarCode)
{
    BarCode_ = BarCode;
}


const char* Product::GetName() const
{
    return name_;
}

float Product::GetCost() const
{
    return cost_;
}

uint32_t Product::GetBarCode() const
{
    return BarCode_;
}

Product::Product() : name_(NULL), BarCode_(0), cost_(0) //constructor
{
    name_ = new char (2);
    name_[0] = '#';
    name_[1] = '\0';
}

Product::Product(const char* name, uint32_t BarCode, float cost) : name_(NULL), BarCode_(BarCode), cost_(cost) //2 argument-constructor
{
    size_t size = strlen(name);
    name_ = new char [1+size];
    name_[size] = '\0';
    strcpy(name_, name);
}
Product::~Product() //Deconstructor
{
    if (name_ != NULL)
    {
        delete [] name_;
    }
}
Product::Product(const Product& p) : name_(NULL), BarCode_(p.BarCode_)
{
    size_t size = strlen(p.name_);
    name_ = new char [1+size];
    name_[size] = '\0';
    cost_=p.cost_;
    BarCode_=p.BarCode_;
    strcpy(name_, p.name_);
}
Product& Product::operator= (const Product& p)
{
    if(this != &p)
    {
        if(name_ != NULL)
        {
            delete[] name_;
        }
        size_t size = strlen(p.name_);
        name_ = new char [1+size];
        name_[size] = '\0';
        strcpy(name_, p.name_);
    }
    return *this;
}

std::ostream& operator << (std::ostream& os , const Product& p)
{
  std::ios_base::fmtflags flags = os.flags();
  os.setf(std::ios::fixed | std::ios::showpoint); // prep for $ output
  os.precision(2);
  os << p.GetName() << '\t' 
     << std::hex << std::uppercase << std::setfill('0') << std::setw(8) // prep for hex output
     << p.GetBarCode() 
     << std::dec << std::setfill(' ') << '\t'          // return dec output
     << p.GetCost();
  os.setf(flags); // return flags to previous states
  return os;
}
