// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatorFlatform.h"

// Sets default values
ARotatorFlatform::ARotatorFlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; // 틱함수 관련 선언    틱관련 함수를 사용을 하지 않을 예정이라면 flase로 꺼놓는 것이 바람직 하다.
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));

	SetRootComponent(SceneRoot);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMesh->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/SkyTown/Meshes/SM_StoneStairs01_2m.SM_StoneStairs01_2m"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
	RotationSpeed = 90.0f;

}

// Called when the game starts or when spawned
void ARotatorFlatform::BeginPlay()
{
	Super::BeginPlay();
	
	//SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	//SetActorRotation(FRotator(0.0f, 90.0f, 0.0f)); // pitch(y값), yaw(z값), roll(x 값) 값을 나타낸다. 해당 구문은 z값을 90도 돌리는 것을 의미한다.
	//로테이션의 단점을 보완해줄 FQuat 가 존재한다
	SetActorScale3D(FVector(2.0f));

	//OnItemPickUp();
}

// Called every frame
void ARotatorFlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	
}

void ARotatorFlatform::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);
}

float ARotatorFlatform::GetRotationSpeed() const
{
	return RotationSpeed;
}








