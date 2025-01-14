#pragma once
#include "../global/vars.h"

void inject_traps(bool replace);

void LaraBurn();
void LavaBurn(ITEM_INFO* item);
void SpikeControl(short item_number);
void PropellerControl(short item_number);
void SideFlameDetection(FX_INFO* fx, long length);
void FlameControl(short fx_number);
