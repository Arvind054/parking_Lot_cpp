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

int main(){

    Vehicle veh("RJ14B4519", VehicleSize::small);

    cout<<veh.getRegNumber()<<endl;
    cout<<veh.getSpotsNeeded()<<endl;


   return 0;
};