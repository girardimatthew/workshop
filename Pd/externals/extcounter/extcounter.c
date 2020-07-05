//extended counter 
//reset the counter to an initial value
//set upper and lower boundaries 
//control the step-width

//header file
#include "m_pd.h"

//new class 
static t_class *extcounter_class;

//data space for the class
typedef struct _extcounter {
    t_object x_obj;
    t_int i_count;                      //stores the counter-value
    t_float step;                       //step width
    t_int i_down, i_up;                 //upper and lower boundaries
    t_outlet *f_out, *b_out;            //pointers for two outlets 
} t_extcounter;

void extcounter_bang(t_extcounter *x) {
    t_float f=x->i_count;
    t_int step = x->step;
    x->i_count+=step;
    
    if(x->i_down-x->i_up) {
        if((step>0) && (x->i_count > x->i_up)) {
            x->i_count = x->i_down;
            outlet_bang(x->b_out);
        } else if (x->i_count < x->i_down) {
            x->i_count = x->i_up;
            outlet_bang(x->b_out);
        }
    }

    outlet_float(x->f_out, f);
}

//reset method 
void extcounter_reset(t_extcounter *x) {
    x->i_count = x->i_down;
}

//set method
void extcounter_set(t_extcounter *x, t_floatarg f) {
    x->i_count = f;
}

//bound method 
void extcounter_bound(t_extcounter *x, t_floatarg f1, t_floatarg f2) {
    x->i_down = (f1<f2)?f1:f2;
    x->i_up = (f1>f2)?f1:f2;
}

//construction of inlets and outlets
void *extcounter_new(t_symbol *s, int argc, t_atom *argv) {
    t_extcounter *x = (t_extcounter *)pd_new(extcounter_class);
    t_float f1=0, f2=0;
    
    x->step=1;
    switch(argc) {
        default:
        case 3:
            x->step=atom_getfloat(argv+2);
        case 2:
            f2=atom_getfloat(argv+1);
        case 1:
            f1=atom_getfloat(argv);
            break;
        case 0:
            break;
    }
    if(argc<2)f2=f1;
    
    x->i_down = (f1<f2)?f1:f2;
    x->i_up = (f1>f2)?f1:f2;

    x->i_count=x->i_down;

    inlet_new(&x->x_obj, &x->x_obj.ob_pd,
        gensym("list"),
        gensym("bound"));
    floatinlet_new(&x->x_obj, &x->step);

    x->f_out = outlet_new(&x->x_obj, &s_float);
    x->b_out = outlet_new(&x->x_obj, &s_bang);

    return (void *)x;
}

//declaration of the new class and its properties
void extcounter_setup(void) {
    extcounter_class = class_new(gensym("extcounter"),
        (t_newmethod)extcounter_new,
        0, sizeof(t_extcounter),
        CLASS_DEFAULT, 
        A_GIMME, 0); //dynamic number of arguments to be passed at the instantiation of the object
    
    //add a method 
    class_addbang(extcounter_class, extcounter_bang);

    class_addmethod(extcounter_class,    //the class
        (t_method)extcounter_reset,      //the method added to the class
        gensym("reset"),                //symbolic selector associated with the method.
        0);                             //And list of atoms that follows the selector 

    class_addmethod(extcounter_class,
        (t_method)extcounter_set,
        gensym("set"),
        A_DEFFLOAT,                     //numerical value
        0);
    
    class_addmethod(extcounter_class,
        (t_method)extcounter_bound,
        gensym("bound"),
        A_DEFFLOAT,
        A_DEFFLOAT,
        0);

    class_sethelpsymbol(extcounter_class, gensym("help-extcounter"));
}


