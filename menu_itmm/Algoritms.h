#pragma once
#include <vector>
#include <string>
using namespace std;
int summing(int* a, int size);
void min_number(int* a, int size, int& l, int& min);
void otbor_elem(string* a, int size, char param, string*& result, int& k);
int linear_search(string* dst, int size, string source);
int binary_search(string* dst, int size, string source);
void spisok_bez_povtoreniy(string* name, int size, string*& result, int& k);
void spisok_bez_povtoreniy_rate(string* name, int size, int*& rate, string*& result, int& k);
void spisok_bez_povtoreniy_sum(string* name, int size, int* ch, int*& sum, string*& result, int& k);
void string_split(string str, char razd, string*& result, int& k);
void string_split_smart(string str, string razd, string*& result, int& count);
void bubble(vector<int> B);
void BubbleBest(vector<int> B);
void shell(vector<int> a);
void sortirovka_min(vector<int> a);
void vstavkami(vector<int> a);
void slienie(vector<int> first, vector<int> second, int k, vector<int> result);
void sort_slienie(vector<int> A);