#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <iostream>
#include "BoxCar.h"
using namespace std;

class Train
{
    string name;
    string color;
    BoxCar *firstCar;

public:
    Train(string name, string color);
    ~Train();
    void attach(BoxCar* );
    BoxCar* detach();
    int getCarCount() const;
    string getTrainName() const;
    void travelTo(string depotName);
};
Train::Train(string name, string color)
{
    this->name = name;
    this->color = color;
    this->firstCar=nullptr;
}
Train::~Train()
{
cout<<"ohh no\t"<<name<<"\tthe\t"<<color<<"\ttrain! you didn't make it to depot and your cargo has spoiled,\t"
<<endl<<"we need to destroy these Boxcar(s)";
BoxCar*destroy=firstCar;
    while (destroy->getNextCar() != nullptr)
    {
        cout<<destroy->getId()<<"\t";
        destroy=destroy->getNextCar();
    }
}
void Train::attach(BoxCar *boxcar)
{
         if (firstCar == nullptr)
    {
        firstCar = boxcar;
    }
    else
    {
        BoxCar *next;
        next = firstCar->getCaboose();
        next->setNextCar(boxcar);
    }
    
    
}

int Train::getCarCount() const
{
    int count = 1;
    BoxCar *counting = firstCar;
    while (counting->getNextCar() != nullptr)
    {
        counting = counting->getNextCar();
        count++;
    }
    return count;
}
string Train::getTrainName() const
{
    return name;
}
void Train::travelTo(string depotName)
{
    BoxCar*local;
    local=firstCar;
    cout << name << "\tthe\t" << color << "\ttrain is on thier way to\t " << depotName << "\thauling :\t"<<endl;
    while (local->getNextCar() != nullptr)
    {
        local->print();
        local = local->getNextCar();
    }
}
BoxCar *Train ::detach()
{
    BoxCar *unload;
    unload = firstCar;
    firstCar = firstCar->getNextCar();
    return unload;
};

#endif // TRAIN_H
