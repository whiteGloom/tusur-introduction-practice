#include <algorithm>
#include "equations.h"
#include <string>

using namespace std;

EquationRoots Equations::getEquationRootsByIteration(double(*equation)(double), double start, double end, double step)
{
    EquationRoots result;

    // Перебираем область значений с заданным шагом
    for (double x = start; x <= end; x += step) {
        // Ограничим шаг, чтобы не выходить за заданную область
        double currentStep = min(step, end - x);

        // Если значение функции от x положительное, а значение от x + currentStep отрицательное (или наоборот),
        // то это значит, что  где-то между (включительно) x и x + currentStep находится корень уравнения.
        if (equation(x) * equation(x + currentStep) < 0) {
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
