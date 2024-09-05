#include <array>
#include <string>
#include <vector>

using namespace std;

using EquationRoots = vector<array<double, 2>>;

class Equations {
	public:
		/// <summary>
		///     Функция для поиска корней уравнения методом перебора, с шагом и точностью равными "step"
		/// </summary>
		/// <param name="equation">Уравнение</param>
		/// <param name="start">Начало области значений для перебора</param>
		/// <param name="end">Конец области значений для перебора</param>
		/// <param name="step">Шаг перебора и предел точности. Чем шаг меньше, тем выше точность, но ниже скорость</param>
		/// <returns>
		///		Список примерных диапазонов, в которых находятся корни уравнения. Может быть пустым, если на выбранном участке нет корней
		/// </returns>
		static EquationRoots getEquationRootsByIteration(double (*equation)(double), double start, double end, double step);

		static string serializeRootsForPrint(EquationRoots roots);
};