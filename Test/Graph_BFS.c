#include<stdio.h>
#include<stdlib.h>
#include "../List.h"
#include "../Graph.h"
#include"Test.h"
void main1(){
	//Graph is from CLRS pg 596 Third edition
	//[r,s,t,u,v,w,x,y] = [1,2,3,4,5,6,7,8]
        Graph a = newGraph(8);

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

		printf("%d\n", getSource(a) == NIL);//1
		int parent = getParent(a, 1);
		printf("%d\n", getParent(a, 2) == parent);//1


		BFS(a, 2);
		printf("%d\n", getSource(a));//2
		printf("%d\n", getParent(a, 2) == NIL);//1
		printf("%d\n", getParent(a, 1));//2
		printf("%d\n", getParent(a, 5));//1
		printf("%d\n", getParent(a, 6));//2
		printf("%d\n", getParent(a, 3));//6
		printf("%d\n", getParent(a, 7));//6
		printf("%d\n", getParent(a, 4));//3
		printf("%d\n", getParent(a, 8));//7


		printf("%d\n", getDist(a, 2));//0
		printf("%d\n", getDist(a, 1));//1
		printf("%d\n", getDist(a, 5));//2
		printf("%d\n", getDist(a, 6));//1
		printf("%d\n", getDist(a, 3));//2
		printf("%d\n", getDist(a, 7));//2
		printf("%d\n", getDist(a, 4));//3
		printf("%d\n", getDist(a, 8));//3

        freeGraph(&a);
}
