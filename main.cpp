#include <iostream>
#include <string>
#include <vector>
#include "Depot.cpp"
using namespace std;

int main(int argc, char **argv)
{
    string knapfordCargo[] = {"lumber", "pulp", "barley", "millet", "ammonia", "chlorine", "steel"};
    string brendomCargo[] = {"coal", "corn", "soybeans", "cattle", "oil"};
    string elsbridgeCargo[] = {"wheat", "nitrogen"};
    cout << endl
         << "Good morning for another day of work in Sodor!" << endl
         << endl;

    Depot knapford("Knapford", knapfordCargo, 7);
    Depot brendom("Brendom", brendomCargo, 5);
    Depot elsbridge("Elsbridge", elsbridgeCargo, 2);
    Depot tidmouth("Tidmouth", {}, 0);
    knapford.print();
    brendom.print();
    elsbridge.print();
    tidmouth.print();
    Train* T1=new Train("thomas","blue");
    Train* T2=new Train("percy","green");
    Train* T3=new Train("rebecca","yellow");
    knapford.loadTrain(T1);
    T1->travelTo(tidmouth.getName());
    brendom.loadTrain(T2);
    T2->travelTo(tidmouth.getName());
    elsbridge.loadTrain(T3);
    T3->travelTo(tidmouth.getName());
    tidmouth.unloadTrain(T1);
    tidmouth.unloadTrain(T2);
    tidmouth.print();
    cout<<"Rebbica engine has borken down,oh no what will happen ?"<<endl;
    cout << endl
         << "The sun is setting, good day!" << endl
         << endl;
    delete T3,T2,T1;
    return 0;
}
