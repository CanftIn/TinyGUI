/*
	Copyright (c) 2018 by CanftIn
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#pragma once
#ifndef _TINY_GUI_H_
#define _TINY_GUI_H_

#define GUI_INPUT_MAX 16

typedef int gui_int;
typedef int gui_bool;
typedef unsigned char gui_char;
typedef float gui_float;
typedef void* gui_texture;
typedef unsigned char gui_byte;
typedef unsigned long gui_flag;
typedef unsigned long gui_size;

enum { gui_false, gui_true };
struct gui_color { gui_byte r, g, b, a; };
struct gui_texCoord { gui_float u, v; };
struct gui_vec2 { gui_float x, y; };
struct gui_rect { gui_float x, y, w, h; };


struct gui_vertex {
	struct gui_vec2 pos;
	struct gui_texCoord uv;
	struct gui_color color;
};

struct gui_draw_command {
	struct gui_vertex *vertexes;
	gui_int vertex_count;
	gui_int vertex_write;
	struct gui_rect clip_rect;
	gui_texture texture;
};

struct gui_draw_list {
	struct gui_draw_command *begin;
	struct gui_draw_command *end;
	gui_byte *memory;
	gui_size size;
	gui_size needed;
};


void gui_begin(struct gui_draw_list *list, gui_byte *memory, gui_size size);
gui_size gui_end(struct gui_draw_list *list);
const struct gui_draw_command *gui_next(const struct gui_draw_list *list,
	const struct gui_draw_command*);

void gui_input_begin(struct gui_input *in);
void gui_input_end(struct gui_input *in);

gui_int gui_button(struct gui_draw_list *list, const struct gui_input *in,
	struct gui_color bg, struct gui_color fg,
	gui_int x, gui_int y, gui_int w, gui_int h, gui_int pad,
	const char *str, gui_int len);
gui_int gui_toggle(struct gui_draw_list *list, const struct gui_input *in,
	struct gui_color bg, struct gui_color fg,
	gui_int x, gui_int y, gui_int w, gui_int h, gui_int pad,
	const char *str, gui_int len, gui_int active);
gui_int gui_slider(struct gui_draw_list *list, const struct gui_input *in,
	struct gui_color bg, struct gui_color fg,
	gui_int x, gui_int y, gui_int w, gui_int h, gui_int pad,
	gui_float min, gui_float v, gui_float max, gui_float step);
gui_int gui_progress(struct gui_draw_list *list, const struct gui_input *in,
	struct gui_color bg, struct gui_color fg,
	gui_int x, gui_int y, gui_int w, gui_int h, gui_int pad,
	gui_float cur, gui_float max, gui_bool modifyable);
gui_int gui_scroll(struct gui_draw_list *list, const struct gui_input *in,
	struct gui_color bg, struct gui_color fg,
	gui_int x, gui_int y, gui_int w, gui_int h,
	gui_int offset, gui_int dst);
gui_int gui_input(struct gui_draw_list *list,
	const struct gui_input *in, gui_char *buffer, gui_int *len,
	struct gui_color bg, struct gui_color fg,
	gui_int x, gui_int y, gui_int w, gui_int h, gui_int active);


#endif // !_TINY_GUI_H_
