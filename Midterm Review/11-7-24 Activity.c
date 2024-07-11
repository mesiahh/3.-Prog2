#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i, j;


typedef struct {
    char type[50]; // Sword, Axe, Crossbow, Staff, Spear, Shield
    int gearLevel; // 1 - 25
} equipment;

typedef struct {
    char type[50]; // Barbarian, Fighter, LapuLapu | Medtech, Priest, Cleric, | Witch, Warlock, Wizard | Marksman, Assassin, Jungler
    char role[50]; // Tank, Healer, Mage, DPS
} Profession;

typedef struct {
    char name[50];
    Profession profession;
    equipment* gear; // points to an array of up to 3 equipment for the adventurer
    int gearscore;
} adventurer;

typedef struct Node { // link list
    struct Node* next;
    adventurer Adventurer;
} node;

// Function to display available roles
void displayRole() {
    printf("Available Roles:\n");
    printf("1. Tank\n");
    printf("2. Healer\n");
    printf("3. Mage\n");
    printf("4. DPS\n");
}

// Function to display available types
void displayType() {
    printf("Available Types:\n");
    printf("1. Barbarian, Fighter, LapuLapu\n");
    printf("2. Medtech, Priest, Cleric\n");
    printf("3. Witch, Warlock, Wizard\n");
    printf("4. Marksman, Assassin, Jungler\n");
}

// Function to create a new node
node* createNode(adventurer adv) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->Adventurer = adv;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
void addNode(node** head, adventurer adv) {
    node* newNode = createNode(adv);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to calculate the gearscore of an adventurer
int calculateGearScore(equipment* gear, int numItems) {
    int totalScore = 0;
    for (i = 0; i < numItems; i++) {
        totalScore += gear[i].gearLevel;
    }
    return totalScore;
}



int main() {
    int numAdventurers;
    printf("Enter the number of adventurers: ");
    scanf("%d", &numAdventurers);
    getchar(); // to consume newline character after number input

    node* head = NULL;

    for (i = 0; i < numAdventurers; i++) {
        adventurer adv;
        printf("Enter the name of adventurer %d: ", i + 1);
        fgets(adv.name, 50, stdin);
        adv.name[strcspn(adv.name, "\n")] = '\0'; // remove trailing newline

        printf("Select Profession:\n");
        displayType();
        printf("Enter profession type: ");
        fgets(adv.profession.type, 50, stdin);
        adv.profession.type[strcspn(adv.profession.type, "\n")] = '\0';

        displayRole();
        printf("Enter role: ");
        fgets(adv.profession.role, 50, stdin);
        adv.profession.role[strcspn(adv.profession.role, "\n")] = '\0';

        adv.gear = (equipment*)malloc(3 * sizeof(equipment));
        for (j = 0; j < 3; j++) {
            printf("Enter equipment %d type: ", j + 1);
            fgets(adv.gear[j].type, 50, stdin);
            adv.gear[j].type[strcspn(adv.gear[j].type, "\n")] = '\0';

            printf("Enter equipment %d gear level (1-25): ", j + 1);
            scanf("%d", &adv.gear[j].gearLevel);
            getchar(); // to consume newline character after number input
        }

        adv.gearscore = calculateGearScore(adv.gear, 3);
        addNode(&head, adv);
    }

    printf("\nAdventurers List:\n");
    node* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Profession: %s, Role: %s, Gearscore: %d\n", 
               temp->Adventurer.name, temp->Adventurer.profession.type, temp->Adventurer.profession.role, temp->Adventurer.gearscore);
        temp = temp->next;
    }

    // Free allocated memory
    temp = head;
    while (temp != NULL) {
        node* next = temp->next;
        free(temp->Adventurer.gear);
        free(temp);
        temp = next;
    }

    return 0;
}

