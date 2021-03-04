#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <type_traits>
using namespace std;

template <typename T>
struct set {
	T * content;
	T duplicateCheck(T item) {
		for (T cont: content)
			if(cont==item)
				return false;
		return true;
	}
	T * insert(T data) {
		for(int i=0;i<content.length();i++) {

		}
		return content;
	}
	T setUnion(T set1, T set2) {
		set <T> set3;
	}
};

int getSize(string,char);
int * stringToNumArr(string);
string * split(string);
int * arrParseInt(string*);
double * arrParseDouble(string*);
char * arrParseChar(string*);

int main(void) {
	ifstream file("input.in");
	string str;
	int count = 0;
	string fileContent[100] = {};
	while (getline(file, str)) {
		fileContent[count] = str;
		count++;
	}

	int testCases = stoi(fileContent[0]);
	int currentInput = 1;
	string * file_content = new string[count];
	for(int i=0;i<count;i++) {
		file_content[i] = *split(fileContent[i]);
	}
	cout << arrParseInt(&file_content[1]);
	while(testCases>0) {
		int inputChoice = arrParseInt(&file_content[currentInput])[0];
		currentInput++;
		switch(inputChoice) {
			case 1:
				set <int> s1_1;
				set <int> s1_2;
				break;
			case 2:
				set <double> s2_1;
				set <double> s2_2;
				break;
			case 3:
				set <char> s3_1;
				set <char> s3_2;
				break;
			case 4:
				set <string> s4_1;
				set <string> s4_2;
				break;
			case 5:
				break;
			case 6:
				break;
		}
		
		inputChoice = arrParseInt(&file_content[currentInput])[0];
		switch(inputChoice) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
		}
		testCases--;
	}
	
//	string * temp = split(fileContent[0]);
//	set1.content = arrParseInt(temp);
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
	if(counter1==0&&items[0]!='\0') {
		newArr[0] = items.substr(0,items.length());
	}
	else if(counter1!=0&&items[0]!='\0') {
		newArr[counter1] = items.substr(counter2,items.length()-counter2);
	}
	return newArr;
}

int * arrParseInt(string * items) {
	int * result = new int[items->length()];
	for(int i=0;i<items->length();i++)
		result[i] = stoi(items[i]);
	return result;
}

double * arrParseDouble(string * items) {
	double * result = new double[items->length()];
	for(int i=0;i<items->length();i++)
		result[i] = stod(items[i]);
	return result;
}

char * arrParseChar(string * items) {
	char * result = new char[items->length()];
	for(int i=0;i<items->length();i++)
		result[i] = items[i][0];
	return result;
}
