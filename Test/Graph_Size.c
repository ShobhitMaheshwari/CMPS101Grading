#include<stdio.h>
#include<stdlib.h>
#include "../List.h"
#include "../Graph.h"
#include"Test.h"
void main1(){
        Graph a = newGraph(4);
		printf("%d\n", getSize(a)); // 0

		//addEdge(a, 1, 2);
		//printf("%d\n", getSize(a)); // 1

		addArc(a, 1, 2);
		printf("%d\n", getSize(a)); // 1

		addArc(a, 2, 3);
		printf("%d\n", getSize(a)); // 2



        freeGraph(&a);
}
