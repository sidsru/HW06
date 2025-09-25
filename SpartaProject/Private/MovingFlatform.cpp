// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingFlatform.h"

// Sets default values
AMovingFlatform::AMovingFlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; // 틱함수 관련 선언    

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMesh->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/SkyTown/Meshes/SM_StoneStairs01_2m.SM_StoneStairs01_2m"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
	
	MaxSpeed = 100;
	Leng = 300;
}

void AMovingFlatform::BeginPlay()
{
	Super::BeginPlay();


	StartLocation = GetActorLocation();
	MaxLength = StartLocation + FVector(0, Leng, 0);
}

bool target = false;

void AMovingFlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 시작점과 끝점을 설정한뒤
	// 끝점에 도달시 뒤로 돌아가도록 설정
	// 
	if (!target)
	{
		AddActorLocalOffset(FVector(0.0f, MaxSpeed * DeltaTime, 0.0f));
		if (GetActorLocation().Y >= MaxLength.Y) target = true;
	}
	else
	{
		AddActorLocalOffset(FVector(0.0f, -1 * MaxSpeed * DeltaTime, 0.0f));
		if (GetActorLocation().Y <= StartLocation.Y) target = false;
	}
	
}
