#ifndef BANDLIST_H
#define BANDLIST_H

#include "stdafx.h"
#include <string>

//Stages

enum Stage {
	STAGE_MAIN,
	STAGE_NME,
	STAGE_DANCE,
	STAGE_PIT,
	STAGE_FESTIVALREPUBLIC,
	STAGE_ONEEXTRA,
	STAGE_INTRODUCING,
	STAGE_ALTERNATIVE,
	STAGE_JAGERHAUS
};

struct Band {
	std::string bandName;
	Stage stage;
	int inputStartTime;       //Start and End times as 4 digit numbers representing hhmm
	int inputEndTime;
	int day;                  //Day as an integer, 0 = Friday, 1 = Saturday, 2 = Sunday
	int16_t startTime;        //Final start and end times are number of minutes since 00:00 Friday. 
							  //Conversion function will create these for each selected band (so they don't have to be computated for every single band!)
	int16_t endTime;
};

//Friday Main Stage

const Band foals{ "Foals", STAGE_MAIN, 2215, 2330, 0 };     //Format {Name, Stage, Start Time, End Time, Day}
const Band disclosure{ "Disclosure", STAGE_MAIN, 2020, 2135, 0 };
const Band chvrches{ "Chvrches", STAGE_MAIN, 1900, 1945, 0 };
const Band boyBetterKnow{ "Boy Better Know",STAGE_MAIN, 1745, 1830, 0 };
const Band dieAntwoord{ "Die Antwoord", STAGE_MAIN, 1625, 1715, 0 };
const Band lowerThanAtlantis{ "Lower Than Atlantis", STAGE_MAIN, 1515, 1555, 0 };
const Band nothingButThieves{ "Nothing But Thieves", STAGE_MAIN, 1415, 1450, 0 };
const Band frankCarter{ "Frank Carter", STAGE_MAIN, 1315, 1350, 0 };
const Band frankTurner{ "Frank Turner", STAGE_MAIN, 1200, 1250, 0 };

//Saturday Main Stage

const Band sundaraKarma{ "Sundara Karma", STAGE_MAIN, 1200, 1230, 1 };
const Band clutch{ "Clutch", STAGE_MAIN, 1255, 1330, 1 };
const Band skindred{ "Skindred", STAGE_MAIN, 1355, 1430, 1 };
const Band parkwayDrive{ "Parkway Drive", STAGE_MAIN, 1500, 1540, 1 };
const Band slaves{ "Slaves", STAGE_MAIN, 1610, 1650, 1 };
const Band eodm{ "Eagles of Death Metal", STAGE_MAIN, 1720, 1800, 1 };
const Band courteeners{ "Courteeners", STAGE_MAIN, 1830, 1915, 1 };
const Band imagineDragons{ "Imagine Dragons", STAGE_MAIN, 1950, 2050, 1 };
const Band rhcp{ "Red Hot Chili Peppers", STAGE_MAIN, 2130, 2330, 1 };

//Sunday Main Stage

const Band stateChamps{ "State Champs", STAGE_MAIN, 1200, 1230, 2 };
const Band theVirginmarys{ "The Virginmarys", STAGE_MAIN, 1250, 1320, 2 };
const Band coheedAndCambira{ "Coheed and Cambria", STAGE_MAIN, 1340, 1415, 2 };
const Band sleepingWithSirens{ "Sleeping With Sirens", STAGE_MAIN, 1440, 1520, 2 };
const Band fiveFingerDeathPunch{ "Five Finger Death Punch", STAGE_MAIN, 1545, 1645, 2 };
const Band asapRocky{ "ASAP Rocky", STAGE_MAIN, 1715, 1750, 2 };
const Band violaBeachTribute{ "Viola Beach Tribute", STAGE_MAIN, 1800, 1815, 2 };
const Band vaccines{ "The Vaccines", STAGE_MAIN, 1830, 1925, 2 };
const Band fallOutBoy{ "Fall Out Boy", STAGE_MAIN, 2000, 2115, 2 };
const Band biffyClyro{ "Biffy Clyro", STAGE_MAIN, 2200, 1330, 2 };

//Friday NME Stage

const Band jackU{ "Jack U", STAGE_NME, 2215, 2330, 0 };
const Band twentOnePilots{ "Twenty One Pilots", STAGE_NME, 2050, 2140, 0 };
const Band crystalCastles{ "Crystal Castles", STAGE_NME, 1935, 2020, 0 };
const Band neighbourhood{ "The Neighbourhood", STAGE_NME, 1825, 1905, 0 };
const Band internet{ "The Internet", STAGE_NME, 1720, 1755, 0 };
const Band giggs{ "Giggs", STAGE_NME, 1620, 1650, 0 };
const Band muraMasa{ "Mura Masa", STAGE_NME, 1520, 1550, 0 };
const Band hinds{ "Hinds", STAGE_NME, 1425, 1455, 0 };
const Band haelos{ "Haelos", STAGE_NME, 1330, 1400, 0 };
const Band fickleFriends{ "Fickle Friends", STAGE_NME, 1235, 1305, 0 };

//Saturday NME Stage

const Band fatherson{ "Fatherson", STAGE_NME, 1200, 1230, 1 };
const Band sunsetSons{ "Sunset Sons", STAGE_NME, 1250, 1320, 1 };
const Band highlySuspect{ "Highly Suspect", STAGE_NME, 1340, 1410, 1 };
const Band whitney{ "Whitney", STAGE_NME, 1430, 1500, 1 };
const Band blossoms{ "Blossoms", STAGE_NME, 1520, 1550, 1 };
const Band netsky{ "Netsky", STAGE_NME, 1610, 1650, 1 };
const Band sigma{ "Sigma", STAGE_NME, 1720, 1800, 1 };
const Band jackGarratt{ "Jack Garratt", STAGE_NME, 1830, 1910, 1 };
const Band kreptAndKonan{ "Krept & Konan", STAGE_NME, 1940, 2025, 1 };
const Band nas{ "NAS", STAGE_NME, 2100, 2150, 1 };
const Band twoDoorCinemaClub{ "Two Door Cinema Club", STAGE_NME, 2230, 2330, 1 };

//Sunday NME Stage

const Band blackFoxxes{ "Black Foxxes", STAGE_NME, 1200, 1230, 2 };
const Band basement{ "Basement", STAGE_NME, 1250, 1320, 2 };
const Band springKing{ "Spring King", STAGE_NME, 1340, 1410, 2 };
const Band deafHavana{ "Deaf Havana", STAGE_NME, 1430, 1500, 2 };
const Band tonightAlive{ "Tonight Alive", STAGE_NME, 1520, 1550, 2 };
const Band halfMoonRun{ "Half Moon Run", STAGE_NME, 1610, 1650, 2 };
const Band ratBoy{ "Rat Boy", STAGE_NME, 1720, 1800, 2 };
const Band savages{ "Savages", STAGE_NME, 1830, 1910, 2 };
const Band cageTheElephant{ "Cage The Elephant", STAGE_NME, 1940, 2025, 2 };
const Band theWombats{ "The Wombats", STAGE_NME, 2100, 2150, 2 };
const Band the1975{ "The 1975", STAGE_NME, 2230, 2330, 2 };

//Friday Dance Stage

const Band draper{ "Draper", STAGE_DANCE, 1250, 1320, 0 };
const Band hermitud{ "Hermitud", STAGE_DANCE, 1340, 1410, 0 };
const Band ninetyNineSouls{ "99 Souls", STAGE_DANCE, 1425, 1510, 0 };
const Band lionBabe{ "Lion Babe", STAGE_DANCE, 1535, 1610, 0 };
const Band tkayMaidza{ "Tkay Maidza", STAGE_DANCE, 1635, 1715, 0 };
const Band dannyLHarle{ "Danny L Harle", STAGE_DANCE, 1730, 1814, 0 };
const Band philipGeorge{ "Philip George", STAGE_DANCE, 1820, 1905, 0 };
const Band alunaGeorge{ "Alunageorge", STAGE_DANCE, 1935, 2020, 0 };
const Band hannahWants{ "Hannah Wants", STAGE_DANCE, 2050, 2150 };
const Band oliverHeldens{ "Oliver Heldens", STAGE_DANCE, 2200, 2330 };

//Friday Pit

const Band swmrs{ "SWMRS", STAGE_PIT, 1215, 1245, 0 };
const Band trashBoat{ "Trash Boat", STAGE_PIT, 1305, 1335, 0 };
const Band creeper{ "Creeper", STAGE_PIT, 1355, 1425, 0 };
const Band superheaven{ "Superheaven", STAGE_PIT, 1445, 1520, 0 };
const Band citizen{ "Citizen", STAGE_PIT, 1540, 1615, 0 };
const Band dinosaurPileUp{ "Dinosaur Pile Up", STAGE_PIT, 1635, 1710, 0 };
const Band nothingMore{ "Nothing More", STAGE_PIT, 1730, 1810, 0 };
const Band hacktivist{ "Hacktivist", STAGE_PIT, 1830, 1910, 0 };
const Band crossfaith{ "Crossfaith", STAGE_PIT, 1940, 2025, 0 };
const Band thrice{ "Thrice", STAGE_PIT, 2100, 2150, 0 };
const Band askingAlexandria{ "Asking Alexandria", STAGE_PIT, 2230, 2330, 0 };

//Friday Festival Republic

const Band area52{ "Area 52", STAGE_FESTIVALREPUBLIC, 1200, 1230, 0 };
const Band whiteMiles{ "White Miles", STAGE_FESTIVALREPUBLIC, 1245, 1315, 0 };
const Band banners{ "Banners", STAGE_FESTIVALREPUBLIC, 1335, 1405, 0 };
const Band transviolet{ "Transviolet", STAGE_FESTIVALREPUBLIC, 1425, 1455, 0 };
const Band anteros{ "Anteros", STAGE_FESTIVALREPUBLIC, 1515, 1545, 0 };
const Band otherkin{ "Otherkin", STAGE_FESTIVALREPUBLIC, 1600, 1635, 0 };
const Band lewisDelMar{ "Lewis Del Mar", STAGE_FESTIVALREPUBLIC, 1655, 1725, 0 };
const Band theSherlocks{ "The Sherlocks", STAGE_FESTIVALREPUBLIC, 1745, 1815, 0 };
const Band blaenavon{ "Blaenavon", STAGE_FESTIVALREPUBLIC, 1835, 1905, 0 };
const Band luh{ "Luh", STAGE_FESTIVALREPUBLIC, 1925, 2000, 0 };
const Band rationale{ "Rationale", STAGE_FESTIVALREPUBLIC, 2020, 2100, 0 };
const Band pulledApartByHorses{ "Pulled Apart By Horses", STAGE_FESTIVALREPUBLIC, 2120, 2200, 0 };
const Band maximoPark{ "Maximo Park", STAGE_FESTIVALREPUBLIC, 2230, 2300, 0 };

//Friday 1Extra

const Band kFlay{ "K Flay", STAGE_ONEEXTRA, 1215, 1245, 0 };
const Band geko{ "Geko", STAGE_ONEEXTRA, 1305, 1335, 0 };
const Band ladyLeshurr{ "Lady Leshurr", STAGE_ONEEXTRA, 1355, 1425, 0 };
const Band mickJenkins{ "Mick Jenkins", STAGE_ONEEXTRA, 1445, 1515, 0 };
const Band troyboi{ "Troyboi", STAGE_ONEEXTRA, 1535, 1620, 0 };
const Band baauer{ "Baauer", STAGE_ONEEXTRA, 1640, 1740, 0 };
const Band charlieSloth{ "Charlie Sloth", STAGE_ONEEXTRA, 1805, 1850, 0 };
const Band maverickSabre{ "Maverick Sabre", STAGE_ONEEXTRA, 1915, 1950, 0 };
const Band littleSimz{ "LittleSimz", STAGE_ONEEXTRA, 2020, 2100, 0 };
const Band protoje{ "Protoje", STAGE_ONEEXTRA, 2130, 2215, 0 };
const Band wiley{ "Wiley", STAGE_ONEEXTRA, 2245, 2330, 0 };

//Friday Introducing

const Band dusk{ "Dusk", STAGE_INTRODUCING, 1110, 1135, 0 };
const Band fauxPas{ "Faux Pas", STAGE_INTRODUCING, 1150, 1215, 0 };
const Band jordanAllen{ "Jordan Allen", STAGE_INTRODUCING, 1230, 1255, 0 };
const Band strongAsianMothers{ "Strong Asian Mothers", STAGE_INTRODUCING, 1310, 1335, 0 };
const Band theWholls{ "The Wholls", STAGE_INTRODUCING, 1350, 1415, 0 };
const Band eatFast{ "Eat Fast", STAGE_INTRODUCING, 1530, 1555, 0 };
const Band happyAccidents{ "Happy Accidents", STAGE_INTRODUCING, 1615, 1640, 0 };
const Band airways{ "Airways", STAGE_INTRODUCING, 1700, 1725, 0 };
const Band parisYouthFoundation{ "Paris Youth Foundation", STAGE_INTRODUCING, 1745, 1810, 0 };
const Band muncieGirls{ "Muncie Girls", STAGE_INTRODUCING, 1830, 1855, 0 };
const Band beau{ "Beau", STAGE_INTRODUCING, 1915, 1940, 0 };
const Band coquinMigale{ "Coquin Migale", STAGE_INTRODUCING, 2000, 2025, 0 };

//Friday Alternative

const Band ianBoldsworth{ "Ian Boldsworth", STAGE_ALTERNATIVE, 1200, 1215, 0 };
const Band alPorter{ "Al Porter", STAGE_ALTERNATIVE, 1215, 1245, 0 };
const Band markSteel{ "Mark Steel", STAGE_ALTERNATIVE, 1245, 1330, 0 };
const Band lloydGriffith{ "Lloyd Griffith", STAGE_ALTERNATIVE, 1330, 1400, 0 };
const Band leeNelson{ "Lee Nelson", STAGE_ALTERNATIVE, 1400, 1440, 0 };
const Band johnRobins{ "John Robins", STAGE_ALTERNATIVE, 1450, 1520, 0 };
const Band angelaBarnes{ "Angela Barnes", STAGE_ALTERNATIVE, 1520, 1550, 0 };
const Band saraPascoe{ "Sara Pascoe", STAGE_ALTERNATIVE, 1550, 1630, 0 };
const Band russelHoward{ "Russel Howard", STAGE_ALTERNATIVE, 1635, 1715, 0 };

//Friday Jagerhaus

const Band theAcademic{ "The Academic", STAGE_JAGERHAUS, 1400, 1430, 0 };
const Band waco{ "Waco", STAGE_JAGERHAUS, 1500, 1530, 0 };
const Band getInuit{ "Get Inuit", STAGE_JAGERHAUS, 1600, 1630, 0 };
const Band demobHappy{ "Demob Happy", STAGE_JAGERHAUS, 1700, 1730, 0 };
const Band gnarwolves{ "Gnarwolves", STAGE_JAGERHAUS, 1815, 1900, 0 };

#endif