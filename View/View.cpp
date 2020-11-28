#include<stdio.h>
#include"../Controller/control.h"
#include<stdlib.h>

int main(){
    int patient, availableCure, numberOfPeople = 0;
    scanf("%d %d", &patient, &availableCure);
    getchar();
    for(int i = 0; i < patient; i++){
        Person newPerson;
        scanf("%d %s %d - %[^\n]", &newPerson.date, newPerson.month, &newPerson.year, newPerson.name);
        getchar();
        pushMid(newPerson);
        numberOfPeople++;
    }

    outputResult(availableCure, numberOfPeople);
    return 0;
}
