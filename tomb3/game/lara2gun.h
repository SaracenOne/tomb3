#pragma once
#include "../global/vars.h"

void inject_lara2gun(bool replace);

void draw_pistol_meshes(long weapon_type);
void undraw_pistol_mesh_right(long weapon_type);
void undraw_pistol_mesh_left(long weapon_type);
void ready_pistols(long weapon_type);
void set_arm_info(LARA_ARM* arm, int frame);
void draw_pistols(long weapon_type);
void undraw_pistols(long weapon_type);
void AnimatePistols(long weapon_type);
