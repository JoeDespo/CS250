/*
* Name: Joseph D'Esposito
* Course: CS 250
* Last Update: 9/12/2023
* Program: Programming Assignment 1
*
* This program prompts the user to enter the starting population, birth rate,
* death rate and the number of years to project. Then it calculates and prints
* the growth rate and the estimated population after each year.
*/

#include <iostream>
using namespace std;

//Prototypes:
float growthRate (float birthR, float deathR);
float estimatePop (int pop, float birthR, float deathR);

int main()
{
    //Declare variables
    int population = 0; //Population of the first year
    float birthRate = 0; //Birth rate
    float deathRate = 0; //Death rate
    float years = 0; //Number of years to project
    float growth = 0; //function growthReturn's return value is stored here
    float estimatedPopulation = 0; //function estimatePop's return value is stored here
    const float RATE_LIMIT = 0; //Limit for birth/death rate input
    const int POPULATION_LIMIT = 2; //Limit for population input
    const int YEARS_LIMIT = 0; //Limut for years to project input
    
    //Receive user input, loop until input is valid invalid
    do
    {
        cout << "Enter the start population. Can't be less than 2." << endl;
        cin >> population;
    }while (population < POPULATION_LIMIT);
    
    do
    {
        cout << "Enter the birth rate. Can't be a negative number." << endl;
        cin >> birthRate;
    }while (birthRate < RATE_LIMIT);
    
    do
    {
        cout << "Enter the death rate. Can't be a negative number." << endl;
        cin >> deathRate;
    }while (deathRate < RATE_LIMIT);
    
    do
    {
        cout << "Enter the number of years to project. Can't be less than 1." << endl;
        cin >> years;
    }while (years < YEARS_LIMIT);
    
    
    //Find growth rate
    growth = growthRate(birthRate, deathRate);
    
    //Loop for each projected year to find the estimated population of that year.
    for (int i = 0; i < years; i++)
    {
        estimatedPopulation = estimatePop(population, birthRate, deathRate);
        //Replace the input population with the new estimated population for the
        //following year. For each year there is an iteration.
        population = estimatedPopulation; //This replaces the input population
        //output each of the estimated population
        cout << "The estimated population in " << i+1 << " year(s) will be "
        << estimatedPopulation * years << endl;
    }
    
    //output the growth rate and estimated population.
    cout << "The growth rate is " << growth << endl;
    
    return 0;
}

//This function takes birth rate & subtracts it from death rate to return the growth rate.
float growthRate (float birthR, float deathR)
{
    return (birthR - deathR);
}

//This function takes population, birth rate, & death rate & returns estimated population;
float estimatePop (int pop, float birthR, float deathR)
{
    float estimate; //Contains the formula to solve the estimated population.
    //Esimated population formula: P + ( B * P ) / 100 – ( D * P ) / 100
    estimate = pop + (birthR * pop) / 100 - (deathR * pop) / 100;
    return estimate;
}
