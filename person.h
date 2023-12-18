#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person {
    private:
    double height = 0.0;
    double weight = 0.0;

    public:
    double getHeight();
    void setHeight(double);
    
    double getWeight();
    void setWeight(double);

    double calculateBMI();

    int calculateCalories(int);

    double calculateProtein(double);

};

#endif