// Fill out your copyright notice in the Description page of Project Settings.

#include "FindPatrolPathPoint.h"
#include "NPC_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC.h"
#include "BlackboardKeys.h"

UFindPatrolPathPoint::UFindPatrolPathPoint(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Find Patrol Path Point");
}


EBTNodeResult::Type UFindPatrolPathPoint::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	// get the AI controller for the patrolling	NPC
	ANPC_AIController* const cont = Cast<ANPC_AIController>(owner_comp.GetAIOwner());

	// get the current patrol path index from the blackboard
	int const index = cont->get_blackboard()->GetValueAsInt(bb_keys::patrol_path_index);

	// use the index to get the current patrol path from the NPC's reference to the patrol path 
	ANPC* const npc = Cast<ANPC>(cont->GetPawn());
	FVector const point = npc->get_patrol_path()->get_patrol_point(index);

	// transform this point to a global position using its parent 
	FVector const global_point = npc->get_patrol_path()->GetActorTransform().TransformPosition(point);

	// write the global current path point to the blackboard 
	//cont->get_blackboard()->SetValueAsVector(bb_keys::patrol_path_vector, global_point);
	cont->get_blackboard()->SetValueAsVector(bb_keys::target_location, global_point);

	// finish with success
	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}
