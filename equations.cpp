#include "equations.h"
#include <algorithm>

using namespace std;

EquationRoots Equations::getEquationRootsByIteration(float(*equation)(float), float start, float end, float step)
{
    EquationRoots result;

    // Перебираем область значений с заданным шагом
    for (float x = start; x <= end; x += step) {
        // Ограничим шаг, чтобы не выходить за заданную область
        float currentStep = min(step, end - x);

        // Если значение функции от x положительное, а значение от x + currentStep отрицательное (или наоборот),
        // то это значит, что  где-то между (включительно) x и x + currentStep находится корень уравнения.
        if (equation(x) * equation(x + currentStep) < 0) {
            result.push_back({ x, x + currentStep });
        }
    }

    return result;
}

