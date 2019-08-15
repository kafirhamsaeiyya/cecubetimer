/*
 *--------------------------------------
 * Program Name: CUBE
 * Author: De2290 aka kafirhamsaeiyya
 * License: GNU GPLv3
 * Description: A simple cube timer for the TI84 Plus CE
 *--------------------------------------
*/

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers (recommended) */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphx.h>
#include "gfx/logo_gfx.h"
#define FONT_HEIGHT 8
/* Put your function prototypes here */
void dispSprite_Centered(gfx_sprite_t *sprite);
void print_Time(float elasped);
void print_TextCentered(char *text);
/* Put all your globals here */

void main(void) {
	char *cubewelcome = "Cube Timer";
	real_t cubeFinish_time;
	list_t *times_List;
	gfx_Begin();
	gfx_SetPalette(logo_gfx_pal, sizeof_logo_gfx_pal, 0);
	gfx_SetTextFGColor(255);
	gfx_FillScreen(0);
	gfx_SetTextTransparentColor(1);
	gfx_SetTextBGColor(0);
	print_TextCentered(cubewelcome);
	dispSprite_Centered(rubikcube);
	print_Time(0.0f);
	timer_Control = TIMER1_DISABLE;
	timer_1_Counter = 0;
	while (!os_GetCSC());
	timer_Control = TIMER1_ENABLE | TIMER1_32K | TIMER1_UP;	
	do {
		float elapsed = (float)atomic_load_increasing_32(&timer_1_Counter) / 32768;
		print_Time(elapsed);
	       	cubeFinish_time = os_FloatToReal(elapsed);

	} while (!os_GetCSC());
	times_List = ti_MallocList(5);
	times_List->items[0] = cubeFinish_time;
	ti_SetVar(TI_REAL_LIST_TYPE, ti_L1, times_List);
	free(times_List);
	while (!os_GetCSC());


	
	gfx_End();

}

/* Put other functions here */
void dispSprite_Centered(gfx_sprite_t *sprite) {
	gfx_Sprite(sprite, (LCD_WIDTH - 60) / 2, (LCD_HEIGHT - 60) / 2);
}

void print_Time(float elapsed) {
	real_t elapsed_real;
	char str[10];
	elapsed_real = os_FloatToReal(elapsed <= 0.001f ? 0.0f : elapsed);
	os_RealToStr(str, &elapsed_real, 8, 1, 2);
	gfx_PrintStringXY(str, (LCD_WIDTH - gfx_GetStringWidth(str)) / 2, (LCD_HEIGHT - FONT_HEIGHT) / 2+60);

}

void print_TextCentered(char *text) {
	gfx_PrintStringXY(text, (LCD_WIDTH - gfx_GetStringWidth(text)) / 2, (LCD_HEIGHT - FONT_HEIGHT) / 2-60);
}
