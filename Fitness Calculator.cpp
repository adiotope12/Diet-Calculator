#include <iostream>
#include <iomanip>
#include <string.h>
#include "person.h"
#include "person.cpp"

using namespace std;

//function setHeight(Person &person) makes sure entered height is nonnegative and sets the height by passing the person object by reference
void setHeight(Person &person){
    double height;

    cout << "Enter your height in Inches" << endl;
    cin >> height;

    while (height < 1){
        cout << "Invalid Height" << endl;
        cout << "Enter your height in Inches" << endl;
        cin >> height;
    }
    person.setHeight(height);

    cout << "Height: " << person.getHeight() << " Inches" << endl;
}

//function setWeight(Person &person) makes sure entered weight is nonnegative and sets the height by passing the person object by reference
void setWeight(Person &person){
   double weight;

    cout << "Enter your weight in pounds" << endl;
    cin >> weight;

    while (weight < 1){
        cout << "Invalid Weight" << endl;
        cout << "Enter your weight in pounds" << endl;
        cin >> weight;
    }
    person.setWeight(weight);

    cout << "Weight: " << person.getWeight() << " pounds" << endl;
}

int main(){
    Person person;
    double height;
    double weight;
    string BMIrange;
    string input;

    cout << "Diet Calculator\n";
    cout << setfill('-') << setw(16) <<"\n";

    setHeight(person);

    //This section of code asks the user to make sure the entered values are correct, and if not has the user re-input values.
    cout << "Is this correct? Yes or No" << endl;
    cin >> input;

    while (input !="Yes"){
        if (input == "No"){
            setHeight(person);
            cout << "Is this correct? Yes or No" << endl;
            cin >> input;

        } else {
            cout << "Invalid Input" << endl;
            cout << "Height: " << person.getHeight() << " Inches" << endl;
            cout << "Is this correct? Yes or No" << endl;
            cin >> input;
        }
    }

    cout << setfill('-') << setw(30) <<"\n";
    setWeight(person);
    cout << "Is this correct? Yes or No" << endl;
    cin >> input;

    while (input !="Yes"){
        if (input == "No"){
            setWeight(person);
            cout << "Is this correct? Yes or No" << endl;
            cin >> input;

        } else {
            cout << "Invalid Input" << endl;
            cout << "Weight: " << person.getWeight() << " pounds" << endl;
            cout << "Is this correct? Yes or No" << endl;
            cin >> input;
        }
    }
    cout << setfill('-') << setw(60) <<"\n";

    //This section takes the entered height and weight and uses the class member functions to output the information.
    cout << setfill(' ') << setw(30) << "Results:" << endl;
    cout << setfill('-') << setw(60) <<"\n";

    if (person.calculateBMI() < 18.5){
        BMIrange = "Underweight";
    } else if (person.calculateBMI() < 25){
        BMIrange = "Normal weight";
    } else if (person.calculateBMI() < 30){
        BMIrange = "Overweight";
    } else {
        BMIrange = "Obese";
    }

    cout << fixed << setprecision(2) << "BMI: " << person.calculateBMI() << ", "  << BMIrange << endl;
    cout << fixed << setprecision(0) << "Maintenance calories (moderately active): ~ " << person.calculateCalories(15) << " calories" << endl;
    cout << "Daily Protein intake: " << person.calculateProtein(.7) << " - " << person.calculateProtein(1) << " grams" << endl;
    cout << setfill('-') << setw(60) <<"\n";

    //Allows user to exit program, or choose to restart
    cout << "input \"exit\" to exit application, or 'r' to restart" << endl;
    cin >> input;

    while ((input !="exit")&&(input !="r")){

        cout << "Invalid Input" << endl;
        cout << "input \"exit\" to exit application, or 'r' to restart" << endl;
        cin >> input;

        if (input == "r"){
        cout << endl;
        main();
    }
    }

    if (input == "r"){
        cout << endl;
        main();
    }

    return 0;
    
}