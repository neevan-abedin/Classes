#include <iostream>
#include <cstring>
#include "media.h"
#include "videogame.h"

using namespace std;

Videogame::Videogame()
{

}

char* Videogame::getPublisher(){
  return publisher;
}

float* Videogame::getRating(){
  return &rating;
}

int Videogame::getType(){
  return 2;
}