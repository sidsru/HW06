// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingFlatform.generated.h"


UCLASS()
class SPARTAPROJECT_API AMovingFlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingFlatform();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


public:	

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float Leng;

	FVector MaxLength;

};
