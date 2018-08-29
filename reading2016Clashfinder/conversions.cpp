#include "stdafx.h"


int convertToMinutes(int hhmm, int day) {
	int hh = hhmm / 100;
	int mm = hhmm % 100;
	int minutes = hh * 60 + mm + day * 24 * 60;
	return minutes;
}

int convertToHhmm(int seconds, int day) {
	seconds = seconds - (day * 24 * 60 * 60);
	int hh = seconds / 60 / 60;
	seconds -= hh * 60 * 60;
	int mm = seconds / 60;
	int hhmm = (hh * 100) + mm;
	return hhmm;
}