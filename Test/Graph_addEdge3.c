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
		/**
		1:
		2: 3
		3: 2
		4:
		 */
		printGraph(stdout, a);

		addEdge(a, 2, 3);//nothing should happem
		/**
		1:
		2: 3
		3: 2
		4:
		 */
		printGraph(stdout, a);

		addEdge(a, 3, 2);//nothing should happem
		/**
		1:
		2: 3
		3: 2
		4:
		 */
		printGraph(stdout, a);


        freeGraph(&a);
}
