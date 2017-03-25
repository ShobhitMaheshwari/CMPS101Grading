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

		addArc(a, 2, 3);
		addArc(a, 3, 2);
		/**
		1:
		2: 3
		3: 2
		4:
		 */
		printGraph(stdout, a);

		addArc(a, 2, 4);
		/**
		1:
		2: 3 4
		3: 2
		4:
		 */
		printGraph(stdout, a);

		addArc(a, 2, 4);
		addArc(a, 4, 2);
		/**
		1:
		2: 3 4
		3: 2
		4: 2
		 */
		printGraph(stdout, a);

	 	addArc(a, 2, 1);//alphabetic order is maintained
		addArc(a, 1, 2);
		/**
		1: 2
		2: 1 3 4
		3: 2
		4: 2
		 */
		printGraph(stdout, a);


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
