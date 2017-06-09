// Copyright 2017 Tossaporn Ketkwanchai

#include "OpenDoor.h"
#include "Engine.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// Find the owning Actor
	AActor* Owner = GetOwner();
	// Create a rotation
	FRotator NewRotation = FRotator(0.0f,50.f,0.0f);
	// Set the door Rotation
	Owner->SetActorRotation(NewRotation);
	/*FRotator Owner = GetOwner()->GetActorRotation();
	GetOwner()->SetActorRotation(FQuat(Owner.Roll, Owner.Pitch, Owner.Yaw + 10,0),ETeleportType::None);
	
	UE_LOG(LogTemp, Warning, TEXT("Rotation Set to %s"), *Owner.ToString());*/
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

