#include <iostream>

using namespace std;

void moveTower(int disk, char source, char dest, char spare) 
{
    if(disk == 0) {
        cout << "move disk " << disk << " from " << source << " to " << dest << endl;
    }
    else {
        moveTower(disk - 1, source, spare, dest);
        cout << "move disk " << disk << " from " << source << " to " << dest << endl;
        moveTower(disk -1, spare, dest, source);
    }
}

int main() 
{
	cout << "Please enter the number of disk initially on peg A to continue..." << endl;
	cout << "(Recall that n initial disks would be called as" << endl;
	cout << "disk 0, disk 1, disk 2, ..., disk n-1" << endl;
	cout << "and we want to move all of them to peg B)" << endl;
	
	int n;
	cin >> n;
	
	moveTower(n-1, 'A', 'B', 'C');
	return 0;
}

