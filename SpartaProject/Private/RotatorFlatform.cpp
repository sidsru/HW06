// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatorFlatform.h"

// Sets default values
ARotatorFlatform::ARotatorFlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; // ƽ�Լ� ���� ����    ƽ���� �Լ��� ����� ���� ���� �����̶�� flase�� ������ ���� �ٶ��� �ϴ�.
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
	//SetActorRotation(FRotator(0.0f, 90.0f, 0.0f)); // pitch(y��), yaw(z��), roll(x ��) ���� ��Ÿ����. �ش� ������ z���� 90�� ������ ���� �ǹ��Ѵ�.
	//�����̼��� ������ �������� FQuat �� �����Ѵ�
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








