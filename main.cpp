/*----------------------------------------------------------
 * Program 2: Cuatro
 *
 * Class: CS 141, Spring 2020. Tue 4pm lab
 * System: CLion on Windows 10 & CLion on Mac
 * Author: Shawn Klein
 *
 * NOTE: To the users browsing my repo, this
 * project was built following the constraints
 * listed below:
 * 2) The board must be displayed and manipulated
 * by using 16 separate variables representing the
 * 16 locations on the board.
 * 3) You may store potential characters remaining
 * to be played ("OO/CC  II/ZZ" and "oo/cc  ii/zz")
 * in one or more C++ strings.
 * 4) You may not use arrays or vectors or C++ string
 * variables anywhere in your program besides what
 * has been specifically described above.
 * ---------------------------------------------------------
 */
#include <iostream>
#include <string>

using namespace std;

// these are my global variables
const string constCurlies = "oOcC";
const string constStraights = "iIzZ";
const string constConsts = "cCzZ";
const string constVowel = "oOiI";
const string constUpper = "OCIZ";
const string constLower = "ociz";

string avlTkns = "OOCCIIZZoocciizz";
bool activeGame = true;

char b1 = '.',  b2 = '.',  b3 = '.',  b4 = '.',  b5 = '.',  b6 = '.',  b7 = '.',  b8 = '.';
char b9 = '.', b10 = '.', b11 = '.', b12 = '.', b13 = '.', b14 = '.', b15 = '.', b16 = '.';

void displayInstructions() {
    cout << "Welcome to the game of Cuatro, where you try to complete a set      \n"
         << "of four pieces that are alike.  Players take turns making moves.    \n"
         << "On each move your OPPONENT chooses the piece, then YOU get to       \n"
         << "place it on the board.  If you create a set of four alike when      \n"
         << "you place your piece, then you win!       \n"
         << "\n"
         << "A set of four alike can be completed by using four all upper (or all\n"
         << "lower) case characters, four all vowels (or all consonants), or four\n"
         << "all curved (or all straight-lined). Curved letters are 'O' and 'C'\n"
         << "(upper or lower), and straight-line letters are 'I' and 'Z' (upper or\n"
         << "lower). Groups of four can be created in a row, column, diagonal, or\n"
         << "corner quadrant.\n"
         << "\n"
         << "When prompted for input you may also enter 'x' or 'X' to exit." << endl;
}

void displayBoard() {
    cout << "       ---------    Square #\n      | "
         << b1  << ' ' << b2  << ' ' << b3  << ' ' << b4  << " |  1  2  3  4\n      | "
         << b5  << ' ' << b6  << ' ' << b7  << ' ' << b8  << " |  5  6  7  8\n      | "
         << b9  << ' ' << b10 << ' ' << b11 << ' ' << b12 << " |  9 10 11 12\n      | "
         << b13 << ' ' << b14 << ' ' << b15 << ' ' << b16 << " | 13 14 15 16" << endl;
    cout << "       ---------\n      Pieces:     Curved Straight"<< endl;
    cout << "            Upper: " << avlTkns.at(0) << avlTkns.at(1) << "/" << avlTkns.at(2) << avlTkns.at(3)
         << "  " << avlTkns.at(4) << avlTkns.at(5) << "/" << avlTkns.at(6) << avlTkns.at(7) << endl;
    cout << "            Lower: " << avlTkns.at(8) << avlTkns.at(9) << "/" << avlTkns.at(10) << avlTkns.at(11)
         << "  " << avlTkns.at(12) << avlTkns.at(13) << "/" << avlTkns.at(14) << avlTkns.at(15) << endl;
    cout << "                Vowel/Consonant"<< endl;
}

void assignToBoard(char c, int i) {
    switch (i) {
        case  1: b1  = c; break;
        case  2: b2  = c; break;
        case  3: b3  = c; break;
        case  4: b4  = c; break;
        case  5: b5  = c; break;
        case  6: b6  = c; break;
        case  7: b7  = c; break;
        case  8: b8  = c; break;
        case  9: b9  = c; break;
        case 10: b10 = c; break;
        case 11: b11 = c; break;
        case 12: b12 = c; break;
        case 13: b13 = c; break;
        case 14: b14 = c; break;
        case 15: b15 = c; break;
        case 16: b16 = c; break;
    }

}

bool isPositionAvailable(int i) {
    switch (i) {
        case  1: return b1  == '.' ? true : false;
        case  2: return b2  == '.' ? true : false;
        case  3: return b3  == '.' ? true : false;
        case  4: return b4  == '.' ? true : false;
        case  5: return b5  == '.' ? true : false;
        case  6: return b6  == '.' ? true : false;
        case  7: return b7  == '.' ? true : false;
        case  8: return b8  == '.' ? true : false;
        case  9: return b9  == '.' ? true : false;
        case 10: return b10 == '.' ? true : false;
        case 11: return b11 == '.' ? true : false;
        case 12: return b12 == '.' ? true : false;
        case 13: return b13 == '.' ? true : false;
        case 14: return b14 == '.' ? true : false;
        case 15: return b15 == '.' ? true : false;
        case 16: return b16 == '.' ? true : false;
        default: return false;
    }
}

// OICZ  (all upper case)
// ZiiI  (all straight-line)
// ZzCc  (all consonants)
bool isCurl(char c) {
    return constCurlies.find(c) != string::npos;
}
bool isStrait(char c) {
    return constStraights.find(c) != string::npos;
}
bool isConst(char c) {
    return constConsts.find(c) != string::npos;
}
bool isVowel(char c) {
    return constVowel.find(c) != string::npos;
}
bool isUpper(char c) {
    return constUpper.find(c) != string::npos;
}
bool isLower(char c) {
    return constLower.find(c) != string::npos;
}

void checkCombo(char a,char b,char c,char d) {
    if (isCurl(a) && isCurl(b) && isCurl(c) && isCurl(d)){
        activeGame = false;
    } else if (isStrait(a) && isStrait(b) && isStrait(c) && isStrait(d)){
        activeGame = false;
    } else if (isConst(a) && isConst(b) && isConst(c) && isConst(d)){
        activeGame = false;
    } else if (isVowel(a) && isVowel(b) && isVowel(c) && isVowel(d)){
        activeGame = false;
    } else if (isUpper(a) && isUpper(b) && isUpper(c) && isUpper(d)){
        activeGame = false;
    } else if (isLower(a) && isLower(b) && isLower(c) && isLower(d)){
        activeGame = false;
    }

}

void checkForWin() {
    // check quadrants
    checkCombo( b1, b2, b5, b6);
    checkCombo( b3, b4, b7, b8);
    checkCombo( b9,b10,b13,b14);
    checkCombo(b11,b12,b15,b16);

    // check rows
    checkCombo( b1, b2, b3, b4);
    checkCombo( b5, b6, b7, b8);
    checkCombo( b9,b10,b11,b12);
    checkCombo(b13,b14,b15,b16);

    // check columns
    checkCombo(b1,b5,b9,b13);
    checkCombo(b2,b6,b10,b14);
    checkCombo(b3,b7,b11,b15);
    checkCombo(b4,b8,b12,b16);

    // check cross
    checkCombo(b1,b6,b11,b16);
    checkCombo(b4,b7,b10,b13);
}

bool emptyTokens() {
    int stringVal;
    for (int i = 0; i < avlTkns.size(); ++i) {
        stringVal += avlTkns.at(i);
    }

    return stringVal == 558;
}


int main() {
    char userToken;
    string userPosition;
    int posNum;
    int idx;
    int turnNum = 1;

    displayInstructions();

    while (activeGame == true) {
        displayBoard();

        cout << turnNum << ". Player " << (turnNum % 2 ? "1" : "2")
             << " enter piece, and Player "<< (turnNum % 2 ? "2" : "1")
             << " enter destination: ";

        cin >> userToken;
        if (userToken == 'X' ||userToken == 'x' || emptyTokens() == 1) {
            cout << "Exiting program..."  << endl;
            activeGame = false;
            break;
        }

        cin >> userPosition;
        posNum = stoi(userPosition);

        if ((isPositionAvailable(posNum)) == 1) {
            idx = avlTkns.find(userToken);
            if (idx > -1 ){
                turnNum++;
                avlTkns.replace(idx ,1," ");
                assignToBoard(userToken, posNum);
                checkForWin();
            } else {
                cout << "*** Sorry, that is an invalid piece.  Please retry." << endl;
            }
        } else {
             if (posNum < 1 || posNum > 16) {
                cout << "*** Sorry, that destination is invalid.  Please retry." << endl;
            } else if (!constCurlies.find(userToken) || !constStraights.find(userToken)) {
                 cout << "*** Sorry, that is an invalid piece.  Please retry." << endl;
             } else {
                 cout << "*** Sorry, that destination is occupied.  Please retry." << endl;
            }
        }
        if (activeGame == false) {
            cout << "*** Player " << (turnNum % 2 ? "1" : "2") << " you won!" << endl;
            break;
        }

    }

    return 0;
}
