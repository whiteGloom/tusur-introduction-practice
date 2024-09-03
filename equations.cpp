#include "equations.h"
#include <algorithm>

using namespace std;

EquationRoots Equations::getEquationRootsByIteration(float(*equation)(float), float start, float end, float step)
{
    EquationRoots result;

    // ���������� ������� �������� � �������� �����
    for (float x = start; x <= end; x += step) {
        // ��������� ���, ����� �� �������� �� �������� �������
        float currentStep = min(step, end - x);

        // ���� �������� ������� �� x �������������, � �������� �� x + currentStep ������������� (��� ��������),
        // �� ��� ������, ���  ���-�� ����� (������������) x � x + currentStep ��������� ������ ���������.
        if (equation(x) * equation(x + currentStep) < 0) {
            result.push_back({ x, x + currentStep });
        }
    }

    return result;
}

