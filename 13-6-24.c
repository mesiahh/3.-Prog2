#include <stdio.h>

int main(void){

	int b[10] = {2,4,6};
	int c[10] = {3,7,11};
    // b should store odd and c should store even?????

    int *a[2] = {b,c};

	int i;
	int j;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 10; j++){
            //printf("%d", a[i][j]);
            printf("%d", *(a[i] + j));
        }
        printf("\n");
    }
}




// Example 3: Comparison operators on Pointers using array

// //Illustrates comparison operators on pointers using array
// #include <stdio.h>

// int main(){
//     int n = 10; // length of an array
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int* ptr; // Declaration of pointer variable
//     ptr = arr; //Pointer points the first element (0th index)
//     int count_even = 0;
//     int count_odd = 0;

//     for (int i = 0; i < n; i++){
//         if (*ptr % 2 == 0){
//             count_even++;
//         }
//         if (*ptr % 2 != 0){
//             count_odd++;
//         }
//         ptr++; //Pointing to the next element in an array
//     }
//     printf("\n No of even elements in an array is : %d", count_even);
//     printf("\n No of odd elements in an array is : %d", count_odd);
// }














// Pointer Arithmetic on Arrays 
// - Reckall that pointers contain addresses.
// - An array name acts like a pointer constant.
// - The value of this pointer constant is the address of the first element (at index 0).

// Example: 1D Array Traversal Using Pointers

// // C program to illustrate the array traversal using pointers
// #include <stdio.h>

// int main(){
//     int N = 5;
//     // An array
//     int arr[] = {1,2,3,4,5};
//     //Declare pointer variable
//     int* ptr;
//     //Pointer to first element in array arr[]
//     ptr = arr;
//     printf("Array elements: ");
//     // Traveerse array using ptr
//     for (int i= 0; i < N; i++){
//         //Print element at which ptr points
//         printf("%d ", ptr[0]);     // array elements value
//         // printf("%d ", ptr[i]);     // displays random values
//         // printf("%d ", arr[i]);     // usual use of index
//         // printf("%d ", *ptr[0]);    // invalid
//         // printf("%d ", *ptr);       // value
//         // printf("%d ", ptr);        // address of each element
        
//     }
// }





// // Illustrates the array traversal using pointers in 2D array
// #include <stdio.h>

// // Function to traverse 2D array using pointers
// void traverseArr(int* arr, int N, int M){
//     int i, j;
//     // Traverse rows of 2D matrix
//     for (i = 0; i < N; i++){
//         for (j = 0; j < M; j++){
//             // print the element
//             printf("%d ", *((arr + i * M) + j));
//             //printf("%d ", (arr + i * M) + j);
//             // printf("%d ", *(arr + i * M));
//         }
//         printf("\n");
//     }
// }

// int main(){
//     int N = 3, M = 2;
//     // A 2D array
//     int arr[][2] = { {1,2},{3,4},{5,6}};
//     printf("2D-array elements:\n");
//     //Function call
//     traverseArr((int*)arr, N, M);
//     return 0;
// }



// Passing of Arrays to a Function
// - To pass a single dimension array as an argument, declare a formal parameter in one of three ways:
// * as a pointer void myFunction(int* param){...}
// * as a sized array void myFunction(int param[10]){...}
// * as an unsized array void myFunction(int param[0]){...}

// - When an entire array is passed as an argument to a function, only the array name is passed.
// - The starting address of the array gets passde to the function and not the copy of the entire array.
// - When you call a function with an array name, a pointer to the first element in the array is passed into the function.

// Example:

// #include <stdio.h>
// int minarray(int arr[], int size){
//     min=arr[0];
//     int i = 0;
//     printf("Before\t\tAfter\n");
//     for (i=1;i<size;i++){
//         printf("[%d]: %d \t min = %d", i, arr[i], min);
//         if (min>arr[i]){
//             min=arr[i];
//         }
//         printf("\t[%d]: %d\tmin=%d\n", i, arr[i], min);
//     }
//     return min;
// }

// int main(){
//     int i = 0, min = 0;
//     int numbers[]={4,5,7,3,8,9}; //declaration of array
//     min=minarray(numbers, 6);
//     printf("Minimum number is %d \n", min);

// }





//Array accepts 8 inputs
// ask if it wants to see odd, even, or both
//print function should be separate from the main function
// Sum of the odd and even saved at the last index of the array
// Use pointer arithmetic only
#include <stdio.h>
// return total should be arr[8]
int oddodd(int* arr){
	int i;
	int total_odd;
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 != 0){
			printf("[%d]: %d is Odd\n", i, *(arr+i));
			total_odd += *(arr+i);
		}
	}
	return total_odd;
}


int eveneven(int* arr){
	int i;
	int total_even;
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 == 0){
			printf("[%d]: %d is Even\n", i, *(arr+i));
			total_even += *(arr+i);
		}
	}
	return total_even;
}


int both(int* arr){
	int i;
	int total_even, total_odd;
	int total_both;
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 != 0){
			printf("[%d]: %d is Odd\n", i, *(arr+i));
			total_odd += *(arr+i);
		}
		if (arr[i] % 2 == 0){
			printf("[%d]: %d is Even\n", i, *(arr+i));
			total_even += *(arr+i);
		}
	}
	
	total_both = total_even + total_odd;
	return total_both;
	
}



int main(){
	int arr[7];
	int odd, even;
	int i;
	printf("Input 8 numbers: \n");
	for(i = 0; i <= 7; i++){
		scanf("%d", &arr[i]);
	}
	int n;
	int total;
	printf("Good! \n\n Now do you want to see the output odd, even, or both. (press 1 if only odd, 2 if only even, 3 if both): \n");
	scanf("%d", &n);
	
	if (n == 1){
		total = oddodd((int*)arr);
	} else if (n == 2){
		total = eveneven((int*)arr);
	} else if (n == 3){
		total = both((int*)arr);
	} else{
		return 1;
	}
	
	
	printf("Total: %d", total);
	
	return 0;
}






	if (arr[9] == arr[10]){
		printf("\n\nTotal: %d %d", arr[8], second[0]);
		return 0;
	} else if (arr[9] != arr[10]){
		return 0;
	}
	



//Array accepts 8 inputs
// ask if it wants to see odd, even, or both
//print function should be separate from the main function
// Sum of the odd and even saved at the last index of the array
// Use pointer arithmetic only


// create another function that splits into two separates array; one for odd and one for array
// if they have the same size 


#include <stdio.h>
// return total should be arr[8]
void oddodd(int* arr){
	int i;
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 != 0){
			printf("[%d]: %d is Odd\n", i, *(arr+i));
			*(arr+8) += *(arr+i);
		}
	}
}


void eveneven(int* arr){
	int i;
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 == 0){
			printf("[%d]: %d is Even\n", i, *(arr+i));
			*(arr+8) += *(arr+i);
		}
	}

}

//
void both(int* arr, int* second){
	int i;
	int counterodd = 0, countereven = 0;
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 != 0){
			printf("[%d]: %d is Odd\n", i, *(arr+i));
			counterodd++;
			*(arr+8) += *(arr+i);
		}
	}
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 == 0){
			printf("[%d]: %d is Even\n", i, *(arr+i));
			countereven++;
			*(second) += *(arr+i);
		}	
	}
	
	*(arr+9) += counterodd;
	*(arr+10) += countereven - 1;
	
}



// int main(){
// 	int arr[10];
// 	int second[0]; 
// 	int odd, even;
// 	int i;
// 	printf("Input 8 numbers: \n");
// 	for(i = 0; i <= 7; i++){
// 		scanf("%d", &arr[i]);
// 	}
// 	int n;
// 	int total;
// 	printf("Good! \n\n Now do you want to see the output odd, even, or both. (press 1 if only odd, 2 if only even, 3 if both): \n");
// 	scanf("%d", &n);
	
// 	if (n == 1){
// 		oddodd((int*)arr);
// 	} else if (n == 2){
// 		eveneven((int*)arr);
// 	} else if (n == 3){
// 		both((int*)arr, (int*)second);
// 	} else{
// 		return 1;
// 	}
	
// 	printf("\n\nTotal: %d %d", arr[9], arr[10]);
// 	if (arr[9] == arr[10]){
// 		printf("\n\nTotal: %d %d", arr[8], second[0]);
// 		return 2;
// 	} else if (arr[9] != arr[10]){
// 		return 0;
// 	}
	

// }






//Array accepts 8 inputs
// ask if it wants to see odd, even, or both
//print function should be separate from the main function
// Sum of the odd and even saved at the last index of the array
// Use pointer arithmetic only


// create another function that splits into two separates array; one for odd and one for array
// if they have the same size 


#include <stdio.h>
// return total should be arr[8]
void oddodd(int* arr){
	int i;
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 != 0){
			printf("[%d]: %d is Odd\n", i, *(arr+i));
			*(arr+8) += *(arr+i);
		}
	}
}


void eveneven(int* arr){
	int i;
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 == 0){
			printf("[%d]: %d is Even\n", i, *(arr+i));
			*(arr+8) += *(arr+i);
		}
	}

}

//
void both(int* arr, int* second){
	int i;
	int counterodd = 0, countereven = 0;
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 != 0){
			printf("[%d]: %d is Odd\n", i, *(arr+i));
			counterodd++;
			*(arr+8) += *(arr+i);
		}
	}
	for(i = 0; i <= 7; i++){
		if (arr[i] % 2 == 0){
			printf("[%d]: %d is Even\n", i, *(arr+i));
			countereven++;
			*(second) += *(arr+i);
		}	
	}
	*(arr+9) += counterodd;
	*(arr+10) += countereven - 1;
}



int main(){
	int arr[10];
	int second[0]; 
	int odd, even;
	int i, j;
	printf("Input 8 numbers: \n");
	for(i = 0; i <= 7; i++){
		scanf("%d", &arr[i]);
	}
	int n;
	int total;
	printf("Good! \n\n Now do you want to see the output odd, even, or both. (press 1 if only odd, 2 if only even, 3 if both): \n");
	scanf("%d", &n);
	
	if (n == 1){
		oddodd((int*)arr);
	} else if (n == 2){
		eveneven((int*)arr);
	} else if (n == 3){
		both((int*)arr, (int*)second);
	} else{
		return 1;
	}
	
	printf("\n\nTotal: %d %d\n\n", arr[9], arr[10]);
	
		for(i = 0; i <= 7; i++){
			int even = 0;
			int odd = 0;
			if (arr[i] % 2 == 0){
				even += arr[i];
			}
			
			for(j = 0; j <=7; j++){
			if (arr[j] % 2 != 0){
				odd += arr[j];
			}	
			}
			int totaloddeven = even + odd;
			printf("Total Even [%d] + Odd [%d] = %d\n", even, odd, totaloddeven);
		}
	
	if (arr[9] == arr[10]){

		printf("\n\nTotal: %d %d", arr[8], second[0]);
		return 2;
	} else if (arr[9] != arr[10]){
		return 0;
	}
	

}

//topic for tommorow; Dynamically allocated array






