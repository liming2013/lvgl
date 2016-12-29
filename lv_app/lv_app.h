/**
 * @file lv_app.h
 *
 */

#ifndef LV_APP_H
#define LV_APP_H

/*********************
 *      INCLUDES
 *********************/
#include "lvgl/lvgl.h"

#if LV_APP_ENABLE != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum
{
	LV_APP_MODE_NONE 	 = 0x0000,
	LV_APP_MODE_NOT_LIST = 0x0001,		/*Do not list the application*/
	LV_APP_MODE_NO_SC_TITLE = 0x0002,	/*No short cut title*/
}lv_app_mode_t;

typedef enum
{
	LV_APP_COM_TYPE_STR,    /*String data to process*/
	LV_APP_COM_TYPE_BIN,    /*Binary data as 'int32_t' array*/
	LV_APP_COM_TYPE_LOG,    /*String about an event to log*/
	LV_APP_COM_TYPE_NOTICE,   /*String to display to the user as a notification*/
    LV_APP_COM_TYPE_TRIG,   /*A trigger to do some specific action (data is ignored)*/
}lv_app_com_type_t;

struct __LV_APP_DSC_T;

typedef struct
{
	const struct __LV_APP_DSC_T * dsc;
	char * name;
	lv_obj_t * sc;
	lv_obj_t * sc_title;
	lv_obj_t * win;
	void * app_data;
	void * sc_data;
	void * win_data;
}lv_app_inst_t;

typedef struct __LV_APP_DSC_T
{
	const char * name;
	lv_app_mode_t mode;
	void (*app_run)(lv_app_inst_t *, const char *, void *);
	void (*app_close) (lv_app_inst_t *);
	void (*com_rec) (lv_app_inst_t *, lv_app_inst_t *, lv_app_com_type_t, const void *, uint32_t);
	void (*sc_open) (lv_app_inst_t *, lv_obj_t *);
	void (*sc_close) (lv_app_inst_t *);
	void (*win_open) (lv_app_inst_t *, lv_obj_t *);
	void (*win_close) (lv_app_inst_t *);
	uint16_t app_data_size;
	uint16_t sc_data_size;
	uint16_t win_data_size;
}lv_app_dsc_t;

typedef struct {
	lv_rects_t  menu_style;
	lv_btns_t  menu_btn_style;
	lv_labels_t  menu_btn_label_style;
	lv_imgs_t  menu_btn_img_style;
	lv_lists_t app_list_style;
	lv_pages_t  sc_page_style;
    lv_labels_t win_txt_style;
	lv_wins_t  win_style;
	lv_btns_t  sc_style;
    lv_btns_t  sc_send_style;
    lv_btns_t  sc_rec_style;
	lv_labels_t sc_title_style;
    lv_labels_t sc_txt_style;


	opa_t menu_opa;
	opa_t menu_btn_opa;
	opa_t sc_opa;

	cord_t menu_h;
	cord_t app_list_w;
	cord_t app_list_h;
	cord_t sc_title_margin;
}lv_app_style_t;


/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_app_init(void);
lv_app_inst_t * lv_app_run(const lv_app_dsc_t * app_dsc, const char * cstr, void * conf);
void lv_app_close(lv_app_inst_t * app);
uint16_t lv_app_com_send(lv_app_inst_t * app_send, lv_app_com_type_t type , const void * data, uint32_t len);
lv_obj_t * lv_app_sc_open(lv_app_inst_t * app);
void lv_app_sc_close(lv_app_inst_t * app);
lv_obj_t * lv_app_win_open(lv_app_inst_t * app);
void lv_app_win_close(lv_app_inst_t * app);
lv_obj_t * lv_app_win_get_from_obj(lv_obj_t * obj);
const lv_app_dsc_t * lv_app_dsc_get(const char * name);

void lv_app_con_set(lv_app_inst_t * sender, lv_app_inst_t * receiver);
lv_app_style_t * lv_app_style_get(void);
void lv_app_rename(lv_app_inst_t * app, const char * name);
void lv_app_refr_style(void);

lv_app_inst_t * lv_app_get_next(lv_app_inst_t * prev, lv_app_dsc_t * dsc);

const lv_app_dsc_t * lv_app_example_init(void);

/**********************
 *      MACROS
 **********************/

#endif /*LV_APP_ENABLE != 0*/

#endif /*LV_APP_H*/
