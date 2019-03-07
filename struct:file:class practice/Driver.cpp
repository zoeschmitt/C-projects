// File Name: Driver.cpp
//
// Author: Dmytro Katrychuk, Jill Seaman
// Date: 10/13/2018
//
// Tests the Player class, which manages songs on a music player device.

#include <iostream>
using namespace std;

#include "Player.h"

using namespace std;

int main() {
    Player ipod("iPod touch", 32.0);
    ipod.addSong("Pink Floyd", "Hey You", "4:41", 10.82);

    // expecting "Song is already present."
    ipod.addSong("Pink Floyd", "Hey You", "4:41", 10.82);

    ipod.addSong("The Doors", "Light My Fire", "7:06", 15.90);

    // expecting "Not enough memory."
    ipod.addSong("The Rolling Stones", "Gimme Shelter", "4:30", 10.33);

    ipod.addSong("The Rolling Stones", "Gimme Shelter", "4:30", 5.27);
    ipod.displaySongInfo("Pink Floyd", "Hey You");

    // expecting 3 songs, total length of 16:17 and 0.01 Mb of free space left
    ipod.deviceInfo();

    ipod.removeSong("Pink Floyd", "Hey You");
    
    // expecting 2 songs, total length of 11:36 and 10.83 Mb of free space left
    ipod.deviceInfo();


    Player sony("Sony Walkman", 64.0);
    // expecting "Song was not found!"
    sony.removeSong("The Doors", "Light My Fire");

    sony.addSong("Nirvana", "Polly", "2:57", 6.76);
    sony.addSong("Metallica", "Turn The Page", "6:06", 14.06);
    sony.addSong("Cream", "White Room", "5:03", 11.64);

    // expecting order: Nirvana, Cream, Metallica
    sony.displaySongsByLength();

    // expecting 3 songs, total length of 14:06 and 31.54 Mb of free space left    
    sony.deviceInfo();
}
/*
 Song is already present.
 Not enough memory.
 Song info:
 Band: Pink Floyd
 Title: Hey You
 Length: 4:41
 Size: 10.82 Mb
 
 Device info:
 Name: iPod touch
 Songs: 3/1000
 Total length: 16:17
 Free space left: 0.01 Mb
 
 Device info:
 Name: iPod touch
 Songs: 2/1000
 Total length: 11:36
 Free space left: 10.83 Mb
 
 Song was not found!
 All songs sorted by length:
 Band: Nirvana
 Title: Polly
 Length: 2:57
 Size: 6.76 Mb
 
 Band: Cream
 Title: White Room
 Length: 5:03
 Size: 11.64 Mb
 
 Band: Metallica
 Title: Turn The Page
 Length: 6:06
 Size: 14.06 Mb
 
 Device info:
 Name: Sony Walkman
 Songs: 3/1000
 Total length: 14:06
 Free space left: 31.54 Mb
 
 */
