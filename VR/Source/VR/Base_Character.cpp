// Fill out your copyright notice in the Description page of Project Settings.

#include "Base_Character.h"


// Sets default values
ABase_Character::ABase_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABase_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABase_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABase_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



//implement calculate health
void ABase_Character::CalculateHealth(float Delta)
{
	Health += Delta;
	CalculateDead();
}

//implement calculate dead
void ABase_Character::CalculateDead()
{
	if (Health <= 0)
		isDead = true;
	else
		isDead = false;
	
}

//implement posteditchangeproperty
#if WITH_EDITOR
void ABase_Character::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{

	isDead = false;
	Health = 100;

Super::PostEditChangeProperty(PropertyChangedEvent);

CalculateDead ();

}



#endif


