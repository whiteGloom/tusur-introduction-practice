#include <array>
#include <vector>

using namespace std;

using EquationRoots = vector<array<float, 2>>;

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
		static EquationRoots getEquationRootsByIteration(float (*equation)(float), float start, float end, float step);
};