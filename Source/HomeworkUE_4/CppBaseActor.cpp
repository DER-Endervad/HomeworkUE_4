// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation[0] = -50;
	InitialLocation[1] = 250;
	InitialLocation[2] = 50;
	SetActorLocation(InitialLocation);
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::SinMovement() {
	world = GetWorld();
	if (world)
	{
		my_time = world->GetTimeSeconds();
	}
	InitialLocation[2] = Amplitude * FMath::FastAsin(Frequency * my_time) + InitialLocation[2];
	if (InitialLocation[2] > 300)
	{
		InitialLocation[2] = 50;
	}
	SetActorLocation(InitialLocation);
}

