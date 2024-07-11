#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/* The functions available are found in .h, although these functions are available does not mean,
they are needed to be used in the actual solution. Most functions are used during the initial population of the list and can be ignored, but again are available if you see fit. */

/* display() and populateSchoolList() is really the only required function you need to call in the actual solution */

team findTeam(char schoolInput[], char sportInput[], schoolList totalList){
    int i, j;
     
    team found;
    found.count = 0;
    found.teamMembers = malloc(sizeof(studentInfo) * totalList.schoolCount);
     
    for(i = 0; i < totalList.schoolCount; i++){
        if(strcmp(totalList.schoolList[i].school, schoolInput) == 0 &&
           strcmp(totalList.schoolList[i].game.esport, sportInput) == 0){
           found.teamMembers[found.count++] = totalList.schoolList[i];
        }
    }
    
    strcpy(found.teamDepartment, schoolInput);
    strcpy(found.game, sportInput);
     
    for(i = 0; i < found.count; i++){
        for(j = i + 1; j < found.count; j++){
            if(found.teamMembers[i].game.rank < found.teamMembers[j].game.rank){
                studentInfo Temp = found.teamMembers[i];
                found.teamMembers[i] = found.teamMembers[j];
                found.teamMembers[j] = Temp;  
            }
        }
    }
    
    if(found.count >= 6){
        found.count--;
    }
    return found;
}

int main(){
    schoolList totalList; //Refers to the list of all students interested in
                          //joining the tournament

    team foundTeam; //Refers to the team found based on the given criteria of
                    //school and choice of game

    char schoolInput[20];
    char sportInput[20];

    populateSchoolList(&totalList);

    printf("===Find Teams!===");
    printf("\nInput School: ");
    scanf(" %s",schoolInput);
    printf("Input Sport: ");
    scanf(" %s",sportInput);


    /* Proper function call to findTeam */
    foundTeam = findTeam(schoolInput, sportInput, totalList);

    display(foundTeam);
    
    free(foundTeam.teamMembers);
    
    return 0;
}
