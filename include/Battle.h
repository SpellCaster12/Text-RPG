#pragma once

#include <vector>

#include "Dialogue.h"

class Creature;

// Possible event types, should equate to what the player can do in a battle
enum class BattleEventType { ATTACK, DEFEND };

class BattleEvent
{
public:

	// Creature that initiated the event, e.g. the attacker
	Creature* source;

	// Creature being affected, e.g. the one being attacked
	Creature* target;

	// Type of event, e.g. attack, or defense
	BattleEventType type;

	// Constructor
	BattleEvent(Creature* source, Creature* target, BattleEventType type);

	// Convert the event type to the corresponding function and call it on the source and target
	int run();
};

class Battle
{
private:

	// All the creatures that are participating in the fight. We assume the player is a Creature with id "player".
	std::vector<Creature*> combatants;

	// Actions that the player can take in the battle
	Dialogue battleOptions;

	// Remove a creature from the combatants list, and report that it's dead
	void kill(Creature* creature);

	// Run the next turn for the enemies and the player.
	void nextTurn();

public:

	// Constructor
	Battle(std::vector<Creature*>& combatants);

	// Run the battle until either the player dies, or all the opposing combatants do
	void run();
};