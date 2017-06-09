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
	Owner = GetOwner();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		//  if the ActorThatOpens is in the volune
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds(); // 
	}

	//Check if time's door opening reach Door Close Delay
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
		CloseDoor();
	}
		
	
	
}

void UOpenDoor::OpenDoor() {
	// Find the owning Actor
	//AActor* Owner = GetOwner();
	// Create a rotation
	//FRotator NewRotation = FRotator(0.0f, 50.f, 0.0f);
	
	// Set the door Rotation
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
	UE_LOG(LogTemp, Warning, TEXT("Rotation Set to %s"), *Owner->GetActorRotation().ToString());
	/*FRotator Owner = GetOwner()->GetActorRotation();
	GetOwner()->SetActorRotation(FQuat(Owner.Roll, Owner.Pitch, Owner.Yaw + 10,0),ETeleportType::None);*/
}

void UOpenDoor::CloseDoor() {


	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));

	UE_LOG(LogTemp, Warning, TEXT("Close Door Rot : %s"), *Owner->GetActorRotation().ToString());

}

