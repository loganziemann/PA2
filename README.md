From the data I collected in this programming assignment, I noticed that bubble sort was by FAR the most involved and convoluted
way to sort vectors of integers. Bubble sort had almost sixty million more operations (~160 million total operations) to complete 
than both the insertion sort and the selection sort (both were ~100 million total operations). Also, as the number of nodes increased
within the vector, the bubble sort trended towards a much longer run time earlier than both the insertion sort and selection sort.
While the selection sort had a much more reasonable run time, it was still about 3/2 the amount of time it took for the insertion sort
to complete its sorting process by the time the nodes had been increased to 1000. Because of my findings, I think it is safe to assume
that the most efficient way to sort numbers in a vector is through insertion sort. Adding more nodes to the vector doesn't seem to put
as much stress on the program with that method of sorting as it does with the bubble sort, and, to a lesser extent, the selection sort.
