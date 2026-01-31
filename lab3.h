
// student: Ahmad Alabdulrahem 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STR_MAX 100
#define M 99
#define MAX 10

struct owner
{
     char name[STR_MAX];
     int age;
    
};
typedef struct owner owner_t;

struct vehicle 
{
    char vehicle_type[STR_MAX];
    char model[STR_MAX];
    char registration_number[STR_MAX];
    owner_t owner;
    
};
typedef struct vehicle vehicle_t;



vehicle_t addavehicle();
void check(char* x);
void printall(vehicle_t places[], int size);
void print(vehicle_t places[], int size);

void write(vehicle_t places[], char filename[], int size);
void read(vehicle_t places[], char filename[], int *size);

void deleteavehicle(vehicle_t places[], int *size);
void sort(vehicle_t places[], int size);
