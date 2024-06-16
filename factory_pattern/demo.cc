#include <iostream>
#include <string>
#include <memory> // shared_ptr, unique_ptr, weak_ptr

class Product
{
	public:
		virtual ~Product() {};
		virtual std::string Operation() const = 0; // pure virutual function
};

class ConcreteProduct1: public Product
{
	public:
		virtual std::string Operation() const override
		{
			return {"Result of the ConcreteProduct1"};
		}
};

class ConcreteProduct2: public Product
{
	public:
		virtual std::string Operation() const override
		{
			return {"Result of the ConcreteProduct2"};
		}
};


class Creator
{
	public:
		virtual ~Creator(){}
		virtual Product* Factory() const = 0; // pure virtual method.

		std::string SomeOperation()  const
		{
			/* base pointer or base reference can points to derived class instance. */
			Product* product = this->Factory();
			/* std::shared_ptr<Product> product = std::make_shared<Product>(this->Factory()); */

			std::string result = "Creator: The same creator's code has just worked with " +
				product->Operation();

			delete product;

			return result;
		};
};

class ConcreteCreator1 : public Creator
{
	public:
		virtual Product* Factory() const
		{
			return new ConcreteProduct1();
		};
};

class ConcreteCreator2 : public Creator
{
	public:
		virtual Product* Factory() const
		{
			return new ConcreteProduct2();
		};
};


/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void ClientCode(const Creator& creator) {
  // ...
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << creator.SomeOperation() << std::endl;
  // ...
}


/* int main() { */
/*   std::cout << "App: Launched with the ConcreteCreator1.\n"; */
/*   Creator* creator = new ConcreteCreator1(); */
/*   ClientCode(*creator); */
/*   std::cout << std::endl; */
/*   std::cout << "App: Launched with the ConcreteCreator2.\n"; */
/*   Creator* creator2 = new ConcreteCreator2(); */
/*   ClientCode(*creator2); */
/**/
/*   delete creator; */
/*   delete creator2; */
/*   return 0; */
/* } */


/**
 * The Application picks a creator's type depending on the configuration or
 * environment.
 */

int
main()
{
  std::cout << "App: Launched with the ConcreteCreator1.\n";
  /* auto creator = std::make_shared<ConcreteCreator1>(); */
  std::shared_ptr<ConcreteCreator1> creator(new ConcreteCreator1);
  ClientCode((*creator));
  std::cout << std::endl;

  std::cout << "App: Launched with the ConcreteCreator2.\n";
  auto creator2 = std::make_shared<ConcreteCreator2>();
  ClientCode(*creator2);

  return 0;
}


/* int */
/* main(int argc, char** argv) */
/* { */
/* 	return 0; */
/* } */
