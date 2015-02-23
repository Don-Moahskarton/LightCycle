// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef LIGHTCYCLE_LightCycleMovementComponent_generated_h
#error "LightCycleMovementComponent.generated.h already included, missing '#pragma once' in LightCycleMovementComponent.h"
#endif
#define LIGHTCYCLE_LightCycleMovementComponent_generated_h

#define ULightCycleMovementComponent_EVENTPARMS
#define ULightCycleMovementComponent_RPC_WRAPPERS
#define ULightCycleMovementComponent_CALLBACK_WRAPPERS
#define ULightCycleMovementComponent_INCLASS \
	private: \
	static void StaticRegisterNativesULightCycleMovementComponent(); \
	friend LIGHTCYCLE_API class UClass* Z_Construct_UClass_ULightCycleMovementComponent(); \
	public: \
	DECLARE_CLASS(ULightCycleMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0), 0, LightCycle, NO_API) \
	DECLARE_SERIALIZER(ULightCycleMovementComponent) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<ULightCycleMovementComponent*>(this); }


#define ULightCycleMovementComponent_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULightCycleMovementComponent(const class FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULightCycleMovementComponent) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ULightCycleMovementComponent(const ULightCycleMovementComponent& InCopy); \
public:


#define ULightCycleMovementComponent_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULightCycleMovementComponent(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ULightCycleMovementComponent(const ULightCycleMovementComponent& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULightCycleMovementComponent)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME ULightCycleMovementComponent


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
ULightCycleMovementComponent_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ULightCycleMovementComponent_RPC_WRAPPERS \
	ULightCycleMovementComponent_CALLBACK_WRAPPERS \
	ULightCycleMovementComponent_INCLASS \
	ULightCycleMovementComponent_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ULightCycleMovementComponent_RPC_WRAPPERS \
	ULightCycleMovementComponent_CALLBACK_WRAPPERS \
	ULightCycleMovementComponent_INCLASS \
	ULightCycleMovementComponent_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LightCycleMovementComponent."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


