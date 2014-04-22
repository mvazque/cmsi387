/**
 * Implementation of the software paging unit.
 */
#include "addressTranslation.h"

#include <stdio.h>
#include <stdlib.h>

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {    
   int page;
   int offset;
   int physicalAddress;
   
   //This checks to make sure that the logical address is valid
   if(logical < 0 || logical >= 256){
      return ERR_OUT_OF_RANGE;
   }
   
   //Top four bits are the page number. Bottom four are the offset
   page = ((logical & PAGEMASK) >> PAGEBITS);
   offset = (logical & PAGESIZE);

   //Checks table to ensure the frame is valid
   if(ptr[page].valid == 0){
      return  ERR_INVALID;
   }

   //Gets physical address of page and adds with offset
   physicalAddress = ((ptr[page].frame) << PAGEBITS) + offset;
   return physicalAddress;	
}

