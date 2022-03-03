#include <iostream>
#include <string>
#include <vector>
#include "Functions.h"
#include "Algoritms.h"
#include "menu.h"

using namespace std;
void Algoritm1() {
	int* A;
	int N;
	int B;
	int sum;
	cout << "������� ���������� �����" << endl;
	cin >> N;
	cout << "������� �����" << endl;
	A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sum = summing(A, N);

	cout << sum << endl;
}

void Algoritm2() {

	int* A;
	int N;
	int B;
	int l;
	int min;

	cout << "������� ���������� �����" << endl;
	cin >> N;
	cout << "������� �����" << endl;

	A = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> B;
		A[i] = B;
	}
	l = 0;

	min = A[0];

	min_number(A, N, l, min);

	cout << "����������� �����:" << min << " ��� ������: " << l << endl;
}

void Algoritm3() {

	string* A;
	string* result;
	string buffer;
	char letter;
	int N;
	int k;

	cout << "������� ���������� ���������" << endl;
	cin >> N;

	A = new string[N];
	result = new string[N];

	cout << "������� ��������" << endl;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << "������� �����" << endl;

	cin >> letter;

	k = 0;

	otbor_elem(A, N, letter, result, k);

	cout << "����� ������:" << endl;

	for (int i = 0; i < k; i++) {
		cout << "[" << i << "] = "<< result[i] << endl;
	}
}

void Algoritm4() {

	string* A;
	string buffer;
	string str;
	int N;
	int idx;

	cout << "������� ���������� ���������" << endl;
	cin >> N;

	A = new string[N];

	cout << "������� ��������" << endl;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << "������� ������� �����" << endl;
	cin >> str;

	idx = linear_search(A, N, str);

	cout << "�������� ����� " << idx << endl;

}

void Algoritm5() {

	string* A;
	string buffer;
	string str;
	int N;
	int idx;

	cout << "������� ���������� ���������" << endl;
	cin >> N;

	A = new string[N];

	cout << "������� ��������" << endl;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << "������� ������� �����" << endl;
	cin >> str;

	idx = binary_search(A, N, str);

	cout << "�������� ����� " << idx << endl;

}

void Algoritm6()
{
	string* name;
	string* list;
	string buffer;
	int N, k;

	cout << "������� ���������� ���������" << endl;
	cin >> N;

	name = new string[N + 1];
	list = new string[N + 1];

	cout << "������� ��������" << endl;

	for (int i = 0; i < N; i++) {
		cin >> name[i];
	}

	k = 0;
	spisok_bez_povtoreniy(name, N, list, k);

	cout << "������ ��� ����������" << endl;
	for (int i = 0; i < k; i++) {
		cout << "[" << i << "] = " << list[i] << endl;
	}
}

void Algoritm7()
{
	string* name;
	string* list;
	int* Rate;
	string buffer;
	int N, k;

	cout << "������� ���������� ���������" << endl;
	cin >> N;

	name = new string[N + 1];
	list = new string[N + 1];
	Rate = new int[N + 1];

	cout << "������� ��������" << endl;

	for (int i = 0; i < N; i++) {
		cin >> name[i];
	}

	k = 0;

	spisok_bez_povtoreniy_rate(name, N, Rate, list, k);

	cout << "������ ��� ���������� � ������� ��������" << endl;
	for (int i = 0; i < k; i++) {
		cout << "[" << i << "] = " << list[i] << "\t��� �������: " << Rate[i] << endl;
	}
}

void Algoritm8()
{
	string* name;
	string* list;
	int* CH;
	int* Sum;
	string buffer;
	int N, B, k;

	cout << "������� ���������� ���������" << endl;
	cin >> N;

	name = new string[N + 1];
	list = new string[N + 1];
	CH = new int[N + 1];
	Sum = new int[N + 1];

	cout << "������� ��������" << endl;

	for (int i = 0; i < N; i++) {
		cin >> name[i];
		cin >> B;
		CH[i] = B;
	}

	k = 0;

	spisok_bez_povtoreniy_sum(name, N, CH, Sum, list, k);

	cout << "������ ��� ���������� � ������� ��������" << endl;
	for (int i = 0; i < k; i++) {
		cout << "[" << i << "] = " << list[i] << "\t��������������: " << Sum[i] << endl;
	}
}

void Algoritm9()
{
	string* str;
	string buffer;
	int k;

	cout << "������� ������" << endl;
	getline(cin, buffer);

	str = new string[buffer.length() / 2 + 1];

	k = 0;

	string_split(buffer, ' ', str, k);

	for (int i = 0; i < k; i++) {
		cout << "[" << i << "] = " << str[i] << endl;
	}

}

void Algoritm10()
{
	string* result;
	string buffer;
	string razd = " ,/.'*-+?";
	int count = 0;

	cout << "������� ������" << endl;
	getline(cin, buffer);

	buffer = buffer + " ";

	result = new string[buffer.length() / 2 + 2];

	result[0] = "";

	string_split_smart(buffer, razd, result, count);

	for (int i = 0; i < count; i++) {
		cout << "[" << i << "] = " << result[i] << endl;
	}

}

void alg10() {
	string name;
	string zn = " ,;.?!-*+/";
	string* w;
	int count = 0;
	cout << "������� ������: " << endl;
	getline(cin, name);
	name = name + " ";
	int len = name.length() / 2 + 2;
	w = new string[len];
	w[0] = ""; //������ �������
	for (int i = 0; i < name.length(); i++) {
		int l = zn.find(name[i]);
		if (l < 0 || l > zn.length()) {
			w[count] = w[count] + name[i];
		}
		else {
			if (name[i] == ' ') {
				if (w[count] != "") {
					w[++count] = "";
				}
			}
			else {
				if (w[count] != "") {
					count++;
				}
				w[count] = name[i];
				w[++count] = "";
			}
		}
	}
	cout << "����� ������: " << endl;
	for (int i = 0; i < count; i++) {
		cout << w[i] << endl;
	}
}
