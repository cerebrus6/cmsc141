#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <math.h>
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
	int del(T data) {
		struct node <T> * ptr;
		ptr = head;
		if(ptr!=NULL) {
			while(ptr !=NULL) {
				if(ptr->content==data) {
					if(ptr->prev!=NULL&&ptr->next!=NULL) {
						ptr->prev->next=ptr->next;
					} else if(ptr->prev!=NULL&&ptr->next==NULL) {
						ptr->prev->next=NULL;
					} else {
						head = head->next;
					}
				return 1;
				}
				ptr = ptr -> next;
			}
		}
		return 0;
	}
	bool isSubset(node <T> * tempPtr) {
		struct node <T> * ptr1 = head;
		struct node <T> * ptr2;
		int doesExists;
		while(ptr1!=NULL&&ptr1->next!=NULL) {
			ptr2 = tempPtr;
			doesExists = 0;
			while(ptr2!=NULL&&ptr2->next!=NULL) {
				if(ptr1->content==ptr2->content)
					doesExists = 1;
				ptr2 = ptr2->next;
			}
			if(doesExists == 0)
				return false;
			ptr1 = ptr1->next;
		}
		return true;
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
	void setUnion(node <T> * set2) {
		struct node <T> * ptr;
		struct node <T> * tempPtr;
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
		ptr = set2;
		int doesExist;
		if(ptr!=NULL) {
			while(ptr !=NULL) {
				doesExist = 0;
				tempPtr = head;
					if(tempPtr!=NULL) {
						while(tempPtr !=NULL) {
							if(ptr->content==tempPtr->content) {
								doesExist=1;
								break;
							}
							tempPtr=tempPtr->next;
						}
					}
				if(doesExist==0) {
					cout << ",";
					cout << ptr -> content;
				}


				ptr = ptr -> next;
			}
		}
		printf("}\n");
	}
	void setIntersection(node <T> * tempPtr) {
		struct node <T> * ptr1 = head;
		struct node <T> * ptr2;
		int doesExists;
		int comma = 0;
		cout << "{";
		if(ptr1!=NULL) {
			while(ptr1 !=NULL) {
				ptr2 = tempPtr;
				doesExists = 0;
				if(ptr2!=NULL) {
					while(ptr2!=NULL) {
						if(ptr1->content==ptr2->content) {
							doesExists = 1;
							break;
						}
					ptr2 = ptr2->next;
					}
				}
				if(doesExists == 1) {
					if(comma==0)
						comma = 1;
					else
						cout << ",";
				cout << ptr1->content;
				}
				ptr1 = ptr1->next;
			}
		}
		cout << "}" << endl;
	}
	void setDifference(node <T> * tempPtr) {
		struct node <T> * ptr1 = head;
		struct node <T> * ptr2;
		int doesExists;
		int comma = 0;
		cout << "{";
		if(ptr1!=NULL) {
			while(ptr1 !=NULL) {
				ptr2 = tempPtr;
				doesExists = 0;
				if(ptr2!=NULL) {
					while(ptr2!=NULL) {
						if(ptr1->content==ptr2->content) {
							doesExists = 1;
							break;
						}
					ptr2 = ptr2->next;
					}
				}
				if(doesExists == 0) {
					if(comma==0)
						comma = 1;
					else
						cout << ",";
				cout << ptr1->content;
				}
				ptr1 = ptr1->next;
			}
		}
		cout << "}" << endl;
	}
	int getSize() {
		int size = 0;
		struct node <T> * ptr1 = head;
		if(ptr1!=NULL) {
			while(ptr1!=NULL) {
				size+=1;
				ptr1=ptr1->next;
			}
		}
	return size;
	}
	T getIndex(int n) {
		struct node <T> * ptr1 = head;
		if(ptr1!=NULL) {
			while(n>0) {
				ptr1=ptr1->next;
				n-=1;
			}
		}
		return ptr1->content;
	}
	void powerSet() {
		struct node <T> * ptr1 = head;
		int n = 0;
		T * newArr = new T[getSize()];
		for(int i=0;i<getSize();i++) {
			newArr[i]=ptr1->content;
			ptr1=ptr1->next;
		}

    int pow_set_size = pow(2, getSize());
    int counter, j, comma;
    cout << "{";
    for(counter = 0; counter < pow_set_size; counter++) {
		if(counter!=0)
			cout << ",";
    	cout << "{";
		comma = 0;
	    for(j = 0; j < getSize(); j++) {
			if(counter & (1 << j)) {
				if(comma!=0)
					cout << ",";
   	    	    cout << newArr[j];
				comma=1;
			}

	    }
    	cout << "}";
    }
    cout << "}";
//		if()
//		Set<Set<T>> powerSet = new HashSet<Set<T>>();
//
//		for( long i = 0; i < (1 << n - 1); i++) {
//		    Set<T> element = new HashSet<T>();
//		    for( int j = 0; j < n; j++ )
//		        if( (i >> j) % 2 == 1 ) element.add(list.get(j));
//		    powerSet.add(element);
//		}

//		struct node <T> * ptr1 = head;
//		struct node <T> * ptr2 = head;
//		int counter = 1;
//		for(int i=0;i<counter;i++) {
//			if(ptr2!=NULL) {
//				ptr2=ptr2->next;
//			}
//		}
//		counter+=1;
//		if(ptr2!=)
	}
};

template <typename T>
struct dualSet {
	struct set <T> s1;
	struct set <T> s2;
	void insert(int s, T data) {
		switch(s) {
			case 1:
				s1.insert(data);
				s1.display();
				break;
			case 2:
				s2.insert(data);
				s2.display();
				break;
		}
	}
	void del(int s, T data) {
		switch(s) {
			case 1:
				s1.del(data);
				s1.display();
				break;
			case 2:
				s2.del(data);
				s2.display();
				break;
		}
	}
	void powerSet(int n) {
		switch(n) {
			case 1:
				s1.powerSet();
				break;
			case 2:
				s2.powerSet();
				break;
		}
	}
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
				break;
			case 2:
				for(int i = 0; i<size;i++)
					s2.s1.insert(stod(tempArrString[i]));
				currentInput+=1;
				tempArrString = split(fileContent[currentInput]);
				for(int i = 0; i<size;i++)
					s2.s2.insert(stod(tempArrString[i]));
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
				break;
		}
		currentInput+=1;
		int operations = stoi(split(fileContent[currentInput])[0]);
		currentInput+=1;
		for(;operations>0;operations--) {
			tempArrString = split(fileContent[currentInput]);
			switch(choice) {
				case 1:
					switch(stoi(tempArrString[0])) {
						case 1:
							s1.insert(stoi(tempArrString[1]), stoi(tempArrString[2]));
							currentInput+=1;
							break;
						case 2:
							s1.del(stoi(tempArrString[1]), stoi(tempArrString[2]));
							currentInput+=1;
							break;
						case 3:
							s1.s1.display();
							s1.s2.display();
							if(s1.s1.isSubset(s1.s2.head))
								cout << "true" << endl;
							else
								cout << "false" << endl;
							currentInput+=1;
							break;
						case 4:
							s1.s1.setUnion(s1.s2.head);
							currentInput+=1;
							break;
						case 5:
							s1.s1.setIntersection(s1.s2.head);
							currentInput+=1;
							break;
						case 6:
							s1.powerSet(stoi(tempArrString[1]));
							currentInput+=1;
							break;
					}
					break;
				case 2:
					switch(stoi(tempArrString[0])) {
						case 1:
							s2.insert(stoi(tempArrString[1]), stod(tempArrString[2]));
							currentInput+=1;
							break;
						case 2:
							s2.del(stoi(tempArrString[1]), stod(tempArrString[2]));
							currentInput+=1;
							break;
						case 3:
							if(s2.s1.isSubset(s2.s2.head))
								cout << "true" << endl;
							else
								cout << "false" << endl;
							currentInput+=1;
							break;
						case 4:
							s2.s1.setUnion(s2.s2.head);
							currentInput+=1;
							break;
						case 5:
							s2.s1.setIntersection(s2.s2.head);
							currentInput+=1;
							break;
						case 6:
							s2.powerSet(stoi(tempArrString[1]));
							currentInput+=1;
							break;
					}
					break;
			}
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
