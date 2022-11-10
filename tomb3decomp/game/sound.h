#pragma once
#include "../global/vars.h"

void inject_sound(bool replace);

void SOUND_Init();
void SOUND_Stop();
void SOUND_EndScene();

#define StopSoundEffect	( (void(__cdecl*)(long)) 0x00467D00 )
#define SoundEffect	( (long(__cdecl*)(long, PHD_3DPOS*, long)) 0x00467840 )

enum sound_effect_names
{
	SFX_LARA_FEET,
	SFX_LARA_CLIMB2,
	SFX_LARA_NO,
	SFX_LARA_SLIPPING,
	SFX_LARA_LAND,
	SFX_LARA_CLIMB1,
	SFX_LARA_DRAW,
	SFX_LARA_HOLSTER,
	SFX_LARA_FIRE,
	SFX_LARA_RELOAD,
	SFX_LARA_RICOCHET,
	SFX_LARA_FLARE_IGNITE,
	SFX_LARA_FLARE_BURN,
	SFX_FLARE_IGNITE_W,
	SFX_FLARE_BURN_W,
	SFX_LARA_HARPOON_FIRE,
	SFX_LARA_HARPOON_LOAD,
	SFX_LARA_WET_FEET,
	SFX_LARA_WADE,
	SFX_RUMBLE_LOOP,
	SFX_ICKET_BARRIER,
	SFX_CRICKET_LOOP,
	SFX_LARA_HARPOON_LOAD_WATER,
	SFX_LARA_HARPOON_FIRE_WATER,
	SFX_LARA_KNEES_SHUFFLE,
	SFX_PUSH_SWITCH,
	SFX_LARA_CLIMB3,
	SFX_LARA_BODYSL,
	SFX_LARA_SHIMMY,
	SFX_LARA_JUMP,
	SFX_LARA_FALL,
	SFX_LARA_INJURY,
	SFX_LARA_ROLL,
	SFX_LARA_SPLASH,
	SFX_LARA_GETOUT,
	SFX_LARA_SWIM,
	SFX_LARA_BREATH,
	SFX_LARA_BUBBLES,
	SFX_LARA_SWITCH,
	SFX_LARA_KEY,
	SFX_LARA_OBJECT,
	SFX_LARA_GENERAL_DEATH,
	SFX_LARA_KNEES_DEATH,
	SFX_LARA_UZI_FIRE,
	SFX_LARA_UZI_STOP,
	SFX_LARA_SHOTGUN,
	SFX_LARA_BLOCK_PUSH1,
	SFX_LARA_BLOCK_PUSH2,
	SFX_LARA_EMPTY,
	SFX_LARA_SHOTGUN_SHELL,
	SFX_LARA_BULLETHIT,
	SFX_LARA_BLKPULL,
	SFX_LARA_FLOATING,
	SFX_LARA_FALLDEATH,
	SFX_LARA_GRABHAND,
	SFX_LARA_GRABBODY,
	SFX_LARA_GRABFEET,
	SFX_LARA_SWITCHUP,
	SFX_METEOR,
	SFX_WATER_LOOP,
	SFX_UNDERWATER,
	SFX_UNDERWATER_SWITCH,
	SFX_LARA_PICKUP,
	SFX_BLOCK_SOUND,
	SFX_DOOR,
	SFX_HELICOPTER_LOOP,
	SFX_ROCK_FALL_CRUMBLE,
	SFX_ROCK_FALL_LAND,
	SFX_JET_FLY_BY,
	SFX_STALEGTITE,
	SFX_LARA_THUD,
	SFX_GENERIC_SWOOSH,
	SFX_OIL_SMG_FIRE,
	SFX_CITY_PORTCULLIS,
	SFX_SWINGING_FLAMES,
	SFX_SPINING_HOOKS,
	SFX_BLAST_CIRCLE,
	SFX_BAZOOKA_FIRE,
	SFX_HECKLER_KOCH_FIRE,
	SFX_WATERFALL_LOOP,
	SFX_CROC_ATTACK,
	SFX_CROC_DEATH,
	SFX_PORTCULLIS_UP,
	SFX_PORTCULLIS_DOWN,
	SFX_T_REX_ATTACK,
	SFX_BODY_SLAM,
	SFX_POWER_HUM_LOOP,
	SFX_T_REX_ROAR,
	SFX_T_REX_FOOTSTOMP,
	SFX_T_REX_SNIFF,
	SFX_UNUSED1,
	SFX_ARMY_SMG_FIRE,
	SFX_ARMY_SMG_DEATH,
	SFX_ARMY_SMG_FOOTSTEPS,
	SFX_WING_MUTE_ATTACK,
	SFX_WING_MUTE_DEATH,
	SFX_WING_MUTE_FLYING,
	SFX_RAT_ATTACK,
	SFX_RAT_DEATH,
	SFX_TIGER_ROAR,
	SFX_TIGER_BITE,
	SFX_TIGER_STRIKE,
	SFX_TIGER_DEATH,
	SFX_TIGER_GROWL,
	SFX_HECKLER_KOCH_STOP,
	SFX_EXPLOSION1,
	SFX_EXPLOSION2,
	SFX_EARTHQUAKE_LOOP,
	SFX_MENU_ROTATE,
	SFX_MENU_CHOOSE,
	SFX_MENU_GAMEBOY,
	SFX_MENU_SPININ,
	SFX_MENU_SPINOUT,
	SFX_MENU_STOPWATCH,
	SFX_MENU_GUNS,
	SFX_MENU_PASSPORT,
	SFX_MENU_MEDI,
	SFX_LARA_CLIMB_WALLS_NOISE,
	SFX_VERY_LIGHT_WATER,
	SFX_TARGET_HITS,
	SFX_TARGET_SMASH,
	SFX_DESSERT_EAGLE_FIRE,
	SFX_VAULT_DOORS,
	SFX_LARA_MINI_LOAD,
	SFX_LARA_MINI_LOCK,
	SFX_LARA_MINI_FIRE,
	SFX_GATE_OPENING,
	SFX_LARA_ELECTRIC_LOOP,
	SFX_LARA_ELECTRIC_CRACKLES,
	SFX_COMMANDER,
	SFX_SWITCH_COVER,
	SFX_CLEANER_FUSEBOX,
	SFX_CROW_CAW,
	SFX_CROW_WING_FLAP,
	SFX_CROW_DEATH,
	SFX_CROW_ATTACK,
	SFX_SOFT_WIND_LOOP,
	SFX_SWAT_SMG_FIRE,
	SFX_LIZARD_MAN_ATTACK_1,
	SFX_LIZARD_MAN_ATTACK_2,
	SFX_LIZARD_MAN_DEATH,
	SFX_LIZARD_MAN_CLIMB,
	SFX_LIZARD_MAN_FIRE,
	SFX_GENERIC_BODY_SLAM,
	SFX_HECKER_KOCH_OVERLAY,
	SFX_LARA_SPIKE_DEATH,
	SFX_LARA_DEATH3,
	SFX_ROLLING_BALL,
	SFX_TUBE_LOOP,
	SFX_RUMBLE_NEXTDOOR,
	SFX_LOOP_FOR_SMALL_FIRES,
	SFX_DART_GUN,
	SFX_QUAD_START,
	SFX_QUAD_IDLE,
	SFX_QUAD_ACCELERATE,
	SFX_QUAD_MOVE,
	SFX_QUAD_STOP,
	SFX_BATS_1,
	SFX_LOOP_FOR_GAS_HISS,
	SFX_LAUNCHER_1,
	SFX_LAUNCHER_2,
	SFX_TRAPDOOR_OPEN,
	SFX_TRAPDOOR_CLOSE,
	SFX_RESERVOIR_FLUSH,
	SFX_MACAQUE_SATND_WAIT,
	SFX_MACAQUE_ATTACK_LOW,
	SFX_MACAQUE_ATTACK_JUMP,
	SFX_MACAQUE_JUMP,
	SFX_MACAQUE_DEATH,
	SFX_SEAL_MUTE_FIRE,
	SFX_SEAL_MUTE_BREATH_IN,
	SFX_SEAL_MUTE_FIRE_2,
	SFX_SEAL_MUTE_FOOT,
	SFX_SEAL_MUTE_DEATH,
	SFX_SEAL_MUTE_BRUSH_TAIL,
	SFX_SEAL_MUTE_HIT_FLR,
	SFX_DOG_ATTACK_1,
	SFX_DOG_AWARE,
	SFX_DOG_FOOT_1,
	SFX_DOG_JUMP,
	SFX_DOG_GROWL,
	SFX_DOG_DEATH,
	SFX_VULTURE_WING_FLAP,
	SFX_VULTURE_ATTACK,
	SFX_VULTURE_DIE,
	SFX_VULTURE_GLIDE,
	SFX_SCUBA_DIVER_FLIPPER,
	SFX_SCUBA_DIVER_ARM,
	SFX_SCUBA_DIVER_BREATH_W,
	SFX_SCUBA_DIVER_BREATH_S,
	SFX_LONDON_MERCENARY_DEATH,
	SFX_CLEANER_LOOP,
	SFX_SCUBA_DIVER_DEATH,
	SFX_SCUBA_DIVER_DIVING,
	SFX_BOAT_START,
	SFX_BOAT_IDLE,
	SFX_BOAT_ACCELERATE,
	SFX_BOAT_MOVING,
	SFX_BOAT_STOP,
	SFX_BOAT_SLOW_DOWN,
	SFX_JET_ROOFS,
	SFX_QUAD_SIDE_IMPACT,
	SFX_QUAD_FRONT_IMPACT,
	SFX_QUAD_LAND,
	SFX_FLAME_THROWER_LOOP,
	SFX_RUMMBLE,
	SFX_DRILL_BIT_1,
	SFX_VERY_SMALL_WINCH,
	SFX_ALARM_1,
	SFX_MINE_CART_TRACK_LOOP,
	SFX_MINE_CART_PULLY_LOOP,
	SFX_MINE_CART_CLUNK_START,
	SFX_SAVE_CRYSTAL,
	SFX_WOOD_GATE,
	SFX_METAL_SHUTTERS_SMASH,
	SFX_UNDERWATER_FAN_ON,
	SFX_UNDERWATER_FAN_STOP,
	SFX_SMALL_FAN_ON,
	SFX_SWINGING_BOX_BAG,
	SFX_MINE_CART_SREECH_BRAKE,
	SFX_SPANNER,
	SFX_SMALL_METAL_SHUTTERS,
	SFX_AREA51_SWINGER_START,
	SFX_AREA51_SWINGER_STOP,
	SFX_AREA51_SWINGER_LOOP,
	SFX_SLIDE_DOOR_CLOSE_1,
	SFX_SLIDE_DOOR_CLOSE_2,
	SFX_OILDRUM_ROLL,
	SFX_OILDRUM_HIT,
	SFX_SIDE_BLADE_SWING,
	SFX_SIDE_BLADE_BACK,
	SFX_SKEL_TRAP_PART_1,
	SFX_SKEL_TRAP_PART_2,
	SFX_SMALL_FAN,
	SFX_TONY_BOSS_STONE_DEATH,
	SFX_TONY_BOSS_NORMAL_DEATH,
	SFX_TONY_BOSS_LAUGH,
	SFX_LONDON_BOSS_SHOOTER,
	SFX_HARD_WIND_LOOP,
	SFX_COMPY_ATTACK,
	SFX_COMPY_JUMP,
	SFX_COMPY_WAIT,
	SFX_COMPY_DIE,
	SFX_COMPY_RUN_WALK,
	SFX_BLOWPIPE_NATIVE_FEET,
	SFX_BLOWPIPE_NATIVE_ATTACK,
	SFX_BLOWPIPE_NATIVE_DEATH,
	SFX_BLOWPIPE_NATIVE_BLOW,
	SFX_BLOWPIPE_NATIVE_SWOOSH,
	SFX_SHIVA_WALK_MURMA,
	SFX_RAPTOR_FEET,
	SFX_RAPTOR_ATTACK_1,
	SFX_RAPTOR_ATTACK_2,
	SFX_RAPTOR_ATTACK_3,
	SFX_RAPTOR_ROAR,
	SFX_RAPTOR_DIE_1,
	SFX_RAPTOR_DIE_2,
	SFX_HUGE_ROCKET_LOOP,
	SFX_SHIVA_SWORD_1,
	SFX_SHIVA_SWORD_2,
	SFX_SHIVA_DEATH,
	SFX_SHIVA_FOOTSTEP,
	SFX_SHIVA_LAUGH,
	SFX_SHIVA_HIT_GROUND,
	SFX_HYBRID_FOOT,
	SFX_HYBRID_HOOF,
	SFX_HYBRID_ATTACK,
	SFX_HYBRID_DEATH,
	SFX_HYBRID_SWOOSH,
	SFX_SMALL_SWITCH,
	SFX_CLAW_MUTE_FOOTSTEPS,
	SFX_CLAW_MUTE_ATTACK,
	SFX_CLAW_MUTE_DEATH,
	SFX_CLAW_MUTE_BODY_THUD,
	SFX_CLAW_MUTE_LAZER,
	SFX_CLAW_MUTE_SWOOSH,
	SFX_CLAW_MUTE_CLAW,
	SFX_HYBRID_BODY_SLAM,
	SFX_SMALL_DOOR_SUBWAY,
	SFX_DEATH_SLIDE_GRAB,
	SFX_DEATH_SLIDE_GO,
	SFX_DEATH_SLIDE_STOP,
	SFX_RADAR_BLIP,
	SFX_BOB_FEET,
	SFX_BOB_ATTACK,
	SFX_BOB_DEATH,
	SFX_BOB_CLIMB,
	SFX_BOB_GET_DOWN,
	SFX_FOOTSTEPS_MUD,
	SFX_FOOTSTEPS_ICE,
	SFX_FOOTSTEPS_GRAVEL,
	SFX_FOOTSTEPS_SAND_GRASS,
	SFX_FOOTSTEPS_WOOD,
	SFX_FOOTSTEPS_SNOW,
	SFX_FOOTSTEPS_METAL,
	SFX_LOOP_FOR_LONDON,
	SFX_1ST_LOOP_FOR_BIG_DRILL,
	SFX_SMALL_DOOR_SUBWAY_CLOSE,
	SFX_2ND_LOOP_FOR_BIG_DRILL,
	SFX_ENGLISH_HOY,
	SFX_AMERCAN_HOY,
	SFX_OIL_RED_SMG_DEATH,
	SFX_RADIO_LOOP,
	SFX_PUNK_ATTACK,
	SFX_PUNK_DEATH,
	SFX_SECURITY_GUARD_FIRE,
	SFX_SECURITY_GUARD_DEATH,
	SFX_LAZER_LOOP,
	SFX_WINSTON_BRUSH_OFF,
	SFX_WINSTON_CUPS,
	SFX_WINSTON_HU,
	SFX_WINSTON_BULLET_TRAY,
	SFX_WINSTON_FOOTSTEPS,
	SFX_WINSTON_TAKE_HIT,
	SFX_WINSTON_GET_UP,
	SFX_WINSTON_FART,
	SFX_WALL_BLADES,
	SFX_MACAQUE_CHATTER,
	SFX_MACAQUE_ROLL,
	SFX_WHALE_CALL,
	SFX_GENERATOR_LOOP,
	SFX_GENERATOR_SHITTING,
	SFX_GASMETER,
	SFX_LARA_TURN_WHEEL,
	SFX_COBRA_HISS,
	SFX_DART_SPITT,
	SFX_RATTLE_SNAKE,
	SFX_SWING_PUMP,
	SFX_SQEEK,
	SFX_DRIPS_REVERB,
	SFX_TONK,
	SFX_BOO_MUTE,
	SFX_VENDING_MACHINE_LOOP,
	SFX_VENDING_SPIT,
	SFX_DOORBELL,
	SFX_BURGLAR_ALARM,
	SFX_BOAT_SCRAPE,
	SFX_TICK_TOCK,
	SFX_WILARD_FOOT_STEPS,
	SFX_WILARD_ATTACK,
	SFX_WILARD_TAKE_HIT,
	SFX_WILARD_LEGS_SHUFFLE,
	SFX_WILARD_FIRE_CHARGE,
	SFX_WILARD_FIRE_SHOOT,
	SFX_WILARD_ODD_NOISE,
	SFX_WILARD_STAB,
	SFX_LITTLE_SUB_LOOP,
	SFX_LITTLE_SUB_START,
	SFX_LITTLE_SUB_STOP,
	SFX_LONDON_BOSS_DIE_PART_1,
	SFX_LONDON_BOSS_DIE_PART_2,
	SFX_LONDON_BOSS_FIRE,
	SFX_LONDON_BOSS_SUMMON,
	SFX_LONDON_BOSS_TAKE_HIT,
	SFX_LONDON_BOSS_VAULT,
	SFX_LONDON_BOSS_SUMMON_NOT,
	SFX_LONDON_BOSS_LAUGH,
	SFX_WATER_MILL,
	SFX_PLUG_WINCH,
	SFX_GIANT_METAL_WHEELS,
	SFX_TRIBOSS_ATTACK,
	SFX_TRIBOSS_TAKE_HIT,
	SFX_TRIBOSS_TURN_CHAIR,
	SFX_TRIBOSS_SHOOT,
	SFX_TRIBOSS_DEATH_VOCAL,
	SFX_TRIBOSS_CHAIR_2,
	SFX_TONY_BOSS_SHOOT_1,
	SFX_TONY_BOSS_SHOOT_2,
	SFX_TONY_BOSS_SHOOT_3,
	SFX_TONY_BOSS_ATTACK,

	NumSamples
};
