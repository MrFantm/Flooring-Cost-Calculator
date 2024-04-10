#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main() {

   const float laborCost = 4.55, carpetPadding = 1.65, carpetCost = 5.32, vinylCost = 3.45;
   string space = "          ";

   //Declaring File Stream
   ifstream mrInputFile;
   ofstream mrOutputFile;
   
   string names[4];
   
   mrInputFile.open("flooring.txt");
   mrOutputFile.open("estimateInfo.txt");
   
   //Get Names
   for(int i = 0; i < 4; i++) {
      mrInputFile >> names[i];
   }
   
   
   //Get Number of Rooms
   int numOfRooms;
   int roomNum[10];
   mrInputFile >> numOfRooms;
   
   //Room Info
   char floorType[10];
   float dimensions[10][2], totalCost;

   for(int i = 0; i < numOfRooms; i++) {
      mrInputFile >> roomNum[i];
      mrInputFile >> floorType[i];
      mrInputFile >> dimensions[i][0];
      mrInputFile >> dimensions[i][1];
   }
   
   float totalSqrFt, actualTotal = 0;
   
   //Print Output
   mrOutputFile << "Estimate for: " << names[0] <<  " " << names[1] << endl;
   mrOutputFile << "Salesperson: " << names[2] <<  " " << names[3] << endl << endl;
   mrOutputFile << "Room Number" << space << "Room Size" << space << "Square Footage" << space << "Cost (Installed)" << endl;
   
   //Run calculations for each room
   for(int i = 0; i < numOfRooms; i++) {
      totalSqrFt = dimensions[i][0] * dimensions[i][1];
      
      if(floorType[i] == 'C') {
          totalCost = totalSqrFt * (carpetCost + carpetPadding + laborCost);
      } else if(floorType[i] == 'V') {
          totalCost = (totalSqrFt * vinylCost) + (totalSqrFt * laborCost);
      }
      actualTotal = actualTotal + totalCost;
      mrOutputFile << "    " << roomNum[i] << "           " << fixed << setprecision(2) << dimensions[i][0] << " ft x " << dimensions[i][1] << " ft" << "      " << totalSqrFt << " sq ft                $" << totalCost << endl; 
   }
   
   mrOutputFile << endl << endl << "Total Flooring Cost will be $" << actualTotal;
   
   cout << "\nSuccessfully generated Estimate File! Have a nice day!\n";

   return 0;
}