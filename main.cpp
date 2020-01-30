/*
 Name: Logan Ziemann
 Class: CPSC 122
 Date: Jan. 29, 2020
 Programming Assignment: PA2                                                            
 Description: This program takes multiple sized vectors of sorted, reverse-sorted, and randomized numbers and sorts them
 			  through three different sorting approaches (insertion, bubble, and selection). It also calculates every individual operation
 			  and stores them in their respective .csv file
 Notes: I used cplusplus.com as reference
*/

#include "header.h"

int main(){
	extern vector<int> sorted;
	extern vector<int> reverseSorted;
	extern vector<int> randomVec;
	
	openFiles();
	
	createAll(500);
	createAll(1000);
	createAll(5000);
	createAll(10000);
	
	outputToFile("bubble");
	outputToFile("selection");
	outputToFile("insertion");
	
	//display();	// test sorting and variables by outputting to screen
	
	closeFiles();
	
	return 0;
}
