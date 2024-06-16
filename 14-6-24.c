// // malloc
// // calloc
// // realloc
// // is found in a different library

// int *ptr = (int*)malloc(sizeof(int)* 5);

// // difference between malloc and callor

// // calloc initialiizes everything to zero



// // malloc gets a big chunk of data

// // calloc gets specified chunk of data

// TOPIC FOR TODAY: MALLOC

// create a shoplist

// write 7 function only arrays no any complex shit
// 1.) Display Stock //void
// 2.) Update Stock // int
// 3.) Change Price // int
// 4.) Add to Cart  // int
// 5.) Remove Cart  // void
// 6.) View Cart    // void
// 7.) Check Out   // void


// Stock
//     Name Quantity Price

// Name and Price verifies in cart





// DisplayStock(){
// Stock Name
// Quantity //updateStock changes quantity
// Price    //changePrice changes price
// }

// AddtoCart{
//     price of that product
//     printf("name and total price of product") ;
// }





// cls();
// 	viewCart();
// 	checkOut();


// 	switch(){
// 		case 1:
// 		case 2: 
// 		case 3:
// 		case 4:
// 		case 5: 
		
// 	}



// Sort Stock
// Search Product
// Add new product













    
// int addCart(){
	
// }





#include <stdio.h>


int main(){
	int name[5] = {1, 2, 3, 4, 5};
	int stock[5] = {60, 42, 29, 60, 38};
    int numstock[5] = {60, 42, 29, 60, 38};
	float price[5] = {12.00, 25.00, 20.00, 15.00, 8.00};
	float eachPrice[5];
	int i;
	int total_price;
	char presyo, addPrice, reducePrice;
	int change;	
	
	
	
	displayStock((int*) name, (int*) stock, (float*) price); // print function 1
	
	
	// for loop for buying quantities of products
	for(i = 0; i <= 4; i++){
		int num;
		printf("\nHow many stocks of %d do you want? ", name[i]);
		scanf("%d", &num);
		
		if (num > stock[i]){
			system("cls");
			printf("\n\nYou have exceeded the amount of stocks \n\n chocolate [%d] : stocks [%d]\n", name[i], stock[i]);
			printf("You have inputted %d\n\n", num);
			printf("Please run the program again ty\n");
		return 0;			
	}
	updateStock((int*) stock, num, i); // update function 2
	*(price+i) *= num; //updates price
	total_price += *(price+i);
	*(eachPrice+i) *= num;
}
	//price of each products purchased 
	printf("**price of each products purchased**\n");
	for (i = 0; i<= 4; i++){
		printf("Chocolate Product [%d] : Price [%d]\n", name[i], price[i]);
	}
	
	
	// shows total price
	printf("\n\nTotal Price: %d", total_price);
	
	
	// //asks if it wants to change price
	// printf("\nDo you want to change price? (Yes/No)");
	// scanf("%c", &presyo);
	
	
	
	// if (presyo == 'Yes' || presyo == 'yes' || ){
	// 	printf("\n\nDo you want to add or reduce price? [1 if add and 2 if reduce]");
	// 	scanf("%d", &change);
		
		
	// 	if(change == 1){
			
			
	// 		printf("Good! Here's the updated stock of our products!");
	// 		printf("\n\n");
			
			
	// 		displayStock((int*) name, (int*) stock, (float*) price);
			
			
	// 			//price of each products purchased 
	// 		printf("**price of each products purchased**\n");
	// 			for (i = 0; i<= 4; i++){
	// 			printf("Chocolate Product [%d] : Price [%d] :  Stocks [%d]\n", name[i], eachPrice[i], stocks[i]);
	// 			}
				
	// 			printf("How many times do you want to add")
	// 			for (i = 0; i <= 4; i++){
					
	// 				scanf(""); 
	// 				changePrice()
	// 			}
				
				
	// 	} else if (change == 2){
	// 		pritnf("")
	// 	} else{
	// 		system("cls");
	// 		printf("Error! you have please only input between 1 and 2\n\n please try again");
	// 		return 0;
	// 	}
	// } else if (presyo == 'No' || presyo == 'no' ){
	// 	//proceed
	// } else{
	// 	printf("Error!!!! goodbye try again");
	// 	return 0;
	// 	//error
	// }


    printf("Do you want to add these to your cart? [1 if yes and 2 if remove]");
    if(choice1 == 1){
        addCart();
    } else if (choice2 == 2){
        removeCart();
    }else{
        printf("\n\n\nError try again");
        return 0;
    }
	


    viewCart((int*) name, (int*) stock, (float*) eachPrice)

	displayStock((int*) name, (int*) stock, (float*) price);
	
	
	
	
	printf("Total Price: ");
	//changePrice((int*) name, (int*) stock, (float*) price);
	
	return 0;
}




// 1. Displat Stock
void displayStock(int* name, int* stock, float* price){
	printf("Please select the type of flavor of chocolate you want to buy :)))\n");
	printf("%d \t %d \t %d \t %d \t %d\n", name[0], name[1], name[2], name[3], name[4]);
	printf("Milk \t Dark \t Mint \t White \t Peanut\n");
	printf("%d \t %d \t %d \t %d \t %d\n", stock[0], stock[1], stock[2], stock[3], *(stock+4));
	printf("%.2f \t %.2f \t %.2f \t %.2f \t %.2f\n", price[0], price[1], price[2], price[3], price[4]);
	printf("\n\n");
	
}

// 2. update Stock
int updateStock(int* stock, int num, int i){
	*(stock+i) -= num;
}

// 3. Change Price
int changePrice(int* name, int* stock, float* price){
	int i;
	for(i = 0; i <= 4; i++){
		
	}
	
// 4. Add Cart
void addCart(){
    printf("The products have been added to your cart! You can check them in the view cart section. Thank you.");
}
// 5. Remove Cart
void removeCart(){
    printf("The products have been removed from your cart! :(( we are sad to see you throw them away. Thank you.");
}
//6. viewCart
void viewCart(int* name, int* stock, float* eachPrice){
    int i;
    printf("Cart:\n\n");
    for (i = 0; i <= 4; i++){
        printf("[%d] Chocolate : Stock [%d] : Total Price [%.2f]\n", *(name + i), *(stock), *(eachPrice + i));
    }
}
// 7. checkOut

// prints total price 
	

	//viewcart a print function that prints the amount ordered
	
	//for loop that displays the total price
	// and ask if there's a product he wants to add?
	//7. checkOut function is an print end statement
}








































































































