#include <mruby.h>
#include <mruby/class.h>
#include <mruby/variable.h>
#include <mruby/value.h>
#include <mrgss.h>
#include <mrgss/mrgss-types.h>

/**
 * Set instance variables from constructor
 * @param mrb
 * @param self
 * @param r
 * @param g
 * @param b
 * @param a
 */
static void set_instance_variables(mrb_state *mrb, mrb_value self, mrb_int r, mrb_int g, mrb_int b, mrb_int a) {
    mrgss_iv_create(mrb, self, "@r", mrb_fixnum_value(r));
    mrgss_iv_create(mrb, self, "@g", mrb_fixnum_value(g));
    mrgss_iv_create(mrb, self, "@b", mrb_fixnum_value(b));
    mrgss_iv_create(mrb, self, "@a", mrb_fixnum_value(a));
}
/**
 * Color Object Constructor
 * @param mrb 
 * @param self
 * @return 
 */
static mrb_value
initialize(mrb_state *mrb, mrb_value self) {
    mrb_int r, g, b, a, param_count;
    param_count = mrb_get_args(mrb, "|iiii", &r, &g, &b, &a);
    r = clamp_to_byte(r);
    g = clamp_to_byte(g);
    b = clamp_to_byte(b);
    a = clamp_to_byte(a);
    switch (param_count) {
        case 0:
            set_instance_variables(mrb, self, 0, 0, 0, 255);
            break;
        case 3:
            set_instance_variables(mrb, self, r, g, b, 255);
            break;
        case 4:
            set_instance_variables(mrb, self, r, g, b, a);
            break;
        default:
            mrgss_raise(mrb, E_ARGUMENT_ERROR, "Wrong number of arguments");
            return mrb_nil_value();
            break;
    }
    return self;
}
/**
 * red getter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value get_r(mrb_state *mrb, mrb_value self) {
    return mrgss_iv_get(mrb, self, "@r");
}
/**
 * green getter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value get_g(mrb_state *mrb, mrb_value self) {
    return mrgss_iv_get(mrb, self, "@g");
}
/**
 * blue getter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value get_b(mrb_state *mrb, mrb_value self) {
    return mrgss_iv_get(mrb, self, "@b");
}
/**
 * alpha getter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value get_a(mrb_state *mrb, mrb_value self) {
    return mrgss_iv_get(mrb, self, "@a");
}
/**
 * red setter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value set_r(mrb_state *mrb, mrb_value self) {
    mrb_int val;
    mrb_get_args(mrb, "i", &val);
    val = clamp_to_byte(val);
    mrgss_iv_create(mrb, self, "@r", mrb_fixnum_value(val));
    return self;
}
/**
 * green setter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value set_g(mrb_state *mrb, mrb_value self) {
    mrb_int val;
    mrb_get_args(mrb, "i", &val);
    val = clamp_to_byte(val);
    mrgss_iv_create(mrb, self, "@g", mrb_fixnum_value(val));
    return self;
}
/**
 * blue setter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value set_b(mrb_state *mrb, mrb_value self) {
    mrb_int val;
    mrb_get_args(mrb, "i", &val);
    val = clamp_to_byte(val);
    mrgss_iv_create(mrb, self, "@b", mrb_fixnum_value(val));
    return self;
}
/**
 * alpha setter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value set_a(mrb_state *mrb, mrb_value self) {
    mrb_int val;
    mrb_get_args(mrb, "i", &val);
    val = clamp_to_byte(val);
    mrgss_iv_create(mrb, self, "@a", mrb_fixnum_value(val));
    return self;
}
/**
 * Type initializer
 * @param mrb
 */
void mrgss_init_color(mrb_state *mrb) {
    struct RClass *type = mrgss_create_class(mrb, "Color");
    mrb_define_method(mrb, type, "initialize", initialize, MRB_ARGS_OPT(4));
    mrb_define_method(mrb, type, "r", get_r, MRB_ARGS_NONE());
    mrb_define_method(mrb, type, "g", get_g, MRB_ARGS_NONE());
    mrb_define_method(mrb, type, "b", get_b, MRB_ARGS_NONE());
    mrb_define_method(mrb, type, "a", get_a, MRB_ARGS_NONE());
    mrb_define_method(mrb, type, "r=", set_r, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, type, "g=", set_g, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, type, "b=", set_b, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, type, "a=", set_a, MRB_ARGS_REQ(1));
    mrb_define_alias(mrb, type, "red", "r");
    mrb_define_alias(mrb, type, "green", "g");
    mrb_define_alias(mrb, type, "blue", "b");
    mrb_define_alias(mrb, type, "alpha", "a");
    mrb_define_alias(mrb, type, "red=", "r=");
    mrb_define_alias(mrb, type, "green=", "g=");
    mrb_define_alias(mrb, type, "blue=", "b=");
    mrb_define_alias(mrb, type, "alpha=", "a=");
}
