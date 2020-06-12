#include <iostream>
#include <string>
using namespace std;
// In summary, operator function(overloaded operator) can be split into two types: member function of a class and friend function of another class!!!
// For the member fucntion, there is a implicit parameter this pointer to the current object. Hence, the overloaded operator defined as class member function has one less parameter than the  the friend version!!

class Complex 
{
	private:
		double m_db_real;
		double m_db_imag;
	
	public:
		// constructor
		Complex(double _real = 0, double _imag = 0)
			:m_db_real(_real), m_db_imag(_imag)
		{
			cout << "Complex" << endl;
		}

		// Implement the complex addtion by operator overloading
		// This is automatically called when '+' is used with
		// between two Complex objects
		/*
		Most overloaded operators may be defined as ordinary non-member functions or as class member functions. In case we define the overloaded operator as a member function, we only pass one argument for another variable of the same class!
		*/
		// reference saves memory!!!!
		Complex operator + (const Complex & _obj) const
		{
			Complex result;
			result.m_db_real = m_db_real + _obj.m_db_real;
			result.m_db_imag = m_db_imag + _obj.m_db_imag;
			
			return result;
		}

		Complex operator - (const Complex & _obj) const
		{
			return Complex(m_db_real - _obj.m_db_real, m_db_imag - _obj.m_db_imag);
		}

		// Declare the operator function(overloaded operator) as non-member function!
		/*
			// The global operator function is made friend of this class so 
// that it can access private members. Recalls that the friend function has the right to access the private and protected members!!!
		*/
		friend Complex operator * (Complex & _obj_1, Complex & _obj_2);
//		friend Complex operator / (Complex & _obj_1, Complex & _obj_2);
		double get_real()
		{
			return m_db_real;
		}

		double get_imag()
		{
			return m_db_imag;
		}
};

/*
	 In case we define above function as non-member function of a class then we would have to pass two arguments for each operand as follows
*/

Complex operator * (Complex & _obj_1, Complex & _obj_2)
{
return Complex(_obj_1.m_db_real * _obj_2.m_db_real - _obj_1.m_db_imag * _obj_2.m_db_imag,
		_obj_1.m_db_real * _obj_2.m_db_imag + _obj_1.m_db_imag * _obj_2.m_db_real);
}






int main()
{
	Complex a(1.0, 3.0), b(2.0, 4.0), res;

	res = a + b;
	cout << "real part: " <<  res.get_real() << endl;
	cout << "imaginary part: " << res.get_imag() << endl;
	
	res = a * b;
	cout << "real part: " <<  res.get_real() << endl;
	cout << "imaginary part: " << res.get_imag() << endl;
	

	return 0;
}
