// File Name: Player.cpp
// Manages songs on a music player device.

#include <iomanip>
using namespace std;

#include "Player.h"

//******************************************************************
// Player: assigns the name and size to seperate variables, and
// initializes the count to 0.
// name: the name of the player.
// size: max size the player can hold in mb.
//******************************************************************
Player::Player(string name, float size)
{
    name1 = name;
    sizeMG = size;
    count = 0;
}

//******************************************************************
// addSong: checks if a song is allowed to be added in, and
// adds the song in.
// band: the name of the band.
// title: name of the song.
// length: length of the song.
// size: space in mb the song takes up.
// returns true if the song has been added and false if it has not.
//******************************************************************
bool Player::addSong(string band, string title, string length, float size) {
    
    Song addNewSong;                                    //will hold the new song.
    
    if(count >= SIZE)
        return false;
    else if(size + totalSize() >= sizeMG) {
        cout << "Not enough Memory." << endl;
        return false;
    }
    else if(searchInfo(band, title) != -1) {
        cout << "Song is already present." << endl;
        return false;
    }
    
    addNewSong.band = band;
    addNewSong.title = title;
    addNewSong.length = length;
    addNewSong.size = size;

    arr[count] = addNewSong;
    count++;
    
    return true;
    
}

//******************************************************************
//removeSong: removes a song from the array of songs.
//band: name of the band.
//title: name of the song.
//returns true if the song was removed.
//******************************************************************
bool Player::removeSong(string band, string title) {
    int index;                                      //will hold location of song to be removed.
    
    if((index = searchInfo(band, title)) == -1) {
        cout << "This song was not found" << endl;
        return false;
    }
    bool found = false;             //has been found in the array.
    
    for(int i = 0; i < count; i++) {
        if(found) {
            arr[i-1] = arr[i];
            continue;
        }
        if(i == index) {
            found = true;
        }
    }
    count--;
    return true;
}

//******************************************************************
//displaySongInfo: checks if the song exists and then calls a
//funcion to display the song.
//band: band name.
//title: song name.
//******************************************************************
void Player::displaySongInfo(string band, string title) {
    int index;                              //will hold location of song to be displayed.
    
    if((index = searchInfo(band, title)) == -1) {
        cout << "This song was not found" << endl;
        return;
    }
    
    cout << "Song information: " << endl;
    displaySongs(index);
}

//******************************************************************
//displaySongsByLength: sorts the songs by their length all while
//calling a function to display them.
//******************************************************************
void Player::displaySongsByLength() {
    for(int i = 0; i < count; i++) {
        int shortSong = i;                   //will hold the shortest length song.
        
        for(int z = i + 1; z < count; z++) {
            if(arr[z].length.toSeconds() < arr[shortSong].length.toSeconds()) {
                shortSong = z;
            }
        }
        Song temp = arr[i];                 //will temporarily hold the arr value.
        arr[i] = arr[shortSong];
        arr[shortSong] = temp;
    }
    for(int i = 0; i < count; i++) {
        displaySongs(i);
    }
}

//******************************************************************
//deviceInfo: calculates total length and free space and displays
//the device information.
//******************************************************************
void Player::deviceInfo() {
    int totalL = 0;                //will hold the total length.
    float free = sizeMG;           //will hold the free space left.
    
    for(int i = 0; i < count; i++) {
        totalL += arr[i].length.toSeconds();
        free -= arr[i].size;
    }
    cout << setprecision(4);
    cout << "Device information: " << endl;
    cout << left << setw(8) << "Name: " << name1 << endl;
    cout << setw(15) << "Number of Songs: " << count << "/" << SIZE << endl;
    cout << setw(15) << "Total Length: ";
    cout << TimeStamp(totalL).toString() << endl;
    cout << setw(15) << "Amount of space left: " << free << "Mb" << endl;
    cout << endl;
}

//******************************************************************
//searchInfo: searches for a song based on the band name and song
//name.
//band: band name.
//title: song name.
//returns i if the song is found and -1 if not found.
//******************************************************************
int Player::searchInfo(string band, string title)
{
    for(int i = 0; i < count; i++) {
        if(arr[i].band == band && arr[i].title == title) {
            return i;
        }
    }
    return -1;
}

//******************************************************************
//displaySongs: displays the song.
//index: holds the locaiton of the song to be displayed.
//******************************************************************
void Player::displaySongs(int index) {
    cout << left;
    cout << setw(8) << "Band: " << arr[index].band << endl;
    cout << setw(8) << "Title: " << arr[index].title << endl;
    cout << setw(8) << "Length: " << arr[index].length.toString() << endl;
    cout << setw(8) << "Size: " << arr[index].size << "Mb" << endl << endl;
}

//******************************************************************
//totalSize: calculates the total size of the songs.
//returns the total.
//******************************************************************
int Player::totalSize() {
    int total = 0;                  //will hold total size.
    
    for (int i = 0; i < count; i++) {
        total += arr[i].size;
    }
    return total;
}
