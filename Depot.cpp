#include"Depot.h"
Depot::Depot(string name, string cargo[], int count)
{
    cout << "Constructing the " << name << " Depot Station" << endl;
    this->name = name;
    allocateYard(count);
    for(int i = 0; i < count; i++) {
        cout << " " << cargo[i];
        BoxCar *car = new BoxCar(cargo[i], rand() % 30000 + 10000);
        yard[i] = car;
    }
    cout << endl << endl;
}

Depot::~Depot()
{
    cout << "It's the end of the day, Closing Depot " << name;
    if (yard != nullptr) {
        cout << " Deallocating car(s)"; 
        for(int i = 0; i < count; i++) {
            cout << " " << yard[i]->getId();
            delete yard[i];
        }
        cout << endl;
        deallocateYard();
    }
    else {
        cout << " No cars to deallocate" << endl; 
    }
    cout << endl;
}

string Depot::getName() const {
    return name;
}


void Depot::allocateYard(int count)
{
    this->count = count;
    if (count > 0) {
        cout << "Allocating yard for " << count << " BoxCars for Depot " << name << ":";
        yard = new BoxCar*[count];        
    }
    else {
        cout << name << " has no cargo to allocate" << endl;
    }
}

void Depot::deallocateYard()
{
    if (yard != nullptr) {
        cout << "DE-allocating yard for " << count << " BoxCars for Depot " << name << endl;
        delete [] yard;
        yard = nullptr;          
        count = 0;
    }
}


void Depot::loadTrain(Train* train)
{
    cout << "Loading " << train->getTrainName() << " from " << name << " with " << count << " cars." << endl;
    for(int i = 0; i < count; i++) {
        train->attach(yard[i]);
    }
    deallocateYard();
    cout << "Bye " << train->getTrainName() << " have a great trip! " << name << " now has " << count << " cars." << endl;
}

void Depot::unloadTrain(Train* train)
{
    cout << "Unloading " << train->getTrainName() << " into " << name << " with " << train->getCarCount() << " cars." << endl;
    // there are currently trains in the yard, we need to expand!
    BoxCar **oldYard = this->yard;
    int oldCount = this->count;
    int newCount = oldCount + train->getCarCount();
    if (newCount > 0) {
        allocateYard(newCount);
        for (int i = 0; i < newCount; i++) { 
            if (i < oldCount) {
                yard[i] = oldYard[i];
            }
            else {
                yard[i] = train->detach();
            }
        }
    }
    if (oldCount > 0) {
        // finally delete the oldYard array of pointers
        // note we don't call deallocateYard because it 
        // would wipe the newly allocated yard for the unloaded train
        delete [] oldYard;    
    }
    cout << "Thanks " << train->getTrainName() << " for the cargo! " << name << " now has " << count << " cars." << endl;
}

void Depot::print()
{
    cout << "Depot " + name + " yard has the following BoxCars: " << endl;
    for(int i = 0; i < count; i++) {
        BoxCar *car = yard[i];
        car->print();
    }    
}

