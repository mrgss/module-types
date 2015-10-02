/* 
 * File:   mrgss-types.h
 * Author: manuel
 *
 * Created on 24 de septiembre de 2015, 19:05
 */

#ifndef MRGSS_TYPES_H
#define	MRGSS_TYPES_H

#include <mruby.h>

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct rect {
        mrb_int x, y, w, h;
    } mrgss_rect;


    void mrgss_init_color(mrb_state *mrb);
    void mrgss_init_rect(mrb_state *mrb);
    mrb_int clamp_to_byte(mrb_int value);
    mrb_value mrgss_color_new(mrb_state *mrb, mrb_int r, mrb_int g, mrb_int b, mrb_int a);
    void mrgss_rect_get(mrb_state *mrb, mrb_value object, mrgss_rect *rect);

#ifdef	__cplusplus
}
#endif

#endif	/* MRGSS_TYPES_H */

