#include <array>
#include <string>
#include <vector>

using namespace std;

using EquationRoots = vector<array<double, 2>>;

class Equations {
	public:
		static const int INPUT_RANGE_EXCEPTION = 100;
		static const int INPUT_STEP_EXCEPTION = 101;

		/// <summary>
		///     Функция для поиска корней уравнения методом перебора, с шагом и точностью равными "step"
		/// </summary>
		/// <param name="equation">Уравнение</param>
		/// <param name="start">Начало области значений для перебора</param>
		/// <param name="end">Конец области значений для перебора</param>
		/// <param name="step">Шаг перебора и предел точности. Чем шаг меньше, тем выше точность, но ниже скорость</param>
		/// <param name="expectedValue">Искомое значение уравнения, при котором мы считаем X корнем</param>
		/// <returns>
		///		Список примерных диапазонов, в которых находятся корни уравнения. Может быть пустым, если на выбранном участке нет корней
		/// </returns>
		static EquationRoots getEquationRootsByIteration(double (*equation)(double), double start, double end, double step, double expectedValue = 0);

		/// <summary>
		///     Функция для сериализации списка корней в удобочитаемый формат
		/// </summary>
		static string serializeRootsForPrint(EquationRoots roots);
};
