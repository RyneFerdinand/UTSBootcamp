struct Person{
    int date;
    char month[255];
    int monthNum;
    int year;
    char name[255];
};

struct Node{
    Person p;
    Node *next, *prev;
} *head = NULL, *tail = NULL, *curr = NULL;

char month[12][255] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};