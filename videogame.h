#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Videogame : public Media {
 public:
  Videogame();
  virtual int getType();
  char* getPublisher();
  float* getRating();
 private:
  char publisher[30];
  float rating;
};
#endif