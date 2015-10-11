#include <mruby.h>
#include <stdio.h>
#include <mrgss/mrgss_color.h>
#include <mrgss/mrgss_rect.h>

void
mrb_mrgss_types_gem_init(mrb_state* mrb) {
    mrgss_color_init(mrb);
    mrgss_rect_init(mrb);
}

void
mrb_mrgss_types_gem_final(mrb_state* mrb) {
    /* finalizer */
}
