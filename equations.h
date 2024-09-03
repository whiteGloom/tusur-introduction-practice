#include <array>
#include <vector>

using namespace std;

using EquationRoots = vector<array<float, 2>>;

class Equations {
	public:
		/// <summary>
		///     ‘ункци€ дл€ поиска корней уравнени€ методом перебора, с шагом и точностью равными "step"
		/// </summary>
		/// <param name="equation">”равнение</param>
		/// <param name="start">Ќачало области значений дл€ перебора</param>
		/// <param name="end"> онец области значений дл€ перебора</param>
		/// <param name="step">Ўаг перебора и предел точности. „ем шаг меньше, тем выше точность, но ниже скорость</param>
		/// <returns>
		///		—писок примерных диапазонов, в которых наход€тс€ корни уравнени€. ћожет быть пустым, если на выбранном участке нет корней
		/// </returns>
		static EquationRoots getEquationRootsByIteration(float (*equation)(float), float start, float end, float step);
};