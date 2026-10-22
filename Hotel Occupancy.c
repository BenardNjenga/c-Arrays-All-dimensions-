/*
Name;Benard Njenga
Reg no;CT100/G/30708/26
Description;* Week 6 Activity: Arrays
            * Hotel Management System - Revenue Tracker & Room Occupancy
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    /* ---------------------------------------------------
       1D Array: Weekly Revenue Tracker
       --------------------------------------------------- */
    float revenue[7];
    float totalRevenue = 0;

    printf("==== Weekly Revenue Tracker ====\n");
    for(int day = 0; day < 7; day++){
        printf("Enter revenue for day %d: ", day + 1);
        scanf("%f", &revenue[day]);
        totalRevenue += revenue[day];
    }

    float avgRevenue = totalRevenue / 7;
    printf("\nTotal Weekly Revenue : KES %.2f\n", totalRevenue);
    printf("Average Daily Revenue: KES %.2f\n", avgRevenue);

    /* ---------------------------------------------------
       2D Array: Room Occupancy (One Branch)
       occupancy[floor][room] -> 1 = occupied, 0 = vacant
       --------------------------------------------------- */
    int occupancy[5][10];
    srand(time(0));   // seed the random generator once

    printf("\n==== Room Occupancy (One Branch) ====\n");
    for(int floor = 0; floor < 5; floor++){
        int occupied = 0, vacant = 0;

        for(int room = 0; room < 10; room++){
            occupancy[floor][room] = rand() % 2;   // simulate 0 or 1

            if(occupancy[floor][room] == 1)
                occupied++;
            else
                vacant++;
        }

        printf("Floor %d: Occupied = %d, Vacant = %d\n", floor + 1, occupied, vacant);
    }

    /* ---------------------------------------------------
       3D Array: Multiple Branches
       chain[branch][floor][room] -> 1 = occupied, 0 = vacant
       --------------------------------------------------- */
    int chain[3][5][10];
    int totalOccupied = 0;

    printf("\n==== Occupancy Across All Branches ====\n");
    for(int branch = 0; branch < 3; branch++){
        int branchOccupied = 0;

        for(int floor = 0; floor < 5; floor++){
            for(int room = 0; room < 10; room++){
                chain[branch][floor][room] = rand() % 2;

                if(chain[branch][floor][room] == 1){
                    branchOccupied++;
                    totalOccupied++;
                }
            }
        }

        printf("Branch %d occupied rooms: %d\n", branch + 1, branchOccupied);
    }

    printf("\nTotal Occupied Rooms (All Branches): %d\n", totalOccupied);

    return 0;
}
