#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char name[50];
    int age;
    float height;
    float weight;
    char email[100];
};
int main(){
    struct user person;
    strcpy(person.name, "Ricardo Blanco");
    person.age = 30;
    person.height = 1.75;
    person.weight = 70.5;
    strcpy(person.email, "ricardo@example.com");

    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %.2f\n", person.height);
    printf("Weight: %.2f\n", person.weight);
    printf("Email: %s\n", person.email);

    return 0; 
}