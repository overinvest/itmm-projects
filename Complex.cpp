#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>

using namespace std;

void localize() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void string_split_smart(string str, string razd, string* &result, int& count) {
	for (int i = 0; i < str.length(); i++) {
		int l = razd.find(str[i]);
		if (l < 0 || l > razd.length()) {
			result[count] += str[i];
		}
		else {
			if (str[i] == ' ') {
				if (result[count] != "") {
					result[++count] = "";
				}
			}
			else {
 				result[++count] = str[i];
			}
		}
	}
}

class Complex {
public:
	Complex(int _real = 0, int _im = 0) {
		real = _real;
		im = _im;

		real_f = (double)real;
		im_f = (double)im;

		mod = sqrt(real_f * real_f + im_f * im_f);
	}

	Complex(double _real, double _im = 0.0) {
		real_f = _real;
		im_f = _im;

		real = (int)real_f;
		im = (int)im_f;

		mod = sqrt(real_f * real_f + im_f * im_f);
	}

	Complex(int _real, double _im = 0.0) {
		real_f = (double)_real;
		im_f = _im;

		real = _real;
		im = (int)im_f;

		mod = sqrt(real_f * real_f + im_f * im_f);
	}

	Complex(double _real, int _im = 0) {
		real_f = _real;
		im_f = (double)_im;

		real = (int)real_f;
		im = _im;

		mod = sqrt(real_f * real_f + im_f * im_f);
	}

	int GetReal() {
		return this->real;
	}

	int GetIm() {
		return this->im;
	}

	double GetMod() {
		mod = sqrt(real_f * real_f + im_f * im_f);
		return this->mod;
	}

	void SetReal(int rl) {
		real = rl;
		real_f = (double)real;
		mod = sqrt(real_f * real_f + im_f * im_f);
	}

	void SetIm(int iml) {
		im = iml;
		im_f = (double)im;
		mod = sqrt(real_f * real_f + im_f * im_f);
	}

	void SetReal(double rl) {
		real_f = rl;
		real = (int)real_f;
		mod = sqrt(real_f * real_f + im_f * im_f);
	}

	void SetIm(double iml) {
		im_f = iml;
		im = (int)im_f;
		mod = sqrt(real_f * real_f + im_f * im_f);
	}

	~Complex(void) {
		real = 0;
		im = 0;
		real_f = 0.0;
		im_f = 0.0;
		mod = 0;
	};

	Complex operator+(Complex comp) {
		return Complex(real + comp.real, im + comp.im);
	}

	Complex operator-(Complex comp) {
		return Complex(real + comp.real, im + comp.im);
	}

	Complex operator*(Complex comp) {
		return Complex(real * comp.real - im * comp.im, real * comp.im + comp.real * im);
	}

	Complex operator/(Complex comp) {
		double sum_sqrt = comp.GetMod();

		if (sum_sqrt == 0.f) {
			cout << "Деление на 0 невозможно, попробуйте ввести другое число" << endl;
			return Complex();
		}
		else {
			return Complex((real_f * comp.real_f + im_f * comp.im_f) / sum_sqrt, (real_f * comp.im_f - comp.im_f * im_f) / sum_sqrt);
		}

	}

	friend ostream& operator<<(ostream& out, const Complex& comp) {

		string reals;
		string ims;

		if (ceil(comp.real_f) > comp.real) {
			reals = to_string(comp.real_f);
		}
		else {
			reals = to_string(comp.real);
		}

		if (ceil(comp.im_f) > comp.im) {
			ims = to_string(comp.im_f);
		}
		else {
			ims = to_string(comp.im);
		}

		if (comp.real_f != 0.0) {
			if (comp.im_f > 1.0) {
				out << reals << "+" << ims << "i";
			}
			else if (comp.im_f < -1.0) {
				out << reals << ims << "i";
			}
			else {
				if (comp.im_f > 0.0) {
					out << reals << "+i";
				}
				else if (comp.im_f < 0.0) {
					out << reals << "-i";
				}
				else {
					out << reals;
				}
			}
		}
		else {

			if (abs(comp.im_f) == 1.0) {
				if (comp.im_f > 0.0) {
					out << "i";
				} else {
					out << "-i";
				}
			}
			else {
				if (comp.im_f == 0.0) {
					out << 0;
				}
				else {
					out << ims << "i";
				}
			}
		}

		return out;
	}

	friend istream& operator>>(istream& in, Complex& comp) {
		comp.SetReal(0);
		comp.SetIm(0);

		string* w = new string[3];
		string str;
		int k = 0;

		in >> str;

		string_split_smart(str, " +-", w, k);

		for (int i = 0; i < k + 1; i++) {

			int l = w[i].find("i");

			if (l >= 0 && l < str.length()) {
				w[i].erase(l, 1);

				if (w[i].length() == 0 || w[i] == "-" || w[i] == "+") {
					w[i] += "1";
				}

				double im = stod(w[i]);

				comp.SetIm(im);
			}
			else {

				if (w[i] != "") {
					double real = stod(w[i]);

					comp.SetReal(real);
				}
			}
		}

		return in;
	}
private:
	int real;
	int im;

	double real_f;
	double im_f;
	double mod;
};

int main() {
	localize();

	Complex A = {1, 5};
	Complex B(3, 2);
	Complex C;

	for (int i = 0; i < 5; i++) {

		cout << "Введите комплексное число:" << endl;
		cout << "Complex A: ";
		cin >> A;

		cout << "Complex B: ";
		cin >> B;

		cout << "Complex C: ";
		cin >> C;

		cout << "\t\tВычисления..." << endl;

		cout << "Сложение чисел:" << endl;

		cout << "\t A + B: " << A + B << endl << "\t B + C: " << B + C << endl << "\t C + A: " << C + A << endl;

		cout << "Умножение чисел:" << endl;

		cout << "\t A * B: " << A * B << endl << "\t B * C: " << B * C << endl << "\t C * A: " << C * A << endl;

		cout << "Деление чисел:" << endl;

		cout << "\t A / B: " << A / B << endl << "\t B / C: " << B / C << endl << "\t C / A: " << C / A << endl;

	}

}
