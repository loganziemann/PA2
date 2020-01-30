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

#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

extern ofstream ofs1;
extern ofstream ofs2;
extern ofstream ofs3;

extern vector<int> sorted;	// three types of vectors, then 4 randoms are stored
extern vector<int> reverseSorted;
extern vector<int> randomVec;
extern vector<int> randomVec500;
extern vector<int> randomVec1000;
extern vector<int> randomVec5000;
extern vector<int> randomVec10000;

void openFiles();
void closeFiles();

void createSorted(int numNodes, vector<int> &sorted);
void createReverseSorted(int numNodes, vector<int> &reverseSorted);

void createRandomVector(int numNodes);
void createPreSorted(int numNodes);
void createAll(int numNodes);

void outputToFile(string sortType);

vector<int> performSelectionSort(vector<int> vec);	// these functions sort those vectors
vector<int> performBubbleSort(vector<int> vec);
vector<int> performInsertionSort(vector<int> vec);

vector<int> createRandom(int numNodes, vector<int> &randomVec);

double selectionTimer(vector<int>);
double bubbleTimer(vector<int>);
double insertionTimer(vector<int>);

extern int dataComp;	// counts data comparisons
extern int loopCtrl;	// counts loop control comparisons
extern int dataAO;		// counts assignment operations involving data
extern int loopCtrlAO; // counts assignment operations invovling loop control
extern int other;		// counts all other misc. operations
extern int total;		// sum of all above counters
