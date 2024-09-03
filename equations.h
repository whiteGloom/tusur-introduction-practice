#include <array>
#include <vector>

using namespace std;

using EquationRoots = vector<array<float, 2>>;

class Equations {
	public:
		/// <summary>
		///     ������� ��� ������ ������ ��������� ������� ��������, � ����� � ��������� ������� "step"
		/// </summary>
		/// <param name="equation">���������</param>
		/// <param name="start">������ ������� �������� ��� ��������</param>
		/// <param name="end">����� ������� �������� ��� ��������</param>
		/// <param name="step">��� �������� � ������ ��������. ��� ��� ������, ��� ���� ��������, �� ���� ��������</param>
		/// <returns>
		///		������ ��������� ����������, � ������� ��������� ����� ���������. ����� ���� ������, ���� �� ��������� ������� ��� ������
		/// </returns>
		static EquationRoots getEquationRootsByIteration(float (*equation)(float), float start, float end, float step);
};