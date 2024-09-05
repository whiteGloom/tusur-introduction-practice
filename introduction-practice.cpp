#include <iostream>
#include <string>
#include "equations.h"
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>

#ifdef _WIN32
	#include <windows.h>
#endif

using namespace std;

static double equationTest(double x)
{
	return x * x - 5;
}

static double equation12(double x)
{
	return sin(x) - x + 0.15;
}

static double equation13(double x)
{
	return 0.1 * x * x - x * log(x);
}

static double equation14(double x)
{
	return pow(x, 4) - 26 * pow(x, 3) + 131 * x * x - 226 * x + 120;
}

static double equation15(double x)
{
	return pow(x, 4) - 0.486 * pow(x, 3) - 5.792 * x * x + 0.486 * x + 4.792;
}

static double equation16(double x)
{
	return x * x - 5 * sin(x);
}

static double equation17(double x)
{
	return 3 * x * x - 8 * sin(2 * x) - 2 * x;
}

static double equation18(double x)
{
	return pow(-x,	3) + 12 * sin(3 * x) - 5 * x;
}

static double equation19(double x)
{
	return pow(M_E, -x) * cos(M_PI * x);
}

static void printRootsInfo(double(*equation)(double), string equationPrintableRepresentation, double start, double stop, double step) {
	EquationRoots roots = Equations::getEquationRootsByIteration(equation, start, stop, step);

	cout << "Примерные диапазоны корней уравнения \"" << equationPrintableRepresentation << "\" на участке [" << start << ", " << stop << "]:" << endl;
	cout << Equations::serializeRootsForPrint(roots) << endl << endl;
}

int main()
{
	#ifdef _WIN32
		SetConsoleOutputCP(CP_UTF8);
	#endif

	double step = 0.001;

	printRootsInfo(equationTest, "x^2 - 5", -3, 3, step);

	printRootsInfo(equation12, "sin(x) - x + 0.15", 0, 2, step);

	printRootsInfo(equation13, "0.1 * x^2 - x * ln(x)", -1, 3, step);

	printRootsInfo(equation14, "x^4 - 26 * x^3 + 131 * x^2 - 226 * x + 120", 0, 4, step);

	printRootsInfo(equation15, "x^4 - 0.486 * x^3 - 5.792 * x^2 + 0.486 * x + 4.792", -3, 3, step);

	printRootsInfo(equation16, "x^2 - 5 * sin(x)", -1, 3, step);

	printRootsInfo(equation17, "3 * x^2 - 8 * sin(2 * x) - 2 * x", -1, 3, step);

	printRootsInfo(equation18, "-x^3 + 12 * sin(3 * x) - 5 * x", -1, 1, step);

	printRootsInfo(equation19, "e^(-x) * cos(pi * x)", -10, 10, step);

	cin.get();
};
