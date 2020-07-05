#include "m_pd.h"

//new class
static t_class *counter_class;                                  //pointer to the new class

//define data space of the class
typedef struct _counter {                                       //struct of type _counter
    t_object x_obj;                                             //necessary element. Store internal object properties
    t_int i_count;                                              //store the counter-value
} t_counter;                                                    //struct name

//add method. manipulate the data with
void counter_bang(t_counter *x) {                               //
    t_float f=x->i_count;                                       //store the counter in a floating point-buffer.
    x->i_count++;                                               //counter is increased.
    outlet_float(x->x_obj.ob_outlet, f);                        //first argument: outlet. second argument: send a floating-point value to the first argument (outlet)
}

// the constructor
void *counter_new(t_floatarg f) {                               //one argument of type t_floatarg. used to initialise the counter
    t_counter *x = (t_counter *)pd_new(counter_class);          //pd_new reserves memory for the data space, initialises the variables that are internal to the object
                                                                //and returns a pointer to the data space

    x->i_count=f;                                               //variable value has to be initialize
    outlet_new(&x->x_obj, &s_float);                            //new outlet created. pointer and description of outlet-type.
                                                                //return a pointer to the new outlet and save this pointer in t_object-variable x_obj.ob_outlet

    return (void *)x;                                           //return a pointer to the instantiated data space
}

//declare the new class and its properties
void counter_setup(void) {                                      //
    counter_class = class_new(                                  //Generate a new instance of the class and return a pointer
        gensym("counter"),                                      //symbolic name of the class
        (t_newmethod)counter_new,                               //class constructor
        0,                                                      //destructor
        sizeof(t_counter),                                      //size of the data structure is passed so as to let Pd reserve and free enough memory 
        CLASS_DEFAULT,                                          //graphical rapresentation of the class object
        A_DEFFLOAT,                                             //the object needs one argument of the type t_floatarg 
        0);                                                     // 
  
    class_addbang(counter_class, counter_bang);                 //method space. add a method for "bang"-message to the class that is defined 
                                                                //in the first argument. The added method is defined in the second argument.
}
