#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "problem.h"

void expiredProductRemoval(storeInventory *store, date currentDate){
    int i, j;
    int identify;
    
    store->expiredInventory.product = malloc(sizeof(productInfo) * store->currentInventory.inventoryCount);
    
    for(i = 0; i < store->currentInventory.inventoryCount; i++){
        identify = 0;
        if(store->currentInventory.product[i].expiryDate.year < currentDate.year){
            identify = 1;
        }
        
        if(store->currentInventory.product[i].expiryDate.year == currentDate.year && 
           store->currentInventory.product[i].expiryDate.month <= currentDate.month){
            identify = 1;
        }
        
        if(identify){
            store->expiredInventory.product[store->expiredInventory.inventoryCount] = store->currentInventory.product[i];
            store->expiredInventory.inventoryCount++;
            store->currentInventory.inventoryCost -= store->currentInventory.product[i].price * store->currentInventory.product[i].quantity;
            store->expiredInventory.inventoryCost += store->currentInventory.product[i].price * store->currentInventory.product[i].quantity;
            
            for(j = i; j < store->currentInventory.inventoryCount - 1; j++){
                store->currentInventory.product[j] = store->currentInventory.product[j + 1];
            }
            
            store->currentInventory.inventoryCount--;
            
            i--;
        }
    }
/* Write the code for the function here */

}
