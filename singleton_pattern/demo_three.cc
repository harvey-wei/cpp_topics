#include <iostream>
#include <string>


/** private consturctor
  * disable copy consturctor and assignment
  * static get instance and static inst
 */
class Singleton
{
	private:
		/**
	     * Singleton class can only be constructed by static function.
		 */
		Singleton(std::string _value) : value(_value) {};

		std::string value;

	public:
		/* Disallow copying */
		Singleton(const Singleton& rhs) = delete;
		Singleton(const Singleton&& rhs) = delete;

		/* Disallow assignment */
		Singleton& operator=(const Singleton& rhs) = delete;


		/* static function has no this pointer since it is class function.*/
		static Singleton& get_instance(std::string _value)
		{
			/* static variable has the lifetime of the whole program. */
			/* But static variable is initialized only once. */
			static Singleton inst(_value);

			return inst;
		}

		void print_val()
		{
			std::cout << value << std::endl;
		}
};


int
main(int argc, char** argv)
{
	static Singleton& inst_one = Singleton::get_instance("Singleton");
	static Singleton& inst_two = Singleton::get_instance("Singleton_two");

	inst_one.print_val();
	inst_two.print_val();

	return 0;
}
