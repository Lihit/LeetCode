#include "iostream"
using namespace std;
template <typename T>
class Hello
{
public:
	Hello(int row, int col, int value) {
		this->row = row;
		this->col = col;
		this->Mat = new T[row * col];
		for (int i = 0; i < row * col; ++i)
		{
			this->Mat[i] = value;
		}
	}

	T& operator()(int i, int j) {
		return Mat[i * col + j];
	}

	void setMat(T newValue) {
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				(*this)(i, j) = newValue;
			}
		}
	}
public:
	T *Mat;
	int row;
	int col;

};
int main(int argc, char const *argv[])
{
	Hello<int> tmp(5, 5, 5);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << tmp(i, j) << " ";
		}
		cout << endl;
	}

	tmp.setMat(100);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << tmp(i, j) << " ";
		}
		cout << endl;
	}
	return 0;
}