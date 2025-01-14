#include "../tomb3/pch.h"
#include "lara1gun.h"
#include "../3dsystem/phd_math.h"
#include "control.h"
#include "items.h"
#include "effect2.h"
#include "objects.h"
#include "draw.h"
#include "gameflow.h"
#include "triboss.h"
#include "effects.h"
#include "larafire.h"
#include "../specific/smain.h"
#include "../3dsystem/3d_gen.h"
#include "../specific/game.h"
#include "collide.h"
#include "box.h"
#include "sound.h"

void ControlHarpoonBolt(short item_number)
{
	ITEM_INFO* item;
	ITEM_INFO* target;
	FLOOR_INFO* floor;
	short* bounds;
	long oldX, oldZ, c, s, nx, nz, nn, nn1, ox, oz, on, on1;
	short room_number, target_num, obj_num;

	item = &items[item_number];
	oldX = item->pos.x_pos;
	oldZ = item->pos.z_pos;
	item->pos.x_pos += (item->speed * phd_sin(item->pos.y_rot)) >> W2V_SHIFT;
	item->pos.y_pos += item->fallspeed;
	item->pos.z_pos += (item->speed * phd_cos(item->pos.y_rot)) >> W2V_SHIFT;
	room_number = item->room_number;
	floor = GetFloor(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, &room_number);
	item->floor = GetHeight(floor, item->pos.x_pos, item->pos.y_pos, item->pos.z_pos);

	if (item->room_number != room_number)
		ItemNewRoom(item_number, room_number);

	for (target_num = room[item->room_number].item_number; target_num != NO_ITEM; target_num = target->next_item)
	{
		target = &items[target_num];
		obj_num = target->object_number;

		if (target == lara_item || !target->collidable)
			continue;

		if (obj_num == UPV || obj_num != SMASH_WINDOW && obj_num != SMASH_OBJECT1 && obj_num != SMASH_OBJECT2 && obj_num != SMASH_OBJECT3 &&
			obj_num != CARCASS && obj_num != EXTRAFX6 && (target->status == ITEM_INVISIBLE || !objects[obj_num].collision))
			continue;

		bounds = GetBestFrame(target);

		if (item->pos.y_pos < target->pos.y_pos + bounds[2] || item->pos.y_pos > target->pos.y_pos + bounds[3])
			continue;

		s = phd_sin(target->pos.y_rot);
		c = phd_cos(target->pos.y_rot);

		nx = item->pos.x_pos - target->pos.x_pos;
		nz = item->pos.z_pos - target->pos.z_pos;
		nn = (c * nx - s * nz) >> W2V_SHIFT;

		ox = oldX - target->pos.x_pos;
		oz = oldZ - target->pos.z_pos;
		on = (c * ox - s * oz) >> W2V_SHIFT;

		nn1 = (s * nx + c * nz) >> W2V_SHIFT;
		on1 = (s * ox + c * oz) >> W2V_SHIFT;

		if (nn < bounds[0] && ox < bounds[0] || nn > bounds[1] && ox > bounds[1] ||
			nn1 < bounds[4] && on1 < bounds[4] || nn1 > bounds[5] && on1 > bounds[5])
			continue;

#ifdef RANDO_STUFF
		if (obj_num == SMASH_OBJECT1 && rando.levels[RANDOLEVEL].original_id != LV_CRASH ||
#else
		if (obj_num == SMASH_OBJECT1 && CurrentLevel != LV_CRASH ||
#endif
			obj_num == SMASH_WINDOW || obj_num == SMASH_OBJECT2 || obj_num == SMASH_OBJECT3)
			SmashWindow(target_num);
		else if (obj_num == CARCASS || obj_num == EXTRAFX6)
		{
			if (item->status != ITEM_ACTIVE)	//original bug: this doesn't work, need to check target instead of item
			{
				item->status = ITEM_ACTIVE;		//same here
				AddActiveItem(target_num);
			}
		}
		else if (obj_num != SMASH_OBJECT1)
		{
			if (objects[obj_num].intelligent)
			{
				if (obj_num == TRIBEBOSS)
				{
					if (TribeBossShieldOn)
						FindClosestShieldPoint(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, target);
					else
					{
						HitTarget(target, 0, weapons[LG_HARPOON].damage << item->item_flags[0]);
						savegame.ammo_hit++;
					}
				}
				else
				{
					if (obj_num != LON_BOSS)
						DoLotsOfBlood(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, 0, 0, item->room_number, 3);

					HitTarget(target, 0, weapons[LG_HARPOON].damage << item->item_flags[0]);
					savegame.ammo_hit++;
				}
			}

			KillItem(item_number);
			return;
		}
	}

	c = GetCeiling(floor, item->pos.x_pos, item->pos.y_pos, item->pos.z_pos);

	if (item->pos.y_pos >= item->floor || item->pos.y_pos <= c)
	{
		if (item->hit_points == 256)
			item->current_anim_state = item->pos.x_rot;

		if (item->hit_points >= 192)
		{
			item->pos.x_rot = item->current_anim_state + (((item->hit_points - 192) * ((rcossin_tbl[512 * (item->hit_points & 7)] >> 1) - 1024)) >> 6);
			item->hit_points--;
		}

		item->hit_points--;

		if (!item->hit_points)
		{
			KillItem(item_number);
			return;
		}

		item->fallspeed = 0;
		item->speed = 0;
	}
	else
	{
		item->pos.z_rot += 6370;

		if (room[item->room_number].flags & ROOM_UNDERWATER)
		{
			if (!(wibble & 0xF))
				CreateBubble(&item->pos, item->room_number, 2, 8);

			TriggerRocketSmoke(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, 64);
			item->fallspeed = short((-128 * phd_sin(item->pos.x_rot)) >> W2V_SHIFT);
			item->speed = short((128 * phd_cos(item->pos.x_rot)) >> W2V_SHIFT);
		}
		else
		{
			item->pos.x_rot -= 182;

			if (item->pos.x_rot < -0x4000)
				item->pos.x_rot = -0x4000;

			item->fallspeed = short((-256 * phd_sin(item->pos.x_rot)) >> W2V_SHIFT);
			item->speed = short((256 * phd_cos(item->pos.x_rot)) >> W2V_SHIFT);
		}
	}

	room_number = item->room_number;
	floor = GetFloor(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, &room_number);
	GetHeight(floor, item->pos.x_pos, item->pos.y_pos, item->pos.z_pos);

	if (item->room_number != room_number)
		ItemNewRoom(item_number, room_number);
}

void ControlRocket(short item_number)
{
	ITEM_INFO* item;
	ITEM_INFO* target;
	FLOOR_INFO* floor;
	PHD_VECTOR oldPos;
	PHD_VECTOR pos;
	PHD_VECTOR vel;
	PHD_3DPOS bPos;
	short* bounds;
	long abovewater, speed, c, rad, exploded, r, s, nx, nz, nn, ox, oz, on, nn1, on1;
	short oldRoom, room_number, target_num, obj_num;

	item = &items[item_number];
	oldPos.x = item->pos.x_pos;
	oldPos.y = item->pos.y_pos;
	oldPos.z = item->pos.z_pos;
	oldRoom = item->room_number;

	if (room[item->room_number].flags & ROOM_UNDERWATER)
	{
		if (item->speed <= 128)
		{
			item->speed += (item->speed >> 2) + 4;

			if (item->speed > 128)
				item->speed = 128;
		}
		else
			item->speed -= item->speed >> 2;

		abovewater = 0;
		item->pos.z_rot += 182 * ((item->speed >> 3) + 3);
	}
	else
	{
		if (item->speed < 512)
			item->speed += (item->speed >> 2) + 4;

		abovewater = 1;
		item->pos.z_rot += 182 * ((item->speed >> 2) + 7);
	}

	item->shade = -0x3DF0;

	phd_PushUnitMatrix();
	phd_mxptr[M03] = 0;
	phd_mxptr[M13] = 0;
	phd_mxptr[M23] = 0;
	phd_RotYXZ(item->pos.y_rot, item->pos.x_rot, item->pos.z_rot);

	phd_PushMatrix();
	phd_TranslateRel(0, 0, -128);
	pos.x = phd_mxptr[M03] >> W2V_SHIFT;
	pos.y = phd_mxptr[M13] >> W2V_SHIFT;
	pos.z = phd_mxptr[M23] >> W2V_SHIFT;
	phd_PopMatrix();

	phd_TranslateRel(0, 0, -1536 - (GetRandomControl() & 0x1FF));
	vel.x = phd_mxptr[M03] >> W2V_SHIFT;
	vel.y = phd_mxptr[M13] >> W2V_SHIFT;
	vel.z = phd_mxptr[M23] >> W2V_SHIFT;
	phd_PopMatrix();

	if (wibble & 4)
		TriggerRocketFlame(pos.x, pos.y, pos.z, vel.x - pos.x, vel.y - pos.y, vel.z - pos.z, item_number);

	TriggerRocketSmoke(item->pos.x_pos + pos.x, item->pos.y_pos + pos.y, item->pos.z_pos + pos.z, -1);

	if (room[item->room_number].flags & ROOM_UNDERWATER)
	{
		bPos.x_pos = item->pos.x_pos + pos.x;
		bPos.y_pos = item->pos.y_pos + pos.y;
		bPos.z_pos = item->pos.z_pos + pos.z;
		CreateBubble(&bPos, item->room_number, 4, 8);
	}

	vel.x = pos.x + (GetRandomControl() & 0xF) + item->pos.x_pos - 8;
	vel.y = pos.y + (GetRandomControl() & 0xF) + item->pos.y_pos - 8;
	vel.z = pos.z + (GetRandomControl() & 0xF) + item->pos.z_pos - 8;
	TriggerDynamic(vel.x, vel.y, vel.z, 14, (GetRandomControl() & 3) + 28, (GetRandomControl() & 7) + 16, GetRandomControl() & 7);

	speed = (item->speed * phd_cos(item->pos.x_rot)) >> W2V_SHIFT;
	item->pos.x_pos += (speed * phd_sin(item->pos.y_rot)) >> W2V_SHIFT;
	item->pos.y_pos -= (item->speed * phd_sin(item->pos.x_rot)) >> W2V_SHIFT;
	item->pos.z_pos += (speed * phd_cos(item->pos.y_rot)) >> W2V_SHIFT;
	
	room_number = item->room_number;
	floor = GetFloor(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, &room_number);
	item->floor = GetHeight(floor, item->pos.x_pos, item->pos.y_pos, item->pos.z_pos);

	if (item->room_number != room_number)
		ItemNewRoom(item_number, room_number);

	c = GetCeiling(floor, item->pos.x_pos, item->pos.y_pos, item->pos.z_pos);

	if (item->pos.y_pos >= item->floor || item->pos.y_pos <= c)
	{
		exploded = 1;
		rad = WALL_SIZE << item->item_flags[0];	//blast radius is 1 square, 2 for biggun rockets
	}
	else
	{
		exploded = 0;
		rad = 0;
	}

	if (room[item->room_number].flags & ROOM_UNDERWATER && abovewater)
	{
		splash_setup.x = item->pos.x_pos;
		splash_setup.y = room[item->room_number].maxceiling;
		splash_setup.z = item->pos.z_pos;
		splash_setup.InnerXZoff = 16;
		splash_setup.InnerXZsize = 12;
		splash_setup.InnerYsize = -96;
		splash_setup.InnerXZvel = 160;
		splash_setup.InnerYvel = -0x4000;
		splash_setup.InnerGravity = 128;
		splash_setup.InnerFriction = 7;
		splash_setup.MiddleXZoff = 24;
		splash_setup.MiddleXZsize = 24;
		splash_setup.MiddleYsize = -64;
		splash_setup.MiddleXZvel = 224;
		splash_setup.MiddleYvel = -0x2000;
		splash_setup.MiddleGravity = 72;
		splash_setup.MiddleFriction = 8;
		splash_setup.OuterXZoff = 32;
		splash_setup.OuterXZsize = 32;
		splash_setup.OuterXZvel = 272;
		splash_setup.OuterFriction = 9;
		SetupSplash(&splash_setup);
	}

	GetNearByRooms(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, rad << 2, rad << 2, item->room_number);

	for (r = 0; r < number_draw_rooms; r++)
	{
		for (target_num = room[draw_rooms[r]].item_number; target_num != NO_ITEM; target_num = target->next_item)
		{
			target = &items[target_num];
			obj_num = target->object_number;

			if (target == lara_item || !target->collidable)
				continue;

			if (obj_num != SMASH_WINDOW && obj_num != SMASH_OBJECT1 && obj_num != SMASH_OBJECT2 &&
				obj_num != SMASH_OBJECT3 && obj_num != CARCASS && obj_num != EXTRAFX6 && obj_num != FLYING_MUTANT_EMITTER &&
				(!objects[obj_num].intelligent || target->status == ITEM_INVISIBLE || !objects[obj_num].collision))
				continue;

			bounds = GetBoundsAccurate(target);

			if (item->pos.y_pos + rad < target->pos.y_pos + bounds[2] || item->pos.y_pos - rad > target->pos.y_pos + bounds[3])
				continue;

			s = phd_sin(target->pos.y_rot);
			c = phd_cos(target->pos.y_rot);
			
			nx = item->pos.x_pos - target->pos.x_pos;
			nz = item->pos.z_pos - target->pos.z_pos;
			nn = (c * nx - s * nz) >> W2V_SHIFT;

			ox = oldPos.x - target->pos.x_pos;
			oz = oldPos.z - target->pos.z_pos;
			on = (c * ox - s * oz) >> W2V_SHIFT;

			nn1 = (s * nx + c * nz) >> W2V_SHIFT;
			on1 = (s * ox + c * oz) >> W2V_SHIFT;

			if (nn + rad < bounds[0] && ox + rad < bounds[0] || nn - rad > bounds[1] && ox - rad > bounds[1] ||
				nn1 + rad < bounds[4] && on1 + rad < bounds[4] || nn1 - rad > bounds[5] && on1 - rad > bounds[5])
				continue;

#ifdef RANDO_STUFF
			if (obj_num == SMASH_OBJECT1 && rando.levels[RANDOLEVEL].original_id == LV_CRASH)
#else
			if (obj_num == SMASH_OBJECT1 && CurrentLevel == LV_CRASH)
#endif
			{
				if (item->item_flags[0] == 1)
					SmashWindow(target_num);

				if (!exploded)
				{
					exploded = 1;
					rad = WALL_SIZE << item->item_flags[0];
					r = -1;
					break;
				}
			}
#ifdef RANDO_STUFF
			else if (obj_num == SMASH_OBJECT1 && rando.levels[RANDOLEVEL].original_id != LV_CRASH ||
#else
			else if (obj_num == SMASH_OBJECT1 && CurrentLevel != LV_CRASH ||
#endif
				obj_num == SMASH_WINDOW || obj_num == SMASH_OBJECT2 || obj_num == SMASH_OBJECT3)
				SmashWindow(target_num);
			else if (obj_num == CARCASS || obj_num == EXTRAFX6)
			{
				if (item->status != ITEM_ACTIVE)	//original bug: this doesn't work, need to check target instead of item
				{
					item->status = ITEM_ACTIVE;		//same here
					AddActiveItem(target_num);
				}
			}
			else if (target->object_number != SMASH_OBJECT1)
			{
				if (obj_num == TRIBEBOSS && TribeBossShieldOn)
					FindClosestShieldPoint(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, target);
				else
					HitTarget(target, 0, 30 << item->item_flags[0]);

				savegame.ammo_hit++;

				if (target->hit_points <= 0)
				{
					savegame.kills++;

					if (obj_num != TRIBEBOSS && obj_num != WILLARD_BOSS && obj_num != TONY && obj_num != LON_BOSS &&
						obj_num != ELECTRIC_CLEANER && obj_num != WHALE && obj_num != FLYING_MUTANT_EMITTER)
					{
						if (obj_num == LIZARD_MAN && lizard_man_active)
							lizard_man_active = 0;

						item_after_projectile = target->next_active;
						CreatureDie(target_num, 1);
					}
				}

				if (!exploded)
				{
					exploded = 1;
					rad = WALL_SIZE << item->item_flags[0];
					r = -1;
					break;
				}
			}
		}
	}

	if (exploded)
	{
		if (room[oldRoom].flags & ROOM_UNDERWATER)
		{
			item->pos.x_pos = oldPos.x;
			item->pos.y_pos = oldPos.y;
			item->pos.z_pos = oldPos.z;
			ItemNewRoom(item_number, oldRoom);
			TriggerUnderwaterExplosion(item);
		}
		else
		{
			TriggerExplosionSparks(oldPos.x, oldPos.y, oldPos.z, 3, -2, 0, item->room_number);

			for (int i = 0; i < 2; i++)
				TriggerExplosionSparks(oldPos.x, oldPos.y, oldPos.z, 3, -1, 0, item->room_number);
		}

		AlertNearbyGuards(item);
		SoundEffect(SFX_EXPLOSION1, &item->pos, 0x1800000 | SFX_SETPITCH);
		SoundEffect(SFX_EXPLOSION2, &item->pos, SFX_DEFAULT);
		KillItem(item_number);
	}
}

void ControlGrenade(short item_number)
{
	ITEM_INFO* item;
	ITEM_INFO* target;
	PHD_VECTOR oldPos;
	PHD_VECTOR pos;
	PHD_VECTOR vel;
	short* bounds;
	long abovewater, exploded, rad, r, s, c, nx, nz, nn, ox, oz, on, nn1, on1;
	short yrot, target_num, obj_num;

	item = &items[item_number];
	oldPos.x = item->pos.x_pos;
	oldPos.y = item->pos.y_pos;
	oldPos.z = item->pos.z_pos;
	item->shade = -0x3DF0;

	if (room[item->room_number].flags & ROOM_UNDERWATER)
	{
		abovewater = 0;
		item->fallspeed += (5 - item->fallspeed) >> 1;
		item->speed -= item->speed >> 2;

		if (item->speed)
		{
			item->pos.z_rot += 182 * ((item->speed >> 4) + 3);

			if (item->required_anim_state)
				item->pos.y_rot += 182 * ((item->speed >> 2) + 3);
			else
				item->pos.x_rot += 182 * ((item->speed >> 2) + 3);
		}
	}
	else
	{
		item->fallspeed += 3;
		abovewater = 1;

		if (item->speed)
		{
			item->pos.z_rot += 182 * ((item->speed >> 2) + 7);

			if (item->required_anim_state)
				item->pos.y_rot += 182 * ((item->speed >> 1) + 7);
			else
				item->pos.x_rot += 182 * ((item->speed >> 1) + 7);
		}
	}

	phd_PushUnitMatrix();
	phd_mxptr[M03] = 0;
	phd_mxptr[M13] = 0;
	phd_mxptr[M23] = 0;
	phd_RotYXZ(item->pos.y_rot, item->pos.x_rot, item->pos.z_rot);
	phd_TranslateRel(0, 0, -64);
	pos.x = phd_mxptr[M03] >> W2V_SHIFT;
	pos.y = phd_mxptr[M13] >> W2V_SHIFT;
	pos.z = phd_mxptr[M23] >> W2V_SHIFT;
	phd_PopMatrix();

	if (item->speed && abovewater)
		TriggerRocketSmoke(item->pos.x_pos + pos.x, item->pos.y_pos + pos.y, item->pos.z_pos + pos.z, -1);

	vel.x = (item->speed * phd_sin(item->goal_anim_state)) >> W2V_SHIFT;
	vel.y = item->fallspeed;
	vel.z = (item->speed * phd_cos(item->goal_anim_state)) >> W2V_SHIFT;
	item->pos.x_pos += vel.x;
	item->pos.y_pos += vel.y;
	item->pos.z_pos += vel.z;

	yrot = item->pos.y_rot;
	item->pos.y_rot = item->goal_anim_state;
	DoProperDetection(item_number, oldPos.x, oldPos.y, oldPos.z, vel.x, vel.y, vel.z);
	item->goal_anim_state = item->pos.y_rot;
	item->pos.y_rot = yrot;

	if (room[item->room_number].flags & ROOM_UNDERWATER && abovewater)
	{
		splash_setup.x = item->pos.x_pos;
		splash_setup.y = room[item->room_number].maxceiling;
		splash_setup.z = item->pos.z_pos;
		splash_setup.InnerXZoff = 16;
		splash_setup.InnerXZsize = 12;
		splash_setup.InnerYsize = -96;
		splash_setup.InnerXZvel = 160;
		splash_setup.InnerGravity = 128;
		splash_setup.InnerYvel = -2048 - (item->fallspeed << 5);
		splash_setup.InnerFriction = 7;
		splash_setup.MiddleXZoff = 24;
		splash_setup.MiddleXZsize = 24;
		splash_setup.MiddleYsize = -64;
		splash_setup.MiddleXZvel = 224;
		splash_setup.MiddleGravity = 72;
		splash_setup.MiddleYvel = -1024 - (item->fallspeed << 4);
		splash_setup.MiddleFriction = 8;
		splash_setup.OuterXZoff = 32;
		splash_setup.OuterXZsize = 32;
		splash_setup.OuterXZvel = 272;
		splash_setup.OuterFriction = 9;
		SetupSplash(&splash_setup);
	}

	exploded = 0;
	rad = 0;

	if (item->hit_points)
	{
		item->hit_points--;

		if (!item->hit_points)
		{
			rad = WALL_SIZE;
			exploded = 1;
		}
	}

	GetNearByRooms(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, rad << 2, rad << 2, item->room_number);

	for (r = 0; r < number_draw_rooms; r++)
	{
		for (target_num = room[draw_rooms[r]].item_number; target_num != NO_ITEM; target_num = target->next_item)
		{
			target = &items[target_num];
			obj_num = target->object_number;

			if (target == lara_item || !target->collidable)
				continue;

			if (obj_num != SMASH_WINDOW && obj_num != SMASH_OBJECT1 && obj_num != SMASH_OBJECT2 &&
				obj_num != SMASH_OBJECT3 && obj_num != CARCASS && obj_num != EXTRAFX6 && obj_num != FLYING_MUTANT_EMITTER &&
				(!objects[obj_num].intelligent || target->status == ITEM_INVISIBLE || !objects[obj_num].collision))
				continue;

			bounds = GetBestFrame(target);

			if (item->pos.y_pos + rad < target->pos.y_pos + bounds[2] || item->pos.y_pos - rad > target->pos.y_pos + bounds[3])
				continue;
			
			s = phd_sin(target->pos.y_rot);
			c = phd_cos(target->pos.y_rot);

			nx = item->pos.x_pos - target->pos.x_pos;
			nz = item->pos.z_pos - target->pos.z_pos;
			nn = (c * nx - s * nz) >> W2V_SHIFT;

			ox = oldPos.x - target->pos.x_pos;
			oz = oldPos.z - target->pos.z_pos;
			on = (c * ox - s * oz) >> W2V_SHIFT;

			nn1 = (s * nx + c * nz) >> W2V_SHIFT;
			on1 = (s * ox + c * oz) >> W2V_SHIFT;

			if (nn + rad < bounds[0] && ox + rad < bounds[0] || nn - rad > bounds[1] && ox - rad > bounds[1] ||
				nn1 + rad < bounds[4] && on1 + rad < bounds[4] || nn1 - rad > bounds[5] && on1 - rad > bounds[5])
				continue;

#ifdef RANDO_STUFF
			if (obj_num == SMASH_OBJECT1 && rando.levels[RANDOLEVEL].original_id != LV_CRASH)
#else
			if (obj_num == SMASH_OBJECT1 && CurrentLevel != LV_CRASH)
#endif
				SmashWindow(target_num);
			else if (obj_num == SMASH_WINDOW || obj_num == SMASH_OBJECT2 || obj_num == SMASH_OBJECT3)
				SmashWindow(target_num);
			else if (obj_num == CARCASS || obj_num == EXTRAFX6)
			{
				if (item->status != ITEM_ACTIVE)	//original bug: this doesn't work, need to check target instead of item
				{
					item->status = ITEM_ACTIVE;		//same here
					AddActiveItem(target_num);
				}
			}
			else if (target->object_number != SMASH_OBJECT1)
			{
				if (obj_num == TRIBEBOSS && TribeBossShieldOn)
					FindClosestShieldPoint(item->pos.x_pos, item->pos.y_pos, item->pos.z_pos, target);
				else
					HitTarget(target, 0, 20);

				savegame.ammo_hit++;

				if (target->hit_points <= 0)
				{
					savegame.kills++;

					if (obj_num != TRIBEBOSS && obj_num != WHALE && obj_num != WILLARD_BOSS && obj_num != TONY &&
						obj_num != LON_BOSS && obj_num != ELECTRIC_CLEANER && obj_num != FLYING_MUTANT_EMITTER)
					{
						if (obj_num == LIZARD_MAN && lizard_man_active)
							lizard_man_active = 0;
						item_after_projectile = target->next_active;
						CreatureDie(target_num, 1);
					}
				}

				if (!exploded)
				{
					exploded = 1;
					rad = WALL_SIZE;
					r = -1;
				}
			}
		}
	}

	if (exploded)
	{
		if (room[item->room_number].flags & ROOM_UNDERWATER)
			TriggerUnderwaterExplosion(item);
		else
		{
			TriggerExplosionSparks(oldPos.x, oldPos.y, oldPos.z, 3, -2, 0, item->room_number);

			for (int i = 0; i < 2; i++)
				TriggerExplosionSparks(oldPos.x, oldPos.y, oldPos.z, 3, -1, 0, item->room_number);
		}

		AlertNearbyGuards(item);
		SoundEffect(SFX_EXPLOSION1, &item->pos, 0x1800000 | SFX_SETPITCH);
		SoundEffect(SFX_EXPLOSION2, &item->pos, SFX_DEFAULT);
		KillItem(item_number);
	}
}

void draw_shotgun_meshes(long weapon_type)
{
	lara.back_gun = 0;
	lara.mesh_ptrs[HAND_R] = meshes[objects[WeaponObject(weapon_type)].mesh_index + HAND_R];
}

void undraw_shotgun_meshes(long weapon_type)
{
	lara.back_gun = (short)WeaponObject(weapon_type);
	lara.mesh_ptrs[HAND_R] = meshes[objects[LARA].mesh_index + HAND_R];
}

void inject_lara1gun(bool replace)
{
	INJECT(0x004459B0, ControlHarpoonBolt, inject_rando ? 1 : replace);
	INJECT(0x004461E0, ControlRocket, inject_rando ? 1 : replace);
	INJECT(0x00446DD0, ControlGrenade, inject_rando ? 1 : replace);
	INJECT(0x00445250, draw_shotgun_meshes, replace);
	INJECT(0x00445290, undraw_shotgun_meshes, replace);
}
