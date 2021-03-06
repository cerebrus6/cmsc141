#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

template <typename T>
struct node {
	T content;
	struct node * prev;
	struct node * next;
};

template <typename T>
struct set {
	struct node <T> * head = NULL;
//	T duplicateCheck(T item) {
//		struct node <T> * tempNode = head;
//		while(tempNode!=NULL&&tempNode->next!=NULL) {
//			if(tempNode->content==item)
//				return true;
//			tempNode = tempNode->next;
//		}
//		return false;
//	}
	int insert(T data) {
		struct node <T> * newNode = (struct node <T> *) malloc(sizeof(struct node <T>));
		struct node <T> * tempPtr;
			if(head==NULL) {
				newNode -> prev = NULL;
				newNode -> next = NULL;
				newNode -> content = data;
				head = newNode;
			} else {
				tempPtr = head;
				while(tempPtr->next!=NULL) {
					if(tempPtr->content==data)
						return 0;
					tempPtr = tempPtr -> next;
				}
				if(tempPtr->content==data)
					return 0;
				tempPtr -> next = newNode;
				newNode -> prev = tempPtr;
				newNode -> next = NULL;
				newNode -> content = data;
			}
		return 1;
	}
	void display() {
		struct node <T> * ptr;
		ptr = head;
		printf("{");
		if(ptr!=NULL) {
			while(ptr !=NULL) {
				cout << ptr -> content;
				if(ptr->next!=NULL)
					printf(",");
				ptr = ptr -> next;
			}
  }
		printf("}\n");
	}
	T setUnion(T set1, T set2) {
		set <T> set3;
	}
};

template <typename T>
struct dualSet {
	struct set <T> s1;
	struct set <T> s2;
};

int getSize(string,char);
string * split(string);

int main(void) {
	ifstream file("input.in");
	string str;
	int count = 0;
	string fileContent[100] = {};
	while (getline(file, str)) {
		fileContent[count] = str;
		count++;
	}
	
	int currentInput = 0, testCases = stoi(fileContent[currentInput]), size, choice;
	currentInput+=1;
	struct dualSet <int> s1;
	struct dualSet <double> s2;
	struct dualSet <char> s3;
	struct dualSet <string> s4;
	while(testCases>0) {
//		int * tempArrInt = new int[size];
		choice = stoi(fileContent[currentInput]);
		currentInput += 1;
		size = getSize(fileContent[currentInput], ' ');
		string * tempArrString = split(fileContent[currentInput]);
		switch(choice) {
			case 1:
				for(int i = 0; i<size;i++)
					s1.s1.insert(stoi(tempArrString[i]));
				currentInput+=1;
				tempArrString = split(fileContent[currentInput]);
				for(int i = 0; i<size;i++)
					s1.s2.insert(stoi(tempArrString[i]));
				currentInput+=1;
				s1.s1.display();
				s1.s2.display();
				break;
			case 2:
				for(int i = 0; i<size;i++)
					s2.s1.insert(stod(tempArrString[i]));
				currentInput+=1;
				tempArrString = split(fileContent[currentInput]);
				for(int i = 0; i<size;i++)
					s2.s2.insert(stod(tempArrString[i]));
				currentInput+=1;
				s2.s1.display();
				s2.s2.display();
				break;
			case 3:
				char* char_arr;
				for(int i = 0; i<size;i++) {
					char_arr = &tempArrString[i][0];
					s3.s1.insert(*char_arr);
				}
				currentInput+=1;
				tempArrString = split(fileContent[currentInput]);
				for(int i = 0; i<size;i++){
				    char_arr = &tempArrString[i][0];
					s3.s2.insert(*char_arr);
				}
				currentInput+=1;
				s3.s1.display();
				s3.s2.display();
				break;
		}
		testCases--;
	}
	return 0;
}

int getSize(string num, char splitter=' ') {
	int size = 0, s;
	for(s = 0; num[s]!='\0';s++)
		if(num[s]==splitter)
			size++;
	if(size==0&&s>0)
		size=1;
	else if(size==0&&s==0)
		size=0;
	else
		size+=1;
	return size;
}

string * split(string items) {
	int sizeOf = getSize(items);
	string * newArr = new string[sizeOf];
	int counter1 = 0, counter2 = 0, start = 0;
	for(int i=0;items[i]!='\0';i++) {
		if(items[i]==' ') {
			int j=i+1;
			newArr[counter1] = items.substr(counter2,start);
			counter1++;
			counter2 = i+1;
			start=0;
		}
		start++;
	}
	if(counter1==0&&items[0]!='\0')
		newArr[0] = items.substr(0,items.length());
	else if(counter1!=0&&items[0]!='\0')
		newArr[counter1] = items.substr(counter2,items.length()-counter2);
	return newArr;
}
