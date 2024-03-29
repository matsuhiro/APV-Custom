
#ifdef PDFVIEW2_H__
#error PDFVIEW2_H__ can be included only once
#endif


#define PDFVIEW2_H__


#include "fitz.h"
#include "mupdf.h"

#define MAX_BOX_NAME 8

/**
 * Holds pdf info.
 */
typedef struct {
    int last_pageno;
	pdf_xref *xref;
	pdf_outline *outline;
    int fileno; /* used only when opening by file descriptor */
    pdf_page **pages; /* lazy-loaded pages */
    fz_glyph_cache *glyph_cache;
    char box[MAX_BOX_NAME + 1];
} pdf_t;




/*
 * Declarations
 */


pdf_t* create_pdf_t();
pdf_t* parse_pdf_file(const char *filename, int fileno);
pdf_t* get_pdf_from_this(JNIEnv *env, jobject this);
void get_size(JNIEnv *env, jobject size, int *width, int *height);
void save_size(JNIEnv *env, jobject size, int width, int height);
void fix_samples(unsigned char *bytes, unsigned int w, unsigned int h);
void rgb_to_alpha(unsigned char *bytes, unsigned int w, unsigned int h);
int get_page_size(pdf_t *pdf, int pageno, int *width, int *height);
void pdf_android_loghandler(const char *m);
jobject create_find_result(JNIEnv *env);
void set_find_result_page(JNIEnv *env, jobject findResult, int page);
void add_find_result_marker(JNIEnv *env, jobject findResult, int x0, int y0, int x1, int y1);
void add_find_result_to_list(JNIEnv *env, jobject *list, jobject find_result);
int convert_point_pdf_to_apv(pdf_t *pdf, int page, int *x, int *y);
int convert_box_pdf_to_apv(pdf_t *pdf, int page, fz_bbox *bbox);
int find_next(JNIEnv *env, jobject this, int direction);
pdf_page* get_page(pdf_t *pdf, int pageno);

