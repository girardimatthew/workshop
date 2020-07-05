# 11.1

The Student_into structure that we defined in Chapter 09 did not define a copy constructor, assignment operator, or destructor. Why not?

Because the compiler synthesizes these operation for us. Sometimes they are exactly what we need. The rest of the time, the synthesized operations can lead to counterintuitive behavior, and even to run-time failures.

If a class defines no constructors, the compiler will synthesize the default constructor. If the class does not explicitly define them, the compiler will synthesize the copy constructor, assignment operator, and/or destructor. The synthesized operations are defined recursively: Each synthesized operator recursively applies the appropriate operation for the data members of the class.

If we do not define any constructors, the compiler will synthesize one for us. In this case, our users will be able to define Student_info objects, but will not be able to initialize them explicitly, except as a copies of other Student_info objects.

# 11.2
That structure did define a default constructor. Why?
since `midterm` and `final` are not class objects with constructors, and their default-initializing will give them undefined values, meaning they will hold whatever garbage happens to be in memory when the object is created.

# 11.3
It obliterates the previous value.

# 11.4
It destroys each data element according to the appropriate rules for the type of that element. Members that are of built-in type are copied or assigned by copying or assigning their value. The destructor for built-in types has no work to do—even if the type is a pointer. In particular, destroying a pointer through the default destructor does not free the space at which the pointer points.