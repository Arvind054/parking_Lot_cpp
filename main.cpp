#include<bits/stdc++.h>
#include <ctime>
#include <chrono>
#include <cstdint>
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
    bool canFitInSpot(VehicleSize spotSize){
      return size <= spotSize;
    }
};

// Bus Class

//Constructor for the Vehicles
// This constructor makes sure that when an object of the class is created it first creates an vehicle Object and with the passed parameters.
class Bus : public Vehicle{
    public:
    Bus(string regNumber): Vehicle(regNumber, VehicleSize ::large){};

    bool canFitInSpot(VehicleSize spotSize){
     return this->getVehicleSize() == spotSize;
   }
};

class Car : public Vehicle{
    public:
    Car(string regNumber): Vehicle(regNumber, VehicleSize ::medium){};

   bool canFitInSpot(VehicleSize spotSize){
     return this->getVehicleSize() == spotSize;
   }
};
class Bike : public Vehicle{
    public:
    Bike(string regNumber): Vehicle(regNumber, VehicleSize ::small){};

    bool canFitInSpot(VehicleSize spotSize){
     return this->getVehicleSize() == spotSize;
   }
};





// Parking Spot

class Level{
    private:
    int levelNumber;
    vector<ParkingSpot>spots;

    public:
    Level(int levelNumber, int numSpots){
          this->levelNumber = levelNumber;
          spots.resize(numSpots);
    }

    bool parkVehicle(Vehicle vehicle){
       for(ParkingSpot& spot: spots){
        if(spot.canFitVehicle(vehicle)){
            spot.parkVehicle(&vehicle);
            return true;
        }
       }
       return false;
    }

    bool removeVehicle(Vehicle* vehicle){
        for(ParkingSpot& spot : spots){
          if(!spot.isAvailable() && spot.getVehicle() == vehicle){
               spot.removeVehicle();
               return true;
          }
        }
        return false;
    }
};

class ParkingSpot{
     private:
     Vehicle* vehicle;
     VehicleSize spotSize;
     int row;
     int spotNumber;
     Level* level;

     public:
     ParkingSpot(Level* level, int row, int spotNumber, VehicleSize spotSize){
       this->level = level;
       this->spotSize = spotSize;
       this->row = row;
       this->spotNumber = spotNumber;
       this->vehicle = NULL;
     }


     // Check Wheter parking spot is available or not
     bool isAvailable(){
      return this->vehicle == NULL;
     }

     //Check whether a vehicle can fit in the spot or not
     bool canFitVehicle(Vehicle& vehicle){
      return this->isAvailable() && vehicle.canFitInSpot(this->spotSize);    
    }
    

    // To park the vehicle

    void parkVehicle(Vehicle* vehicle){
        if(canFitVehicle(*vehicle)) this->vehicle = vehicle;
        return ;
    }

    // TO remove the parked Vehicle
    
    void removeVehicle(){
       this->vehicle = NULL;
       return ;
    }

    // To get the Spot size
    VehicleSize getSpotSize(){
      return this->spotSize;
    }

    // To get the row of the parking Spot

    int getSpotRow(){
      return this->row;
    }

    // To get the spot number in a given row
    int getSpotNumber(){
      return this->spotNumber;
    }

    // To get the Vehicle
    Vehicle* getVehicle(){
       return this->vehicle;
    }
};

// Parking Lot Class

class ParkingLot{
   vector<Level>levels;
   public:
    ParkingLot(int totalLevels, int spotsPerLevel){
         levels.resize(totalLevels);
         for(int i = 0; i<totalLevels; i++){
            levels[i] = Level(i,spotsPerLevel);
         }
    }
    bool parkVehicle(Vehicle* vehicle){
            for(auto& level: levels){
               if(level.parkVehicle(*vehicle)){
                  return true;
               }
            }
            return false;
   }
   bool removeVehicle(Vehicle* vehicle){
      for(auto& level: levels){
         if(level.removeVehicle(vehicle)){
            return true;
         }
      }
      return false;
   }
};

// Ticket Class

class Ticket{
   private:
   Vehicle* vehicle;
   chrono::time_point<chrono::system_clock> entryTime;
   chrono::time_point<chrono::system_clock> exitTime;

   public:
   Ticket(Vehicle* vehicle){
      this->vehicle = vehicle;
      this->entryTime = chrono::system_clock::now();
   }

   void setExitTime(){
      this->exitTime = chrono::system_clock::now();
   }

   int64_t getDuration(){
      auto duration = chrono::duration_cast<chrono::seconds>(exitTime - entryTime);
      return duration.count();
   }
};


class Payment{
   public:
   double calculateFees(Ticket ticket){
      double duration  = ticket.getDuration();
      return duration/3600.0;
   }
   void processPayment(Ticket ticket){
         double fees = calculateFees(ticket);
         cout<<"Payment Complete For the: Rs. "<<fees<<endl;
   }
};

int main(){
   return 0;
};