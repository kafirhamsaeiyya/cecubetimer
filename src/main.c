/*
 *--------------------------------------
 * Program Name:
 * Author:
 * License:
 * Description:
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
void dispText(char *text);
/* Put all your globals here */

void main(void) {
       	char *time = "00.00";
	gfx_Begin();
	gfx_SetPalette(logo_gfx_pal, sizeof_logo_gfx_pal, 0);
	gfx_SetTextFGColor(255);
	gfx_FillScreen(0);
	gfx_SetTextTransparentColor(0);
	gfx_SetTextBGColor(0);
	dispSprite_Centered(rubikcube);
	dispText(time);
	while (!os_GetCSC());
	gfx_End();

}

/* Put other functions here */
void dispSprite_Centered(gfx_sprite_t *sprite) {
	gfx_Sprite(sprite, (LCD_WIDTH - 60) / 2, (LCD_HEIGHT - 60) / 2);
}

void dispText(char *text) {
	gfx_PrintStringXY(text, (LCD_WIDTH - gfx_GetStringWidth(text)) / 2, (LCD_HEIGHT - FONT_HEIGHT) / 2+60);
}
