/* Write your comment here */
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

/* Define the maximum number of items and containers that you need to consider */
#define MAX_ITEMS 50
#define MAX_CONTAINERS 50


int i, ch, dataSet, setCount, numberContainers, containerCapacity, numberItems, itemSizes[50];
int allocations;

/* function prototype declaration */
void InitialAllocationReading(int *allocations, int numberItems);
void NextReading(int *allocations, int numberItems, int numberContainers);
int ValidReading(int *allocations);
void DisplayReading(int *allocations,int numberItems);
void PossibleSolution(int *allocations, int itemSizes[], int containerCapacity, int numberContainers, int numberItems);


int main(void)
{  
	/* The array for storing the allocations odometer digits */
	int numberItems;       /*length*/
	int numberContainers;  /*range*/
	int allocations[MAX_ITEMS]; /*allocations array*/
	int containerCapacity;

	FILE *fp;

	fp=fopen("input.txt","r");
	if (fp == NULL) {
		printf("failed to open file"); 
	}
	printf("Costly containers\nEngGen 131 Sem 2 2008\n\n");
	printf("Which data set? ");
	scanf("%d", &dataSet);


	setCount=0;
	while(setCount<dataSet){
		ch=fgetc(fp);
		if(ch=='#'){
			setCount++;
		}
	}

	fscanf(fp,"%d",&numberContainers);
	printf("Number of containers: %d\n", numberContainers);

	fscanf(fp,"%d",&containerCapacity);
	printf("Container Capacity: %d\n", containerCapacity);

	fscanf(fp,"%d",&numberItems);
	printf("Number of items: %d\n", numberItems);


	printf("item sizes: ");
	for (i=0; i<numberItems; i++){
		fscanf(fp,"%d",&itemSizes[i]);
		printf("%d ", itemSizes[i]);

	}



	/*create the initial allocation odometer reading (function is called here)*/ 
	InitialAllocationReading(allocations, numberItems);

	/*Generates all readings for the allocations*/ 
	while (ValidReading(allocations)) {
			DisplayReading(allocations, numberItems);
		NextReading(allocations, numberItems, numberContainers);
		PossibleSolution(allocations,itemSizes,containerCapacity,numberContainers,numberItems);
	}
	
	return 0;
}

/*function definition for initial allocation odometer reading*/ 
void InitialAllocationReading(int *allocations, int numberItems)
{
	/*this is function is suppose to set initial allocation odometer reading all to zero, and be the same
	the length as the number of items we have.*/ 
	int i;
	for (i=0; i<numberItems; i++){
		allocations[i]=0; 
	}
}

/*function definition for the next reading of the allocations odometer*/
void NextReading(int *allocations, int numberItems, int numberContainers)
{
	int i;
	i=numberItems-1;
	allocations[i]++;

	while(allocations[i]==numberContainers) {
		allocations[i]=0;
		i--;

		if (i<0){
			allocations[0] = -1;
			return;
		}
		allocations[i]++;
	}



}

/*function definition for the valid readings of the allocations odometer*/
int ValidReading(int *allocations)
{
int i, j, k, check;
	
if (allocations[0] == -1){
return 0;
}

	
		for ( i = 0; i < numberContainers; i++) {
			check = 0;	
			for ( j = 0; j < numberItems; j++) {		

				if ( allocations[j] == i ) {
					check += itemSizes[j];

					if (check > containerCapacity) {
						if (i = (numberContainers-1)){
						for (k = (j+1); k < (numberItems); k++){
								allocations[k] = (numberContainers-1);
						}
						}
					return 1;
					}
				}
			
		}
			return 0;
	}

}

/*function definition for displaying the valid readings of the allocations odometer*/
void DisplayReading(int *allocations, int numberItems)
{ 
	int i;

	for (i=0; i<numberItems; i++){
		printf("%d", allocations[i]);
	}
	printf("\n");
}

//FFFFFFFFFFFFFFFFFFFFFFFFFFFF

////Set total Weight in each container to be zero intitally.The allocations and itemSizes array are paired
//up and if a solution is found where the the totalWeight in a container is less than the container capacity,
//by adding up the values from the itemSizes array then a solution is found.

void PossibleSolution(int *allocations, int itemSizes[], int containerCapacity,int numberContainers, int numberItems)
{
	/*int sortingSolutions[numberItems][numberContainers];*/
//   

//	
//
//	int allocation,totalSize[MAX_ITEMS], i, j;
//
//	for (i=0; i<MAX_ITEMS;i++){
//	totalSize[MAX_ITEMS]=0;
//	}
//j = 0;
//	while( j < numberContainers){	
//	for(i =0; i<numberItems; i++) /*for itemSizes array*/{
//			if( allocations[j] == itemSizes[j]){
//				(totalSize[i] += itemSizes[i]);
//				printf(" solution found");
//			}
//
//				if (totalSize[i] > containerCapacity){
//					return 0;
//				} /* bc its not a valid solution */
//	   i++;
//	}
//}


	/*int totalSize[MAX_ITEMS] = {0};
	int i, j;

	for (i =0; i<numberItems; i++){
		for (j=0; j<numberContainers; j++){
			if (i==allocation[j]){
				totalSize[i] += itemSizes[j]*/



 



	/*printf("%d", sortingSolutions[numberItems][numberContainers]);*/


	////each element stores the sum of its row and column position
	//for (i =0; i<numberItems; i++)
	//	for (j=0; j<numberContainers; j++)
	//		

	///*displaying the contents of the two dimensional array*/
	//for (i =0; i<numberItems; i++){
	//	for (j=0; j<numberContainers; j++){
	//	}
	//	printf("%d", sortingSolutions[i][j]);
 //     }
	//printf("\n");
}






	//	int totalWeight, i;
	//
	//	totalWeight=0;
	//	for (i =0; i<50; i++){
	//		(allocations[i] == itemSizes[i]); /* pairing up the allocations array with the intemSizes array*/
	//		totalWeight += itemSizes[i];  /*add up the itemSizes which have been allocated*/
	//		if (totalWeight <= containerCapacity){  /* if the totalWeight in each container is less than the containerCapacity*/
	//			printf("solution found\n");
	//			printf("%d ", itemSizes[i]); /*might not need this*/
	//
	//		}
	//		else {
	//			printf("no solution found\n");
	//		}
	//
	//	}
	//}









