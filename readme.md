
## Parking Lot Design Using C++

An object-oriented parking lot model written in C++. The project focuses on the core domain objects needed to represent vehicles, parking spots, levels, tickets, and payment logic.

## About

This repository contains a simple C++ implementation of a parking lot system built for learning and practice with object-oriented design. It models a realistic parking scenario and keeps the code in a single source file for clarity.

## Features

- Multiple parking levels.
- Multiple parking spots per level.
- Vehicle types for bikes, cars, and buses.
- Spot-size based parking rules.
- Ticket creation with entry and exit timestamps.
- Basic payment calculation based on parked duration.

## Design Overview

The main classes in the project are:

- `Vehicle`: Base class that stores the registration number, size, and required number of spots.
- `Bike`, `Car`, `Bus`: Concrete vehicle types with predefined sizes.
- `ParkingSpot`: Represents a single spot and tracks the parked vehicle.
- `Level`: Holds a collection of parking spots and handles parking and removal at the level scope.
- `ParkingLot`: Coordinates parking across all levels.
- `Ticket`: Stores vehicle entry and exit time.
- `Payment`: Calculates and prints the parking fee.

## Assumptions

For this design, the following assumptions are used:

- The parking lot has multiple levels.
- Each level has multiple spots.
- The parking lot supports bikes, cars, and buses.
- A bike requires 1 spot.
- A car requires 2 spots.
- A bus requires 5 spots.

## How to Build and Run

This project is a single-file C++ program. You can compile it with a modern C++ compiler such as `g++`.

```bash
g++ -std=c++17 main.cpp -o parking_lot
./parking_lot
```

On Windows, the executable name will usually be `parking_lot.exe`:

```bash
g++ -std=c++17 main.cpp -o parking_lot.exe
parking_lot.exe
```





