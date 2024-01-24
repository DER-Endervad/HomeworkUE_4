// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UCLASS()
class HOMEWORKUE_4_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector InitialLocation;
	UWorld* world;
	float my_time = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SinMovement();

	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere);
	float Frequency = 4.0;

	UPROPERTY(EditAnywhere);
	float Amplitude = 1;
};
