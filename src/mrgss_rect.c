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
 * @param x
 * @param y
 * @param w
 * @param h
 */
static void set_instance_variables(mrb_state *mrb, mrb_value self, mrb_int x, mrb_int y, mrb_int w, mrb_int h) {
    mrgss_iv_create(mrb, self, "@x", mrb_fixnum_value(x));
    mrgss_iv_create(mrb, self, "@y", mrb_fixnum_value(y));
    mrgss_iv_create(mrb, self, "@w", mrb_fixnum_value(w));
    mrgss_iv_create(mrb, self, "@h", mrb_fixnum_value(h));
}
/**
 * Rect Object Constructor
 * @param mrb 
 * @param self
 * @return 
 */
static mrb_value
initialize(mrb_state *mrb, mrb_value self) {
    mrb_int x, y, w, h, param_count;
    param_count = mrb_get_args(mrb, "|iiii", &x, &y, &w, &h);
    w = w < 0 ? 0 : w;
    h = h < 0 ? 0 :h;
    switch (param_count) {
        case 2:
            set_instance_variables(mrb, self, x, x, y, y);
            break;
        case 4:
            set_instance_variables(mrb, self, x, y, w, h);
            break;
        default:
            mrgss_raise(mrb, E_ARGUMENT_ERROR, "Wrong number of arguments");
            return mrb_nil_value();
            break;
    }
    return self;
}
/**
 * x getter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value get_x(mrb_state *mrb, mrb_value self) {
    return mrgss_iv_get(mrb, self, "@x");
}
/**
 * y getter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value get_y(mrb_state *mrb, mrb_value self) {
    return mrgss_iv_get(mrb, self, "@y");
}
/**
 * width getter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value get_w(mrb_state *mrb, mrb_value self) {
    return mrgss_iv_get(mrb, self, "@w");
}
/**
 * height getter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value get_h(mrb_state *mrb, mrb_value self) {
    return mrgss_iv_get(mrb, self, "@h");
}
/**
 * x setter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value set_x(mrb_state *mrb, mrb_value self) {
    mrb_int val;
    mrb_get_args(mrb, "i", &val);
    mrgss_iv_create(mrb, self, "@x", mrb_fixnum_value(val));
    return self;
}
/**
 * y setter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value set_y(mrb_state *mrb, mrb_value self) {
    mrb_int val;
    mrb_get_args(mrb, "i", &val);
    mrgss_iv_create(mrb, self, "@y", mrb_fixnum_value(val));
    return self;
}
/**
 * width setter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value set_w(mrb_state *mrb, mrb_value self) {
    mrb_int val;
    mrb_get_args(mrb, "i", &val);
    val = val < 0 ? 0 : val;
    mrgss_iv_create(mrb, self, "@w", mrb_fixnum_value(val));
    return self;
}
/**
 * height setter
 * @param mrb
 * @param self
 * @return 
 */
static mrb_value set_h(mrb_state *mrb, mrb_value self) {
    mrb_int val;
    mrb_get_args(mrb, "i", &val);
    val = val < 0 ? 0 : val;
    mrgss_iv_create(mrb, self, "@h", mrb_fixnum_value(val));
    return self;
}
/**
 * Type initializer
 * @param mrb
 */
void mrgss_init_rect(mrb_state *mrb) {
    struct RClass *type = mrgss_create_class(mrb, "Rect");
    mrb_define_method(mrb, type, "initialize", initialize, MRB_ARGS_OPT(4));
    mrb_define_method(mrb, type, "x", get_x, MRB_ARGS_NONE());
    mrb_define_method(mrb, type, "y", get_y, MRB_ARGS_NONE());
    mrb_define_method(mrb, type, "w", get_w, MRB_ARGS_NONE());
    mrb_define_method(mrb, type, "h", get_h, MRB_ARGS_NONE());
    mrb_define_method(mrb, type, "x=", set_x, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, type, "y=", set_y, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, type, "w=", set_w, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, type, "h=", set_h, MRB_ARGS_REQ(1));
    mrb_define_alias(mrb, type, "width", "w");
    mrb_define_alias(mrb, type, "height", "h");
    mrb_define_alias(mrb, type, "width=", "w=");
    mrb_define_alias(mrb, type, "height=", "h=");
}
