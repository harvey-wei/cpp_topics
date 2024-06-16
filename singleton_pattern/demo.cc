#include <iostream>

class SP
{
	/* Key is to create instance from get_instance. */
	/* Hence, the constructor must private or protected. */
	private:
		SP(int _val)
			: val(_val)
		{}

	public:
	/* Disable both assignment and copying. */
	void operator=(const SP& rhs) = delete;
	SP(const SP& rhs) = delete;

	/* static member function has no this ptr. */
	static SP& get_instance(int v)
	{
		static SP inst(v);

		return inst;
	}

	void do_sth()
	{
		std::cout << "val: " << val << std::endl;
	}

	private:
		int val;
};

int
main(int argc, char** argv)
{
	SP& inst = SP::get_instance(10);

	/* No constructor and just return the reference.*/
	SP& inst2 = SP::get_instance(99);
	inst.do_sth();
	inst2.do_sth();

	return 0;
}
