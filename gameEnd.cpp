#include "gameEnd.hpp"

void gameEnd(Player &rj )
{

	/*BAD ENDING*/
	if(rj.getGameEnd() ==1)
	{
		std::cout << "You feel a vise like grip around your neck." << std::endl;
		std::cout << "You struggle to breathe and claw at the tentacles around your neck." << std::endl;
		std::cout << "It is no use fighting, everything goes black." << std::endl;
		std::cout << "When the troops arrive they will be greeted by an individual that looks and sounds like you." << std::endl;
		std::cout << "This individual will be rescued and the troops will slowly be killed and replaced by dopplegangers." << std::endl;
		std::cout << "They will eventually get back stateside and will continue the cycle of death and replacement." << std::endl;
		std::cout << "Within eight months over 90% of the human population of the world has been replaced." << std::endl;
		std::cout << "If you had learned more about the danges of the creature, you wouldn't have asked for assistance." << std::endl;
		std::cout << "You would have asked for fire to rain down on the base and wipe it from the face of the Earth." << std::endl;
	
	return;

	}

	/*GOOD ENDING*/
	if(rj.getGameEnd() ==2)
	{
		std::cout << "Fire rains down from the sky, and you are killed." << std::endl;
		std::cout << "Instead of thinking of your self, you were driven by the desire to save humanity from whatever this Thingy was." << std::endl;
		std::cout << "The Thingy was also killed in the bombing. " <<std::endl;
		std::cout << "And it is because of you and your sacrifice that humanity continues to exist." << std::endl;
		std::cout << "Thanks for playing." << std::endl;
	}

	/*SECRET ENDING*/

	if (rj.getGameEnd() == 3)
	{
		std::cout << "Why does my life suck so hard?" << std::endl;
		std::cout << "Why can't it be like the movies?" << std::endl;
		std::cout << "Or like those old Greek plays with the Deus Ex Machina to guarantee a happy ending?" << std::endl;
		std::cout << "Suddenly your whole field of vision is saturated in bright light." << std::endl;
		std::cout << "After a moment of disorientation, you are dumbfounded to see that you are in a different room!" << std::endl;
		std::cout << "The floor is white linoleum." << std::endl;
		std::cout << "Fluorescent lights hum above your head." << std::endl;
		std::cout << "It looks like you have been transported to an office." << std::endl;
		std::cout << "Three guys appear before you." << std::endl;
		std::cout << "They are dressed in business casual attire." << std::endl;
		std::cout << "Each one is wearing a polo shirt and khakis." << std::endl;
		std::cout << "One is dressed in a green polo, the second is dressed in a yellow polo, and the third in a purple polo." << std::endl;
		std::cout << "You try to ask them what is happening, but you feel yourself unable to talk or move." << std::endl;
		std::cout << "'Don't worry, this is not an alien abduction,' the guy in purple polo says." << std::endl;
		std::cout << "'We are the engineers of this game,' the guy in the yellow polo says." << std::endl;
		std::cout << "You have no undrestanding of what is going on or what they are talking about." << std::endl;
		std::cout << "'Let's just cut to the chase,' the guy in the green polo says." << std::endl;
		std::cout << "'Yeah, we got a deadline,' the guy in the yellow shirt says." << std::endl;
		std::cout << "'Okay, okay,' the guy in the purple polo says." << std::endl;
		std::cout << "'You found the secret ending in the game,' the guy in the purple polo says." << std::endl;
		std::cout << "'That means this alien creature gets wiped from existence,' the guy in the yellow polo says." << std::endl;
		std::cout << "'And everyone in the base is restored back to life with no traumatic memories of what occurred,' the guy in the green polo shirt says." << std::endl;
		std::cout << "'Since we are feeling generous, we'll repair all the damage you have done to your liver through years of drinking,' the guy in the yellow shirt says." << std::endl;
		std::cout <<"'It's like you have the liver of an 18 year old,' the guy in the purple says." << std::endl;

		std::cout << "You wake up in your quarters." << std::endl;
		std::cout << "Your head is killing you from last night's drinking exploits." << std::endl;
		std::cout << "What a very bizarre dream you had there." << std::endl;
		std::cout << "You grab an unfinished bottle of beer from the nightstand and take a few swigs." << std::endl;
		std::cout << "It looks like it is going to be another boring and routine day on the base." << std::endl;
		std::cout << "But you welcome that over all the disturbing stuff you dreamed about." << std::endl;
		


	}




}



