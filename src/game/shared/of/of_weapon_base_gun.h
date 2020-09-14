// ========= Copyright Open Fortress Developers, CC-BY-NC-SA ============
// Purpose: COFWeaponBaseGun is the root of most ranged weapons
// Author(s): KaydemonLP
//
#pragma once

#include "of_weapon_base.h"

#if defined( CLIENT_DLL )
    #define COFWeaponBaseGun C_OFWeaponBaseGun
#endif

class COFWeaponBaseGun: public COFWeaponBase
{
    DECLARE_CLASS(COFWeaponBaseGun, COFWeaponBase);
    DECLARE_NETWORKCLASS();
    DECLARE_PREDICTABLE();
	
#ifdef GAME_DLL
	DECLARE_DATADESC();
#endif

    //NOTE: I'm basing this class interface entirely on the serverside vtable, and so..
    //OFTODO: Compare COFWeaponBaseGun members to client.dylib CTFWeaponBaseGun

    COFWeaponBaseGun();
	~COFWeaponBaseGun();
/*
	virtual bool CanBeSelected();
	virtual bool HasPrimaryAmmo();
	virtual bool CanDeploy();
	virtual bool Holster();
	virtual void PrimaryAttack();
	virtual void SecondaryAttack();
	
	// What is this used for??
	// Re: Apparently there's a "last_shot_crits" attribute, dont think anything uses it - Kay
	virtual bool HasLastShotCritical();
	
	virtual void DoFireEffects();
	virtual bool ShouldDoMuzzleFlash();
	virtual int GetWeaponProjectileType() const;
	virtual CBaseEntity *FireProjectile( CTFPlayer *pPlayer );
	virtual void RemoveProjectileAmmo( CTFPlayer *pPlayer );
	virtual void ModifyProjectile( CBaseEntity *pEnt );
	virtual void FireBullet( CTFPlayer *pPlayer );
	// OFTODO: Figure out what the types are
	virtual void FirePipeBomb( CTFPlayer *pPlayer, int iType );
	// OFTODO: Ditto
	virtual void FireArrow( CTFPlayer *pPlayer, int ProjectileType_t );
	
	virtual void FireJar( CTFPlayer *pPlayer );
	virtual void FireFlameRocket( CTFPlayer *pPlayer );
	// OFTODO: Figure out what the magic bool does
	virtual void FireEnergyBall( CTFPlayer *pPlayer, bool bMagic );
	virtual void GetWeaponSpread();
	virtual char GetCustomProjectileModel( CAttribute_String *szParam );
	virtual float GetProjectileSpeed();
	virtual float GetProjectileGravity();
	virtual float GetProjectileSpread();
	virtual int GetAmmoPerShot();
	virtual int GetProjectileDamage();
	virtual bool ShouldPlayFireAnim();
	virtual void ZoomIn();
	virtual void ZoomOut();
	virtual void PlayWeaponShootSound();
	virtual bool ShouldRemoveDisguiseOnPrimaryFire() const;
	*/
};