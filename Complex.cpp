
#include <iostream>
#include <locale>
#include <Windows.h>

using namespace std;

void localize() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

class Complex {
public:
	Complex(int _real = 0, int _im = 0) {
		real = _real;
		im = _im;
		mod = sqrt(real^2 + im^2);
	}

	int GetReal() {
		return this->real;
	}

	int GetIm() {
		return this->im;
	}

	double GetMod() {
		mod = sqrt(real ^ 2 + im ^ 2);
		return this->mod;
	}

	void SetReal(int rl) {
		real = rl;
		mod = sqrt(real ^ 2 + im ^ 2);
	}

	void SetIm(int iml) {
		im = iml;
		mod = sqrt(real ^ 2 + im ^ 2);
	}

	Complex operator+(Complex comp) {
		return Complex(real + comp.real, im + comp.im);
	}

	Complex operator-(Complex comp) {
		return Complex(real - comp.real, im - comp.im);
	}

	Complex operator*(Complex comp) {
		return Complex(real*comp.real - im*comp.im, real*comp.im + comp.real*im);
	}

	Complex operator/(Complex comp) {
		double sum_sqrt = comp.GetMod();

		try {
			if (sum_sqrt == 0.f) {
				throw sum_sqrt;
			}
			else {
				int new_real = (real * comp.real + im * comp.im) / sum_sqrt;
				int new_im = (real * comp.im - comp.im * im) / sum_sqrt;

				return Complex(new_real, new_im);
			}
		}
		catch (int myNum) {
			cout << "Деление на 0 невозможно, попробуйте ввести другое число" << endl;
			return Complex();
		}
	}

	friend ostream& operator<<(ostream &out, const Complex &comp) {
		if (comp.real != 0) {
			if (comp.im > 1) {
				out << comp.real << "+i" << comp.im;
			}
			else if (comp.im < -1) {
				out << comp.real << "-i" << abs(comp.im);
			}
			else {
				if (comp.im > 0) {
					out << comp.real << "+i";
				}
				else if (comp.im < 0) {
					out << comp.real << "-i";
				} else {
					out << comp.real;
				}
			}
		}
		else {
			if (comp.im > 1) {
				out << "i" << comp.im;
			}
			else if (comp.im < -1) {
				out << "-i" << abs(comp.im);
			}
			else {
				if (comp.im > 0) {
					out << "i";
				}
				else if (comp.im < 0) {
					out << "-i";
				}
				else {
					out << 0;
				}
			}
		}

		return out;
	}

	friend istream& operator>>(istream& in, Complex& comp) {
		in >> comp.real;
		in >> comp.im;

		comp.mod = sqrt(comp.real ^ 2 + comp.im ^ 2);
		return in;
	}
private:
	double real;
	double im;
	double mod;
};

int main() {
	localize();

	Complex A(5, 3);
	Complex B(5, -3);
	Complex C;

	cout << "Введите комплексное число:" << endl;
	cin >> C;

	cout << "Complex A: " << A << endl;
	cout << "Complex B: " << B << endl;
	cout << "Complex C: " << C << endl;
	cout << "Complex A + B: " << A + B << endl;
	cout << "Complex A - B: " << A - B << endl;
	cout << "Complex A * B: " << A * B << endl;
	cout << "Complex B / C: " << B / C << endl;
}