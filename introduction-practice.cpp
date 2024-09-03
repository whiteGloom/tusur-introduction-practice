#include <iostream>
#include <string>
#include "equations.h"

using namespace std;

static float equation(float x)
{
	return x * x - 5;
};

int main()
{
	setlocale(LC_ALL, "RU");

	EquationRoots roots = Equations::getEquationRootsByIteration(equation, -5, 5, float(0.01));
	EquationRoots::size_type rootsCount = roots.size();

	// При желании, в дальнешем можно вынести представление в виде текста в отдельную функцию
	string resultPrintable = "Примерные диапазоны корней уравнения: [";
	for (EquationRoots::size_type i = 0; i < rootsCount; i += 1) {
		auto& range = roots[i];

		resultPrintable += "[" + to_string(range[0]) + ", " + to_string(range[1]) + "]";

		if (i != rootsCount - 1) {
			resultPrintable += ", ";
		}
	}
	resultPrintable += "]";

	cout << resultPrintable << endl;

	cin.get();
};
