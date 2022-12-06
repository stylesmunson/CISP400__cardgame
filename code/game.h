#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>

#include "CardBase.h"
#include "CardMonster.h"
#include "CardItem.h"


void load_cards(deque<CardBase*>& _deck, Font& _fontCardTitle, Font& _fontCardData, Font& _fontCardDescription)
{
	//MONSTERS
	_deck.emplace_back(new CardMonster("Gary the Vampire", 3, 3, "He used to be Gary the Accountant. Still good at math, just needs blood to survive.", "res/graphics/garyvampire.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Monster Truck", 6, 2, "The truck is alive...  and it's hungry.", "res/graphics/monstertruck1.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Skeleton Lawyer", 3, 1, "Brittle, but vicious in the courtroom", "res/graphics/skeletonlawyer.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Angry Mom", 10, 5, "She's already said your full name twice. You're in for it now.", "res/graphics/angrymom.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Coffee Cup", 2, 1, "Stronger than glass, but will still break if it falls off a table, probably. Hot !", "res/graphics/coffeecup.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Playwright", 3, 6, "Thick skin. Has definitely heard it all before.", "res/graphics/playwright.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Volcano (Nice)", 2, 8, "Pretty sleepy. Watch out for his twin.", "res/graphics/volcanonice.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Volcano (Evil)", 8, 5, "Hot-headed. Sorry.", "res/graphics/volcanoevil.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Rat Pit", 4, 6, "A pit full of rats. Not advised to get in.", "res/graphics/ratpit.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Sandwich", 5, 5, "Has mayo. If we had better mechanics you might be weak to it.", "res/graphics/sandwich.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Hardcore Show Pit", 4, 8, "Nicest people you could meet, but will still mess you up.", "res/graphics/hardcoreshowpit.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Train Conductor", 7, 4, "This guy steers the train. It could go anywhere, but he keeps it on the tracks.", "res/graphics/trainconductor.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Baby", 1, 1, "Will never amount to anything unless it grows up.", "res/graphics/baby.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Goblin Drummer", 2, 2, "How does she reach the kick pedal?", "res/graphics/goblindrummer.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Cool Sun", 9, 9, "Nearly unstoppabe...", "res/graphics/coolsun.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Wizard on Vacation", 2, 2, "Likely not paying attention.", "res/graphics/temp.wizardvacation", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("The World (350 Years Ago)", 9, 6, "It was pretty bad back then.", "res/graphics/world350.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Giant Hand", 5, 1, "Like a normal sized hand, but much bigger.", "res/graphics/gianthand.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Dirty Dishes", 1, 3, "When are you finally gonna get around to doing these?", "res/graphics/dirtydishes.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardMonster("Magic Cockroach", 7, 10, "Unlikely to die. Sort of like a regular cockroach.", "res/graphics/magiccockroach.png", _fontCardTitle, _fontCardData, _fontCardDescription));

	//ITEMS
	_deck.emplace_back(new CardItem("Biscuit", "DEF", 1, "Carbs are more important than you think.", "res/graphics/biscuit.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("Puppy", "PWR", 5, "Woof! (I bestow onto you 5 power points, battler.)", "res/graphics/puppy.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("Iron Stomach", "DEF", 10, "This is what we call Beginner's Luck.", "res/graphics/ironstomache.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("Spinach", "PWR", 3, "Eat your wet, leafy greens.", "res/graphics/spinach.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("Soil", "PWR", 2, "If it's good for plants, it's good for you.", "res/graphics/soil.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("Running Shoes", "DEF", 4, "Become faster than ever for only $12.99 at Walmart.", "res/graphics/runningshoes.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("Grandma's Quilt", "DEF", 6, "RIP to a real one.", "res/graphics/grammaquilt.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("Vacuum Cleaner", "PWR", 5, "It dustn't make you suck.", "res/graphics/vacuum.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("BestBuy 12mo. Warranty", "DEF", 8, "I guess these 60 bucks didn't go to waste after all.", "res/graphics/12months.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("Pandora's Box", "PWR", 9, "Don't ask us where we got this.", "res/graphics/pandorabox.png", _fontCardTitle, _fontCardData, _fontCardDescription));
	_deck.emplace_back(new CardItem("Cardboard's Box", "DEF", 4, "Please ask us where we got this.", "res/graphics/cardboardbox.png", _fontCardTitle, _fontCardData, _fontCardDescription));

}

void fill_tokens(vector<CircleShape>& _p1tokens, vector<CircleShape>& _p2tokens)
{
	for (int i = 0; i < 12; i++)
	{
		_p1tokens.push_back(CircleShape(25, 13));
		_p1tokens.at(i).setOutlineColor(Color::Red);
		_p1tokens.at(i).setOutlineThickness(2);
		_p1tokens.at(i).setFillColor({ 203, 76, 78, 255 });

		_p2tokens.push_back(CircleShape(25, 13));
		_p2tokens.at(i).setOutlineColor(Color::Cyan);
		_p2tokens.at(i).setOutlineThickness(2);
		_p2tokens.at(i).setFillColor({ 84, 175, 190, 255 });
	}
}