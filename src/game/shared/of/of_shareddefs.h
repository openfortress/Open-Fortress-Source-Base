// ========= Copyright Open Fortress Developers, CC-BY-NC-SA ============
// Purpose: General definitions
// Author(s): ficool2, Fenteale, Kay, Ms
//

#include "shareddefs.h"
#include "mp_shareddefs.h"

// OFSTATUS: INCOMPLETE  ( labeling )
enum OF_Collision_Group_t
{
	OF_COLLISION_GROUP_UNKNOWN20 = LAST_SHARED_COLLISION_GROUP,
	OF_COLLISION_GROUP_UNKNOWN21,
	OF_COLLISION_GROUP_UNKNOWN22,
	OF_COLLISION_GROUP_UNKNOWN23,
	// OFINFO: labelled as "TFCOLLISION_GROUP_ROCKETS" in public SDK code, shared/particlesystemquery.cpp
	OF_COLLISION_GROUP_ROCKETS,
	OF_COLLISION_GROUP_UNKNOWN25,
	OF_COLLISION_GROUP_PUMPKIN_BOMB,
	// OFINFO: this is called in FireRocket + FireArrow in CPointWeaponMimic, guessing its for projectiles?
	OF_COLLISION_GROUP_PROJECTILE,
};


// Sourced from sourcemod API
#define DMG_CRIT                DMG_ACID        // < Crits and minicrits
#define DMG_RADIUS_MAX          DMG_ENERGYBEAM  // < No damage falloff 
#define DMG_NOCLOSEDISTANCEMOD  DMG_POISON      // < Don't do damage falloff too close 
#define DMG_HALF_FALLOFF        DMG_RADIATION   // < 50% damage falloff
#define DMG_USEDISTANCEMOD      DMG_SLOWBURN    // < Do damage falloff 
#define DMG_IGNITE              DMG_PLASMA      // < Ignite victim 
#define DMG_USE_HITLOCATIONS    DMG_AIRBOAT     // < Do hit location damage (sniper rifle) 

#ifdef CLIENT_DLL
#define Shared_VarArgs VarArgs
#else
#define Shared_VarArgs UTIL_VarArgs
#endif

// maybe rename to OF_ ? - cherry
// nevermind! compatibility

#define TF_DAMAGE_CRIT_MULTIPLIER	3
#define TF_WEAPON_RANDOM_RANGE				1000.0f
#define TF_WEAPON_CRIT_CHANCE_NORMAL		0.02f
#define TF_WEAPON_CRIT_CHANCE_RAPID			0.02f
#define TF_WEAPON_CRIT_DURATION				2.0f

#define OF_PLAYER_WEAPON_COUNT 6
#define OF_PLAYER_GRENADE_COUNT 6
#define OF_PLAYER_BUILDABLE_COUNT 6

#define SF_STICKY_MAY_NOT_STICK 1<<10 // makes stickys not stick!

enum OFPlayerState
{
	TF_STATE_ACTIVE,
	TF_STATE_WELCOME,
	TF_STATE_OBSERVER,
	TF_STATE_DYING,
	TF_STATE_LAST
};

enum
{
	OF_TEAM_RED = FIRST_GAME_TEAM,
	OF_TEAM_BLUE,

	OF_TEAM_COUNT
};

enum
{
	OF_WEAPON_MODE_PRIMARY = 0,
	OF_WEAPON_MODE_SECONDARY,
	OF_WEAPON_MODE_COUNT
};

enum
{
	OF_WEAPON_TYPE_PRIMARY = 0,
	OF_WEAPON_TYPE_SECONDARY,
	OF_WEAPON_TYPE_MELEE,
	OF_WEAPON_TYPE_GRENADE,
	OF_WEAPON_TYPE_BUILDING,
	OF_WEAPON_TYPE_PDA,
	OF_WEAPON_TYPE_ITEM1,
	OF_WEAPON_TYPE_ITEM2
};

enum
{
	OF_AMMO_DUMMY,
	OF_AMMO_PRIMARY,
	OF_AMMO_SECONDARY,
	OF_AMMO_METAL,
	OF_AMMO_GRENADES1,
	OF_AMMO_GRENADES2,
	OF_AMMO_GRENADES3,
	OF_AMMO_COUNT
};

// only these two values should exist as the others are probably econ related
enum
{
	OF_GRENADELAUNCHERTYPE_PIPE = 0,
	OF_GRENADELAUNCHERTYPE_STICKY,
};

// These values are approximate and gotten via limited testing
// using the override projectile type attribute in Live tf2
// couldn't get some of these to spawn, so for those i used the FireProjectile class as a reference
// however some i still couldnt figure out, those are marked as Unknown
// If you know a better way, feel free to update this
enum
{
	OF_PROJECTILE_TYPE_NONE = 0,		 // 0  "projectile_bullet"
	OF_PROJECTILE_TYPE_BULLET,           // 1  "projectile_bullet"
	OF_PROJECTILE_TYPE_ROCKET,           // 2  "projectile_rocket"
	OF_PROJECTILE_TYPE_PIPEBOMB,         // 3  "projectile_pipe"
	OF_PROJECTILE_TYPE_STICKYBOMB,       // 4  "projectile_pipe_remote"
	OF_PROJECTILE_TYPE_SYRINGE,          // 5  "projectile_syringe"
	OF_PROJECTILE_TYPE_FLARE,            // 6  "projectile_flare"
	OF_PROJECTILE_TYPE_JARATE,           // 7  "projectile_jar"
	OF_PROJECTILE_TYPE_ARROW,            // 8  "projectile_arrow"
	OF_PROJECTILE_TYPE_FLAMEROCKET,      // 9  Seems to be unused?
	OF_PROJECTILE_TYPE_MADMILK,          // 10 "projectile_jar_milk"
	OF_PROJECTILE_TYPE_CROSSBOW,         // 11 "projectile_healing_bolt"
	OF_PROJECTILE_TYPE_MANGLER,          // 12 "projectile_energy_ball"
	OF_PROJECTILE_TYPE_BISON,            // 13 "projectile_energy_ring" 
	OF_PROJECTILE_TYPE_STICKYJUMPER,     // 14 Defined only via items game
	OF_PROJECTILE_TYPE_CLEAVER,           // 15 "projectile_cleaver"
	OF_PROJECTILE_TYPE_UNKNOWN1,         // 16 
	OF_PROJECTILE_TYPE_CANNONBALL,       // 17 "projectile_cannonball"
	OF_PROJECTILE_TYPE_RANGER,           // 18 Defined only via items game
	OF_PROJECTILE_TYPE_ARROW_FESTIVE,    // 19 Defined only via items game
	OF_PROJECTILE_TYPE_UNKNOWN2,         // 20
	OF_PROJECTILE_TYPE_UNKNOWN3,         // 21
	OF_PROJECTILE_TYPE_JARATE_FESTIVE,   // 22 Defined only via items game
	OF_PROJECTILE_TYPE_CROSSBOW_FESTIVE, // 23 Defined only via items game
	OF_PROJECTILE_TYPE_JARATE_BREAD,     // 24 Defined only via items game
	OF_PROJECTILE_TYPE_MADMILK_BREAD,    // 25 Defined only via items game
	OF_PROJECTILE_TYPE_GRAPPLE,       	 // 26 "tf_projectile_grapplinghook"

	OF_PROJECTILE_TYPE_BALLOFFIRE,		 // 27? "tf_projectile_balloffire" Havent tried out projectile override in a while so these werent in my list
	OF_PROJECTILE_TYPE_GASPASSER,		 // 28? "projectile_jar_gas" 
	OF_PROJECTILE_TYPE_COUNT
};

enum
{
	OF_RELOAD_STAGE_NONE = 0,
	OF_RELOAD_STAGE_START,
	OF_RELOAD_STAGE_LOOP,
	OF_RELOAD_STAGE_END
};

enum
{
	OF_CLASS_UNDEFINED = 0,

	OF_CLASS_SCOUT,
	OF_CLASS_SNIPER,
	OF_CLASS_SOLDIER,
	OF_CLASS_DEMO,
	OF_CLASS_MEDIC,
	OF_CLASS_HEAVY,
	OF_CLASS_PYRO,
	OF_CLASS_SPY,
	OF_CLASS_ENGINEER,

	OF_CLASS_CIVILIAN,
	OF_CLASS_COUNT
};

// not all of these exist, compatibility only
// https://csrd.science/misc/datadump/current/tf_conds.txt
enum ETFCond
{
	TF_COND_AIMING = 0,		// Sniper aiming, Heavy minigun.
	TF_COND_ZOOMED,
	TF_COND_DISGUISING,
	TF_COND_DISGUISED,
	TF_COND_STEALTHED,
	TF_COND_INVULNERABLE,
	TF_COND_TELEPORTED,
	TF_COND_TAUNTING,
	TF_COND_INVULNERABLE_WEARINGOFF,
	TF_COND_STEALTHED_BLINK,
	TF_COND_SELECTED_TO_TELEPORT,
	TF_COND_CRITBOOSTED,
	TF_COND_TMPDAMAGEBONUS,
	TF_COND_FEIGN_DEATH,
	TF_COND_PHASE,
	TF_COND_STUNNED,
	TF_COND_OFFENSEBUFF,
	TF_COND_SHIELD_CHARGE,
	TF_COND_DEMO_BUFF,
	TF_COND_ENERGY_BUFF,
	TF_COND_RADIUSHEAL,
	TF_COND_HEALTH_BUFF,
	TF_COND_BURNING,
	TF_COND_HEALTH_OVERHEALED,
	TF_COND_URINE,
	TF_COND_BLEEDING,
	TF_COND_DEFENSEBUFF,
	TF_COND_MAD_MILK,
	TF_COND_MEGAHEAL,
	TF_COND_REGENONDAMAGEBUFF,
	TF_COND_MARKEDFORDEATH,
	TF_COND_NOHEALINGDAMAGEBUFF,
	TF_COND_SPEED_BOOST,
	TF_COND_CRITBOOSTED_PUMPKIN,
	TF_COND_CRITBOOSTED_USER_BUFF,
	TF_COND_CRITBOOSTED_DEMO_CHARGE,
	TF_COND_SODAPOPPER_HYPE,
	TF_COND_CRITBOOSTED_FIRST_BLOOD,
	TF_COND_CRITBOOSTED_BONUS_TIME,
	TF_COND_CRITBOOSTED_CTF_CAPTURE,
	TF_COND_CRITBOOSTED_ON_KILL,
	TF_COND_CANNOT_SWITCH_FROM_MELEE,
	TF_COND_DEFENSEBUFF_NO_CRIT_BLOCK,
	TF_COND_REPROGRAMMED,
	TF_COND_CRITBOOSTED_RAGE_BUFF,
	TF_COND_DEFENSEBUFF_HIGH,
	TF_COND_SNIPERCHARGE_RAGE_BUFF,
	TF_COND_DISGUISE_WEARINGOFF,
	TF_COND_MARKEDFORDEATH_SILENT,
	TF_COND_DISGUISED_AS_DISPENSER,
	TF_COND_SAPPED,
	TF_COND_INVULNERABLE_HIDE_UNLESS_DAMAGE,
	TF_COND_INVULNERABLE_USER_BUFF,
	TF_COND_HALLOWEEN_BOMB_HEAD,
	TF_COND_HALLOWEEN_THRILLER,
	TF_COND_RADIUSHEAL_ON_DAMAGE,
	TF_COND_CRITBOOSTED_CARD_EFFECT,
	TF_COND_INVULNERABLE_CARD_EFFECT,
	TF_COND_MEDIGUN_UBER_BULLET_RESIST,
	TF_COND_MEDIGUN_UBER_BLAST_RESIST,
	TF_COND_MEDIGUN_UBER_FIRE_RESIST,
	TF_COND_MEDIGUN_SMALL_BULLET_RESIST,
	TF_COND_MEDIGUN_SMALL_BLAST_RESIST,
	TF_COND_MEDIGUN_SMALL_FIRE_RESIST,
	TF_COND_STEALTHED_USER_BUFF,
	TF_COND_MEDIGUN_DEBUFF,
	TF_COND_STEALTHED_USER_BUFF_FADING,
	TF_COND_BULLET_IMMUNE,
	TF_COND_BLAST_IMMUNE,
	TF_COND_FIRE_IMMUNE,
	TF_COND_PREVENT_DEATH,
	TF_COND_MVM_BOT_STUN_RADIOWAVE,
	TF_COND_HALLOWEEN_SPEED_BOOST,
	TF_COND_HALLOWEEN_QUICK_HEAL,
	TF_COND_HALLOWEEN_GIANT,
	TF_COND_HALLOWEEN_TINY,
	TF_COND_HALLOWEEN_IN_HELL,
	TF_COND_HALLOWEEN_GHOST_MODE,
	TF_COND_MINICRITBOOSTED_ON_KILL,
	TF_COND_OBSCURED_SMOKE,
	TF_COND_PARACHUTE_ACTIVE,
	TF_COND_BLASTJUMPING,
	TF_COND_HALLOWEEN_KART,
	TF_COND_HALLOWEEN_KART_DASH,
	TF_COND_BALLOON_HEAD,
	TF_COND_MELEE_ONLY,
	TF_COND_SWIMMING_CURSE,
	TF_COND_FREEZE_INPUT,
	TF_COND_HALLOWEEN_KART_CAGE,
	TF_COND_DONOTUSE_0,
	TF_COND_RUNE_STRENGTH,
	TF_COND_RUNE_HASTE,
	TF_COND_RUNE_REGEN,
	TF_COND_RUNE_RESIST,
	TF_COND_RUNE_VAMPIRE,
	TF_COND_RUNE_REFLECT,
	TF_COND_RUNE_PRECISION,
	TF_COND_RUNE_AGILITY,
	TF_COND_GRAPPLINGHOOK,
	TF_COND_GRAPPLINGHOOK_SAFEFALL,
	TF_COND_GRAPPLINGHOOK_LATCHED,
	TF_COND_GRAPPLINGHOOK_BLEEDING,
	TF_COND_AFTERBURN_IMMUNE,
	TF_COND_RUNE_KNOCKOUT,
	TF_COND_RUNE_IMBALANCE,
	TF_COND_CRITBOOSTED_RUNE_TEMP,
	TF_COND_PASSTIME_INTERCEPTION,
	TF_COND_SWIMMING_NO_EFFECTS,
	TF_COND_PURGATORY,
	TF_COND_RUNE_KING,
	TF_COND_RUNE_PLAGUE,
	TF_COND_RUNE_SUPERNOVA,
	TF_COND_PLAGUE,
	TF_COND_KING_BUFFED,
	TF_COND_TEAM_GLOWS,
	TF_COND_KNOCKED_INTO_AIR,
	TF_COND_COMPETITIVE_WINNER,
	TF_COND_COMPETITIVE_LOSER,
	TF_COND_HEALING_DEBUFF,
	TF_COND_PASSTIME_PENALTY_DEBUFF,
	TF_COND_GRAPPLED_TO_PLAYER,
	TF_COND_GRAPPLED_BY_PLAYER,
	TF_COND_PARACHUTE_DEPLOYED,
	TF_COND_GAS,
	TF_COND_BURNING_PYRO,
	TF_COND_ROCKETPACK,
	TF_COND_LOST_FOOTING,
	TF_COND_AIR_CURRENT,

	TF_COND_LAST
};

enum EOFPowerupSize
{
	OF_POWERUP_SMALL = 0,
	OF_POWERUP_MEDIUM,
	OF_POWERUP_FULL
};

enum
{
	OF_FLAGSTATUS_NONE = 0,
	OF_FLAGSTATUS_TAKEN,
	OF_FLAGSTATUS_DROPPED
};

enum
{
	OF_ITEM_UNDEFINDED = 0,
	OF_ITEM_FLAG
};

// gotta continue re'ing CCaptureFlag to figure out what's what
enum EOFFlagType
{
	TF_FLAGTYPE_CTF = 0,
	TF_FLAGTYPE_UNKNOWN1, // attackdefend.. mvm?
	TF_FLAGTYPE_UNKNOWN2,
	TF_FLAGTYPE_UNKNOWN3, // invade
	TF_FLAGTYPE_UNKNOWN4, // special delivery
	TF_FLAGTYPE_ROBOTDESTRUCTION,
	TF_FLAGTYPE_PLAYERDESTRUCTION
};

enum ETFGameType
{
	OF_GAMETYPE_UNDEFINDED = 0,
	OF_GAMETYPE_CTF,
	OF_GAMETYPE_CP,
	OF_GAMETYPE_ESCORT,
	OF_GAMETYPE_ARENA,

	//TF_GAMETYPE_MVM,
	//TF_GAMETYPE_ROBOTDESTRUCTION,
	//TF_GAMETYPE_PASSTIME,
	//TF_GAMETYPE_PLAYERDESTRUCTION,

	OF_GAMETYPE_COUNT
};

enum
{
	OF_HUDTYPE_UNDEFINDED = 0,
	OF_HUDTYPE_CTF,
	OF_HUDTYPE_CP,
	OF_HUDTYPE_PAYLOAD,
	OF_HUDTYPE_UNKNOWN4,
	OF_HUDTYPE_UNKNOWN5,
	OF_HUDTYPE_UNKNOWN6,
};

const char *GetGameTypeName(ETFGameType GameType);
const char *GetEnumGameTypeName(ETFGameType GameType);
ETFGameType GetGameTypeFromName(const char *GameName);

extern const char* sz_OFPlayerState[TF_STATE_LAST];

extern int GetBuildableId( const char *szBuildableName );

extern const char *GetAmmoName( int iAmmoIndex );

// Weapon Defines
extern const char *g_aWeaponModePrefix[OF_WEAPON_MODE_COUNT];
extern int g_aWeaponDamageTypes[];
extern const char *g_aProjectileTypeNames[OF_PROJECTILE_TYPE_COUNT];

//OFHACK: g_aAmmoNames should probably be an extern + defined somewhere but isn't
// (oh well, just bloats the exe a bit)

// No longer the case, did it properly and moved it to of_shareddefs.cpp now - Kay
extern const char *g_aAmmoNames[OF_AMMO_COUNT];

// Team Defines
extern const char *g_aTeamNames[OF_TEAM_COUNT];
extern color32 g_aTeamColors[];

// health/ammo defines
extern float PackRatios[];

// Class Defines
extern const char *g_aRawPlayerClassNamesShort[];

// Map Defines
extern const char* s_ValveMaps[][3];
extern const char* s_CommunityMaps[][3];