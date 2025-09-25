// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatorFlatform.generated.h"

UCLASS()
class SPARTAPROJECT_API ARotatorFlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARotatorFlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	// Called every frame
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotatorFlatform|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatorFlatform|Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatorFlatform|Properties")
	float RotationSpeed;

	UFUNCTION(BlueprintCallable, Category = "RotatorFlatform|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category = "RotatorFlatform|Properties")
	float GetRotationSpeed() const;

	//UFUNCTION(BlueprintImplementableEvent, Category = "RotatorFlatform|Event")
	//void OnItemPickUp();
};
 