#include <iostream>
using namespace std;

/**
  Class Template
  Class Name: Rectangle
  Member Functions:calc_area(), calc_perimeter()
  Data Members: m_width, m_height (type as Template Argument)
**/

template <typename T>
class Rectangle 
{
	public:
		Rectangle(T _width, T _height);
		T calc_area();
		T calc_perimeter();
	
	private:
		T m_width;
		T m_height;
};

template <typename T>
Rectangle<T>::Rectangle(T _width, T _height)
{
	m_width = _width;
	m_height = _height;
}

template <typename T>
T Rectangle<T>::calc_area()
{
	return m_width * m_height;
}

template <typename T>
T Rectangle<T>::calc_perimeter()
{
	return 2 * (m_width + m_height);
}
// Same Logic/Operations but allow different data types!!
int main()
{
	Rectangle<double> Rect(3.5, 6.5);  // area:22.75, perimeter:20
	cout << Rect.calc_area() << endl;
	cout << Rect.calc_perimeter() << endl;

	return 0;
}
