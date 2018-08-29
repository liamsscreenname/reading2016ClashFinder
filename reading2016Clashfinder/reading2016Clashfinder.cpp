#include "stdafx.h"
#include "bandList.h"

std::vector<Band> initialiseArray(){
	std::vector<Band> bandListTemp {foals, disclosure, chvrches, boyBetterKnow, dieAntwoord, lowerThanAtlantis, nothingButThieves,
	frankCarter, frankTurner, jackU, twentOnePilots, crystalCastles, neighbourhood, internet, giggs, muraMasa, hinds, haelos, fickleFriends, oliverHeldens, hannahWants,
	alunaGeorge, dannyLHarle, tkayMaidza, lionBabe, ninetyNineSouls, hermitud, draper, askingAlexandria, thrice, crossfaith, hacktivist, nothingMore, dinosaurPileUp,
	citizen, superheaven, creeper, trashBoat, swmrs, maximoPark, pulledApartByHorses, rationale, luh, blaenavon, theSherlocks, lewisDelMar, otherkin, anteros, transviolet, banners,
	whiteMiles, area52, wiley, protoje, littleSimz, maverickSabre, charlieSloth, baauer, troyboi, mickJenkins, ladyLeshurr, geko, kFlay, coquinMigale, beau, muncieGirls, parisYouthFoundation,
	airways, happyAccidents, eatFast, theWholls, strongAsianMothers, jordanAllen, fauxPas, dusk, russelHoward, leeNelson, saraPascoe, markSteel, johnRobins, alPorter, angelaBarnes, lloydGriffith,
	ianBoldsworth, gnarwolves, hinds, demobHappy, getInuit, waco, theAcademic, rhcp, biffyClyro};
	return bandListTemp;
}

void sortVector(std::vector<Band> &bandList, int size) {          //Alphabetically sort band name vector
	for (int startIndex = 0; startIndex < size; ++startIndex) {
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex) {
			if (bandList[currentIndex].bandName < bandList[smallestIndex].bandName)
				smallestIndex = currentIndex;
		}
		std::swap(bandList[startIndex], bandList[smallestIndex]);
	}
}

void sortVectorByStartTime(std::vector<const Band*> &userBands, int size) {        //Sort user bands by start time
	for (int startIndex = 0; startIndex < size; ++startIndex) {
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex) {
			if (userBands[currentIndex]->startTime < userBands[smallestIndex]->startTime)
				smallestIndex = currentIndex;
		}
		std::swap(userBands[startIndex], userBands[smallestIndex]);
	}
}

int binarySearch(std::string target, std::vector<Band>&bandList) {        //Binary search function
	int min = 0;
	int max = bandList.size() -1;
	while (min <= max) {
		int midpoint = (min + max) / 2;
		if (bandList[midpoint].bandName > target) {
			max = midpoint - 1;
		}
		else if (bandList[midpoint].bandName < target) {
			min = midpoint + 1;
		}
		else
			return midpoint;
	}
	return -1;
}

bool checkMatchAndPush(std::string input, std::vector<Band> &bandList, std::vector<const Band*> &userBands) {
	int index = binarySearch(input, bandList);    //Perform binary search for user's input in band list, and return the index if it's there, and -1 if it's not.
	if (index != -1) {
		userBands.push_back(&bandList[index]);       //Push the address of the matching band into the next space in the vector of pointers
		bandList[index].startTime = convertToMinutes(bandList[index].inputStartTime, bandList[index].day);
		bandList[index].endTime = convertToMinutes(bandList[index].inputEndTime, bandList[index].day);          //Convert start and end times for use with clashfinder
		return true;
	}
	else return false;   //If band name not found, -1 returned and this function will return "false"
}

void userInput(std::vector<Band> &bandList, std::vector<const Band*> &userBands) {
	std::string input{ "NULL" };
	int bandNum{ 1 };
	std::cout << "Enter the bands you want to see, one by one, hitting enter after each entry. Type \"done\" when you're finished." << std::endl;
	while (1) {
		std::cout << "Band #" << bandNum << ": ";
		std::getline(std::cin, input);
		if (input == "done" || input == "Done")
			break;
		else {
			bool matchFound = checkMatchAndPush(input, bandList, userBands);
			while (!matchFound) {
				std::cout << "That band name's not recognised, please try again!: ";
				std::getline(std::cin, input);
				matchFound = checkMatchAndPush(input, bandList, userBands);
			}
			++bandNum;
		}
	}
}

bool removeClash(std::vector<const Band*> &userBands, int index1, int index2) {
	std::cout << userBands[index1]->bandName << " and " << userBands[index2]->bandName << " clash! Please enter one to remove:";
	std::string input;
	while (1) {
		std::getline(std::cin, input);
		if (input == userBands[index1]->bandName) {
			userBands.erase(userBands.begin() + index1);
			return true;
		}
		else if (input == userBands[index2]->bandName) {
			userBands.erase(userBands.begin() + index2);
			return false;
		}
		else
			std::cout << "Name not recognised, please try again: ";
	}
}

void clashFinder(std::vector<const Band*> &userBands, int size) {
	for (int startIndex = 0; startIndex < size; ++startIndex) {
		for (int currentIndex = startIndex+1; currentIndex < startIndex + 8 && currentIndex < size; ++currentIndex) {    //There are 9 stages, so one band can only possibly clash with 8 others
			if (userBands[startIndex]->bandName == userBands[currentIndex]->bandName) {         //Remove duplicates
				userBands.erase(userBands.begin() + currentIndex);
				size -= 1;
				currentIndex -= 1;
			}
			else if (userBands[startIndex]->startTime < userBands[currentIndex]->endTime && userBands[startIndex]->endTime > userBands[currentIndex]->startTime) {
				bool currentIndexRemoved = removeClash(userBands, currentIndex, startIndex);
				size -= 1;            //Size of vector will be reduced by one
				if (currentIndexRemoved)
					currentIndex -= 1;
				else
					startIndex -= 1;
			}
		}
	}
}

void printStage(const Band* band) {
	switch (band->stage) {
		case 0: std::cout << "Main Stage";
			break;
		case 1: std::cout << "NME Stage";
			break;
		case 2: std::cout << "Dance Stage";
			break;
		case 3: if (band->day == 2) {
					std::cout << "The Pit";
					break;
				}
				else {
					std::cout << "Lock Up Stage";
					break;
				}
		case 4: std::cout << "Festival Republic Stage";
			break;
		case 5: std::cout << "One Extra Stage";
			break;
		case 6: std::cout << "BBC Introducing Stage";
			break;
		case 7: std::cout << "Alternative Stage";
			break;
		case 8: std::cout << "Jagerhaus Stage";
			break;			
	}
}


int main() {
	std::vector<Band> bandList = initialiseArray();                  //Create vector of bands.
	sortVector(bandList, bandList.size());                           //Sort vector in order for binary search to work.
	std::vector<const Band*> userBands;                             //Create vector of pointers to the bands in "bandList" which user has selected.
	userBands.reserve(50);                                          //User band list has a capacity of at least 50.
	userInput(bandList, userBands);
	sortVectorByStartTime(userBands, userBands.size());
	std::cout << '\n';
	clashFinder(userBands, userBands.size());
	std::cout << '\n' << "Here is your personalised Reading 2016 timetable!:" << std::endl;
	int firstBandOfDay = 0;   // This is to carry on from the next index once the loop is broken by a change of day
	for (int dayi = 0; dayi < 3; dayi++) {
		switch (dayi) {
			case 0: std::cout << '\n' << "Friday August 26th" << '\n' << std::endl;
				break;
			case 1: std::cout << '\n' << "Saturday August 27th" << '\n' << std::endl;
				break;
			case 2: std::cout << '\n' << "Sunday August 28th" << '\n' << std::endl;
				break;
		}
		for (int i = firstBandOfDay; i < userBands.size(); ++i) {
			if (userBands[i]->day == dayi) {
				std::cout << userBands[i]->bandName << " - ";
				printStage(userBands[i]);
				std::cout << " - " << userBands[i]->inputStartTime / 100 << ':' << std::setfill('0') << std::setw(2) << userBands[i]->inputStartTime % 100
					<< " to " << userBands[i]->inputEndTime / 100 << ':' << std::setfill('0') << std::setw(2) << userBands[i]->inputEndTime % 100 << std::endl;
			}
			else {
				firstBandOfDay = i;
				break;
			}
		}
	}
	std::cout << '\n' << std::endl;
	return 0;
}

