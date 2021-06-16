#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef unsigned int uint_t;

typedef enum { ECTS_3, ECTS_6 } module_t;

typedef struct {
  module_t credits;
  uint_t number;
  char* title;
  bool selected;
} descr_t;

char* genTitleString( const char* title ) {
  // YOUR CODE
}

uint_t getCreditRating( module_t type ) {
  // YOUR CODE
}

uint_t set_module_info( descr_t** modules ) {

  // hardcoded number of modules we have
  const uint_t nMods = 15;

  // dynamic memory allocation for module descriptions
  descr_t* mods = NULL;
  mods = (descr_t*) malloc( sizeof(descr_t) * nMods );
  if( mods == NULL ) {
    fprintf( stderr, "Oops! Memory allocation failed\n" );
    exit( EXIT_FAILURE );
  }

  // set info for individual modules

  // YOUR CODE

  mods[ 0].title = "Gravity and Magnetic Field from Space";
  mods[ 1].title = "Gravity Field and Satellite Missions";
  mods[ 2].title = "Orbit Mechanics";
  mods[ 3].title = "Remote Sensing";
  mods[ 4].title = "Deformation and Transformation";
  mods[ 5].title = "Active Tectonics";
  mods[ 6].title = "Geophysical Methods and Archaeology";
  mods[ 7].title = "Geophysics and Engineering";
  mods[ 8].title = "Inverse Problems in Geophysics";
  mods[ 9].title = "Planetary Geology";
  mods[10].title = "Precise Global Navigation Satellite Systems";
  mods[11].title = "Atmosphere and Oceans";
  mods[12].title = "Rheology and Thermal Analysis of Melts";
  mods[13].title = "Geokinematics and Continental Hydrology";
  mods[14].title = "Petrophysics";

  // hand-back number of modules and descriptions

  // YOUR CODE
}

// print a list of all unselected modules
void printModuleList( const descr_t * const mods, uint_t nMods, bool filter ) {
  for( uint_t k = 0; k < nMods; k++ ) {
    if( mods[k].selected == filter ) {
      printf( " * WP %2d \"%s\" [%d ECTS]\n", mods[k].number,
              mods[k].title, getCreditRating( mods[k].credits ) );
    }
  }
}

void printSeparator() {
  uint_t n = 78;
  for( uint_t k = 0; k < n; k++ ) {
    printf( "-" );
  }
  printf( "\n" );
}

void printHeader() {
  printSeparator();
  printf( " MODULE SELECTION TOOL\n" );
  printSeparator();
  printf( " Following the default study plan you have to select 12 credits" );
  printf( " worth of\n elective modules in your 3rd semester.\n" );
  printf( " This tool will help you with the process.\n\n" );
  printSeparator();
}

bool checkValidity( /* YOUR CODE */ ) {

  // check that new represents a valid module number
  *idx = nMods;
  for( uint_t k = 0; k < nMods; k++ ) {
    if( mods[k].number == new ) {
      *idx = k;
    }
  }
  if( *idx == nMods ) {
    printf( " No module with number %d exists!\n", new );
    return false;
  }

  // check that new module has not been selected, yet
  bool valid = true;
  valid = valid && !mods[*idx].selected;
  if( !valid ) {
    printf( " Selection not valid! Module WP %d was already selected!\n",
            new );
  }

  // check that selection will not exceed maximal score
  valid = valid && ( credits + getCreditRating( mods[*idx].credits ) > 12 ?
                     false : true );
  if( !valid ) {
    printf( " Selection not valid! Too many credits!\n" );
  }

  return valid;
}

uint_t getChoice( descr_t* mods, uint_t nMods ) {

  uint_t sumCredits = 0;

  for( uint_t k = 0; k < nMods; k++ ) {
    if( mods[k].selected ) {
      sumCredits += getCreditRating( mods[k].credits );
    }
  }

  printf( " Please select another module from the following list,\n" );
  printf( " by entering its number {7,8,....,21}\n\n" );

  printModuleList( mods, nMods, false );

  bool validChoice = false;
  while( !validChoice ) {

    uint_t new, idx;
    printf( "\n Your choice? " );
    scanf( "%u", &new );

    if( checkValidity( /* YOUR CODE */ ) ) {
      mods[idx].selected = true;
      sumCredits += getCreditRating( mods[idx].credits );
      validChoice = true;
    }
  }

  return sumCredits;
}

void printStatus( descr_t* mods, uint_t nMods ) {

  uint_t sumCredits = 0;

  for( uint_t k = 0; k < nMods; k++ ) {
    if( mods[k].selected ) {
      sumCredits += getCreditRating( mods[k].credits );
    }
  }
  
  // list selected
  printf( " Modules selected so far: \n" );
  if( sumCredits > 0 ) {
    printModuleList( mods, nMods, true );
  }
  else {
    printf( " - none -\n" );
  }
  printf( " ==> That's %d/12 credits\n", sumCredits );
  printSeparator();
}

int main( void ) {

  descr_t* modules = NULL;
  uint_t nModules = set_module_info( &modules );

  printHeader();
  printStatus( modules, nModules );

  uint_t sumCredits = 0;
  while( sumCredits < 12 ) {
    sumCredits = getChoice( modules, nModules );
    printSeparator();
    printStatus( modules, nModules );
  }

  printf( " Thanks for using the MODULE SELECTION TOOL\n" );
  printSeparator();

}
