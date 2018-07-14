#include <iostream>
#include <string>
#include <vector>
#include <string.h> 
#include <gtest\gtest.h>
#include <ctype.h>
using namespace std;


// getAscendingStr Function requirement
//
// Take space seperated digit string (ex. "1 2 3 5 4") and 
//   modify input string to ascending order ("1 2 3 4 5").
//
// return 0 if success, (empty string)
//       -1 if exception occur (ex. string containing non-digit character)
int getAscendingStr(string& inputStr)
{
	int i = 0,count=0;
	string num = inputStr;
	const int size= num.length();
	char cstr[18];
	strcpy_s(cstr, inputStr.c_str());
	//for (int i = 0; i<18; i++)
		//cout << cstr[i];
	int ri[5];
	for (i = 0; cstr[i] != 0; i++) {
		if (isalpha(cstr[i]))
			return -1;	
	}
	int str2int(const char *str);
	int* bubbleSort(int a[], int len);
	char *point;
	char delimsp[] = " ";
	char *strToken = nullptr;
	char *next_token = nullptr;
	point = strtok_s(cstr,delimsp,&next_token);
	while (point != NULL) {
		int x = str2int(point);
		ri[count] = x;
		point = strtok_s(nullptr, delimsp, &next_token);
		count += 1;
	}
	int *b = bubbleSort(ri, 5);
	string fin;
	for (i = 0; i<5; i++) {
		fin = fin + to_string(b[i]);
		if (i != 4)
			fin = fin + " ";
		
	}
	cout << fin << endl;
	inputStr = fin;
	return 0;
	/// Please fill your code here
}
int str2int(const char *str) {
	   int temp = 0;
	     const char *ptr = str;  
	     if (*str == '-' || *str == '+') {
		     str++;                      	
	}
	     while (*str != 0) {
		         if ((*str < '0') || (*str > '9')) {
			             break;                       		
		}
		         temp = temp * 10 + (*str - '0'); 
		         str++;      
	}
	     if (*ptr == '-') {                  
		         temp = -temp;
		
	}
	     return temp;
}

int* bubbleSort(int a[], int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	return a;
}

// solveQ Function requirement
// 
// solve quadratic function ax^2 + bx + c = 0
//
// return 1 if equation has two different real number root 
//          (return vector size should be 2 containing 2 solution.  
//          Greater value should put into smaller vector index)
//        0 there is only one possible solution to the quadratic equation 
//          (return vector size should be 1)
//       -1 complex roots 
//          (return vector size should be 0)
int solveQ(vector<double> &x, double a, double b, double c)
{
	if (pow(b, 2) - 4 * a * c > 0) {
		cout << ((-1) * b + sqrt(pow(b, 2) - 4 * a * c)) / 2 / a << " " << (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2 / a << endl;
		double a1 = ((-1) * b + sqrt(pow(b, 2) - 4 * a * c)) / 2 / a;
		double a2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2 / a;
		x.push_back(a1);
		x.push_back(a2);
		return 1;
	}
	else if (pow(b, 2) - 4 * a * c == 0) {
		cout << (-1) * b / 2 / a << endl;
		double a1 = (-1) * b / 2 / a;
		x.push_back(a1);
		return 0;
	}
	else {
	cout << "無解\n";
	return -1;
}
	return 0;
}

int main(int argc, char*argv[]) {
	
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

TEST(getAscendingStr, SimpleAscending)
{//Simple ascending test case

	string inputStr = "1 -3 2195 4 50";
	string tmpStr = inputStr;
	int err = getAscendingStr(tmpStr);
	EXPECT_EQ(tmpStr, "-3 1 4 50 2195");
	EXPECT_EQ(err, 0);
}

TEST(getAscendingStr, handleNonDigit)
{//getAscendingStr function should handle non digit case
	string tmpStr = "1 3 2 4 a 7f415";
	int err = getAscendingStr(tmpStr);
	EXPECT_EQ(err, -1);
}

TEST(solveQ, twoSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 2, -3);
	EXPECT_EQ(iSol, 1);
	EXPECT_EQ(sol.size(), 2);
	EXPECT_EQ(sol.at(0), 1);
	EXPECT_EQ(sol.at(1), -3);
}

TEST(solveQ, oneSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, -8, 16);
	EXPECT_EQ(iSol, 0);
	EXPECT_EQ(sol.size(), 1);
	EXPECT_EQ(sol.at(0), 4);
}

TEST(solveQ, noSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 1, 16);
	EXPECT_EQ(iSol, -1);
	EXPECT_EQ(sol.size(), 0);
}