// Fill out your copyright notice in the Description page of Project Settings.


#include "NinjaMover.h"

#include "Physics/ImmediatePhysics/ImmediatePhysicsShared/ImmediatePhysicsCore.h"

// Sets default values for this component's properties
UNinjaMover::UNinjaMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	// ...
}


// Called when the game starts
void UNinjaMover::BeginPlay()
{
	Super::BeginPlay();

	MeshComponent = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &UNinjaMover::BeginOverlap);
	
}


// Called every frame
void UNinjaMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (GetOwner()->IsOverlappingActor(Floor))
	{
		UE_LOG(LogTemp, Warning, TEXT("NinjaMover Overlap"));
	}
}

void UNinjaMover::BeginOverlap(
	UPrimitiveComponent* OverlappedComponent, 
    AActor* OtherActor, 
    UPrimitiveComponent* OtherComp, 
    int32 OtherBodyIndex, 
    bool bFromSweep, 
    const FHitResult &SweepResult )
{
	UE_LOG(LogTemp, Warning, TEXT("NinjaMover Overlap"));
	MeshComponent->AddForce(FVector(0.f, 0.f, 1000.f));
}