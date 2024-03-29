//Harmanjeet Singh Hara
//Student ID#:118624220 , email: hhara@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here    

   

   bool read(int& employeeNumber) {
       bool success = fscanf(fptr, "%d,", &employeeNumber) == 1;
       return success;
   }

   bool read(double& employeeSalary) {
       bool success = fscanf(fptr, "%lf,", &employeeSalary) == 1;
       return success;
   }

   bool read(char* employeeName) {
       bool success = fscanf(fptr, "%[^\n]\n", employeeName) == 1;
       return success;
   }
   
}