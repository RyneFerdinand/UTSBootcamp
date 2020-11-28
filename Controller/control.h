#include"../Model/model.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Node* createNode(Person p){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->p.date = p.date;
    strcpy(newNode->p.month, p.month);
    for(int i = 0; i < 12; i++){
        if(strcmp(month[i], p.month) == 0){
            newNode->p.monthNum = i + 1;
            break;
        }
    }
    newNode->p.year = p.year;
    strcpy(newNode->p.name, p.name);
    newNode->next = newNode->prev = NULL;
    return newNode;
}

bool compareDob(Person p1, Person p2){
    if(p1.year > p2.year){
        return true;
    }
    else if(p1.year == p2.year){
        if(p1.monthNum > p2.monthNum){
            return true;
        }
        else if(p1.monthNum == p2.monthNum){
            if(p1.date > p2.date){
                return true;
            }
        }
    }
    return false;
}

void pushHead(Person p){
    Node* temp = createNode(p);
    if(head == NULL){
        head = tail = temp;
    }
    else{
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void pushTail(Person p){
    Node* temp = createNode(p);
    if(head == NULL){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void pushMid(Person p){
    Node* temp = createNode(p);
    if(head == NULL){
        head = tail = temp;
    }
    else if(!compareDob(p, head->p)){
        pushHead(p);
    }
    else if(compareDob(p, tail->p)){
        pushTail(p);
    }
    else{
        curr = head;
        while(curr->next != NULL && compareDob(p, curr->next->p)){
            curr = curr->next;
        }
        curr->next->prev = temp;
        temp->next = curr->next;
        temp->prev = curr;
        curr->next = temp;
    }
}

void outputResult(int availableCure, int numberOfPeople){
    if(head){
        curr = head;
        int counter = 0;
        while(curr && counter < availableCure){
            curr = curr->next;
            counter++;
        }
        if(curr == NULL){
            printf("All patients get the cure, %d cure left\n", availableCure - counter);
        }
        else {
            printf("Need %d more cure\n", numberOfPeople - availableCure);
            while(curr){
                printf("%d %s %d - %s\n", curr->p.date, curr->p.month, curr->p.year, curr->p.name);
                curr = curr->next;
            }
        }
    }
}