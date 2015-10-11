#include <SDL/SDL.h>
#include <mruby.h>
#include <mruby/data.h>
#include <mruby/class.h>
#include <mrgss/mrgss.h>
#include <mrgss/mrgss_color.h>
/**
 * mruby instance data free
 */
static void
color_free (mrb_state *mrb, void *p)
{
  if (p)
    {
      free (p);
    }
}

/**
 * free function structure
 */
struct mrb_data_type const mrbal_color_data_type ={"Color", color_free};

/**
 *  Color mruby Constructor
 */
static mrb_value
initialize (mrb_state* mrb, mrb_value self)
{
  mrb_int r, g, b, a;
  mrb_int count;
  SDL_Color* color;
  DATA_TYPE (self) = &mrbal_color_data_type;
  DATA_PTR (self) = NULL;
  count = mrb_get_args (mrb, "iii|i", &r, &g, &b, &a);
  color = mrb_malloc (mrb, sizeof (SDL_Color));
  color->r = r;
  color->g = g;
  color->b = b;
  if (count < 4)
    {
      color->a = 0;
    }
  else
    {
      color->a = a;
    }
  DATA_PTR (self) = color;
  return self;
}

/**
 * Accessor Color x
 */
static mrb_value
get_r (mrb_state* mrb, mrb_value self)
{
  SDL_Color* color;
  color = DATA_PTR (self);
  return mrb_fixnum_value (color->r);
}

/**
 * Modifier Color r
 */
static mrb_value
set_r (mrb_state* mrb, mrb_value self)
{
  SDL_Color* color;
  mrb_int r;
  mrb_get_args (mrb, "i", &r);
  color = DATA_PTR (self);
  color->r = r;
  return mrb_fixnum_value (r);
}

/**
 * Accessor Color g
 */
static mrb_value
get_g (mrb_state* mrb, mrb_value self)
{
  SDL_Color* color;
  color = DATA_PTR (self);
  return mrb_fixnum_value (color->g);
}

/**
 * Modifier Color g
 */
static mrb_value
set_g (mrb_state* mrb, mrb_value self)
{
  SDL_Color* color;
  mrb_int g;
  mrb_get_args (mrb, "i", &g);
  color = DATA_PTR (self);
  color->g = g;
  return mrb_fixnum_value (g);
}

/**
 * Accessor Color b
 */
static mrb_value
get_b (mrb_state* mrb, mrb_value self)
{
  SDL_Color* color;
  color = DATA_PTR (self);
  return mrb_fixnum_value (color->b);
}

/**
 * Modifier Color b
 */
static mrb_value
set_b (mrb_state* mrb, mrb_value self)
{
  SDL_Color* color;
  mrb_int b;
  mrb_get_args (mrb, "i", &b);
  color = DATA_PTR (self);
  color->b = b;
  return mrb_fixnum_value (b);
}

/**
 * Accessor Color a
 */
static mrb_value
get_a (mrb_state* mrb, mrb_value self)
{
  SDL_Color* color;
  color = DATA_PTR (self);
  return mrb_fixnum_value (color->a);
}

/**
 * Modifier Color a
 */
static mrb_value
set_a (mrb_state* mrb, mrb_value self)
{
  SDL_Color* color;
  mrb_int a;
  mrb_get_args (mrb, "i", &a);
  color = DATA_PTR (self);
  color->a = a;
  return mrb_fixnum_value (a);
}

/**
 * Initialize mruby class
 */
void mrgss_color_init (mrb_state *mrb)
{
  struct RClass *color = mrb_define_class_under (mrb, mrgss_module(),"Color",mrb->object_class);
  mrb_define_method (mrb, color, "initialize", initialize, MRB_ARGS_REQ (3) | MRB_ARGS_OPT (1));
  mrb_define_method (mrb, color, "r", get_r, MRB_ARGS_NONE ());
  mrb_define_method (mrb, color, "r=", set_r, MRB_ARGS_REQ (1));
  mrb_define_method (mrb, color, "g", get_g, MRB_ARGS_NONE ());
  mrb_define_method (mrb, color, "g=", set_g, MRB_ARGS_REQ (1));
  mrb_define_method (mrb, color, "b", get_b, MRB_ARGS_NONE ());
  mrb_define_method (mrb, color, "b=", set_b, MRB_ARGS_REQ (1));
  mrb_define_method (mrb, color, "a", get_a, MRB_ARGS_NONE ());
  mrb_define_method (mrb, color, "a=", set_a, MRB_ARGS_REQ (1));
  MRB_SET_INSTANCE_TT (color, MRB_TT_DATA);
}