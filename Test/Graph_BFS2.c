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

		List l = newList();
		printList(stdout, l);//
		printf("%d\n", length(l));//0

		BFS(a, 2);
		clear(l);
		getPath(l, a, 4);
		printList(stdout, l);// 2 6 3 4

		clear(l);
		getPath(l, a, 8);
		printList(stdout, l);// 2 6 7 8

		clear(l);
		getPath(l, a, 5);
		printList(stdout, l);// 2 1 5

		freeList(&l);
        freeGraph(&a);
}
