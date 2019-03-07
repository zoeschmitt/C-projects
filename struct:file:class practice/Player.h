// File Name: Player.h
// Holds the class for Player.cpp,
// Which manages the songs on a music player device.

#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
using namespace std;

#include "TimeStamp.h"

const int SIZE = 1000;          //Max size for amount of songs.

class Player {

private:
	struct Song
	{
        string band;           //Band name.
        string title;          //Song name.
        TimeStamp length;      //Length of Song.
        float size;            //Size of song in MB.
    };
    int count;                           //counts the amount of songs in array.
    Song arr[SIZE];                      //array of songs.
    string name1;                        //player name.
    float sizeMG;                        //max amount of mb.
    int searchInfo(string, string);
    void displaySongs(int);
    int totalSize();

public:
    Player(string name , float size);
    bool addSong(string , string , string , float );
    bool removeSong(string band, string title);
    void displaySongInfo(string band, string title);
    void displaySongsByLength();
    void deviceInfo();
};

#endif

