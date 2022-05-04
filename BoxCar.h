#ifndef BOXCAR_H
#define BOXCAR_H
#include <string>
#include <iostream>
using namespace std;

class BoxCar
{

    int id;
    string cargo;
    int weight;
    BoxCar *nextCar;
    static int st;

public:
    BoxCar(string cargo, int weight);
    void setNextCar(BoxCar *nextCar);
    BoxCar *getNextCar();
    BoxCar *getCaboose();
    int getId() const;
    void print();
};
int BoxCar::st = 1000;
BoxCar::BoxCar(string cargo, int weight)
{
    this->cargo = cargo;
    this->weight = weight;
    this->id = st;
    this->nextCar = nullptr;
    st++;
}
void BoxCar::setNextCar(BoxCar *nextCar)
{

    this->nextCar = nextCar;
}
BoxCar *BoxCar::getNextCar()
{
    return nextCar;
}
BoxCar *BoxCar::getCaboose()
{
    BoxCar *caboose;
    caboose = this;
    while (caboose->nextCar != nullptr)
    {
        caboose = caboose->getNextCar();
    }
    return caboose;
}
int BoxCar::getId() const
{
    return id;
}
void BoxCar::print()
{
    cout << "BoxCar \t" << getId() << "\t"
         << "has \t" << weight << "\t lbs of \t" << cargo << endl;
}

#endif // BOXCAR_H
