#include "Vehicle.h"
#include "GroundSquare.h"

#include <cstdlib>
#include <ctime>

GroundSquare movement(GroundSquare start, Vehicle veh) {

    GroundSquare new_pos;
    unsigned random = rand()%4;

    switch(random) {
        case 0:
            new_pos.setXCoord(start.getXCoord());
            new_pos.setYCoord(veh.getSpeed() + start.getYCoord());
            break;
        case 1:
            new_pos.setXCoord(veh.getSpeed()/2 + start.getXCoord());
            new_pos.setYCoord(veh.getSpeed()/2 + start.getYCoord());
            break;
        case 2:
            new_pos.setYCoord(start.getYCoord());
            new_pos.setXCoord(veh.getSpeed() + start.getXCoord());
            break;
        default:
            new_pos.setXCoord(veh.getSpeed()/2 + start.getXCoord());
            new_pos.setXCoord((veh.getSpeed()/2)*-1 + start.getYCoord());
    }

    return new_pos;

}

int main() {    
    GroundSquare player_pos;
    Vehicle player;
    srand(time(NULL));

    cout << "BEFORE" << endl << "======" << endl;
    player_pos.print();
    cout << endl;

    GroundSquare new_player_pos = movement(player_pos,player);

    cout << "AFTER" << endl << "=====" << endl;
    new_player_pos.print();
    cout << endl;

    system("PAUSE");
    return 0;
}