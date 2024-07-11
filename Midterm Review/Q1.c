#include <stdio.h>
#include <stdlib.h>

#define STRING_MAX 50
#define LIST_MAX 10

typedef struct{
    int month;
    int year;
}currentDate;

typedef struct{
    int hireMonth;
    int hireYear;
}hiringDetails;

typedef struct{
    char fName[STRING_MAX];
}empDetails;

typedef struct{
    hiringDetails dateOfHire;
    empDetails employeeInfo;
}employee;

typedef struct{
    employee employeeList[LIST_MAX];
    int count;
}employeeRecords;

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate);

void display(employee *loyalList,int loyalListCount);

int main(){
    employeeRecords record;
    int employeeCount;
    int loyalListCount=0;
    record.count=0;
    employee *loyalList;
    currentDate date={7,2023};
    
    int i = 0;
    printf("Input Number of Employees:" );
    scanf("%d",&employeeCount);
    
    printf("\nInput Details for Employees: \n");
    for(i=0;i<employeeCount;i++){
        printf("\n\n===Employee %d===\n",i+1);
        /*CODE FOR INPUTS*/
        printf("Input First Name: ");
        scanf("%s", record.employeeList[i].employeeInfo.fName);
        printf("Input Month of Hire: ");
        scanf("%d", &record.employeeList[i].dateOfHire.hireMonth);
        printf("Input Year of Hire: ");
        scanf("%d", &record.employeeList[i].dateOfHire.hireYear);
        
        record.count++;
    }
    
    loyalList=getLoyalList(record,&loyalListCount,date);
    
    display(loyalList, loyalListCount);
    
    free(loyalList);
    
    return 0;
}

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate){
    /*CODE TO CREATE THE LOYAL LIST*/
    int i; 
    int loyalCount = 0;
    int index = 0; 
    for(i = 0; i < record.count; i++){
        int yearWork = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        int monthWork = currDate.month - record.employeeList[i].dateOfHire.hireMonth;
        
        if(yearWork > 5 || (yearWork == 5 && monthWork == 0)){
            loyalCount++;
        }
    }
    *loyalListCount = loyalCount;
    
    employee *loyalList = (employee *)malloc(loyalCount * sizeof(employee));
    for(i = 0; i < record.count; i++){
        int yearWork = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        int monthWork = currDate.month - record.employeeList[i].dateOfHire.hireMonth;
        
        if(yearWork > 5 || (yearWork == 5 && monthWork == 0)){
            loyalList[index] = record.employeeList[i];
            index++;
        }
    }
    
    return loyalList;
}

void display(employee *loyalList,int loyalListCount){
    /*CODE TO DISPLAY*/
    int i;
    
    if(loyalListCount == 0){
        printf("There are currently no Employees who are eligible for the reward.\n");
    }
    else{
        printf("Loyal List:\n\n");
        for(i = 0; i < loyalListCount; i++){
            printf("Name: %s -- ", loyalList[i].employeeInfo.fName);
            printf("Hire Date:%d-%04d", loyalList[i].dateOfHire.hireMonth, loyalList[i].dateOfHire.hireYear);
            printf("\n");
        }
    }
}
