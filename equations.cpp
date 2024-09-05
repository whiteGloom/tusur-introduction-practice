#include <algorithm>
#include "equations.h"
#include <string>

using namespace std;

EquationRoots Equations::getEquationRootsByIteration(double(*equation)(double), double start, double end, double step, double expectedValue)
{
    if (end <= start) {
        throw INPUT_RANGE_EXCEPTION; // Отрезок области определения составлен неправильно
    }

    if (step <= 0) {
        throw INPUT_STEP_EXCEPTION; // Шаг не может быть меньше или равен нулю
    }

    EquationRoots result = {};

    // Перебираем отрезок области определения с заданным шагом
    for (double x = start; x < end; x += step) {
        // Ограничим шаг, чтобы не выходить за границы отрезка
        double currentStep = min(step, end - x);

        // Если значение функции от x положительное, а значение от x + currentStep отрицательное (или наоборот),
        // то это значит, что  где-то между (включительно) x и x + currentStep находится корень уравнения.
        if ((expectedValue - equation(x)) * (expectedValue - equation(x + currentStep)) < 0) {
            result.push_back({ x, x + currentStep });
        }
    }

    return result;
}

string Equations::serializeRootsForPrint(EquationRoots roots) {
    EquationRoots::size_type rootsCount = roots.size();

    string result = "[";
    for (EquationRoots::size_type i = 0; i < rootsCount; i += 1) {
        auto& range = roots[i];

        result += "[" + to_string(range[0]) + ", " + to_string(range[1]) + "]";

        if (i != rootsCount - 1) {
            result += ", ";
        }
    }
    result += "]";

    return result;
};
