#include "Algoritms.h"
#include <vector>
#include <string>

using namespace std;
void summing(int* a, int size, int &sum) {
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
}

void min_number(int* a, int size, int &l, int &min) {
	l = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] < min) {
			min = a[i];
			l = i;
		}
	}
}

void otbor_elem(string* a, int size, char param, string* &result, int &k) {
	for (int i = 0; i < size; i++) {
		if (a[i].c_str()[0] == param) {
			result[k++] = a[i];
		}
	}
}

void linear_search(string* dst, int size, string source, int &idx) {
	int index = -1;
	int i = 0;

	while (index == -1 && i < size) {

		if (dst[i].compare(source) == 0) {
			index = i;
		}

		i++;
	}

	idx = index;
}

void binary_search(string* dst, int size, string source, int& idx) {
	int start = 0;
	int finish = size - 1;
	int index = -1;
	int i = 0;

	while (start <= finish)
	{
		int middle = (start + finish) / 2;

		int str_cmp_data = source.compare(dst[middle]);

		if (str_cmp_data == 0) {
			index = middle;
			break;
		}
		if (str_cmp_data < 0)
			finish = middle - 1;
		else
			start = middle + 1;
	}

	idx = index;

}

void spisok_bez_povtoreniy(string* name, int size, string* &result, int &k) {

	for (int i = 0; i < size; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (name[i].compare(result[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			result[k++] = name[i];
		}
	}
}

void spisok_bez_povtoreniy_rate(string* name, int size, int* &rate, string* &result, int& k) {

	for (int i = 0; i < size; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (name[i].compare(result[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			result[k] = name[i];
			rate[k] = 1;
			k++;
		}
		else {
			rate[l] += 1;
		}
	}
}

void spisok_bez_povtoreniy_sum(string* name, int size, int* ch, int* &sum, string* &result, int& k) {
	
	for (int i = 0; i < size; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (name[i].compare(result[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			result[k] = name[i];
			sum[k] = ch[i];
			k++;
		}
		else {
			sum[l] += ch[i];
		}
	}
}

void string_split(string str, char razd, string* &result, int &k) {
	string buffer = str;

	while (buffer.length() > 0) {
		int l = buffer.find(" ");
		if (l >= 0 && l < buffer.length()) {
			result[k++] = buffer.substr(0, l);
		}
		buffer.erase(0, l + 1);
	}
}

void string_split_smart(string str, string razd, string* &result, int &count) {
	for (int i = 0; i < str.length(); i++) {
		int l = razd.find(str[i]);
		if (l < 0 || l > razd.length()) {
			result[count] = result[count] + str[i];
		}
		else {
			if (str[i] == ' ') {
				if (result[count] != "") {
					result[++count] = "";
				}
			}
			else {
				if (result[count] != "") {
					count++;
				}
				result[count] = str[i];
				result[++count] = "";
			}
		}
	}
}

void bubble(vector<int> B) {
	int L, F, C;
	L = B.size() - 1;
	do {
		F = 0;
		for (int i = 0; i < L; i++) {
			if (B[i] > B[i + 1]) {
				C = B[i];
				B[i] = B[i + 1];
				B[i + 1] = C;
				F = 1;
			}
		}
		L--;
	} while (F == 1);

}

void BubbleBest(vector<int> B) {
	int L, F, C, Start;
	L = B.size() - 1;
	Start = 0;
	do {
		F = 0;
		for (int i = Start; i < L; i++) {
			if (B[i] > B[i + 1]) {
				C = B[i];
				B[i] = B[i + 1];
				B[i + 1] = C;
				F = 1;
			}
		}
		L--;
		if (F == 1) {
			F = 0;
			for (int i = L; i > Start; i--) {
				if (B[i] < B[i - 1]) {
					C = B[i];
					B[i] = B[i - 1];
					B[i - 1] = C;
					F = 1;
				}
			}
			Start++;
		}
	} while (F == 1);

}

void shell(vector<int> a) {
	int d, f, b;
	d = a.size();
	do {
		d = (d + 1) / 2;
		f = 0;
		for (int i = 0; i + d < a.size(); i++) {
			if (a[i] > a[i + d]) {
				b = a[i];
				a[i] = a[i + d];
				a[i + d] = b;
				f = 1;
			}
		}

	} while ((d > 1) || (f == 1));
}

void sortirovka_min(vector<int> a) {

	int min, l;
	for (int i = 0; i < a.size() - 1; i++)
	{
		min = a[i];
		l = i;
		for (int j = i + 1; j < a.size(); j++)
		{
			if (min > a[j])
			{
				min = a[j];
				l = j;
			}
		}
		a[l] = a[i];
		a[i] = min;
	}

}

void vstavkami(vector<int> a) {

	int B, j, m = 1;
	for (int i = m; i < a.size(); i++)
	{
		B = a[i]; j = i - 1;
		while (j >= 0 && B < a[j])
		{
			a[j + 1] = a[j]; j--;
		}
		a[j + 1] = B;
	}
}

void slienie(vector<int> first, vector<int> second, int k, vector<int> result)
{
	int p, q, cout;
	int NF = first.size();
	int NS = second.size();
	first[NF] = abs(first[NF - 1]);
	if (NS > 0)
	{
		first[NF] += abs(second[NS - 1]);
	}
	second[NS] = first[NF];
	p = 0;
	q = 0;
	cout = 0;
	while (cout < (NF + NS))
	{
		if (first[p] < second[q])
		{
			result[k + cout] = first[p++];
		}
		else
		{
			result[k + cout] = second[q++];
		}
		cout++;
	}
}

void sort_slienie(vector<int> A)
{
	int NF, NS;
	int d, k, i;
	vector<int> first;
	vector<int> second;
	d = 1;
	while (d < A.size())
	{
		k = 0;
		while ((k + d) < A.size())
		{
			NF = 0;
			for (i = 0; i < d && ((k + i) < A.size()); i++)
			{
				first.push_back(A[k + i]);
			}
			NS = 0;
			for (i = 0; i < d && ((k + d + i) < A.size()); i++)
			{
				second.push_back(k + d + i);
			}
			slienie(first, second, k, A);
			k = k + 2 * d;
		}
		d = 2 * d;
	}
}
