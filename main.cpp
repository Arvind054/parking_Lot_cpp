#include<bits/stdc++.h>
using namespace std;

// Enum for vehicle Sizes
enum class VehicleSize {
    small,
    medium,
    large
};

// Base Class
class Vehicle{
    protected:
     string regestrationNumber;
     int spotsNeeded;
     VehicleSize size;
     
     public:
     Vehicle(string regNumber, VehicleSize size){
        this->regestrationNumber = regNumber;
        this->size = size;
        if(size == VehicleSize::small)this->spotsNeeded = 1;
        else if(size == VehicleSize ::medium)this->spotsNeeded = 2;
        else if(size == VehicleSize::large)this->spotsNeeded = 5;
     }
     
     int getSpotsNeeded(){
        return this->spotsNeeded;
     }
     VehicleSize getVehicleSize(){
        return this->size;
     }

     string getRegNumber(){
        return this->regestrationNumber;
     }

};

// Bus Class

//Constructor for the Vehicles
// This constructor makes sure that when an object of the class is created it first creates an vehicle Object and with the passed parameters.
class Bus : public Vehicle{
    public:
    Bus(string regNumber): Vehicle(regNumber, VehicleSize ::large){};

   bool canFitInSpot(int size){
     return size == 5;
   }
};

class Car : public Vehicle{
    public:
    Car(string regNumber): Vehicle(regNumber, VehicleSize ::medium){};

   bool canFitInSpot(int size){
     return size == 2;
   }
};
class Bike : public Vehicle{
    public:
    Bike(string regNumber): Vehicle(regNumber, VehicleSize ::small){};

   bool canFitInSpot(int size){
     return size == 1;
   }
};


int main(){

   Bus B("RJ141245");

   cout<<B.getRegNumber()<<endl;
   return 0;
};