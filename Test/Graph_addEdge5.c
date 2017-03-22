#include<stdio.h>
#include<stdlib.h>
#include "../List.h"
#include "../Graph.h"
#include"Test.h"
void main1(){
        Graph a = newGraph(4);
		/*
		1:
		2:
		3:
		4:
		 */
		printGraph(stdout, a);

		addEdge(a, 2, 3);
		addEdge(a, 2, 4);
	 	addEdge(a, 2, 1);//alphabetic order is maintained
		/**
		1: 2
		2: 1 3 4
		3: 2
		4: 2
		 */
		printGraph(stdout, a);

		addEdge(a, 2, 2);//shouldn't do anything
		/**
		1: 2
		2: 1 3 4
		3: 2
		4: 2
		 */
		printGraph(stdout, a);
		printf("%d\n", getSize(a));//3

		makeNull(a);
		/*
		1:
		2:
		3:
		4:
		 */
		printGraph(stdout, a);
        freeGraph(&a);
}
