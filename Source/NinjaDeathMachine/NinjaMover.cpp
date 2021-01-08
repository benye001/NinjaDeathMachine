// Fill out your copyright notice in the Description page of Project Settings.


#include "NinjaMover.h"
#include "Kismet/GameplayStatics.h"
#include <activation.h>



#include "DrawDebugHelpers.h"
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
	MeshComponent->OnComponentHit.AddDynamic(this, &UNinjaMover::OnComponentHit);

	MeshComponent->AddForce(FVector(BounceStrength, 0.f, 0.f));
}


// Called every frame
void UNinjaMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UNinjaMover::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if((OtherActor != NULL) &&  (OtherComp != NULL) )
	{
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,5.f, FColor::Green,FString::Printf(TEXT("I just hit something")));
		}
		const FVector BounceForce = Hit.ImpactNormal * BounceStrength;
		MeshComponent->AddForce(FVector(BounceForce.X, 0.f, BounceForce.Z));
	}
}