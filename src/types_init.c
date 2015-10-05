#include <mruby.h>
#include <stdio.h>
#include <mrgss.h>
#include <mrgss/mrgss-types.h>

void
mrb_mrgss_types_gem_init(mrb_state* mrb) {
    mrgss_init_color(mrb);
    mrgss_init_rect(mrb);
}

void
mrb_mrgss_types_gem_final(mrb_state* mrb) {
    /* finalizer */
}

mrb_int clamp_to_byte(mrb_int value) {
    return (value > 255) ? (255) : (value < 0 ? 0 : value);
}

void mrgss_rect_get(mrb_state *mrb, mrb_value object, mrgss_rect *rect) {
    rect->x = mrb_int(mrb, mrgss_iv_get(mrb, object, "@x"));
    rect->y = mrb_int(mrb, mrgss_iv_get(mrb, object, "@y"));
    rect->w = mrb_int(mrb, mrgss_iv_get(mrb, object, "@w"));
    rect->h = mrb_int(mrb, mrgss_iv_get(mrb, object, "@h"));    
}

mrb_value mrgss_color_new(mrb_state *mrb, mrb_int r, mrb_int g, mrb_int b, mrb_int a){
    mrb_value args[4];
    args[0] = mrb_fixnum_value(r);
    args[1] = mrb_fixnum_value(g);
    args[2] = mrb_fixnum_value(b);
    args[3] = mrb_fixnum_value(a);
    return mrgss_obj_new(mrb, "Color", 4, args);
}
