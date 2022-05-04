#ifndef DEPOT_H
#define DEPOT_H

#include <string>
#include <iostream>
#include "BoxCar.h"
#include "Train.h"


using namespace std;

class Depot
{
private:

    string name;    // name of the Depot
    BoxCar** yard;  // a dynamic array, each cell stores a pointer to a BoxCar
    int count;      // size of the yard array
    
    /**
     * allocateYard - dynamically allocates a train yard
     * @param count the number of boxCars to accommodate in the yard
    */
    void allocateYard(int count);
    
    /**
     * deallocateYard - returns previously dynamically allocated memory for train yard
    */    
    void deallocateYard();
    
public:

    /**
     * getName accessor retrieve name of depot
    */
    string getName() const;
 
    /**
     * Depot Constructor
     * @param name the depot identifier 
     * @param cargo list of the content boxcars in the yard
     * @param count number of boxcars in the yard
    */
    Depot(string name, string cargo[], int count);
    
    /**
     * Depot Destructor - this should deallocate all boxCars
     * currently in the yard and the trainYard array
    */
    ~Depot();
    
    /**
     * loadTrain - transfers all boxCars in the yard onto the train
     * @param train the train to attach boxCars onto
    */
    void loadTrain(Train* train);
    
    /**
     * unloadTrain - transfers all boxCars from the train into the yard
     * @param train the train to detach boxCars from
    */
    void unloadTrain(Train*);
    
    /**
     * print - a formatted description of the depot and contents of yard
     * this function prints directly to cout
    */
    void print();

};

#endif // DEPOT_H
