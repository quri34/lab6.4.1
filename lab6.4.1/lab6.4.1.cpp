#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
}


int Sum(int* a, const int size, int s)
{
	for (int i = 0; i < size; i++)
		if (a[i] > 0)
			s += a[i];
	return s;
}

int Max(int* a, const int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++)
		if (abs(a[i]) > abs(max))
			max = a[i];
	return max;
}

int Min(int* a, const int size)
{
	int min = a[0];
	for (int i = 1; i < size; i++)
		if (abs(a[i]) < abs(min))
			min = a[i];
	return min;
}

int FindMin(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] == Min(a, size))
			return i;
}

int FindMax(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] == Max(a, size))
			return i;
}

int Dobutok(int* a, const int size)
{
	int d = 1;
	for (int i = 0; i < size; i++)
		if (i > FindMax(a, size) && i < FindMin(a, size) || i < FindMax(a, size) && i > FindMin(a, size))
			d = d * a[i];
	return d;
}

int Sort(int* a, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int max = a[i];
		int imax = i;
		for (int j = i + 1; j < size; j++)
			if (max < a[j])
			{
				max = a[j];
				imax = j;
			}
		a[imax] = a[i];
		a[i] = max;
	}
	return 1;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int n;
	cout << "n = "; cin >> n;
	int* a = new int[n];
	int Low;
	int High;
	cout << "Low = "; cin >> Low;
	cout << "High = "; cin >> High;

	Create(a, n, Low, High);
	cout << "a[" << n << "] = {";
	Print(a, n);
	cout << "}" << endl;

	cout << "Сумa додатних елементів масиву = " << Sum(a, n, 0); cout << endl;
	cout << "Добуток елементів масиву, розташованих між максимальним за модулем і мінімальним за модулем елементами = " << Dobutok(a, n); cout << endl;

	cout << "Елементи масиву, впорядковані за спаданням :" << endl;

	Sort(a, n);

	cout << "a[" << n << "] = {";
	Print(a, n);
	cout << "}" << endl;

	delete[] a;
	return 0;
}
