#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

// This struct is complete
struct Location {
    string name;
    string address;
    string city;
    long postalCode;
    string province;
    double latitude;
    double longitude;
    int priceRangeMin;
    int priceRangeMax;
};

class PizzaZine {
private:
        vector<Location> pizzaLocations;
public:

    void readInFile(const string&, size_t);

    // The following functions need to be implemented
    Location& operator[](size_t);
    void add(Location new_location);
    Location& get(size_t);
    Location& first();
    Location& last();

};


void PizzaZine::readInFile(const string& filename,size_t c) {
    ifstream inFile(filename);
    Location newLoc;

    string line;
    string cell;

    // Read each line
    for (size_t i = 0; i < c; ++i) {
        // Break each line up into 'cells'
        getline(inFile, line);
        stringstream lineStream(line);
        while(getline(lineStream, newLoc.name, ',')) {
            getline(lineStream, newLoc.address, ',');
            getline(lineStream, newLoc.city, ',');
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.postalCode = stoul(cell);
            }

            getline(lineStream, newLoc.province, ',');
            getline(lineStream, cell, ',');
            newLoc.latitude = stod(cell);
            getline(lineStream, cell, ',');
            newLoc.longitude = stod(cell);

            newLoc.priceRangeMin = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.priceRangeMin = stoul(cell);
            }

            newLoc.priceRangeMax = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty() && cell != "\r") {
                newLoc.priceRangeMax = stoul(cell);
            }
            add(newLoc);
        }
    }
}

//returns location with matching index
Location& PizzaZine::operator[](size_t index){
  return pizzaLocations.at(index);
}
//inserts new location at the end of the vector
void PizzaZine::add(Location new_location){
  pizzaLocations.push_back(new_location);
}
//same as operatorm returns location with matching index
Location& PizzaZine::get(size_t index){
  return pizzaLocations.at(index);
}
//returns #1 of the list
Location& PizzaZine::first(){
  return pizzaLocations.front();
}
//returns last of the list
Location& PizzaZine::last(){
  return pizzaLocations.back();
}
