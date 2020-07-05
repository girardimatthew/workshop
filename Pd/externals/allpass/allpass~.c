
//--------------------------------------------------------------------------------
//  allpass~ object for Pure Data 
//
//  allpass~.c
//  
//  Description: a Simple allpass filter
//  
//  Author: Matteo Girardi May 2016
//--------------------------------------------------------------------------------

//---------------------------- NO POINTERS VERSION ----------------------------
//------------------------------------------------------------------------------
// headers
//------------------------------------------------------------------------------

// main header for pd 
#include "m_pd.h"
// math standard library
#include <math.h>

#define MAXLEN 1024

//------------------------------------------------------------------------------
// allpass_tilde_class - pointer to this object's definition
//------------------------------------------------------------------------------
static t_class *allpass_tilde_class;

//------------------------------------------------------------------------------
// _allpass_tilde - data structure holding this object's data
//------------------------------------------------------------------------------ 
typedef struct _allpass_tilde {
    t_object x_obj;
    t_float x_f;
    float m_g;
    float m_delay;
    float m_buff_x[MAXLEN];
    float m_buff_y[MAXLEN];
    int m_pibuf;
    int m_pobuf;
} t_allpass_tilde;

//----------------------------------------------------------------------------
// function prototypes
//----------------------------------------------------------------------------
t_int *allpass_tilde_perform(t_int *w);
void *allpass_tilde_new(t_symbol *s, short argc, t_atom *argv);
void allpass_tilde_dsp(t_allpass_tilde *x, t_signal **sp);
//void allpass_tilde_free(t_allpass_tilde *x);
void allpass_tilde_setup(void);


//------------------------------------------------------------------------------
// allpass_tilde_perform - the signal processing function of this object
//------------------------------------------------------------------------------
t_int *allpass_tilde_perform(t_int *w) {
    t_allpass_tilde *x = (t_allpass_tilde *)(w[1]);
    t_float *in = (t_float *)(w[2]);
    t_float *out = (t_float *)(w[3]);
    int i, n = (int)(w[4]);

    float *buff_x = x->m_buff_x;
    float *buff_y = x->m_buff_y;
    int pibuf = x->m_pibuf;
    int pobuf = x->m_pobuf;
    
    
    for (i = 0; i < n; i++)
    {
        buff_x[pibuf]  = in[i];
        out[i] = -x->m_g * in[i] + buff_x[pobuf] + x->m_g * buff_y[pobuf];
        buff_y[pibuf] = out[i];
        if (++pibuf >= MAXLEN)
            pibuf = 0;
        if (++pobuf >= MAXLEN)
            pobuf = 0;
    }
    x->m_pibuf = pibuf;
    x->m_pobuf = pobuf;
    
    return (w + 5);
}

//------------------------------------------------------------------------------
// allpass_tilde_dsp - installs this object's dsp function in pd's callback list
//------------------------------------------------------------------------------
void allpass_tilde_dsp(t_allpass_tilde *x, t_signal **sp) {
    dsp_add(allpass_tilde_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}

//------------------------------------------------------------------------------
// allpass_tilde_new - instantiates a copy of this object in pd. (aka Constructor)
//------------------------------------------------------------------------------
void *allpass_tilde_new(t_symbol *s, short argc, t_atom *argv) {
	
    int i;
    float g = 0; 
    float delay = 0;
    t_allpass_tilde *x = (t_allpass_tilde *)pd_new(allpass_tilde_class);
    outlet_new(&x->x_obj, gensym("signal"));

    x->m_pibuf = 0;
    for (i = 0; i < MAXLEN; i++) {
        x->m_buff_x[i] = x->m_buff_y[i] = 0;
    }

    if (argc >= 2) {
        g = atom_getfloatarg(1, argc, argv);
    }
    if (argc >= 1) {
        delay = atom_getfloatarg(0, argc, argv);
    }
    x->m_g = g;
    x->m_delay = delay * sys_getsr() / 1000; // ms to # of samples
    if (x->m_delay >= MAXLEN) 
        x->m_delay = MAXLEN -1;
    if (x->m_delay < 0)
        x->m_delay = 0;

    x->m_pobuf = x->m_pibuf - x->m_delay;
    while (x->m_pobuf < 0) {
        x->m_pobuf += MAXLEN;
    }
    post("Delay: %f in_index: %d out_index: %d", x->m_delay, x->m_pibuf, x->m_pobuf);

    return x;
}

//------------------------------------------------------------------------------
// allpass_tilde_free -- what to do when removing an object from a patch window.
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// allpass_tilde_setup - describes the attributes of this object to pd so 
// it may be properly instantiated
// (must always be named with _tilde replacing ~ in the object name)
//------------------------------------------------------------------------------
void allpass_tilde_setup(void) {

    // creates an instance of this object and describes it to pd
    allpass_tilde_class = class_new( gensym("allpass~"), (t_newmethod)allpass_tilde_new, 0, 
                            sizeof(t_allpass_tilde), CLASS_DEFAULT, A_GIMME, 0);

    //Macro. convert float input into signals.
    CLASS_MAINSIGNALIN(allpass_tilde_class, t_allpass_tilde, x_f);                                

    // installs allpass_tilde_dsp so that it will be called when dsp is turned on
    class_addmethod(allpass_tilde_class, (t_method)allpass_tilde_dsp, gensym("dsp"), A_CANT, 0);
}
