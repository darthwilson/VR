// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Base_Character.generated.h"

UCLASS(Blueprintable)
class VR_API ABase_Character : public ACharacter
{
	GENERATED_BODY()

public:

	//Health
	UPROPERTY(BlueprintReadwrite, EditAnywhere, Category = "Base_Character")
		float Health = 100;


	//isDead 
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base_Character")
		bool isDead = false;


	//calculate death (helper)
	virtual void CalculateDead();
	//calculate health 
	UFUNCTION(BlueprintCallable, Category = "Base_Character")
		virtual void CalculateHealth(float delta);

#if WITH_EDITOR
	//editor centric code for changing properties 
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
		override;

#endif

public:
	// Sets default values for this character's properties
	ABase_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
