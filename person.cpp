#include <cmath>
#include "person.h"
using namespace std;


double Person::getHeight(){
    return height;
}
    
void Person::setHeight(double height){
    this->height = height;
}
     
double Person::getWeight(){
    return weight;
}
    
void Person::setWeight(double weight){
    this->weight = weight;
}

double Person::calculateBMI(){
    return weight/pow(height,2) * 703;
}

int Person::calculateCalories(int mult){
    return weight * mult;
}

double Person::calculateProtein(double mult){
    return weight * mult;
}