#include <iostream>
#include <string>
using namespace std;
class Person 
{
	public:
		void play()
		{
			cout << "Person--play()" <<endl;
			cout << m_str_name <<"Human likes playing!" << endl;
		}
		Person(string _name = "Jim")
		{
			cout << "Person()" <<endl;
			m_str_name = _name;
		}
		// virtual keyword is implicted inherited by subclass
		virtual ~Person()  // virtual help the subclass object to release the heap memory!!!
		{
			cout << "~Person" <<endl;
		}
	protected:  // can be inherited by subclass
		string m_str_name;
};

class Soldier: public Person
{
	public:
		Soldier(string _name = "Kevin", int _age = 20)
		{
			m_int_age = _age;
			m_str_name = _name;  // derived from Person!!!!
			cout << "Soldier()" <<endl;
		}
		virtual ~Soldier()  // It is better to write out the virtual explicitly !!k
		{
			cout <<"~Solider()" << endl;
		}
		void play(int x)
		{
			cout << "Soldier also likes playing!"<<endl;
		}
		void work()
		{
			m_int_age = 40;
			/* Person::m_int_age = "Age of person!!!";  // the access method is analogous to that in scope!!!! */
			cout << "Soldier is working!" <<endl;
		}
		
	private:
		int m_int_age;
		/* string m_str_name; */
		int m_int_number;

};

int main()
{
	Soldier soldier;
	Person person(soldier); // copy the value of member derived from Person to person object!!! call default copy constructor
	/* Person *ptr_person = &soldier; */
	/* person = soldier;           // also derived data member come into effect! */
	/* person.play();	           // the behavior is the same as that in in initialization!! */
	/* ptr_person -> play(); */
	/* ptr_person->work();             // ptr_person can call the member functio of subclass's own!!! */
	Person *p = new Soldier; // Due to the default value of constructor, parentheses can be ommitted !!
	p->play();
	/* delete p; // trigger the desctuctor!!!!! */
	p = NULL;
	return 0;
}

