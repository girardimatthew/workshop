#include "m_pd.h"

// new class
static t_class *helloworld_class;                                               //pointer to the new class

//define data space of the class
typedef struct _helloworld {                                                    //struct of type _helloworld
    t_object x_obj;                                                             //necessary element. store internal object properties 
} t_helloworld;                                                                 //struct name

//add method. manipulate the data with
//if a message is sent to an instance of our class, a method is called 
//methods have no return argument and are therefore of type void
void helloworld_bang(t_helloworld *x) {                                         //argument of type t_helloworld. enable to manipualte the data space
    post("Hello World !!");                                                     //send a string to the standard error
}

//the constructor
void *helloworld_new(void) {                                                    //no object arguments
    t_helloworld *x = (t_helloworld *)pd_new(helloworld_class);                 //pd_new reserves memory for the data space, initialises the variables that are
                                                                                //internal to the object and returns a pointer to the data space.
    return (void *)x;                                                           //returns a pointer to the instantiated data space.
}

//delcare the new class and its properties
void helloworld_setup(void) {
    helloworld_class = class_new(                                               //Generate a new instance of the class and return a pointer 
        gensym("helloworld"),                                                   //symbolic name of the class
        (t_newmethod)helloworld_new,                                            //class-constructor
        0,                                                                      //destructor. reserve and free memory for the statis data space
        sizeof(t_helloworld),                                                   //size of the data structure is passed so as to let Pd reserve and free enough memory
        CLASS_DEFAULT,                                                          //graphical rappresentation of the class objects 
        0);                                                                     //list of object-arguments
    
    class_addbang(helloworld_class, helloworld_bang);                           //method space. add a method for "bang"-message to the class that is defined 
                                                                                //in the first argument. The added method is defined in the second argument.
}
