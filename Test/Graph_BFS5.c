#include<stdio.h>
#include<stdlib.h>
#include "../List.h"
#include "../Graph.h"
#include"Test.h"
void main1(){
	//Graph is from CLRS pg 596 Third edition
	//[r,s,t,u,v,w,x,y] = [1,2,3,4,5,6,7,8]
	//BUT there is directed edge from  u to t
	//and no edge between x and u
        Graph a = newGraph(8);

		addEdge(a, 1, 2);//r-s
		addEdge(a, 1, 5);//r-v
		addEdge(a, 2, 6);//s-w
		addEdge(a, 6, 3);//w-t
		addEdge(a, 6, 7);//w-x
		addEdge(a, 3, 7);//t-x
		addArc(a, 4, 3);//u-t //Note the difference
		//addEdge(a, 4, 7);//u-x
		addEdge(a, 4, 8);//u-y
		addEdge(a, 7, 8);//x-y

		BFS(a, 2);
		printf("%d\n", getSource(a));//2
		printf("%d\n", getParent(a, 4));//8
		printf("%d\n", getDist(a, 4));//4
		List l = newList();
		getPath(l, a, 4);
		printList(stdout, l);// 2 6 7 8 4


		BFS(a,4);//again run BFS
		printf("%d\n", getSource(a));//4
		printf("%d\n", getParent(a, 3));//4
		printf("%d\n", getDist(a, 2));//3
		clear(l);
		getPath(l, a, 2);
		printList(stdout, l);//4 3 6 2


		//add edge u-x
		addEdge(a, 4, 7);
		BFS(a,2);//again run BFS

		printf("%d\n", getSource(a));//2
		printf("%d\n", getParent(a, 4));//7
		printf("%d\n", getDist(a, 4));//3
		clear(l);
		getPath(l, a, 4);
		printList(stdout, l);// 2 6 7 4

		freeList(&l);
        freeGraph(&a);
}
