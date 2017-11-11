#include <Arduino.h>
#include <Morse.h>

Morse::Morse() {
}

Morse::~Morse() {

}

char Morse::getLettre(int lettre) {

	switch ( lettre ) {
	case 6:
	  lettreTraduite = 'a';
	  break;
	case 23:
	  lettreTraduite = 'b';
	  break;
	case 21:
	  lettreTraduite = 'c';
	  break;
	case 11:
	  lettreTraduite = 'd';
	  break;
	case 3:
	  lettreTraduite = 'e';
	  break;
	case 29:
	  lettreTraduite = 'f';
	  break;
	case 9:
	  lettreTraduite = 'g';
	  break;
	case 31:
	  lettreTraduite = 'h';
	  break;
	case 7:
	  lettreTraduite = 'i';
	  break;
	case 24:
	  lettreTraduite = 'j';
	  break;
	case 10:
	  lettreTraduite = 'k';
	  break;
	case 27:
	  lettreTraduite = 'l';
	  break;
	case 4:
	  lettreTraduite = 'm';
	  break;
	case 5:
	  lettreTraduite = 'n';
	  break;
	case 8:
	  lettreTraduite = 'o';
	  break;
	case 25:
	  lettreTraduite = 'p';
	  break;
	case 18:
	  lettreTraduite = 'q';
	  break;
	case 13:
	  lettreTraduite = 'r';
	  break;
	case 15:
	  lettreTraduite = 's';
	  break;
	case 2:
	  lettreTraduite = 't';
	  break;
	case 14:
	  lettreTraduite = 'u';
	  break;
	case 30:
	  lettreTraduite = 'v';
	  break;
	case 12:
	  lettreTraduite = 'w';
	  break;
	case 22:
	  lettreTraduite = 'x';
	  break;
	case 20:
	  lettreTraduite = 'y';
	  break;
	case 19:
	  lettreTraduite = 'z';
	  break;
	case 48:
	  lettreTraduite = '1';
	  break;
	case 56:
	  lettreTraduite = '2';
	  break;
	case 60:
	  lettreTraduite = '3';
	  break;
	case 62:
	  lettreTraduite = '4';
	  break;
	case 63:
	  lettreTraduite = '5';
	  break;
	case 47:
	  lettreTraduite = '6';
	  break;
	case 39:
	  lettreTraduite = '7';
	  break;
	case 35:
	  lettreTraduite = '8';
	  break;
	case 33:
	  lettreTraduite = '9';
	  break;
	case 32:
	  lettreTraduite = '0';
	  break;
	default:
	  lettreTraduite = '-';
	  break;
	}

	return lettreTraduite;
}