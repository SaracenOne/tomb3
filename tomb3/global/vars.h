#pragma once
#include "types.h"
#include "math_tbls.h"

#define VAR_(address, type)			(*(type*)(address))
#define ARRAY_(address, type, length)	(*(type(*)length)(address))

/*vars*/
#define lara_item	VAR_(0x006D62A4, ITEM_INFO*)
#define LaraOnPad	VAR_(0x006E2A14, uchar)
#define trigger_index	VAR_(0x006E29A8, short*)
#define lara	VAR_(0x006D61A0, LARA_INFO)
#define anims	VAR_(0x006E2074, ANIM_STRUCT*)
#define commands	VAR_(0x006E2208, short*)
#define changes	VAR_(0x006E287C, CHANGE_STRUCT*)
#define ranges	VAR_(0x006E2204, RANGE_STRUCT*)
#define input	VAR_(0x0069FDF0, long)
#define inputDB	VAR_(0x00626444, long)
#define room	VAR_(0x006E2890, ROOM_INFO*)
#define camera	VAR_(0x006E3040, CAMERA_INFO)
#define height_type	VAR_(0x006E2A24, long)
#define DashTimer	VAR_(0x006D62A0, short)
#define wibble	VAR_(0x006261A8, long)
#define items	VAR_(0x006E2A1C, ITEM_INFO*)
#define gameflow	VAR_(0x006D77C0, GAMEFLOW_INFO)
#define cheat_hit_points	VAR_(0x006D6182, short)
#define savegame	VAR_(0x006D2280, SAVEGAME_INFO)
#define meshes	VAR_(0x006E1434, short**)
#define ExposureMeter	VAR_(0x006D6180, short)
#define mycoll	VAR_(0x004C7448, COLL_INFO*)
#define CurrentLevel	VAR_(0x00633F50, long)
#define DemoPlay	VAR_(0x00625F78, long)
#define assault_timer_display	VAR_(0x006261BC, long)
#define QuadbikeLapTimeDisplayTimer	VAR_(0x006261D4, long)
#define assault_penalty_display_timer	VAR_(0x006261C8, long)
#define assault_timer_active	VAR_(0x006261C0, long)
#define assault_target_penalties	VAR_(0x006D8760, long)
#define assault_penalties	VAR_(0x006261C4, long)
#define assault_targets	VAR_(0x006D8758, long)
#define QuadbikeLapTime	VAR_(0x006261D0, long)
#define GlobalAlpha	VAR_(0x00625DF0, long)
#define bBlueEffect	VAR_(0x005BAB00, bool)
#define water_effect	VAR_(0x005D7AF8, long)
#define shade_effect	VAR_(0x005D7AFC, long)
#define wet	VAR_(0x006A1B60, long)
#define VidSizeLocked	VAR_(0x006302B4, long)
#define BarsWidth	VAR_(0x004C805C, long)
#define DumpX	VAR_(0x004CD8FC, short)
#define DumpY	VAR_(0x004CD8FE, short)
#define DumpWidth	VAR_(0x004CD900, short)
#define DumpHeight	VAR_(0x004CD902, short)
#define screen_sizer	VAR_(0x004C8040, double)
#define game_sizer	VAR_(0x004C8048, double)
#define GtFullScreenClearNeeded	VAR_(0x006A1B58, char)
#define health_bar_timer	VAR_(0x006266C8, long)
#define PoisonFlag	VAR_(0x006D77A0, char)
#define ammotext	VAR_(0x006263F8, TEXTSTRING*)
#define overlay_flag	VAR_(0x004C5834, long)
#define LpModeTS	VAR_(0x006263FC, TEXTSTRING*)
#define LnModeTSLife	VAR_(0x00626400, long)
#define last_target	VAR_(0x006E30D0, GAME_VECTOR)
#define ForcedFixedCamera	VAR_(0x006E30C0, GAME_VECTOR)
#define UseForcedFixedCamera	VAR_(0x006E30F0, char)
#define last_ideal	VAR_(0x006E30E0, GAME_VECTOR)
#define old_cam	VAR_(0x006E3100, OLD_CAMERA)
#define camerasnaps	VAR_(0x00625F3C, char)
#define static_lookcamp	VAR_(0x006E3150, GAME_VECTOR)
#define static_lookcamt	VAR_(0x006E3140, GAME_VECTOR)
#define old_target	VAR_(0x006E3128, PHD_VECTOR)
#define Option_Music_Volume	VAR_(0x004C70B0, short)
#define Option_SFX_Volume	VAR_(0x004C70AC, short)
#define chunky_flag	VAR_(0x006E2A10, long)
#define bones	VAR_(0x006E22E8, long*)
#define SmokeWindX	VAR_(0x006DB880, long)
#define SmokeWindZ	VAR_(0x006DB884, long)
#define outside	VAR_(0x006E1438, long)
#define CurrentRoom	VAR_(0x006E220C, long)
#define CurrentMesh	VAR_(0x006E2888, MESH_INFO*)
#define camera_underwater	VAR_(0x006E2894, long)
#define bound_start	VAR_(0x00626188, long)
#define bound_end	VAR_(0x0062618C, long)
#define mid_sort	VAR_(0x004D38D0, long)
#define number_draw_rooms	VAR_(0x006E143C, long)
#define outside_left	VAR_(0x006E2878, long)
#define outside_right	VAR_(0x006E28A0, long)
#define outside_top	VAR_(0x006E28BC, long)
#define outside_bottom	VAR_(0x006E2200, long)
#define number_dynamics	VAR_(0x006E22EC, long)
#define smcr	VAR_(0x0069FE90, long)
#define smcg	VAR_(0x0069FE8C, long)
#define smcb	VAR_(0x0069FE88, long)
#define SmokeCountL	VAR_(0x006DB888, long)
#define SmokeCountR	VAR_(0x006DB88C, long)
#define SmokeWeapon	VAR_(0x006DCA60, long)
#define App	VAR_(0x006CED80, WINAPP)
#define distanceFogValue	VAR_(0x006CED7C, long)
#define farz	VAR_(0x006CF250, long)
#define CarcassItem	VAR_(0x006E2FFC, short)
#define compy_scared_timer	VAR_(0x006E2A18, long)
#define compys_attack_lara	VAR_(0x006E28C8, long)
#define PirahnaHitWait	VAR_(0x006261D8, long)
#define level_items	VAR_(0x006266B4, long)
#define effects	VAR_(0x006D8750, FX_INFO*)
#define nPolyType	VAR_(0x00634008, long)
#define GammaOption	VAR_(0x004CD8F4, float)
#define level_complete	VAR_(0x00633F54, long)
#define FXType	VAR_(0x006E2FFA, short)
#define OnObject	VAR_(0x006E2960, long)
#define FootPrintNum	VAR_(0x006D79C0, long)
#define objbcnt	VAR_(0x006A1848, long)
#define GnGameMode	VAR_(0x00633F5C, long)
#define dpPrimitiveType	VAR_(0x00634114, D3DPRIMITIVETYPE)
#define BlackGouraudIndex	VAR_(0x004D38D4, long)
#define bFixSkyColour	VAR_(0x004D38DC, bool)
#define FinishLevelCheat	VAR_(0x006A1BD0, long)
#define dontFadePicture	VAR_(0x006A1B78, bool)
#define pictureFading	VAR_(0x006A1B7C, bool)
#define forceFadeDown	VAR_(0x006A1BB0, bool)
#define democount	VAR_(0x006E28C4, long)
#define demoptr	VAR_(0x006E28C0, ulong*)
#define next_item_active	VAR_(0x006D62AA, short)
#define next_item_free	VAR_(0x006D62A8, short)
#define next_fx_active	VAR_(0x006D8768, short)
#define next_fx_free	VAR_(0x006D875C, short)
#define body_bag	VAR_(0x006D62AC, short)
#define KillEverythingFlag	VAR_(0x006261AC, long)
#define baddie_slots	VAR_(0x006D58B0, CREATURE_INFO*)
#define non_lot_slots	VAR_(0x006D58B4, CREATURE_INFO*)
#define cdtrack	VAR_(0x004C51F8, short)
#define IsAtmospherePlaying	VAR_(0x006E2A28, char)
#define reset_flag	VAR_(0x00625F64, long)
#define noinput_count	VAR_(0x00625F60, long)
#define item_after_projectile	VAR_(0x006E2FF8, short)
#define SplashCount	VAR_(0x006261B4, long)
#define floor_data	VAR_(0x00633E24, short*)
#define tiltxoff	VAR_(0x006E2964, long)
#define tiltyoff	VAR_(0x006E2968, long)
#define nLoadedPictures	VAR_(0x006A1BAC, long)
#define T_numStrings	VAR_(0x006D0F00, short)
#define joy_fire	VAR_(0x0069FDF8, long)
#define joy_x	VAR_(0x0069FDFC, long)
#define joy_y	VAR_(0x0069FE00, long)
#define GtWindowClosed	VAR_(0x006CF268, bool)
#define splash_setup	VAR_(0x006DCA80, SPLASH_SETUP)
#define CurrentStartWake	VAR_(0x006266BC, uchar)
#define WakeShade	VAR_(0x006266C0, uchar)
#define SubCurrentStartWake	VAR_(0x006270E0, uchar)
#define SubWakeShade	VAR_(0x006270E4, uchar)
#define TribeBossShieldOn	VAR_(0x006D2260, char)
#define lizard_man_active	VAR_(0x006267D4, char)
#define CurrentAtmosphere	VAR_(0x006E2970, char)
#define number_rooms	VAR_(0x006E2880, short)
#define mesh_base	VAR_(0x00633E20, short*)
#define frames	VAR_(0x006E1430, short*)
#define number_cameras	VAR_(0x006267D0, long)
#define number_sound_effects	VAR_(0x006D8754, long)
#define sound_effects	VAR_(0x006D8764, OBJECT_VECTOR*)
#define number_boxes	VAR_(0x006E3190, long)
#define boxes	VAR_(0x006E318C, BOX_INFO*)
#define overlap	VAR_(0x006E3188, short*)
#define aranges	VAR_(0x006A1850, short*)
#define nTInfos	VAR_(0x00633F28, long)
#define cine	VAR_(0x006E300C, short*)
#define cine_frame	VAR_(0x006E3032, short)
#define cinematic_level	VAR_(0x00625F40, short)
#define cutscene_track	VAR_(0x004C5620, long)
#define actual_current_frame	VAR_(0x00625F44, long)
#define num_cine_frames	VAR_(0x006E300A, short)
#define cine_loaded	VAR_(0x006E3008, short)
#define cinematic_pos	VAR_(0x006E3020, PHD_3DPOS)
#define demo_loaded	VAR_(0x00625F7C, long)
#define sound_active	VAR_(0x006D1F24, long)
#define num_sample_infos	VAR_(0x006D1F20, long)
#define sample_infos	VAR_(0x006D2224, SAMPLE_INFO*)
#define cd_drive	VAR_(0x00633F38, char)
#define Inventory_Mode	VAR_(0x004C70A4, long)
#define passport_text1	VAR_(0x006A01B8, TEXTSTRING*)
#define GF_picfilenames	VAR_(0x006D7880, char**)
#define GF_LoadingPic	VAR_(0x004C561C, short)
#define GF_Playing_Story	VAR_(0x00626204, char)
#define GF_NoFloor	VAR_(0x006261F0, short)
#define GF_DeadlyWater	VAR_(0x006261EC, short)
#define GF_Kill2Complete	VAR_(0x006261FC, char)
#define GF_ScriptVersion	VAR_(0x006261E0, long)
#define GF_Level_Names	VAR_(0x006D78A4, char**)
#define GF_levelnames_buffer	VAR_(0x006D788C, char*)
#define GF_picfilenames_buffer	VAR_(0x006D786C, char*)
#define GF_titlefilenames	VAR_(0x006D7928, char**)
#define GF_titlefilenames_buffer	VAR_(0x006D792C, char*)
#define GF_fmvfilenames	VAR_(0x006D7974, char**)
#define GF_fmvfilenames_buffer	VAR_(0x006D7848, char*)
#define GF_levelfilenames	VAR_(0x006D7934, char**)
#define GF_levelfilenames_buffer	VAR_(0x006D787C, char*)
#define GF_cutscenefilenames	VAR_(0x006D77A8, char**)
#define GF_cutscenefilenames_buffer	VAR_(0x006D7858, char*)
#define GF_sequence_buffer	VAR_(0x006D7860, short*)
#define GF_frontendSequence	VAR_(0x006D7850, short*)
#define GF_GameStrings	VAR_(0x006D7890, char**)
#define GF_GameStrings_buffer	VAR_(0x006D7898, char*)
#define GF_PCStrings	VAR_(0x006D7930, char**)
#define GF_PCStrings_buffer	VAR_(0x006D7894, char*)
#define GF_Puzzle1Strings	VAR_(0x006D77A4, char**)
#define GF_Puzzle2Strings	VAR_(0x006D7878, char**)
#define GF_Puzzle3Strings	VAR_(0x006D78A0, char**)
#define GF_Puzzle4Strings	VAR_(0x006D7840, char**)
#define GF_Puzzle1Strings_buffer	VAR_(0x006D7888, char*)
#define GF_Puzzle2Strings_buffer	VAR_(0x006D7920, char*)
#define GF_Puzzle3Strings_buffer	VAR_(0x006D7978, char*)
#define GF_Puzzle4Strings_buffer	VAR_(0x006D7970, char*)
#define GF_Pickup1Strings	VAR_(0x006D7874, char**)
#define GF_Pickup2Strings	VAR_(0x006D7924, char**)
#define GF_Pickup1Strings_buffer	VAR_(0x006D7844, char*)
#define GF_Pickup2Strings_buffer	VAR_(0x006D7868, char*)
#define GF_Key1Strings	VAR_(0x006D7884, char**)
#define GF_Key2Strings	VAR_(0x006D7854, char**)
#define GF_Key3Strings	VAR_(0x006D789C, char**)
#define GF_Key4Strings	VAR_(0x006D7870, char**)
#define GF_Key1Strings_buffer	VAR_(0x006D784C, char*)
#define GF_Key2Strings_buffer	VAR_(0x006D7864, char*)
#define GF_Key3Strings_buffer	VAR_(0x006D797C, char*)
#define GF_Key4Strings_buffer	VAR_(0x006D785C, char*)
#define GF_BonusLevelEnabled	VAR_(0x00626208, long)
#define GF_PlayingFMV	VAR_(0x006261DC, long)
#define GF_Cutscene_Orientation	VAR_(0x004C5618, ushort)
#define GF_SunsetEnabled	VAR_(0x006261E8, short)
#define GF_StartGame	VAR_(0x00626200, char)
#define GF_LaraStartAnim	VAR_(0x006261E4, long)
#define GF_RemoveWeapons	VAR_(0x006261F4, short)
#define GF_NumSecrets	VAR_(0x004C55F0, short)
#define GF_RemoveAmmo	VAR_(0x006261F8, short)
#define Inv_ringText	VAR_(0x0062642C, TEXTSTRING*)
#define Inv_tagText	VAR_(0x00626430, TEXTSTRING*)
#define Inv_upArrow1	VAR_(0x00626434, TEXTSTRING*)
#define Inv_upArrow2	VAR_(0x00626438, TEXTSTRING*)
#define Inv_downArrow1	VAR_(0x0062643C, TEXTSTRING*)
#define Inv_downArrow2	VAR_(0x00626440, TEXTSTRING*)
#define inv_keys_objects	VAR_(0x00626414, short)
#define inv_keys_current	VAR_(0x00626418, short)
#define inv_main_objects	VAR_(0x004C6AF0, short)
#define inv_main_current	VAR_(0x00626410, short)
#define Inventory_Displaying	VAR_(0x00626454, short)
#define Inventory_Chosen	VAR_(0x004C70A0, short)
#define inv_option_objects	VAR_(0x004C6C14, short)
#define Inventory_DemoMode	VAR_(0x00626478, long)
#define OpenInvOnGym	VAR_(0x004C6C30, long)
#define inv_option_current	VAR_(0x0062641C, short)
#define item_data	VAR_(0x00626488, short)
#define idelay	VAR_(0x00626480, long)
#define idcount	VAR_(0x00626484, long)
#define icompass_option	VAR_(0x004C5E20, INVENTORY_ITEM)
#define igun_option	VAR_(0x004C5E70, INVENTORY_ITEM)
#define iflare_option	VAR_(0x004C5EC0, INVENTORY_ITEM)
#define ishotgun_option	VAR_(0x004C5F10, INVENTORY_ITEM)
#define imagnum_option	VAR_(0x004C5F60, INVENTORY_ITEM)
#define iuzi_option	VAR_(0x004C5FB0, INVENTORY_ITEM)
#define iharpoon_option	VAR_(0x004C6000, INVENTORY_ITEM)
#define im16_option	VAR_(0x004C6050, INVENTORY_ITEM)
#define irocket_option	VAR_(0x004C60A0, INVENTORY_ITEM)
#define igrenade_option	VAR_(0x004C60F0, INVENTORY_ITEM)
#define igunammo_option	VAR_(0x004C6140, INVENTORY_ITEM)
#define isgunammo_option	VAR_(0x004C6190, INVENTORY_ITEM)
#define imagammo_option	VAR_(0x004C61E0, INVENTORY_ITEM)
#define iuziammo_option	VAR_(0x004C6230, INVENTORY_ITEM)
#define iharpoonammo_option	VAR_(0x004C6280, INVENTORY_ITEM)
#define im16ammo_option	VAR_(0x004C62D0, INVENTORY_ITEM)
#define irocketammo_option	VAR_(0x004C6320, INVENTORY_ITEM)
#define igrenadeammo_option	VAR_(0x004C6370, INVENTORY_ITEM)
#define imedi_option	VAR_(0x004C63C0, INVENTORY_ITEM)
#define ibigmedi_option	VAR_(0x004C6410, INVENTORY_ITEM)
#define sgcrystal_option	VAR_(0x004C68C0, INVENTORY_ITEM)
#define ipassport_option	VAR_(0x004C6910, INVENTORY_ITEM)
#define idetail_option	VAR_(0x004C6960, INVENTORY_ITEM)
#define isound_option	VAR_(0x004C69B0, INVENTORY_ITEM)
#define icontrol_option	VAR_(0x004C6A00, INVENTORY_ITEM)
#define igamma_option	VAR_(0x004C6A50, INVENTORY_ITEM)
#define iphoto_option	VAR_(0x004C6AA0, INVENTORY_ITEM)
#define ipickup1_option	VAR_(0x004C6460, INVENTORY_ITEM)
#define ipickup2_option	VAR_(0x004C64B0, INVENTORY_ITEM)
#define ipuzzle1_option	VAR_(0x004C6500, INVENTORY_ITEM)
#define ipuzzle2_option	VAR_(0x004C6550, INVENTORY_ITEM)
#define ipuzzle3_option	VAR_(0x004C65A0, INVENTORY_ITEM)
#define ipuzzle4_option	VAR_(0x004C65F0, INVENTORY_ITEM)
#define ikey1_option	VAR_(0x004C6640, INVENTORY_ITEM)
#define ikey2_option	VAR_(0x004C6690, INVENTORY_ITEM)
#define ikey3_option	VAR_(0x004C66E0, INVENTORY_ITEM)
#define ikey4_option	VAR_(0x004C6730, INVENTORY_ITEM)
#define icon1_option	VAR_(0x004C6780, INVENTORY_ITEM)
#define icon2_option	VAR_(0x004C67D0, INVENTORY_ITEM)
#define icon3_option	VAR_(0x004C6820, INVENTORY_ITEM)
#define icon4_option	VAR_(0x004C6870, INVENTORY_ITEM)
#define Load_Game_Requester	VAR_(0x004C6C38, REQUEST_INFO)
#define Level_Select_Requester	VAR_(0x004C6E50, REQUEST_INFO)
#define GlobePointLight	VAR_(0x006D62B4, long)
#define GlobeXRot	VAR_(0x006D62AE, short)
#define GlobeYRot	VAR_(0x006D62BA, short)
#define GlobeZRot	VAR_(0x006D62B8, short)
#define bossdata	VAR_(0x006D2240, BOSS_STRUCT)
#define TribeBossItem	VAR_(0x006D2264, ITEM_INFO*)
#define IsRoomOutsideNo	VAR_(0x006E2FFE, short)
#define OutsideRoomTable	VAR_(0x006E2FF4, char*)
#define nTPages	VAR_(0x006CED5C, long)
#define game_closedown	VAR_(0x00625F70, long)
#define GlobeLevel	VAR_(0x006D62CA, short)
#define NextAdventure	VAR_(0x006D62C6, short)
#define HiResFlag	VAR_(0x006A184C, long)
#define SavedGames	VAR_(0x00633F4C, long)
#define save_counter	VAR_(0x00633F58, long)
#define malloc_ptr	VAR_(0x00634140, char*)
#define malloc_buffer	VAR_(0x0069FCAC, char*)
#define malloc_free	VAR_(0x006598D8, long)
#define malloc_size	VAR_(0x00634138, long)
#define malloc_used	VAR_(0x006598D4, long)
#define G_lpCmdLine	VAR_(0x006CF25C, char*)
#define title_loaded	VAR_(0x006A1C58, long)
#define HeavyTriggered	VAR_(0x006E28CC, uchar)
#define flip_status	VAR_(0x006E296C, long)
#define flipeffect	VAR_(0x004C5200, long)
#define ExerciseNumber	VAR_(0x006261B8, long)
#define fliptimer	VAR_(0x00625F68, long)
#define lpDirectSound	VAR_(0x00632AC8, LPDIRECTSOUND)
#define acm_volume	VAR_(0x00627470, long)
#define SunsetTimer	VAR_(0x006E289C, long)
#define DXPalette	VAR_(0x006CED58, LPDIRECTDRAWPALETTE)
#define dont_exit_quad	VAR_(0x006267BC, char)
#define HandbrakeStarting	VAR_(0x006267C8, char)
#define Stats_Requester	VAR_(0x00626490, REQUEST_INFO)
#define number_los_rooms	VAR_(0x00625F6C, long)
#define slots_used	VAR_(0x00626794, long)
#define nonlot_slots_used	VAR_(0x00626798, long)
/*renderer/phd/matrix stuff*/
#define phd_leftfloat	VAR_(0x004F6D30, float)
#define phd_topfloat	VAR_(0x004E34A8, float)
#define phd_rightfloat	VAR_(0x005D7A48, float)
#define phd_bottomfloat	VAR_(0x004D78F4, float)
#define phd_winxmin	VAR_(0x00531708, short)
#define phd_winxmax	VAR_(0x005316E0, short)
#define phd_winymin	VAR_(0x004F6D34, short)
#define phd_winymax	VAR_(0x00531714, short)
#define f_centerx	VAR_(0x005316F8, float)
#define f_centery	VAR_(0x005316FC, float)
#define phd_centerx	VAR_(0x004D7914, long)
#define phd_centery	VAR_(0x004D7918, long)
#define phd_mxptr	VAR_(0x005A6A2C, long*)
#define phd_zfar	VAR_(0x004F6D44, long)
#define phd_znear	VAR_(0x005316E8, long)
#define f_oneopersp	VAR_(0x004F6D48, float)
#define f_persp	VAR_(0x005A6AB8, float)
#define one	VAR_(0x004C5084, float)
#define phd_persp	VAR_(0x004F6D50, long)
#define phd_winwidth	VAR_(0x005A6AF4, long)
#define phd_winheight	VAR_(0x004D790C, long)
#define f_znear	VAR_(0x0056C0A0, float)
#define f_zfar	VAR_(0x005316F4, float)
#define f_perspoznear	VAR_(0x0053170C, float)
#define LfAspectCorrection	VAR_(0x004D38D8, float)
#define IMptr	VAR_(0x006E288C, long*)
#define IM_rate	VAR_(0x006E2884, long)
#define IM_frac	VAR_(0x006E2070, long)
#define phd_right	VAR_(0x005D7AE0, long)
#define phd_left	VAR_(0x004F6D58, long)
#define phd_bottom	VAR_(0x004F6D4C, long)
#define phd_top	VAR_(0x004D58E8, long)
#define phd_scrwidth	VAR_(0x005BD3D8, long)
#define phd_scrheight	VAR_(0x00531700, long)
#define phd_WindowRect	VAR_(0x006A1838, RECT)
#define m00	VAR_(0x006CA088, float)
#define m01	VAR_(0x006CA08C, float)
#define m02	VAR_(0x006CA090, float)
#define m03	VAR_(0x006CA094, float)
#define m10	VAR_(0x006CA098, float)
#define m11	VAR_(0x006CA09C, float)
#define m12	VAR_(0x006CA0A0, float)
#define m13	VAR_(0x006CA0A4, float)
#define m20	VAR_(0x006CA0A8, float)
#define m21	VAR_(0x006CA0AC, float)
#define m22	VAR_(0x006A2080, float)
#define m23	VAR_(0x006A2084, float)
#define CurrentTLVertex	VAR_(0x00634004, D3DTLVERTEX*)
#define TLVertexBuffer	VAR_(0x0063413C, D3DTLVERTEX*)
#define VertexBuffer	VAR_(0x00633FF8, D3DTLVERTEX*)
#define TLUnRollBuffer	VAR_(0x006598D0, D3DTLVERTEX*)
#define UnRollBuffer	VAR_(0x00633FF0, D3DTLVERTEX*)
#define bAlphaTesting	VAR_(0x00633FF4, bool)
#define sort3dptrbf	VAR_(0x005316E4, long*)
#define info3dptrbf	VAR_(0x004D7910, short*)
#define surfacenumbf	VAR_(0x0053171C, long)
#define sort3dptrfb	VAR_(0x005316EC, long*)
#define info3dptrfb	VAR_(0x004F6D40, short*)
#define surfacenumfb	VAR_(0x004F6D54, long)
#define f_a	VAR_(0x004D78F8, float)
#define f_b	VAR_(0x004D78FC, float)
#define f_boo	VAR_(0x005316F0, float)
#define f_oneoznear	VAR_(0x00531710, float)
#define nDrawnPoints	VAR_(0x00634000, long)
#define outsideBackgroundTop	VAR_(0x006E2898, float)
#define phd_viewdist	VAR_(0x005BAB04, long)
#define HWConfig	VAR_(0x006CED68, HWCONFIG)
#define CamPos	VAR_(0x006CF800, PHD_VECTOR)
#define CamRot	VAR_(0x006CF810, PHD_VECTOR)
/**/
/*debug stuff*/
#define bLaraOn	VAR_(0x004CDC88, long)
#define bRoomOn	VAR_(0x004CDC8C, long)
#define bObjectOn	VAR_(0x004CDC90, long)
#define bAObjectOn	VAR_(0x004CDC94, long)
#define bEffectOn	VAR_(0x004CDC98, long)
#define bInvItemsOff	VAR_(0x00626450, char)
#define framedump	VAR_(0x006CF248, long)
/**/

/*arrays*/
#define objects	ARRAY_(0x006DCAC0, OBJECT_INFO, [376])
#define w2v_matrix	ARRAY_(0x005A6AC0, long, [indices_count])
#define matrix_stack	ARRAY_(0x005BAB58, long, [40 * indices_count])
#define ZTable	ARRAY_(0x006A2088, float, [40960])
#define UVTable	ARRAY_(0x005E5450, float, [65536])
#define ColorTable	ARRAY_(0x00634010, uchar, [256])
#define IMstack	ARRAY_(0x006E1440, long, [768])
#define interpolated_bounds	ARRAY_(0x006E28B0, short, [6])
#define bound_list	ARRAY_(0x00625F88, long, [128])
#define draw_rooms	ARRAY_(0x006E2220, short, [100])
#define dynamics	ARRAY_(0x006DB380, DYNAMIC, [64])
#define weapons	ARRAY_(0x004C7280, WEAPON_INFO, [11])	//put this in dll asap
#define vbuf	ARRAY_(0x005BD3E0, PHD_VBUF, [1500])
#define v_buffer	ARRAY_(0x00625850, VERTEX_INFO, [40])
#define LPos	ARRAY_(0x0069FE98, PHD_VECTOR, [3])
#define LightPos	ARRAY_(0x0069FE58, long, [12])
#define LightCol	ARRAY_(0x0069FE28, long, [12])
#define lead_info	ARRAY_(0x006D86E0, LEADER_INFO, [8])
#define fish	ARRAY_(0x006D7BE0, FISH_INFO, [200])
#define conflict	ARRAY_(0x0069FCB0, long, [15])
#define keymap	ARRAY_(0x0069FCF0, uchar, [256])
#define sparks	ARRAY_(0x006D8880, SPARKS, [192])
#define spark_dynamics	ARRAY_(0x006DB280, SP_DYNAMIC, [32])
#define depthq_table	ARRAY_(0x005BB2D8, char, [33][256])
#define gouraud_table	ARRAY_(0x004D38E8, char, [256][32])
#define water_palette	ARRAY_(0x006A1228, uchar, [768])
#define game_palette	ARRAY_(0x006A1858, uchar, [768])
#define exit_message	ARRAY_(0x006A1BD8, char, [128])
#define phdspriteinfo	ARRAY_(0x004D58F0, PHDSPRITESTRUCT, [512])
#define G_GouraudPalette	ARRAY_(0x00625450, uchar, [1024])
#define FootPrint	ARRAY_(0x006D79E0, FOOTPRINT, [32])
#define light_level	ARRAY_(0x006A1828, long, [4])
#define box_lines	ARRAY_(0x004C53F8, long, [12][2])
#define inv_colours	ARRAY_(0x006D71E0, short, [17])
#define static_objects	ARRAY_(0x006E2300, STATIC_INFO, [50])
#define IsJointUnderwater	ARRAY_(0x006D6290, char, [15])
#define GotJointPos	ARRAY_(0x006D6190, char, [15])
#define RColorTable	ARRAY_(0x00635748, long, [33][33][33])
#define GColorTable	ARRAY_(0x006598E0, long, [33][33][33])
#define BColorTable	ARRAY_(0x0067CB28, long, [33][33][33])
#define WaterTable	ARRAY_(0x00634148, WATERTAB, [22][64])
#define wibble_table	ARRAY_(0x005D7A60, float, [32])
#define shade_table	ARRAY_(0x005BAB10, short, [32])
#define rand_table	ARRAY_(0x005A6A38, long, [32])
#define wibble_light	ARRAY_(0x006A0220, long, [32][32])
#define electricity_points	ARRAY_(0x006E2080, short, [32][6])
#define lara_meshes	ARRAY_(0x004C52B0, uchar, [28])
#define lara_last_points	ARRAY_(0x004C52D0, uchar, [14])
#define lara_line_counts	ARRAY_(0x004C52E0, uchar, [6])
#define ExpRings	ARRAY_(0x006D5D20, EXPLOSION_RING, [6])
#define KBRings	ARRAY_(0x006D58C0, EXPLOSION_RING, [3])
#define OldPicTexIndices	ARRAY_(0x006A1B80, long, [5])
#define CurPicTexIndices	ARRAY_(0x006A1B98, long, [5])
#define Inventory_ExtraData	ARRAY_(0x00626458, long, [8])
#define T_remapASCII	ARRAY_(0x004C7CE8, char, [95])
#define T_textSpacing	ARRAY_(0x004C7C78, char, [110])
#define T_textStrings	ARRAY_(0x006D0000, TEXTSTRING, [64])
#define T_theStrings	ARRAY_(0x006D0F20, char, [4096])
#define WakePts	ARRAY_(0x006E31A0, WAKE_PTS, [32][2])
#define SubWakePts	ARRAY_(0x006269E0, SUB_WAKE_PTS, [32][2])
#define TonyBossShield	ARRAY_(0x006CFD80, SHIELD_POINTS, [40])
#define LondonBossShield	ARRAY_(0x006D5AA0, SHIELD_POINTS, [40])
#define WillBossShield	ARRAY_(0x006CF820, SHIELD_POINTS, [40])
#define Buckets	ARRAY_(0x005D7B00, TEXTUREBUCKET, [6])
#define ground_zone	ARRAY_(0x006E3160, short*, [4][2])
#define fly_zone	ARRAY_(0x006E3180, short*, [2])
#define sample_lut	ARRAY_(0x006D1F40, short, [370])
#define LastLoadedLevelPath	ARRAY_(0x00633E28, char, [256])
#define GF_Offsets	ARRAY_(0x00633C90, short, [200])
#define GF_Description	ARRAY_(0x00626210, char, [256])
#define GF_level_sequence_list	ARRAY_(0x006D78C0, short*, [24])
#define GF_valid_demos	ARRAY_(0x006D7940, short, [24])
#define GF_CDtracks	ARRAY_(0x004C55F8, short, [16])
#define GF_Add2InvItems	ARRAY_(0x006D79A0, char, [30])
#define GF_SecretInvItems	ARRAY_(0x006D7980, char, [30])
#define RequesterFlags1	ARRAY_(0x006D6800, ulong, [24])
#define RequesterFlags2	ARRAY_(0x006D67A0, ulong, [24])
#define SaveGameReqFlags1	ARRAY_(0x006D7740, ulong, [24])
#define SaveGameReqFlags2	ARRAY_(0x006D76E0, ulong, [24])
#define Inv_itemText	ARRAY_(0x00626420, TEXTSTRING*, [3])
#define inv_main_qtys	ARRAY_(0x004C6AF8, short, [23])
#define inv_main_list	ARRAY_(0x004C6B28, INVENTORY_ITEM*, [23])
#define inv_keys_qtys	ARRAY_(0x004C6B88, short, [23])
#define inv_keys_list	ARRAY_(0x004C6BB8, INVENTORY_ITEM*, [23])
#define inv_option_list	ARRAY_(0x004C6C18, INVENTORY_ITEM*, [5])
#define inv_levelselect_list	ARRAY_(0x004C6C2C, INVENTORY_ITEM*, [1])
#define GlobeLevelComplete	ARRAY_(0x006D62C0, uchar, [6])
#define LaserShades	ARRAY_(0x006D6160, uchar, [32])
#define bats	ARRAY_(0x006DB8A0, BAT_STRUCT, [32])
#define saved_levels	ARRAY_(0x004CD878, short, [24])
#define flipmap	ARRAY_(0x006E2980, long, [10])
#define cd_flags	ARRAY_(0x006E28E0, char, [128])
#define TrackInfos	ARRAY_(0x00627480, TRACK_INFO, [130])
#define DS_Samples	ARRAY_(0x00632B50, LPDIRECTSOUNDBUFFER, [32])
#define SqrtTable	ARRAY_(0x006588D0, long, [1024])
#define LaSlot	ARRAY_(0x006267E0, SOUND_SLOT, [32])
#define Valid_Level_Strings	ARRAY_(0x006D62E0, char, [24][50])
#define Valid_Level_Strings2	ARRAY_(0x006D7220, char, [24][50])
#define los_rooms	ARRAY_(0x006E29C0, long, [20])
#define OutsideRoomOffsets	ARRAY_(0x006E2A40, short, [729])
#define splashes	ARRAY_(0x006DBB20, SPLASH_STRUCT, [4])
#define ripples	ARRAY_(0x006D8780, RIPPLE_STRUCT, [16])
