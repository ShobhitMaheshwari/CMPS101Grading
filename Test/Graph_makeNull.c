#include<stdio.h>
#include<stdlib.h>
#include "../List.h"
#include "../Graph.h"
#include"Test.h"
void main1(){
        Graph a = newGraph(4);
		printf("%d \n", getOrder(a));//4
		printf("%d \n", getSize(a));//0

		addEdge(a, 2, 3);
		printf("%d \n", getOrder(a));//4
		printf("%d \n", getSize(a));//1

		makeNull(a);
		printf("%d \n", getOrder(a));//4
		printf("%d \n", getSize(a));//0

        freeGraph(&a);
}
