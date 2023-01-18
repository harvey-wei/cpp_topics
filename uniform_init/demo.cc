/*
// The syntax
type var_name{arg1, arg2, ....arg n}

The following initialization can be replaced by 
--------------------------------------------------
// uninitialized built-in type
int i;    

// initialized built-in type
int j=10; 

// initialized built-in type
int k(10);

// Aggregate initialization
int a[]={1, 2, 3, 4} 

// default constructor
X x1; 

// Parameterized constructor
X x2(1); 

// Parameterized constructor with single argument
X x3=3; 

// copy-constructor
X x4=x3; 

The uniform initialization.
--------------------------------------------------
int i{};     // initialized built-in type, equals to int i{0};

int j{10}; // initialized built-in type

int a[]{1, 2, 3, 4} // Aggregate initialization

X x1{}; // default constructor

X x2{1}; // Parameterized constructor;

X x4{x3}; // copy-constructor
*/
