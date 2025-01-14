#pragma once
#include "../global/vars.h"

void inject_laraswim(bool replace);

void LaraUnderWater(ITEM_INFO* item, COLL_INFO* coll);
void SwimTurn(ITEM_INFO* item);
void lara_as_swim(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_glide(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_tread(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_dive(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_uwdeath(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_waterroll(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_swim(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_glide(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_tread(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_dive(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_uwdeath(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_waterroll(ITEM_INFO* item, COLL_INFO* coll);

#define LaraSwimCollision	( (void(__cdecl*)(ITEM_INFO*, COLL_INFO*)) 0x0044EE60 )
#define LaraWaterCurrent	( (void(__cdecl*)(COLL_INFO*)) 0x0044F310 )
#define GetWaterDepth	( (long(__cdecl*)(long, long, long, short)) 0x0044F180 )
