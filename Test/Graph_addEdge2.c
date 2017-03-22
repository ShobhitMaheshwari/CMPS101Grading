#include<stdio.h>
#include<stdlib.h>
#include "../List.h"
#include "../Graph.h"
#include"Test.h"
void main1(){
	//Graph is from CLRS pg 596 Third edition
	//[r,s,t,u,v,w,x,y] = [1,2,3,4,5,6,7,8]
        Graph a = newGraph(8);
		/*
		1:
		2:
		3:
		4:
		5:
		6:
		7:
		8:
		 */
		printGraph(stdout, a);

		addEdge(a, 1, 2);//r-s
		addEdge(a, 1, 5);//r-v
		addEdge(a, 2, 6);//s-w
		addEdge(a, 6, 3);//w-t
		addEdge(a, 6, 7);//w-x
		addEdge(a, 3, 7);//t-x
		addEdge(a, 3, 4);//t-u
		addEdge(a, 4, 7);//u-x
		addEdge(a, 4, 8);//u-y
		addEdge(a, 7, 8);//x-y

		/**
		1: 2 5
		2: 1 6
		3: 4 6 7
		4: 3 7 8
		5: 1
		6: 2 3 7
		7: 3 4 6 8
		8: 4 7
		 */
		printGraph(stdout, a);
        freeGraph(&a);
}
