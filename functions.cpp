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

vector<int> sorted, reverseSorted, randomVec, randomVec500, randomVec1000, randomVec5000, randomVec10000;

int dataComp, loopCtrl, dataAO, loopCtrlAO, other, total;

ofstream ofs1, ofs2, ofs3;

/*************************************************************
 * Function: openFiles()
 * Date Created: 1/27/20          	        
 * Date Last Modified: 1/27/20                 
 * Description: this function opens files to prepare them for output                    	
 * Input parameters: n/a
 * Returns: n/a     	
 * Pre: files are closed
 * Post: files are open
 *************************************************************/


void openFiles(){	

	ofs1.open("bubble_sort_results.csv");
	ofs2.open("selection_sort_results.csv");
	ofs3.open("insertion_sort_results.csv");
	
}

/*************************************************************
 * Function: closeFiles()   	
 * Date Created: 1/27/20                  	        
 * Date Last Modified: 1/27/20                    
 * Description: this function closes the files after we're done with them   	
 * Input parameters: n/a
 * Returns: n/a
 * Pre: files are open
 * Post: files are closed
 *************************************************************/

void closeFiles(){

	ofs1.close();
	ofs2.close();
	ofs3.close();
	
}

/*************************************************************
 * Function: createPreSorted() 	
 * Date Created: 1/27/20    	        
 * Date Last Modified: 1/29/20                    
 * Description: creates both sorted and reverse sorted vectors with numNodes # nodes               	
 * Input parameters: number of nodes wanted in vector
 * Returns: n/a
 * Pre: no vectors exist with any values
 * Post: both of the pre-sorted vectors now exist
 *************************************************************/

void createPreSorted(int numNodes){

	createSorted(numNodes, sorted);
	createReverseSorted(numNodes, reverseSorted);
	
}

/*************************************************************
 * Function: createRandomVector()  	
 * Date Created: 1/29/20 	        
 * Date Last Modified: 1/29/20                    
 * Description: creates randomized vector with numNodes # nodes       	
 * Input parameters: number of nodes wanted in vector
 * Returns: n/a
 * Pre: no randomized vectors exist
 * Post: randomized vector exists
 *************************************************************/

void createRandomVector(int numNodes){
	if(numNodes == 500){
	
		randomVec500 = createRandom(500, randomVec);
		
	} else if(numNodes == 1000){
	
		randomVec1000 = createRandom(1000, randomVec);
		
	} else if(numNodes == 5000){
	
		randomVec5000 = createRandom(5000, randomVec);
		
	} else if(numNodes == 10000){
	
		randomVec10000 = createRandom(10000, randomVec);
		
	} else {
	
		cout << "invalid input, try again..." << endl;
		exit(-1);
		
	}
}

/*************************************************************
 * Function: outputToFile()     	
 * Date Created: 1/29/20       	        
 * Date Last Modified: 1/29/20                    
 * Description: outputs collected data into appropriate .csv files for use on a spreadsheet       	
 * Input parameters: string exactly matching one of the three sort types
 * Returns: n/a
 * Pre: nothing is in the .csv files
 * Post: now the .csv files have data from program
 *************************************************************/

void outputToFile(string sortType){

int n;

if(sortType == "bubble"){
		
		ofs1 << "Vector Configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total" << endl;
		
		// SORTED
		for(int i=500; i<=10000; i += n){
			createSorted(i, sorted);
			ofs1 << "Sorted N=" << i << "," << bubbleTimer(sorted) << "," << dataComp << "," << loopCtrl << "," << dataAO << "," << loopCtrlAO << "," << other << "," << total << endl;
			if(i==500){
				n = 500;
			} else if(i==1000){
				n = 4000;
			} else if(i==5000){
				n = 5000;
			}
		}
		
		// DESCENDING SORTED
		for(int i=500; i<=10000; i += n){
			createReverseSorted(i, reverseSorted);
			ofs1 << "Descending sorted N=" << i << "," << bubbleTimer(reverseSorted) << "," << dataComp << "," << loopCtrl << "," << dataAO << "," << loopCtrlAO << "," << other << "," << total << endl;
			if(i==500){
				n = 500;
			} else if(i==1000){
				n = 4000;
			} else if(i==5000){
				n = 5000;
			}
		}
		
		// RANDOM
		vector<int> vec;
		for(int i=500; i<=10000; i +=n){
			if(i==500){
				n = 500;
				vec = randomVec500;
				performBubbleSort(vec);
			} else if(i==1000){
				n = 4000;
				vec = randomVec1000;
				performBubbleSort(vec);
			} else if(i==5000){
				n = 5000;
				vec = randomVec5000;
				performBubbleSort(vec);
			} else if(i==10000){
				vec = randomVec10000;
				performBubbleSort(vec);
			}
			ofs1 << "Random N=" << i << "," << bubbleTimer(vec) << "," << dataComp << "," << loopCtrl << "," << dataAO << "," << loopCtrlAO << "," << other << "," << total << endl;
		}
		
	} else if(sortType == "selection"){
		
		ofs2 << "Vector Configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total" << endl;
		
		// SORTED
		for(int i=500; i<=10000; i += n){
			createSorted(i, sorted);
			ofs2 << "Sorted N=" << i << "," << selectionTimer(sorted) << "," << dataComp << "," << loopCtrl << "," << dataAO << "," << loopCtrlAO << "," << other << "," << total << endl;
			if(i==500){
				n = 500;
			} else if(i==1000){
				n = 4000;
			} else if(i==5000){
				n = 5000;
			}
		}
		
		// DESCENDING SORTED
		for(int i=500; i<=10000; i += n){
			createReverseSorted(i, reverseSorted);
			ofs2 << "Descending sorted N=" << i << "," << selectionTimer(reverseSorted) << "," << dataComp << "," << loopCtrl << "," << dataAO << "," << loopCtrlAO << "," << other << "," << total << endl;
			if(i==500){
				n = 500;
			} else if(i==1000){
				n = 4000;
			} else if(i==5000){
				n = 5000;
			}
		}
		
		// RANDOM
	vector<int> vec;
		for(int i=500; i<=10000; i +=n){
			if(i==500){
				n = 500;
				vec = randomVec500;
				performSelectionSort(vec);
			} else if(i==1000){
				n = 4000;
				vec = randomVec1000;
				performSelectionSort(vec);
			} else if(i==5000){
				n = 5000;
				vec = randomVec5000;
				performSelectionSort(vec);
			} else if(i==10000){
				vec = randomVec10000;
				performSelectionSort(vec);
			}
			ofs2 << "Random N=" << i << "," << selectionTimer(vec) << "," << dataComp << "," << loopCtrl << "," << dataAO << "," << loopCtrlAO << "," << other << "," << total << endl;
		}
		
		
	} else if(sortType == "insertion"){
		
		ofs3 << "Vector Configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total" << endl;
		
		// SORTED
		for(int i=500; i<=10000; i += n){
			createSorted(i, sorted);
			ofs3 << "Sorted N=" << i << "," << insertionTimer(sorted) << "," << dataComp << "," << loopCtrl << "," << dataAO << "," << loopCtrlAO << "," << other << "," << total << endl;
			if(i==500){
				n = 500;
			} else if(i==1000){
				n = 4000;
			} else if(i==5000){
				n = 5000;
			}
		}
		
		// DESCENDING SORTED
		for(int i=500; i<=10000; i += n){
			createReverseSorted(i, reverseSorted);
			ofs3 << "Descending sorted N=" << i << "," << insertionTimer(reverseSorted) << "," << dataComp << "," << loopCtrl << "," << dataAO << "," << loopCtrlAO << "," << other << "," << total << endl;
			if(i==500){
				n = 500;
			} else if(i==1000){
				n = 4000;
			} else if(i==5000){
				n = 5000;
			}
		}
		
		// RANDOM
		vector<int> vec;
		for(int i=500; i<=10000; i +=n){
			if(i==500){
				n = 500;
				vec = randomVec500;
				performInsertionSort(vec);
			} else if(i==1000){
				n = 4000;
				vec = randomVec1000;
				performInsertionSort(vec);
			} else if(i==5000){
				n = 5000;
				vec = randomVec5000;
				performInsertionSort(vec);
			} else if(i==10000){
				vec = randomVec10000;
				performInsertionSort(vec);
			}
			ofs3 << "Random N=" << i << "," << insertionTimer(vec) << "," << dataComp << "," << loopCtrl << "," << dataAO << "," << loopCtrlAO << "," << other << "," << total << endl;
		}
		
	}
}

/*************************************************************
 * Function: createAll()
 * Date Created: 1/29/20          	        
 * Date Last Modified: 1/29/20                    
 * Description: easier way to tell compiler to create all three vectors appropriately
 				(the way the randomized vector is created is different from the other two pre-sorted vectors)       	
 * Input parameters: number of nodes wanted in vector
 * Returns: n/a
 * Pre: have to call two different functions in order to create all needed vectors >:(
 * Post: now you only have to call one function for your vectors :)
 *************************************************************/

void createAll(int numNodes){

	createPreSorted(numNodes);
	createRandomVector(numNodes);
	
}

/*************************************************************
 * Function: createSorted()
 * Date Created: 1/26/20
 * Date Last Modified: 1/26/20                    
 * Description: forms the sorted vector (in order from least to greatest)       	
 * Input parameters: number of nodes wanted in vector, and which vector to manipulate
 * Returns: n/a
 * Pre: sorted vector has no numbers
 * Post: sorted vector has numbers & is sorted appropriately
 *************************************************************/

void createSorted(int numNodes, vector<int> &sorted){

	sorted.clear();
	
	for(int i = 1; i <= numNodes; i++){
	
		sorted.push_back(i);
		
	}
}

/*************************************************************
 * Function: createReverseSorted()
 * Date Created: 1/26/20	        
 * Date Last Modified: 1/26/20                    
 * Description: forms the sorted vector (in order from greatest to least)       	
 * Input parameters: number of nodes wanted in vector, and which vector to manipulate
 * Returns: n/a
 * Pre: reverse sorted vector has no numbers
 * Post: reverse sorted vector has numbers & is sorted appropriately
 *************************************************************/

void createReverseSorted(int numNodes, vector<int> &reverseSorted){

	reverseSorted.clear();
	
	for(int i = numNodes; i > 0; i--){
	
		reverseSorted.push_back(i);
	}
}

/*************************************************************
 * Function: createRandom()
 * Date Created: 1/26/20       	        
 * Date Last Modified: 1/26/20                    
 * Description: forms the random vector (not sorted)
 * Input parameters: number of nodes wanted in vector, and which vector to manipulate
 * Returns: vector of random numbers
 * Pre: random vector has no numbers
 * Post: random vector has numbers & is NOT sorted
 *************************************************************/

vector<int> createRandom(int numNodes, vector<int> &randomVec){
	randomVec.clear();
	srand(time(0));
	
	for(int i = 0; i < numNodes; i++){
	
		int randomNum = rand() % numNodes;
		randomVec.push_back(randomNum);
	}
	
	return randomVec;
}

/*************************************************************
 * Function: performSelectionSort()
 * Date Created: 1/26/20     
 * Date Last Modified: 1/29/20                    
 * Description: runs through the chosen vector and sorts it (selection), also counting each individual operation          	
 * Input parameters: vector you wish to sort
 * Returns: selection sorted version of vector
 * Pre: vector has not been selection sorted
 * Post: vector has been selection sorted
 *************************************************************/

vector<int> performSelectionSort(vector<int> vec){
	total = 0, loopCtrl = 0, loopCtrlAO = 0, other = 0, dataComp = 0, dataAO = 0;
	
	other += 4;
	int swapIndex;
	int sort = 0;
	int smallest;
	bool swap = false;
	
	loopCtrlAO++;
	
	for(int n = 0; n < vec.size(); n++){	// loops for whole vector
	
		loopCtrl++;
		dataAO++;
		smallest = vec[n];	// vec[n] is always first index of n'th iteration
		loopCtrlAO++;
		
		for(int i = sort; i < vec.size(); i++){	// finds smallest num in vec
		
			loopCtrl++;
			dataComp++;
			
			if(vec[i] < smallest){
			
				dataAO += 3;
				swap = true;
				smallest = vec[i];
				swapIndex = i;
			}
		}
		
		loopCtrl++;
		
		dataComp++;
		
		if(swap == true){
		
			dataAO += 3;
			vec[swapIndex] = vec[n];
			vec[n] = smallest;
			swap = false;
			dataAO++;
			sort++;
			
		} else {
		
			dataAO++;
			sort++;
		}
	}
	
	loopCtrl++;
	
	total += loopCtrl;
	total += loopCtrlAO;
	total += other;
	total += dataComp;
	total += dataAO;
	
	return vec;
}

/*************************************************************
 * Function: performBubbleSort()
 * Date Created: 1/26/20  	        
 * Date Last Modified: 1/29/20                    
 * Description: runs through chosen vector and sorts it (bubble), also counting each individual operation
 * Input parameters: vector you wish to sort
 * Returns: bubble sorted version of vector
 * Pre: vector has not been bubble sorted
 * Post: vector has been bubble sorted
 *************************************************************/

vector<int> performBubbleSort(vector<int> vec){
	total = 0, loopCtrl = 0, loopCtrlAO = 0, other = 0, dataComp = 0, dataAO = 0;
	
	other++;
	int largest;
	loopCtrlAO++;
	
	for(int n = 0; n < (vec.size()); n++){	// loops for whole vector
	
	loopCtrl++;
	loopCtrlAO++;
	
		for(int i = n+1; i < (vec.size()); i++){	// finds largest num in vec
		
		loopCtrl++;
		dataComp++;
		
			if(vec[n] > vec[i]){
			
				dataAO += 3;
				largest = vec[n];
				vec[n] = vec[i];
				vec[i] = largest;
			}
		}
		
		loopCtrl++;
	}
	
	loopCtrl++;
	
	total += loopCtrl;
	total += loopCtrlAO;
	total += other;
	total += dataComp;
	total += dataAO;
	
	return vec;
}

/*************************************************************
 * Function: performInsertionSort()
 * Date Created: 1/26/20        
 * Date Last Modified: 1/29/20                    
 * Description: runs through chosen vector and sorts it (insertion), also counting each individual operation     	
 * Input parameters: vector you wish to sort
 * Returns: insertion sorted version of vector
 * Pre: vector has not been insertion sorted
 * Post: vector has been insertion sorted
 *************************************************************/

vector<int> performInsertionSort(vector<int> vec){
	total = 0, loopCtrl = 0, loopCtrlAO = 0, other = 0, dataComp = 0, dataAO = 0;
	
	other += 3;
	int i, j, currValue;
	loopCtrlAO++;
	
	for (i = 1; i < vec.size(); i++) {
	
		loopCtrl++;
		dataAO++;
		currValue = vec[i];
		dataAO++;
		j = i - 1;
		while (j >= 0 && currValue < vec[j]) {
		
			dataComp += 2;
			dataAO++;
			vec[j + 1] = vec[j]; 
			loopCtrlAO++;
			j--;
		}
		
		dataComp += 2;
		dataAO++;
		vec[j + 1] = currValue;
		
	}
	
	loopCtrl++;
	
	total += loopCtrl;
	total += loopCtrlAO;
	total += other;
	total += dataComp;
	total += dataAO;
	
	return vec;
}

/*************************************************************
 * Function: selectionTimer()
 * Date Created: 1/27/20     	        
 * Date Last Modified: 1/27/20                    
 * Description: records the amount of time it takes to complete a selection sort       	
 * Input parameters: vector you wish to sort
 * Returns: time in seconds to complete the sort (double)
 * Pre: don't know how long it takes to complete a sort
 * Post: now have data to compare to other forms of sorting
 *************************************************************/

double selectionTimer(vector<int> vec){
	auto timerStart = chrono::high_resolution_clock::now();
	
	performSelectionSort(vec);
	
	auto timerEnd = chrono::high_resolution_clock::now();
	
	auto duration = chrono::duration_cast<chrono::microseconds>(timerEnd-timerStart);	// finds time and converts to microseconds
	
	double timeElapsed = duration.count();
	
	timeElapsed = timeElapsed / 1e+6;	// converts microseconds to seconds
	
	return timeElapsed;
}

/*************************************************************
 * Function: bubbleTimer()
 * Date Created: 1/27/20        	        
 * Date Last Modified: 1/27/20                    
 * Description: records the amount of time it takes to complete a bubble sort       	
 * Input parameters: vector you wish to sort
 * Returns: time in seconds to complete the sort (double)
 * Pre: don't know how long it takes to complete a sort
 * Post: now have data to compare to other forms of sorting
 *************************************************************/

double bubbleTimer(vector<int> vec){
	auto timerStart = chrono::high_resolution_clock::now();
	
	performBubbleSort(vec);
	
	auto timerEnd = chrono::high_resolution_clock::now();
	
	auto duration = chrono::duration_cast<chrono::microseconds>(timerEnd-timerStart);	// finds time and converts to microseconds
	
	double timeElapsed = duration.count();
	
	timeElapsed = timeElapsed / 1e+6;	// converts microseconds to seconds
	
	return timeElapsed;
}

/*************************************************************
 * Function: insertionTimer()	
 * Date Created: 1/27/20     	        
 * Date Last Modified: 1/27/20                     
 * Description: records the amount of time it takes to complete an insertion sort      	
 * Input parameters: vector you wish to sort
 * Returns: time in seconds to complete the sort (double)
 * Pre: don't know how long it takes to complete a sort
 * Post: now have data to compare to other forms of sorting
 *************************************************************/

double insertionTimer(vector<int> vec){
	auto timerStart = chrono::high_resolution_clock::now();
	
	performInsertionSort(vec);
	
	auto timerEnd = chrono::high_resolution_clock::now();
	
	auto duration = chrono::duration_cast<chrono::microseconds>(timerEnd-timerStart);	// finds time and converts to microseconds
	
	double timeElapsed = duration.count();
	
	timeElapsed = timeElapsed / 1e+6;	// converts microseconds to seconds
	
	return timeElapsed;
}
