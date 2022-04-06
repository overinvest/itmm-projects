#pragma once
#include <string>
using namespace std;

class MyString
{
private:
	char* mem;
	int count;
	int size;
public:
	MyString(string str = "") {
		if (str.length() > 256) {
			size = str.length();
		}
		else {
			size = 256;
		}
		count = str.length();
		mem = new char[size];
		for (int i = 0; i < count; i++) {
			mem[i] = str[i];
		}
	};
	MyString(char* src, int k) {
		count = k;

		if (k > 256) {
			size = k;
		}
		else {
			size = 256;
		}

		mem = new char[size];

		for (int i = 0; i < count; i++) {
			mem[i] = src[i];
		}
	};
	~MyString() { delete[]mem; };
	MyString(const MyString& tmp) {
		count = tmp.count;
		size = tmp.size;

		mem = new char[size];
		for (int i = 0; i < count; i++) {
			mem[i] = tmp.mem[i];
		}
	};
	MyString(int num)
    {
        size = 128;
        count = 0;
        char tmp;
        mem = new char[size];
        /*char nums[] = {'0','1','2','3','4','5','6','7','8','9'};*/
        while (num > 0)
        {
            mem[count++] = num / 10 + 48;
            num /= 10;
        }
        for (int i = 0; i < count || 2; i++)
        {
            tmp = mem[i];
            mem[i] = mem[count - 1 - i];
            mem[count - 1 - i] = tmp;
        }
    }
	MyString &operator=(MyString tmp) {
		if (size != tmp.size) {
			if (size != 0) {
				delete[]mem;
			}

			size = tmp.size;
			mem = new char[size];
		}

		count = tmp.count;
		for (int i = 0; i < count; i++) {
			mem[i] = tmp.mem[i];
		}

		return *this;
	};
	int GetCount() {
		return this->count;
	}
	char& operator[](int k) {
		if (k >= 0 && k < count) {
			return mem[k];
		}

		char a = NULL;

		return a;
	}
	int length() {
		return this->count;
	}
	MyString copy(int start, int _count) {
		int len;

		if (start + _count > this->count) {
			len = this->count - start;
		}
		else {
			len = _count;
		}

		char* str;
		str = new char[len];

		for (int i = start; i < start + len; i++) {
			str[i - start] = this->mem[i];
		}

		MyString new_string(str, len);

		return new_string;
	}
	void del(int start, int _count) {
		if (start < 0) {
			this->count = 0;
		}else if (start < this->count) {
			for (int i = 0; i < this->count - start; i++) {
				mem[start + i] = mem[start + _count + i];
			}

			if (start + _count > this->count) {
				this->count = start;
			}
			else {
				this->count -= _count;
			}
		}
	}
	MyString operator+(MyString tmp) {
		char* str;

		str = new char[count + tmp.count];

		for (int i = 0; i < count; i++) {
			str[i] = mem[i];
		}

		for (int i = 0; i < tmp.count; i++) {
			str[i + count] = tmp.mem[i];
		}

		int new_count = count + tmp.count;

		MyString new_str(str, new_count);

		return new_str;
	}
	int find(MyString dst, int start = 0) {
		int l = -1;
		int index = 0;

		while (l == -1 && index < count - dst.count - start) {
			if (mem[start + index] == dst.mem[0]) {
				l = start + index;
			}

			index++;
		}

		for (int i = 0; i < dst.count && l >= 0; i++) {
			if (mem[l + i] != dst.mem[i]) {
				l = -1;
			}
		}

		return l;
	}
	int find(char dst, int start = 0) {
		int l = -1;
		int index = 0;

		while (l == -1 && index < count - start) {
			if (mem[start + index] == dst) {
				l = start + index;
			}

			index++;
		}

		return l;
	}
	int find(string dst, int start = 0) {
		int l = -1;
		int index = 0;

		while (l == -1 && index < count - dst.length() - start) {
			if (mem[start + index] == dst[0]) {
				l = start + index;
			}

			index++;
		}

		for (int i = 0; i < dst.length() && l >= 0; i++) {
			if (mem[l + i] != dst[i]) {
				l = -1;
			}
		}

		return l;
	}
	int operator == (MyString tmp)
    {
        int result = 0; //сравнимые строки одинаковы
        if (count != tmp.count)
        {
            int result = -1;
        }
        else
        {
            for(int i = 0; i < count && result == 0; i++)
            {
                if (mem[i] != tmp.mem[i])
                {
                    result = -1;
                }
            }
        }
        return result;
    }
	int operator > (MyString tmp)
    {
        int result = 0;
        for (int i = 0; i < count && i < tmp.count; i++)
        {
            if (mem[i] > tmp.mem[i])
            {
                result = -1;
            }
            if (count > tmp.count)
            {
                result = -1;
            }
        }
        return result;
    }
    int operator < (MyString tmp)
    {
        int result = 0;
        for (int i = 0; i < count && i < tmp.count; i++)
        {
            if (mem[i] < tmp.mem[i])
            {
                result = -1;
            }
            if (count < tmp.count)
            {
                result = -1;
            }
        }
        return result;
    }
};

