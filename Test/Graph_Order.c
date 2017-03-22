#include<stdio.h>
#include<stdlib.h>
#include "../List.h"
#include "../Graph.h"
#include"Test.h"
void main1(){
        Graph a = newGraph(4);
		printf("%d", getOrder(a));
        freeGraph(&a);
}
